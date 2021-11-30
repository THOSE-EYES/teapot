# Licensed to the Apache Software Foundation (ASF) under one
# or more contributor license agreements.  See the NOTICE file
# distributed with this work for additional information
# regarding copyright ownership.  The ASF licenses this file
# to you under the Apache License, Version 2.0 (the
# "License"); you may not use this file except in compliance
# with the License.  You may obtain a copy of the License at
# 
#  http://www.apache.org/licenses/LICENSE-2.0
# 
# Unless required by applicable law or agreed to in writing,
# software distributed under the License is distributed on an
# "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
# KIND, either express or implied.  See the License for the
# specific language governing permissions and limitations
# under the License.

cmake_minimum_required(VERSION 3.9)
project(teapot VERSION 0.0.1 DESCRIPTION "3D OpenGL Teapot")

# Find source files
file(GLOB SOURCES "src/*.cpp" "src/*/*.cpp" "src/*/*/*.cpp")

# Command to compile the whole project
add_executable(${PROJECT_NAME} ${SOURCES})

# Setting the compiler
if (UNIX)
	set(CMAKE_CXX_COMPILER "g++")
	set(CXXFLAGS "-O2")
endif (UNIX)

# Find include directory
include_directories(include)

# Link libraries to the executable
if (UNIX)
	target_link_libraries(${PROJECT_NAME} -lglut -lGLU -lGL -lm)
endif (UNIX)

# Windows linking
if (WIN32)
	# Include OpenGL and GLUT
	find_package(OpenGL REQUIRED)
	find_package(GLUT REQUIRED)
	include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )

	# Link libraries to the executable
	target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )
endif (WIN32)