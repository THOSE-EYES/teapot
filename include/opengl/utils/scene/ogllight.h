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

 // Make Windows happy
#ifdef _WIN32
#define _USE_MATH_DEFINES
#define NOMINMAX
#include <Windows.h>
#endif

// Include C++ stuff
#include <deque>
#include <memory>

// Include OpenGL code
#include <GL/gl.h>
#include <GL/glut.h>

// Include project headers
#include "gl/utils/scene/light.h"

// Use this to speed up compilation and to not include files
namespace opengl::factory {
	class OGLLightFactory;
}

namespace opengl::utils::scene {
	class OGLLight : public gl::utils::scene::Light {
	public:
		void enable() override;
		void disable() override;

		void update() override;

		friend class opengl::factory::OGLLightFactory;

	protected:
		static std::shared_ptr<OGLLight> create(const uint8_t& index);

		uint8_t get_index() const;

	private:
		OGLLight() = default;

	private:
		uint8_t index_;
	};
} // namespace opengl::utils::scene