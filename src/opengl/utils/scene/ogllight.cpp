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

 // Include C++ stuff
#include <cmath>

// Include project headers
#include "opengl/utils/scene/ogllight.h"

namespace opengl::utils::scene {
	std::shared_ptr<OGLLight> OGLLight::create(const uint8_t& index) {
		auto pointer = std::shared_ptr<OGLLight>(new OGLLight());
		pointer->index_ = index;

		return pointer;
	}

	void OGLLight::update() {
		// Why to do anything if it is not enabled?
		if (!get_enabled()) return;

		const auto light_position = get_position();
		const float position[4] = { light_position.x, light_position.y, light_position.z, 1.0};
    	glLightfv(GL_LIGHT0 + index_, GL_POSITION, position);

		const auto parameters = get_light_parameters();
		const auto color = parameters.get_color();
		const float ambient[] = { color.get_red(), color.get_green(), color.get_blue(), parameters.get_ambient_intensity() };
		const float diffuse[] = { color.get_red(), color.get_green(), color.get_blue(), parameters.get_diffuse_intensity() };
		const float specular[] = { color.get_red(), color.get_green(), color.get_blue(), parameters.get_specular_intensity() };

		// Set light parameters
		glLightfv(GL_LIGHT0 + index_, GL_AMBIENT, ambient);
    	glLightfv(GL_LIGHT0 + index_, GL_DIFFUSE, diffuse);
    	glLightfv(GL_LIGHT0 + index_, GL_SPECULAR, specular);

		// Set light constants
    	glLightf(GL_LIGHT0 + index_, GL_CONSTANT_ATTENUATION, get_constant_attenuation());
    	glLightf(GL_LIGHT0 + index_, GL_LINEAR_ATTENUATION, get_linear_attenuation());
    	glLightf(GL_LIGHT0 + index_, GL_QUADRATIC_ATTENUATION, get_quadratic_attenuation());
	}

	void OGLLight::enable() {
		// Call the method from superclass
		Light::enable();

		// Enable the light in OpenGL
		glEnable(GL_LIGHT0 + index_);
	}

	void OGLLight::disable() {
		// Call the method from superclass
		Light::disable();

		// Disable the light in OpenGL
		glEnable(GL_LIGHT0 + index_);
	}
} // namespace gl::utils::scene