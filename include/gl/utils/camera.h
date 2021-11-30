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

// Include project headers
#include "gl/utils/transformation.h"

namespace gl::utils {
	class Camera {
	public:
		Camera(const Camera& another) = delete;
		Camera(Camera&& another) = delete;

	public:
		static Camera* get();

		void set_rotation(const utils::Rotation& value);
		utils::Rotation get_rotation() const;

		utils::Position3D get_position() const;

		void set_distance(const GLuint& value);
		GLuint get_distance() const;

	private:
		Camera() = default;

	private:
		utils::Position3D calculate_position(
				const utils::Rotation& rotation, 
				const GLuint& distance) const;

	private:
		static Camera* instance_;

		utils::Rotation rotation_ {.0f, .0f, .0f};
		GLuint distance_{0};
	};
} // namespace gl::utils