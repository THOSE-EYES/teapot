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

// Include project headers
#include "gl/window.h"
#include "gl/utils/camera.h"

// FIXME : remove
#include <iostream>

namespace gl {
	Window* Window::instance_;

	Window* Window::get() {
		// If there is no window instance create it
		if (!instance_) instance_ = new Window();

		return instance_;
	}

	void Window::set_size(Size value) {
		if (value != size_) size_ = value;
	}

	Window::Size Window::get_size() const {
		return size_;
	}

	void Window::set_title(std::string value) {
		// FIXME : after initialization the changes won't have effect

		if (value != title_ || !value.empty()) title_ = value;
	}

	std::string Window::get_title() const {
		return title_;
	}

	void Window::set_scene_rotation(utils::Rotation value) {
		if (scene_rotation_ != value) scene_rotation_ = value;
	}

	utils::Rotation Window::get_scene_rotation() const {
		return scene_rotation_;
	}

	void Window::add_shape(std::shared_ptr<ShapeType> value) {
		if (value) shapes_->push_back(value);
	}

	const std::shared_ptr<Window::Shapes> Window::get_shapes() const {
		return shapes_;
	}

	void Window::init() {
		if (initialized_) {
			// FIXME :  print some message
			return;
		}

		// Set window parameters
		glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
		glutInitWindowSize(size_.at(0), size_.at(1));
		glutCreateWindow(title_.c_str());

		// Set callbacks
		glutIdleFunc(idle_callback);
		glutDisplayFunc(display_callback);
		glutReshapeFunc(reshape_callback);

		// Mark the window initalized
		initialized_ = true;
	}

	void Window::reshape_callback(GLsizei width, GLsizei height) {
		// Set the size of the window
		auto window = Window::get();
		window->set_size({ width, height });

		// Change the matrix mode to make changes in it
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();

		// Set perspective
		gluPerspective(70, 1.0, 1.0, 30.0);

		// Update matrix of view
		if (width <= height)
			glViewport(0, (width - height) / 2, width, width);
		else
			glViewport((width - height) / 2, 0, height, height);

		// Return to the previous matrix mode
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
	}

	void Window::display_callback() {
		// Clear the window
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// FIXME : is it needed here?
		glLoadIdentity();

		// Get the window pointer
		const auto window = Window::get();

		// Rotate the image
		const auto rotation = window->get_scene_rotation();
		glRotatef(rotation.roll, 0.0, 0.0, 1.0);
		glRotatef(rotation.pitch, 0.0, 1.0, 0.0);
		glRotatef(rotation.yaw, 1.0, 0.0, 0.0);

		// Change the observer's position
		const auto observer = utils::Camera::get()->get_position();
		gluLookAt(observer.x, observer.y, observer.z, 
					0.0, 0.0, 0.0, 
					0.0, 1.0, 0.0);
					
		// Draw every shape, which should be drawn
		const auto shapes = window->get_shapes();
		for (const auto& shape : *shapes) {
			shape->draw();
		}

		// Actually draw the shapes
		glFlush();
		glutSwapBuffers();
	}

	void Window::idle_callback() {
		// Redisplay the window's content
		glutPostRedisplay();
	}
} // namespace gl