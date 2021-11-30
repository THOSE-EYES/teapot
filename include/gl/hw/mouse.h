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

#pragma once

// Include C++ stuff
#include <map>

// Make Windows happy
#ifdef _WIN32
	#define _USE_MATH_DEFINES
	#define NOMINMAX
	#include <Windows.h>
#endif

// Include OpenGL code
#include <GL/gl.h>
#include <GL/glut.h>

// Include project headers
#include "gl/utils/transformation.h"

namespace gl::hw {
	class Mouse {
	public:
		Mouse(const Mouse& another) = delete;
		Mouse(Mouse&& another) = delete;

	public:
		static Mouse* get();

		void init();

	public:
		static void button_callback(int btn, int state, int x, int y);
		static void motion_callback(GLsizei x, GLsizei y);

	protected:
		struct ButtonState {
			int state;

			utils::Position2D start;
			utils::Position2D end;
		};

	protected:
		void on_left_button_clicked(const ButtonState& state);
		void on_right_button_clicked(const ButtonState& state);

	private:
		Mouse() = default;

	private:
		static Mouse* instance_;

		std::map<int, ButtonState> buttons_state_;
	};
} // namespace hw