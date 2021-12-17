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

// 
#include "opengl/factory/ogllightfactory.h"

namespace opengl::factory {
	const uint8_t OGLLightFactory::max_index_{7};

	std::map<uint8_t, std::shared_ptr<OGLLightFactory::LightType>> 
	OGLLightFactory::lights_;

	std::shared_ptr<OGLLightFactory::LightType> 
	OGLLightFactory::get_light(const uint8_t& index) {
		// Sanity check
		if (index > max_index_) return {};

		// If the light does not exist. create one
		if (lights_.count(index) == 0) 
			lights_[index] = LightType::create(index);

		return lights_.at(index);
	}
} // opengl::factory