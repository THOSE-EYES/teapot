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
#include "gl/shapes/shape.h"
#include "gl/primitives/points.h"

namespace gl::shapes {
	class Teapot : public Shape<gl::primitives::Point3D> {
	public:
		explicit Teapot(GLushort size);

	public:
		void draw() const override;

	public:
		void set_points(std::shared_ptr<Points> value) = delete;
		std::shared_ptr<Points> get_points() const = delete;

	private:
		GLushort size_;
	};
} // namespace gl::shapes