#pragma once
#include "imports.hpp"
#include "memory/memory.hpp"
#include "ragemp/ragemp_shift.hpp"
#include "gta/natives/database.hpp"
#include <utils.hpp>

namespace functions {
	using namespace native;
	inline Vector3 get_cam_directions() {

		const double PI = 3.141592653589793238463;

		float heading = cam::get_gameplay_cam_relative_heading() + entity::get_entity_heading(player::player_ped_id());
		float pitch = cam::get_gameplay_cam_relative_pitch();

		float x = -sin(heading * PI / 180.0f);
		float y = cos(heading * PI / 180.0f);
		float z = sin(pitch * PI / 180.0f);

		double len = sqrt(x * x + y * y + z * z);
		if (len != 0) {
			x = x / len;
			y = y / len;
			z = z / len;
		}

		return Vector3(x, y, z);
	}

	inline RaycastResult raycast_get_cam(float distance) {

		auto cameraRotation = cam::get_gameplay_cam_rot(2);
		auto cameraCoord = cam::get_gameplay_cam_coord();

		auto direction = functions::get_cam_directions();
		Vector3 destination = Vector3(
			cameraCoord.x + direction.x * distance,
			cameraCoord.y + direction.y * distance,
			cameraCoord.z + direction.z * distance
		);

		RaycastResult result;
		worldprobe::get_shape_test_result(worldprobe::_start_shape_test_ray(cameraCoord.x, cameraCoord.y, cameraCoord.z, destination.x, destination.y, destination.z, -1, -1, 1), (bool*)&result.DidHitAnything, &result.HitCoords, &result.HitNormal, &result.HitEntity);

		return result;
	}

	inline type::entity get_entity_by_raycast() {
		auto raycast = functions::raycast_get_cam(1000);
		if (raycast.DidHitAnything)
			return raycast.HitEntity;
	}

	inline bool world_to_screen(Vector3 pos, ImVec2* out) {
		Vector3	tmp;

		tmp.x = (Memory::Instance().ptr_gta_viewport->fViewMatrix[1] * pos.x) + (Memory::Instance().ptr_gta_viewport->fViewMatrix[5] * pos.y) + (Memory::Instance().ptr_gta_viewport->fViewMatrix[9] * pos.z) + Memory::Instance().ptr_gta_viewport->fViewMatrix[13];
		tmp.y = (Memory::Instance().ptr_gta_viewport->fViewMatrix[2] * pos.x) + (Memory::Instance().ptr_gta_viewport->fViewMatrix[6] * pos.y) + (Memory::Instance().ptr_gta_viewport->fViewMatrix[10] * pos.z) + Memory::Instance().ptr_gta_viewport->fViewMatrix[14];
		tmp.z = (Memory::Instance().ptr_gta_viewport->fViewMatrix[3] * pos.x) + (Memory::Instance().ptr_gta_viewport->fViewMatrix[7] * pos.y) + (Memory::Instance().ptr_gta_viewport->fViewMatrix[11] * pos.z) + Memory::Instance().ptr_gta_viewport->fViewMatrix[15];

		if (tmp.z < 0.001f)
			return false;

		tmp.z = 1.0f / tmp.z;

		tmp.x *= tmp.z;
		tmp.y *= tmp.z;

		int w = ImGui::GetIO().DisplaySize.x;
		int h = ImGui::GetIO().DisplaySize.y;

		out->x = ((w / 2.f) + (.5f * tmp.x * w + 1.f));
		out->y = ((h / 2.f) - (.5f * tmp.y * h + 1.f));

		return true;
	}

	inline Vector2 world_to_screen_vec(Vector3 vWorldPos)
	{
		Vector2 pos = Vector2{ 0, 0 };
		if (Memory::Instance().ptr_gta_world_to_screen)
		{
			if (Memory::Instance().ptr_gta_world_to_screen(&vWorldPos, &pos.x, &pos.y))
			{
				pos.x = pos.x * ImGui::GetIO().DisplaySize.x;
				pos.y = pos.y * ImGui::GetIO().DisplaySize.y;
				return pos;
			}
		}
		return Vector2{ 0, 0 };
	}

	inline CObject* get_local() {
		CWorld* world = Memory::Instance().ptr_gta_world_factory->world;
		return world->getLocalPlayer();
	}

	inline CPlayerAngles* get_camera() {
		uintptr_t camAddress = Memory::Instance().ptr_gta_camera;
		if (camAddress)
			return *(CPlayerAngles**)(camAddress + 0x0);

		return 0;
	}

	inline Vector3 get_bone_position(CObject* ped, int32_t bone)
	{
		__m128 result;
		reinterpret_cast<void* (__fastcall*)(CObject*, __m128*, int32_t)>(Memory::Instance().ptr_gta_get_bone_position)(ped, &result, bone);

		return Vector3::FromM128(result);
	}

	inline float get_distance(Vector3 to, Vector3 from) {
		return (sqrt(
			((to.x - from.x) * (to.x - from.x)) +
			((to.y - from.y) * (to.y - from.y)) +
			((to.z - from.z) * (to.z - from.z))
		));
	}

	inline float screen_distance(float Xx, float Yy, float xX, float yY)
	{
		return sqrt((yY - Yy) * (yY - Yy) + (xX - Xx) * (xX - Xx));
	}

	inline std::string get_name_from_index(WORD i)
	{
		if (i < std::size(ragemp::ragemp_player_shift)) {
			auto id = ~__ROR2__(i + ((0x0 - 0x198) & 0x3FF), 8);
			std::string result = *reinterpret_cast<std::string*>(Memory::Instance().ptr_rage037_get_rage_name(Memory::Instance().ptr_rage037_get_name_verify(), ragemp::ragemp_player_shift[(WORD)id]));
			return result.c_str();
		}

		return "Not found";
	}
}