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
#include "gl/utils/transformation.h"

namespace gl::utils {
bool Rotation::operator==(const Rotation &rhs) const {
  return roll == rhs.roll && pitch == rhs.pitch && yaw == rhs.yaw;
}

bool Rotation::operator!=(const Rotation &rhs) const {
  return !operator==(rhs);
}

bool Position2D::operator==(const Position2D &rhs) const {
  return x == rhs.x && y == rhs.y;
}

bool Position2D::operator!=(const Position2D &rhs) const {
  return !operator==(rhs);
}

bool Position3D::operator==(const Position3D &rhs) const {
  return Position2D::operator==(rhs) && z == rhs.z;
}

bool Position3D::operator!=(const Position3D &rhs) const {
  return !operator==(rhs);
}

Vector2D::Vector2D(float x_, float y_) : x{x_}, y{y_} {}

Vector2D Vector2D::normalize() const {
  // TODO
}

bool Vector2D::normalized() const {
  return x >= 0 && y >= 0 && x <= 1 && y <= 1;
}

Vector3D::Vector3D(float x_, float y_, float z_) : Vector2D(x_, y_), z{z_} {}

Vector3D Vector3D::normalize() const {
  // TODO
}

bool Vector3D::normalized() const {
  return Vector2D::normalized() && z >= 0 && z <= 1;
}

bool Vector2D::operator==(const Vector2D &rhs) const {
  return x == rhs.x && y == rhs.y;
}

bool Vector2D::operator!=(const Vector2D &rhs) const {
  return !operator==(rhs);
}

bool Vector3D::operator==(const Vector3D &rhs) const {
  return Vector2D::operator==(rhs) && z == rhs.z;
}

bool Vector3D::operator!=(const Vector3D &rhs) const {
  return !operator==(rhs);
}
} // namespace gl::utils