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
#include "gl/materials/material.h"

namespace gl::materials {
	void Material::set_light_parameters(const gl::utils::LightParameters& value) {
		// FIXME : add sanity checks

		parameters_ = value;
	}

	gl::utils::LightParameters Material::get_light_parameters() const {
		return parameters_;
	}

	void Material::set_shininess(const float& value) {
		if (shininess_!= value) shininess_ = value;
	}

	float Material::get_shininess() const {
		return shininess_;
	}
} // namespace gl::materials