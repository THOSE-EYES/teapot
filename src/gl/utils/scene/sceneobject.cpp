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
#include "gl/utils/scene/sceneobject.h"

namespace gl::utils::scene {
	void SceneObject::set_rotation(const Rotation& value) {
		if (rotation_ != value) rotation_ = value;
	}

	Rotation SceneObject::get_rotation() const {
		return rotation_;
	}

	Position3D SceneObject::get_position() const {
		return calculate_position(rotation_, distance_);
	}

	Position3D SceneObject::calculate_position(const Rotation& rotation,
												const int32_t& distance) const {
		Position3D position;
		position.x = distance * cos(rotation.pitch) * cos(rotation.yaw);
		position.y = distance * sin(rotation.yaw);
		position.z = distance * cos(rotation.pitch) * sin(rotation.yaw);

		return position;
	}

	void SceneObject::set_distance(const int32_t& value) {
		if (distance_ != value) distance_ = value;
	}

	uint32_t SceneObject::get_distance() const {
		return distance_;
	}

	void SceneObject::enable() {
		enabled_ = true;
	}

	void SceneObject::disable() {
		enabled_ = false;
	}

	bool SceneObject::get_enabled() const {
		return enabled_;
	}
} // namespace gl::utils:scene