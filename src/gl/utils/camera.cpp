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
#include "gl/utils/camera.h"

namespace gl::utils {
	Camera* Camera::instance_;

	Camera* Camera::get() {
		// If there is no window instance create it
		if (!instance_) instance_ = new Camera();

		return instance_;
	}

	void Camera::set_rotation(const utils::Rotation& value) {
		if (rotation_ != value) {
			rotation_ = value;
		}
	}

	utils::Rotation Camera::get_rotation() const {
		return rotation_;
	}

	utils::Position3D Camera::get_position() const {
		return calculate_position(rotation_, distance_);
	}

	utils::Position3D Camera::calculate_position(const utils::Rotation& rotation, 
													const GLuint& distance) const {
		utils::Position3D position;
		position.x = distance * cos(rotation.pitch) * cos(rotation.yaw);
		position.y = distance * sin(rotation.yaw);
		position.z = distance * cos(rotation.pitch) * sin(rotation.yaw);

		return position;
	}

	void Camera::set_distance(const GLuint& value) {
		if (distance_ != value) {
			distance_ = value;
		}
	}

	GLuint Camera::get_distance() const {
		return distance_;
	}
} // namespace gl::utils