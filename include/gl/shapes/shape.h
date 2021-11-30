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
#include <memory>
#include <vector>

// Make Windows happy
#ifdef _WIN32
	#define _USE_MATH_DEFINES
	#define NOMINMAX
	#include <Windows.h>
#endif

// Include OpenGL code
#include <GL/gl.h>
#include <GL/glut.h>

namespace gl::shapes {
	template <class Point>
	class Shape {
	public:
		enum class Mode : GLushort {
			POINTS = 0,
			LINES,
			TRIANGLES
		};

	public:
		using Points = std::vector<std::vector<Point>>;

	public:
		virtual void draw() const = 0;

		void set_points(std::shared_ptr<Points> value) {
			if (points_ != value) points_ = value;
		}

		std::shared_ptr<Points> get_points() const {
			return points_;
		}

		void set_mode(Mode value) {
			if (value != mode_) mode_ = value;
		}

		Mode get_mode() const {
			return mode_;
		}

	private:
		std::shared_ptr<Points> points_;

		Mode mode_{ Mode::POINTS };
	};
} // namespace gl::shapes