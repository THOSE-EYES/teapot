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
#include "gl/utils/color.h"

namespace gl::utils {
	class LightParameters {
	public:
		using Intensity = float;

	public:
		void set_ambient_intensity(const Intensity& value);
		Intensity get_ambient_intensity() const;

		void set_diffuse_intensity(const Intensity& value);
		Intensity get_diffuse_intensity() const;

		void set_specular_intensity(const Intensity& value);
		Intensity get_specular_intensity() const;

		void set_color(const ColorRGB& value);
		ColorRGB get_color() const;

	private:
		Intensity ambient_intensity_;
		Intensity diffuse_intensity_;
		Intensity specular_intensity_;

		ColorRGB color_ {.0f, .0f, .0f};
	};
} // namespace gl::utils