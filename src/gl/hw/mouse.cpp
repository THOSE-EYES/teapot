/**
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

// Include C++ stuff
#include <algorithm>

// FIXME : remove
#include <iostream>

// Include project headers
#include "gl/hw/mouse.h"
#include "gl/window.h"
#include "gl/utils/camera.h"

namespace gl::hw {
	Mouse* Mouse::instance_;

	Mouse* Mouse::get() {
		// If there is no window instance create it
		if (!instance_) instance_ = new Mouse();

		return instance_;
	}

	void Mouse::button_callback(int btn, int state, int x, int y) {
		auto mouse = Mouse::get();

		// Save the state of the button
		utils::Position2D position{x, y};
		mouse->buttons_state_[btn] = {state, position, position};

		// Redraw the screen
		Window::display_callback();
	}

	void Mouse::motion_callback(GLsizei x, GLsizei y) {
		// Find the first pressed button
		auto mouse = Mouse::get();
		auto& buttons_state_ = mouse->buttons_state_;
		auto button = std::find_if(buttons_state_.begin(), buttons_state_.end(),
									[](const auto& pair) -> bool {
										return pair.second.state == GLUT_DOWN;
									});

		// If there are no pressed buttons, just return
		if (button == buttons_state_.end()) return;

		// Update the state of the button
		auto& state = button->second;
		state.end = {static_cast<float>(x), static_cast<float>(y)};

		// Route the event to the dedicated method
		switch (button->first) {
			case GLUT_LEFT_BUTTON:
				mouse->on_left_button_clicked(state);
				break;
			case GLUT_RIGHT_BUTTON:
				mouse->on_right_button_clicked(state);
				break;
		}

		// Redisplay method
		glutPostRedisplay(); 
	}

	void Mouse::on_left_button_clicked(const ButtonState& state) {
		const auto to_angle = [](const auto& start, const auto& end, const auto& length) -> float {
			return (end - start) * 360.0 / static_cast<float>(length);
		};

		// Get the window to operate on
		auto window = Window::get();
		const auto size = window->get_size();

		// Calculate the new rotation value
		auto rotation = window->get_scene_rotation();
   		rotation.pitch += to_angle(state.start.x, state.end.x, size.at(0));
   		rotation.yaw += to_angle(state.start.y, state.end.y, size.at(1));

		// Update the rotation
		window->set_scene_rotation(rotation);
	}

	void Mouse::on_right_button_clicked(const ButtonState& state) {
		auto camera = utils::Camera::get();

		// Zoom the camera
		auto distance = camera->get_distance();
		distance += (state.end.y - state.start.y);

		camera->set_distance(distance);
	}

	void Mouse::init() {
		glutMouseFunc(button_callback);
		glutMotionFunc(motion_callback);
	}
} //namespace gl::hw