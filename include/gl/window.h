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
#include <array>
#include <string>

// Include project headers
#include "gl/shapes/shape.h"
#include "gl/primitives/points.h"
#include "gl/utils/transformation.h"

namespace gl {
	class Window {
	public:
		using Size = std::array<GLint, 2>;
		using ShapeType = gl::shapes::Shape<gl::primitives::Point3D>;								// Just use 3D here
		using Shapes = std::vector<std::shared_ptr<ShapeType>>;

	public:
		Window(const Window& another) = delete;
		Window(Window&& another) = delete;

	public:
		static Window* get();

		void init();

		void set_size(Size value);
		Size get_size() const;

		void set_title(std::string value);
		std::string get_title() const;

		void set_scene_rotation(utils::Rotation value);
		utils::Rotation get_scene_rotation() const;

		void add_shape(std::shared_ptr<ShapeType> value);
		const std::shared_ptr<Shapes> get_shapes() const;

	public:
		static void reshape_callback(GLsizei width, GLsizei height);
		static void display_callback();
		static void idle_callback();

	private:
		Window() = default;

	private:
		static Window* instance_;
		bool initialized_{ false };

		std::string title_{ "Window" };
		Size size_{ 480, 480 };					// Settings for very old and small monitors
		
		utils::Rotation scene_rotation_{ 0.0, 0.0, 0.0 };

		std::shared_ptr<Shapes> shapes_{ std::make_shared<Shapes>() };
	};
} // namespace gl