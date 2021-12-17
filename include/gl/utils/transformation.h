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

namespace gl::utils {
	struct Rotation {
	public:
		float roll;
		float pitch;
		float yaw;

	public:
		bool operator==(const Rotation& rhs) const;
		bool operator!=(const Rotation& rhs) const;
	}; 

	struct Position2D {
	public:
		float x;
		float y;

	public:
		bool operator==(const Position2D& rhs) const;
		bool operator!=(const Position2D& rhs) const;
	};

	struct Position3D : public Position2D {
		float z;

	public:
		bool operator==(const Position3D& rhs) const;
		bool operator!=(const Position3D& rhs) const;
	};

	struct Vector2D {
	public:
		Vector2D() = default;
		Vector2D(float x_, float y_);

	public:
		float x;
		float y;

	public:
		Vector2D normalize() const;
		virtual bool normalized() const;

		bool operator==(const Vector2D& rhs) const;
		bool operator!=(const Vector2D& rhs) const;
	};

	struct Vector3D : public Vector2D {
	public:
		Vector3D() = default;
		Vector3D(float x_, float y_, float z_);

	public:
		float z;

	public:
		Vector3D normalize() const;
		bool normalized() const override;

		bool operator==(const Vector3D& rhs) const;
		bool operator!=(const Vector3D& rhs) const;
	};
} // namespace gl::utils