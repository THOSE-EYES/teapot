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

// Include project headers
#include "opengl/hw/oglmouse.h"
#include "opengl/oglwindow.h"
#include "opengl/utils/scene/oglcamera.h"

namespace opengl::hw {
	std::shared_ptr<OGLMouse> OGLMouse::instance_;

	std::shared_ptr<OGLMouse> OGLMouse::get() {
		// If there is no window instance create it
		if (!instance_) instance_.reset(new OGLMouse());

		return instance_;
	}

	void OGLMouse::button_callback(int id, int state, int x, int y) {
		auto mouse = OGLMouse::get();

		// Save the state of the button
		gl::utils::Position2D position{static_cast<float>(x), 
										static_cast<float>(y)};
		mouse->buttons_[id] = {state == GLUT_DOWN, position};

		// Route the event to the dedicated method
		switch (id) {
			case GLUT_LEFT_BUTTON:
				mouse->on_left_button_clicked();
				break;
			case GLUT_RIGHT_BUTTON:
				mouse->on_right_button_clicked();
				break;
		}		

		// Redraw the screen
		OGLWindow::display_callback();
	}

	void OGLMouse::motion_callback(GLsizei x, GLsizei y) {
		// Find the first pressed button
		auto mouse = OGLMouse::get();
		mouse->on_moved({static_cast<float>(x), 
							static_cast<float>(y)});

		// Redisplay method
		glutPostRedisplay(); 
	}

	void OGLMouse::on_left_button_clicked() {
		// TODO
	}

	void OGLMouse::on_right_button_clicked() {
		// TODO
	}

	void OGLMouse::on_wheel_clicked() {
		// TODO
	}

	// FIXME : split into several methods
	void OGLMouse::on_moved(const gl::utils::Position2D& position) {
		// IF we don't have enough lights, just don't do anything
		auto window = OGLWindow::get();
		auto lights = window->get_lights();
		if (lights.size() != 2) return;

		for (auto& [button, state] : buttons_)  {
			if (state.pressed == false) continue;
			
			// Route the event to the dedicated method
			switch (button) {
				case GLUT_LEFT_BUTTON: {
					auto rotation = lights.at(0)->get_rotation();

					// Update the rotation
					rotation.pitch += window->get_angle_x(state.position, position);
					rotation.yaw += window->get_angle_y(state.position, position);
					lights.at(0)->set_rotation(rotation);

					break;
				}

				case GLUT_RIGHT_BUTTON: {
					auto rotation = lights.at(1)->get_rotation();

					// Update the rotation
					rotation.pitch += window->get_angle_x(state.position, position);
					rotation.yaw += window->get_angle_y(state.position, position);
					lights.at(1)->set_rotation(rotation);

					break;
				}
			}

			// Update the position of the clisk
			state.position = position;
		}
	}

	void OGLMouse::init() {
		glutMouseFunc(button_callback);
		glutMotionFunc(motion_callback);
	}
} //namespace gl::hw