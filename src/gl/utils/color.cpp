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
	ColorRGB::ColorRGB(float red, float green, float blue) :
		red_{ red },
		green_{ green },
		blue_{ blue } {

	}

	float ColorRGB::get_red() const {
		return red_;
	}

	float ColorRGB::get_green() const {
		return green_;
	}

	float ColorRGB::get_blue() const {
		return blue_;
	}

	ColorRGB ColorRGB::random() {
		// Define randomizing lambda to get the values
		const auto random_float = [](float min, float max, int32_t precision) -> float {
			// Don't try to do anything if the values are the same
			if (min == max) return max;

			float factor = pow(10, precision);
			return (rand() % (int32_t)(max * factor)) / factor;
		};

		return { random_float(0.0, 1.0, 2),
				random_float(0.0, 1.0, 2) ,
				random_float(0.0, 1.0, 2) };
	}

	bool ColorRGB::operator==(const ColorRGB& rhs) const {
		return red_ == rhs.red_ && green_ == rhs.green_ && blue_ == rhs.blue_;
	}

	bool ColorRGB::operator!=(const ColorRGB& rhs) const {
		return !operator==(rhs);
	}
} // namespace gl::utils