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
#include "gl/window.h"

namespace opengl {
	class OGLWindow final : public gl::Window {
	public:
		void init();

	public:
		static std::shared_ptr<OGLWindow> get();

		void redraw() const override;

		void set_size(Size value) override;

	public:
		// This is needed for OpenGL
		static void reshape_callback(GLsizei width, GLsizei height);
		static void display_callback();
		static void idle_callback();

	protected:
		OGLWindow();

	protected:
		void rotate(const gl::utils::Rotation& value) const override;

	private:
		void update_geometry(Size size) const;

	private:
		static std::shared_ptr<OGLWindow> instance_;
		bool initialized_{ false };
	};
} // namespace opengl