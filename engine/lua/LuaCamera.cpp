/*
Copyright (c) 2013 Daniele Bartolini, Michele Rossi
Copyright (c) 2012 Daniele Bartolini, Simone Boscaratto

Permission is hereby granted, free of charge, to any person
obtaining a copy of this software and associated documentation
files (the "Software"), to deal in the Software without
restriction, including without limitation the rights to use,
copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following
conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.
*/

#include "Camera.h"
#include "Vec3.h"
#include "Quat.h"
#include "Mat4.h"
#include "LuaStack.h"
#include "LuaEnvironment.h"

namespace crown
{

//-----------------------------------------------------------------------------
CE_EXPORT int camera_local_position(lua_State* L)
{
	LuaStack stack(L);

	Camera* camera = stack.get_camera(1);

	stack.push_vec3(camera->local_position());
	return 1;
}

//-----------------------------------------------------------------------------
CE_EXPORT int camera_local_rotation(lua_State* L)
{
	LuaStack stack(L);

	Camera* camera = stack.get_camera(1);

	stack.push_quat(camera->local_rotation());
	return 1;
}

//-----------------------------------------------------------------------------
CE_EXPORT int camera_local_pose(lua_State* L)
{
	LuaStack stack(L);

	Camera* camera = stack.get_camera(1);

	stack.push_mat4(camera->local_pose());
	return 1;
}

//-----------------------------------------------------------------------------
CE_EXPORT int camera_world_position(lua_State* L)
{
	LuaStack stack(L);

	Camera* camera = stack.get_camera(1);

	stack.push_vec3(camera->world_position());
	return 1;
}

//-----------------------------------------------------------------------------
CE_EXPORT int camera_world_rotation(lua_State* L)
{
	LuaStack stack(L);

	Camera* camera = stack.get_camera(1);

	stack.push_quat(camera->world_rotation());
	return 1;
}

//-----------------------------------------------------------------------------
CE_EXPORT int camera_world_pose(lua_State* L)
{
	LuaStack stack(L);

	Camera* camera = stack.get_camera(1);

	stack.push_mat4(camera->world_pose());
	return 1;
}

//-----------------------------------------------------------------------------
CE_EXPORT int camera_set_local_position(lua_State* L)
{
	LuaStack stack(L);

	Camera* camera = stack.get_camera(1);
	const Vec3 pos = stack.get_vec3(2);

	camera->set_local_position(pos);
	return 0;
}

//-----------------------------------------------------------------------------
CE_EXPORT int camera_set_local_rotation(lua_State* L)
{
	LuaStack stack(L);

	Camera* camera = stack.get_camera(1);
	const Quat rot = stack.get_quat(2);

	camera->set_local_rotation(rot);
	return 0;
}

//-----------------------------------------------------------------------------
CE_EXPORT int camera_set_local_pose(lua_State* L)
{
	LuaStack stack(L);

	Camera* camera = stack.get_camera(1);
	const Mat4 pose = stack.get_mat4(2);

	camera->set_local_pose(pose);
	return 0;
}

//-----------------------------------------------------------------------------
CE_EXPORT int camera_set_projection_type(lua_State* L)
{
	LuaStack stack(L);

	Camera* camera = stack.get_camera(1);
	ProjectionType::Enum proj_type = (ProjectionType::Enum) stack.get_int(2);

	camera->set_projection_type(proj_type);
	return 0;
}

//-----------------------------------------------------------------------------
CE_EXPORT int camera_projection_type(lua_State* L)
{
	LuaStack stack(L);

	Camera* camera = stack.get_camera(1);

	stack.push_uint32(camera->projection_type());
	return 1;
}

//-----------------------------------------------------------------------------
CE_EXPORT int camera_fov(lua_State* L)
{
	LuaStack stack(L);

	Camera* camera = stack.get_camera(1);

	stack.push_float(camera->fov());
	return 1;
}

//-----------------------------------------------------------------------------
CE_EXPORT int camera_set_fov(lua_State* L)
{
	LuaStack stack(L);

	Camera* camera = stack.get_camera(1);
	const float fov = stack.get_float(2);

	camera->set_fov(fov);
	return 0;
}

//-----------------------------------------------------------------------------
CE_EXPORT int camera_aspect(lua_State* L)
{
	LuaStack stack(L);

	Camera* camera = stack.get_camera(1);

	stack.push_float(camera->aspect());
	return 1;
}

//-----------------------------------------------------------------------------
CE_EXPORT int camera_set_aspect(lua_State* L)
{
	LuaStack stack(L);

	Camera* camera = stack.get_camera(1);
	const float aspect = stack.get_float(2);

	camera->set_aspect(aspect);
	return 0;
}

//-----------------------------------------------------------------------------
CE_EXPORT int camera_near_clip_distance(lua_State* L)
{
	LuaStack stack(L);

	Camera* camera = stack.get_camera(1);

	stack.push_float(camera->near_clip_distance());
	return 1;
}

//-----------------------------------------------------------------------------
CE_EXPORT int camera_set_near_clip_distance(lua_State* L)
{
	LuaStack stack(L);

	Camera* camera = stack.get_camera(1);
	const float near = stack.get_float(2);

	camera->set_near_clip_distance(near);
	return 0;
}

//-----------------------------------------------------------------------------
CE_EXPORT int camera_far_clip_distance(lua_State* L)
{
	LuaStack stack(L);

	Camera* camera = stack.get_camera(1);

	stack.push_float(camera->far_clip_distance());
	return 1;
}

//-----------------------------------------------------------------------------
CE_EXPORT int camera_set_far_clip_distance(lua_State* L)
{
	LuaStack stack(L);

	Camera* camera = stack.get_camera(1);
	const float far = stack.get_float(2);

	camera->set_far_clip_distance(far);
	return 0;
}

//-----------------------------------------------------------------------------
void load_camera(LuaEnvironment& env)
{
	env.load_module_function("Camera", "local_position",         camera_local_position);
	env.load_module_function("Camera", "local_rotation",         camera_local_rotation);
	env.load_module_function("Camera", "local_pose",             camera_local_pose);
	env.load_module_function("Camera", "world_position",         camera_world_position);
	env.load_module_function("Camera", "world_rotation",         camera_world_rotation);
	env.load_module_function("Camera", "world_pose",             camera_world_pose);
	env.load_module_function("Camera", "set_local_position",     camera_set_local_position);
	env.load_module_function("Camera", "set_local_rotation",     camera_set_local_rotation);
	env.load_module_function("Camera", "set_local_pose",         camera_set_local_pose);
	env.load_module_function("Camera", "set_projection_type",    camera_set_projection_type);
	env.load_module_function("Camera", "projection_type",        camera_projection_type);
	env.load_module_function("Camera", "fov",                    camera_fov);
	env.load_module_function("Camera", "set_fov",                camera_set_fov);
	env.load_module_function("Camera", "aspect",                 camera_aspect);
	env.load_module_function("Camera", "set_aspect",             camera_set_aspect);
	env.load_module_function("Camera", "near_clip_distance",     camera_near_clip_distance);
	env.load_module_function("Camera", "set_near_clip_distance", camera_set_near_clip_distance);
	env.load_module_function("Camera", "far_clip_distance",      camera_far_clip_distance);
	env.load_module_function("Camera", "set_far_clip_distance",  camera_set_far_clip_distance);

	env.load_module_enum("Camera", "ORTHOGRAPHIC", ProjectionType::ORTHOGRAPHIC);
	env.load_module_enum("Camera", "PERSPECTIVE", ProjectionType::PERSPECTIVE);
}

} // namespace crown