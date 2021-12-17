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
#include "gl/utils/scene/sceneobject.h"

namespace gl::utils::scene {
	class Camera : public SceneObject {
	public:
		Camera();
		
	public:
		Position3D get_observed() const;
		void set_observed(const Position3D& value);

		Vector3D get_up() const;
		void set_up(const Vector3D& value);

	private:
		Position3D observed_;
		Vector3D up_vector_;
	};
} // namespace gl::utils::scene