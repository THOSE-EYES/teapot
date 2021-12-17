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
#include "opengl/oglwindow.h"
#include "opengl/hw/oglkeyboard.h"
#include "opengl/factory/ogllightfactory.h"
#include "opengl/hw/oglmouse.h"
#include "opengl/shapes/teapot.h"

class Application final {
public:
	void init();

protected:
	// FIXME : 	This methods should not use hardcoded data, but get data from
	// 			factories
	std::shared_ptr<gl::Window> create_window() const;
	std::shared_ptr<gl::shapes::Shape<gl::primitives::Point3D>> get_shape() const;

	std::shared_ptr<gl::utils::scene::Camera> create_camera(
		const std::shared_ptr<gl::Window>& window) const;
	std::deque<std::shared_ptr<gl::utils::scene::Light>> get_lights() const;
	gl::utils::LightParameters get_light_parameters() const;
	std::shared_ptr<gl::materials::Material> get_material() const;

private:
	static const std::deque<gl::utils::ColorRGB> light_colors;

	// FIXME : there should be parameters instead of constants

private:
	std::shared_ptr<gl::Window> window_;
	std::shared_ptr<hw::Mouse> mouse_;
	std::shared_ptr<hw::Keyboard> keyboard_;
};