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
#include <array>

 // Include project headers
#include "gl/utils/scene/sceneobject.h"
#include "gl/utils/lightparameters.h"

namespace gl::utils::scene {
	class Light : public SceneObject {
	public:
		using Attenuation = float;

	public:
		void set_light_parameters(const gl::utils::LightParameters& value);
		gl::utils::LightParameters get_light_parameters() const;

		void set_constant_attenuation(const Attenuation& value);
		Attenuation get_constant_attenuation() const;

		void set_linear_attenuation(const Attenuation& value);
		Attenuation get_linear_attenuation() const;

		void set_quadratic_attenuation(const Attenuation& value);
		Attenuation get_quadratic_attenuation() const;

	private:
		gl::utils::LightParameters parameters_;

		Attenuation constant_attenuation_;
		Attenuation linear_attenuation_;
		Attenuation quadratic_attenuation_;


	};
} // namespace gl::utils::scene