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

// Include project headers
#include "gl/utils/transformation.h"

namespace hw {
	class Mouse {
	public:
		virtual void init() = 0;

	protected:
		struct ButtonState {
			bool pressed{false};

			gl::utils::Position2D position;
		};

		struct Motion {
			gl::utils::Position2D start;
			gl::utils::Position2D end;
		};

	protected:
		virtual void on_moved(const gl::utils::Position2D& position) = 0;
		virtual void on_left_button_clicked() = 0;
		virtual void on_right_button_clicked() = 0;
		virtual void on_wheel_clicked() = 0;

	protected:
		std::map<int, ButtonState> buttons_;
	};
} // namespace hw