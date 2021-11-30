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
#include "gl/primitives/points.h"

namespace gl::primitives {
	Point2D::Point2D(GLfloat x_, GLfloat y_) : 
		Point(), x{x_}, y{y_} {

	}

	void Point2D::draw() const {
		glColor3f(color.get_red(), 
					color.get_green(), 
					color.get_blue());
		glVertex2f(x, y);
	}

	Point3D::Point3D(GLfloat x_, GLfloat y_, GLfloat z_) : 
		Point2D{x_, y_}, z{ z_ } {

	}

	void Point3D::draw() const {
		glColor3f(color.get_red(), 
					color.get_green(), 
					color.get_blue());
		glVertex3f(x, y, z);
	}
}