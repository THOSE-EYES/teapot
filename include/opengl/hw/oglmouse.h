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

// Make Windows happy
#ifdef _WIN32
	#define _USE_MATH_DEFINES
	#define NOMINMAX
	#include <Windows.h>
#endif

// Include C++ stuff
#include <memory>

// Include OpenGL code
#include <GL/gl.h>
#include <GL/glut.h>

// Include project headers
#include "hw/mouse.h"

namespace opengl::hw {
	class OGLMouse : public ::hw::Mouse {
	public:
		OGLMouse(const OGLMouse& another) = delete;
		OGLMouse(OGLMouse&& another) = delete;

	public:
		static std::shared_ptr<OGLMouse> get();

		void init() override;

	public:
		static void button_callback(int btn, int state, int x, int y);
		static void motion_callback(GLsizei x, GLsizei y);

	protected:
		void on_moved(const gl::utils::Position2D& position) override;
		void on_left_button_clicked() override;
		void on_right_button_clicked() override;
		void on_wheel_clicked() override;

	private:
		OGLMouse() = default;

	private:
		static std::shared_ptr<OGLMouse> instance_;
	};
} // namespace hw