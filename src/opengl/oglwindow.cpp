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
#include "opengl/oglwindow.h"
#include "opengl/utils/scene/oglcamera.h"

namespace opengl {
	std::shared_ptr<OGLWindow> OGLWindow::instance_;

	OGLWindow::OGLWindow() {
		set_camera(utils::scene::OGLCamera::get());
	}

	std::shared_ptr<OGLWindow> OGLWindow::get() {
		// If there is no window instance create it
		if (!instance_) instance_.reset(new OGLWindow());

		return instance_;
	}

	void OGLWindow::rotate(const gl::utils::Rotation& value) const {
		// OpenGL scene rotation method
		glRotatef(value.roll, 0.0, 0.0, 1.0);
		glRotatef(value.pitch, 0.0, 1.0, 0.0);
		glRotatef(value.yaw, 1.0, 0.0, 0.0);
	}

	void OGLWindow::init() {
		if (initialized_) {
			// FIXME :  print some message
			return;
		}

		// Set window parameters
		glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
		glutInitWindowSize(get_size().width, get_size().height);
		glutCreateWindow(get_title().c_str());

		// Enable some things
		glShadeModel(GL_SMOOTH);
    	glEnable(GL_LIGHTING);
    	glEnable(GL_DEPTH_TEST);

		// Set callbacks
		glutIdleFunc(idle_callback);
		glutDisplayFunc(display_callback);
		glutReshapeFunc(reshape_callback);

		// Mark the window initalized
		initialized_ = true;
	}

	void OGLWindow::redraw() const {
		// Clear the window
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glLoadIdentity();

		// Call the base class method to redraw shapes and update scene objects
		Window::redraw();

		// Actually draw everything
		glutSwapBuffers();
	}

	void OGLWindow::update_geometry(Size size) const {
		// Change the matrix mode to make changes in it
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();

		// Set perspective
		gluPerspective(70, 1.0, 1.0, 30.0);

		// Update matrix of view
		if (size.width <= size.height)
			glViewport(0, (size.width - size.height) / 2, size.width, size.width);
		else
			glViewport((size.width - size.height) / 2, 0, size.height, size.height);

		// Return to the previous matrix mode
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
	}

	void OGLWindow::set_size(Size value) {
		// Call the superclass method
		Window::set_size(value);

		// Make the window update the geometry
		update_geometry(value);
	}

	void OGLWindow::reshape_callback(GLsizei width, GLsizei height) {
		// Set the size of the window
		auto window = OGLWindow::get();
		window->set_size({ static_cast<uint16_t>(width), 
							static_cast<uint16_t>(height) });
	}

	void OGLWindow::display_callback() {
		// Redraw the window
		const auto window = OGLWindow::get();
		window->redraw();
	}

	void OGLWindow::idle_callback() {
		// Redisplay the window's content
		glutPostRedisplay();
	}
} // namespace opengl