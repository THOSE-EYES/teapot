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
#include <cmath>

// Make Windows happy
#ifdef _WIN32
	#define _USE_MATH_DEFINES
	#define NOMINMAX
	#include <Windows.h>
#endif

// Include OpenGL code
#include <GL/gl.h>
#include <GL/glut.h>

namespace gl::utils {
	class ColorRGB {
	public:
		ColorRGB() = default;
		ColorRGB(GLfloat red, GLfloat green, GLfloat blue);

	public:
		GLfloat get_red() const;
		GLfloat get_green() const;
		GLfloat get_blue() const;

		static ColorRGB random();

	private:
		GLfloat red_;
		GLfloat green_;
		GLfloat blue_;
	};
} // namespace gl::utils