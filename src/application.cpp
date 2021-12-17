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
#include "application.h"
#include "opengl/materials/oglmaterial.h"

const std::deque<gl::utils::ColorRGB> Application::light_colors = {
	{1.0f, .0f, .0f},
	{.0f, .0f, 1.0f}
};

void Application::init() {
	// Initialize the window
	window_ = create_window();
	window_->init();

	// Create the one camera
	create_camera(window_);
	
	// Initialize the keyboard
	keyboard_ = opengl::hw::OGLKeyboard::get();
	keyboard_->init();

	// Initialize the mouse
	mouse_ = opengl::hw::OGLMouse::get();
	mouse_->init();

	// Add the lights to the window
	const auto lights = get_lights();
	for (const auto& source : lights) {
		// Enable every source
		source->enable();

		// Add the sources to the window
		window_->add_light(source);
	}

	// Construct the shape to show
	const auto shape = get_shape();
	window_->add_shape(shape);
}

std::shared_ptr<gl::Window> Application::create_window() const {
	// Create the window
	auto window = opengl::OGLWindow::get();

	return window;
}

std::shared_ptr<gl::utils::scene::Camera> 
Application::create_camera(const std::shared_ptr<gl::Window>& window) const {
	// Set up the camera
	auto camera = window->get_camera();
	camera->set_distance(10);
	camera->set_up({.0f, 1.0f, 0.0f});
	camera->set_rotation({0.0, 0.0, 90.0});

	return camera;
}

std::deque<std::shared_ptr<gl::utils::scene::Light>> Application::get_lights() const {
	std::deque<std::shared_ptr<gl::utils::scene::Light>> lights;

	uint8_t index{0};
	for (const auto& color : light_colors) {
		auto source = opengl::factory::OGLLightFactory::get_light(index++);
		if (!source) break;

		// Set the color of the light
		auto parameters = get_light_parameters();
		parameters.set_color(color);

		// Add some settings to the source
		source->set_light_parameters(parameters);
		source->set_constant_attenuation(1.0f);
		source->set_linear_attenuation(0.05f);
		source->set_quadratic_attenuation(0.001f);
		source->set_distance(8);

		// Add the new source to the container
		lights.push_back(source);
	}

	return lights;
}

std::shared_ptr<gl::shapes::Shape<gl::primitives::Point3D>> Application::get_shape() const {
	// Add a teapot to display
	auto shape = std::make_shared<opengl::shapes::Teapot>(3);
	shape->set_mode(opengl::shapes::Teapot::Mode::TRIANGLES);
	shape->set_material(get_material());
	
	return shape;
}

gl::utils::LightParameters Application::get_light_parameters() const {
	gl::utils::LightParameters parameters;
	parameters.set_ambient_intensity(0.8);
	parameters.set_diffuse_intensity(0.1);
	parameters.set_specular_intensity(1.0);

	return parameters;
}

std::shared_ptr<gl::materials::Material> Application::get_material() const {
	auto material = std::make_shared<opengl::materials::OGLMaterial>();
	material->set_shininess(20);

	// Set the color of the light
	auto parameters = get_light_parameters();
	parameters.set_color({1.0, 1.0, 1.0});
	material->set_light_parameters(parameters);

	return material;
}