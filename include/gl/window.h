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
#include "gl/utils/scene/camera.h"
#include "gl/utils/scene/light.h"

namespace gl {
	class Window {
	public:
		using ShapeType = gl::shapes::Shape<gl::primitives::Point3D>;								// Just use 3D here
		using Shapes = std::deque<std::shared_ptr<ShapeType>>;

	public:
		struct Size {
		public:
			uint16_t width;
			uint16_t height;
		public:
			bool operator==(const Size& rhs) const;
			bool operator!=(const Size& rhs) const;
		};

	public:
		Window() = default;

		Window(const Window& another) = delete;
		Window(Window&& another) = delete;

	public:
		virtual void init() = 0;

		virtual void redraw() const;

		virtual void set_size(Size value);
		Size get_size() const;

		void set_title(std::string value);
		std::string get_title() const;

		void set_rotation(utils::Rotation value);
		utils::Rotation get_rotation() const;

		void add_shape(std::shared_ptr<ShapeType> value);
		const std::shared_ptr<Shapes> get_shapes() const;

		std::shared_ptr<utils::scene::Camera> get_camera() const;

		std::deque<std::shared_ptr<utils::scene::Light>> get_lights() const;
		void add_light(const std::shared_ptr<utils::scene::Light>& value);

		float get_angle_x(const gl::utils::Position2D& start, 
							const gl::utils::Position2D& end) const;
		float get_angle_y(const gl::utils::Position2D& start, 
							const gl::utils::Position2D& end) const;

	protected:
		void set_camera(std::shared_ptr<utils::scene::Camera> value);

		virtual void rotate(const utils::Rotation& value) const = 0;

	private:
		std::string title_{ "Window" };
		Size size_{ 480, 480 };					// Settings for very old and small monitors

		utils::Rotation scene_rotation_{ 0.0, 0.0, 0.0 };
		std::shared_ptr<Shapes> shapes_{ std::make_shared<Shapes>() };

		std::shared_ptr<utils::scene::Camera> camera_;

		std::deque<std::shared_ptr<utils::scene::Light>> lights_;
	};
} // namespace gl