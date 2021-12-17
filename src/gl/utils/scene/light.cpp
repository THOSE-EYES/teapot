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
#include "gl/utils/scene/light.h"

namespace gl::utils::scene {
	void Light::set_light_parameters(const gl::utils::LightParameters& value) {
		// FIXME : add sanity checks

		parameters_ = value;
	}

	void Light::set_constant_attenuation(const Attenuation& value) {
		if (constant_attenuation_ != value) constant_attenuation_ = value;
	}

	void Light::set_linear_attenuation(const Attenuation& value) {
		if (linear_attenuation_ != value) linear_attenuation_ = value;
	}

	void Light::set_quadratic_attenuation(const Attenuation& value) {
		if (quadratic_attenuation_ != value) quadratic_attenuation_ = value;
	}

	gl::utils::LightParameters Light::get_light_parameters() const {
		return parameters_;
	}

	Light::Attenuation Light::get_constant_attenuation() const {
		return constant_attenuation_;
	}

	Light::Attenuation Light::get_linear_attenuation() const {
		return linear_attenuation_;
	}

	Light::Attenuation Light::get_quadratic_attenuation() const {
		return quadratic_attenuation_;
	}
} // namespace gl::utils::scene