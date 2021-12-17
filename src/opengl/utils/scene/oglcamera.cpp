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
#include "opengl/utils/scene/oglcamera.h"

namespace opengl::utils::scene {
	std::shared_ptr<OGLCamera> OGLCamera::instance_;

	std::shared_ptr<OGLCamera> OGLCamera::get() {
		// If there is no instance create it
		if (!instance_) instance_.reset(new OGLCamera());

		return instance_;
	}

	void OGLCamera::update() {
		const auto position{ get_position() };
		const auto point{ get_observed() };
		const auto up_vector{ get_up() };

		// Update camera's position
		gluLookAt(position.x, position.y, position.z,
			point.x, point.y, point.z,
			up_vector.x, up_vector.y, up_vector.z);
	}
} // namespace gl::utils::scene