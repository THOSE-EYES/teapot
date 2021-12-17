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
#include "gl/utils/color.h"

namespace gl::primitives {
	// FIXME : should be a class
	struct Point {
	public:
		virtual void draw() const  = 0;
	
	public:	
		gl::utils::ColorRGB color;
	};

	// FIXME : should be a class
	struct Point2D : public Point {
	public:
		Point2D() = default;
		Point2D(float x, float y);

	public:
		float x, y;
	};

	// FIXME : should be a class
	struct Point3D : public Point2D {
	public:
		Point3D() = default;
		Point3D(float x, float y, float z);

	public:
		float z;
	};
}