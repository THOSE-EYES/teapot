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
#include "gl/utils/color.h"

namespace gl::utils {
	ColorRGB::ColorRGB(GLfloat red, GLfloat green, GLfloat blue) :
		red_{ red },
		green_{ green },
		blue_{ blue } {

	}

	GLfloat ColorRGB::get_red() const {
		return red_;
	}

	GLfloat ColorRGB::get_green() const {
		return green_;
	}

	GLfloat ColorRGB::get_blue() const {
		return blue_;
	}

	ColorRGB ColorRGB::random() {
		// Define randomizing lambda to get the values
		const auto random_float = [](GLfloat min, GLfloat max, GLint precision) -> GLfloat {
			// Don't try to do anything if the values are the same
			if (min == max) return max;

			GLfloat factor = pow(10, precision);
			return (rand() % (GLint)(max * factor)) / factor;
		};

		return { random_float(0.0, 1.0, 2),
				random_float(0.0, 1.0, 2) ,
				random_float(0.0, 1.0, 2) };
	}
} // namespace gl::utils