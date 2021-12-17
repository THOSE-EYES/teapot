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
#include "opengl/hw/oglkeyboard.h"
#include "opengl/oglwindow.h"

namespace opengl::hw {
	std::shared_ptr<OGLKeyboard> OGLKeyboard::instance_;

	std::shared_ptr<OGLKeyboard> OGLKeyboard::get() {
		// If there is no instance create it
		if (!instance_) instance_.reset(new OGLKeyboard());

		return instance_;
	}

	void OGLKeyboard::keyboard_callback(unsigned char key, int x, int y) {
		// Get keyboard instance
		auto keyboard = OGLKeyboard::get();
		keyboard->on_key_pressed(key);
	}

	void OGLKeyboard::init() {
		glutKeyboardFunc(keyboard_callback);
	}

	void OGLKeyboard::on_key_pressed(char key) {
		// TODO

		// Redraw the screen
		auto window = OGLWindow::get();
		window->redraw();
	}
	
	void OGLKeyboard::on_key_released(char key) {
		// TODO
	}
} //namespace gl::hw