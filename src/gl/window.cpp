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

namespace gl {
	bool Window::Size::operator==(const Window::Size& rhs) const {
		return width == rhs.width && height == rhs.height;
	}

	bool Window::Size::operator!=(const Window::Size& rhs) const {
		return !operator==(rhs);
	}

	void Window::redraw() const {
		// Rotate the image
		const auto rotation = get_rotation();
		rotate(rotation);

		// Update camera
		get_camera()->update();

		// Update the lights
		const auto lights = get_lights();
		for (const auto& source : lights) source->update();

		// Draw every shape, which should be drawn
		const auto shapes = get_shapes();
		for (const auto& shape : *shapes) shape->draw();
	}

	void Window::set_size(Size value) {
		if (value != size_) {
			size_ = value;

			// Redraw the window
			redraw();
		}
	}

	Window::Size Window::get_size() const {
		return size_;
	}

	void Window::set_title(std::string value) {
		// FIXME : after initialization the changes won't have effect

		if (value != title_ || !value.empty()) title_ = value;
	}

	std::string Window::get_title() const {
		return title_;
	}

	void Window::set_rotation(utils::Rotation value) {
		if (scene_rotation_ != value) scene_rotation_ = value;
	}

	utils::Rotation Window::get_rotation() const {
		return scene_rotation_;
	}

	void Window::add_shape(std::shared_ptr<ShapeType> value) {
		if (value) shapes_->push_back(value);
	}

	std::deque<std::shared_ptr<utils::scene::Light>> 
	Window::get_lights() const {
		return lights_;
	}

	void Window::add_light(const std::shared_ptr<utils::scene::Light>& value) {
		// Sanity check
		if (!value) return;

		// FIXME : add some checks to not add the same light twice

		lights_.push_back(value);
	}

	const std::shared_ptr<Window::Shapes> Window::get_shapes() const {
		return shapes_;
	}

	std::shared_ptr<utils::scene::Camera> Window::get_camera() const {
		return camera_;
	}

	void Window::set_camera(std::shared_ptr<utils::scene::Camera> value) {
		if (camera_ != value) camera_ = value;
	}

	float Window::get_angle_x(const gl::utils::Position2D& start, 
								const gl::utils::Position2D& end) const {
		return (end.x - start.x) * 360.0 / static_cast<float>(size_.width);
	}

	float Window::get_angle_y(const gl::utils::Position2D& start, 
								const gl::utils::Position2D& end) const {
		return (end.y - start.y) * 360.0 / static_cast<float>(size_.height);
	}
} // namespace gl