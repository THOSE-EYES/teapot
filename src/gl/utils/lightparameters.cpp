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
#include "gl/utils/lightparameters.h"

namespace gl::utils {
	void LightParameters::set_ambient_intensity(const Intensity& value) {
		if (ambient_intensity_ != value) ambient_intensity_ = value;
	}

	void LightParameters::set_diffuse_intensity(const Intensity& value) {
		if (diffuse_intensity_ != value) diffuse_intensity_ = value;
	}

	void LightParameters::set_specular_intensity(const Intensity& value) {
		if (specular_intensity_ != value) specular_intensity_ = value;
	}

	void LightParameters::set_color(const ColorRGB& value) {
		if (color_ != value) color_ = value;
	}

	LightParameters::Intensity LightParameters::get_ambient_intensity() const {
		return ambient_intensity_;
	}

	LightParameters::Intensity LightParameters::get_diffuse_intensity() const {
		return diffuse_intensity_;
	}

	LightParameters::Intensity LightParameters::get_specular_intensity() const {
		return specular_intensity_;
	}

	ColorRGB LightParameters::get_color() const {
		return color_;
	}
} // namespace gl::materials