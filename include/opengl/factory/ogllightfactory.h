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
#include <map>
#include <memory>

// Include project headers
#include "opengl/utils/scene/ogllight.h"

namespace opengl::factory {
	class OGLLightFactory {
		using LightType = opengl::utils::scene::OGLLight;
	public:
		virtual ~OGLLightFactory() = 0;

	public:
		static std::shared_ptr<LightType> get_light(const uint8_t& index);

	private:
		static const uint8_t max_index_;
		static std::map<uint8_t, std::shared_ptr<LightType>> lights_;
	};
} // opengl::factory