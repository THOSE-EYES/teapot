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

// Include project headers
#include "opengl/shapes/teapot.h"

namespace opengl::shapes {
	Teapot::Teapot(uint16_t size) :
		Shape<gl::primitives::Point3D>(), size_{size} {

	}
	
	void Teapot::draw() const {
		// Setting the material if it is present
		const auto material = get_material();
		if (material) material->set();

		// Let the teapot be white for simplicity
		glColor3f(1.0f, 1.0f, 1.0f);

		// Draw a teapot based on the given mode
		switch (get_mode()) {
			case Mode::LINES:
				glutWireTeapot(size_);
				break;
			case Mode::TRIANGLES:
				glutSolidTeapot(size_);
				break;
		}
	}
} // namespace opengl::shapes