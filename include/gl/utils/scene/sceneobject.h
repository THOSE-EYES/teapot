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
#include <stdint.h>

 // Include project headers
#include "gl/utils/transformation.h"

namespace gl::utils::scene {
	class SceneObject {
	public:
		virtual void enable();
		virtual void disable();
		bool get_enabled() const;

		void set_rotation(const Rotation& value);
		Rotation get_rotation() const;

		Position3D get_position() const;

		void set_distance(const int32_t& value);
		uint32_t get_distance() const;

		virtual void update() = 0;

		// FIXME : implement later
		//virtual void reset() = 0;

	protected:
		virtual Position3D calculate_position(const Rotation& rotation,
												const int32_t& distance) const;

	private:
		Rotation rotation_{ .0f, .0f, .0f };
		int32_t distance_{ 0 };

		bool enabled_{false};
	};
} // namespace gl::utils:scene