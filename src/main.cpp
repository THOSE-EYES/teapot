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
#include "gl/hw/keyboard.h"
#include "gl/hw/mouse.h"
#include "gl/utils/camera.h"
#include "gl/shapes/teapot.h"

int main(int argc, char* argv[]) {
	// Setting the seed for the random number generator
	#ifdef WIN32
		::srand(GetTickCount());
	#else
		srand(time(NULL));
	#endif

	// Init GLUT
	glutInit(&argc, argv);

	// Initialize the window
	auto window = gl::Window::get();
	window->init();

	// Initialize the keyboard
	auto keyboard = gl::hw::Keyboard::get();
	keyboard->init();

	// Initialize the mouse
	auto mouse = gl::hw::Mouse::get();
	mouse->init();

	// Initialize the camera
	// FIXME : hardcoded parameter
	auto camera = gl::utils::Camera::get();
	//camera->set_rotation({0, 0, 0});
	camera->set_distance(10);

	// Add a teapot to display
	auto teapot = std::make_shared<gl::shapes::Teapot>(GLushort(3));
	teapot->set_mode(gl::shapes::Teapot::Mode::LINES);
	window->add_shape(teapot);

	// Enter the main loop
	glutMainLoop();

	return 0;
}