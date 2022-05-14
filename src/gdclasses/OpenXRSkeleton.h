/////////////////////////////////////////////////////////////////////////////////////
// Our OpenXR hand GDNative object implemented through skeleton (bones)

#ifndef OPENXR_SKELETON_H
#define OPENXR_SKELETON_H

#include "openxr/OpenXRApi.h"
#include "openxr/extensions/xr_ext_hand_tracking_extension_wrapper.h"
#include "OpenXRHandPose.h"
#include <Ref.hpp>
#include <Skeleton.hpp>
#include <iostream>
#include <string>
#include <Dictionary.hpp>

namespace godot {
class OpenXRSkeleton : public Skeleton {
	GODOT_CLASS(OpenXRSkeleton, Skeleton)

private:
	OpenXRApi *openxr_api;
	XRExtHandTrackingExtensionWrapper *hand_tracking_wrapper = nullptr;
	int hand;
	int motion_range;
	int movement_thumb;
	int movement_index;
	int movement_middle;
	int movement_ring;
	int movement_little;
	Dictionary hand_pose;
	enum MovementType {
		FREE,
		STATIC,
		EXTEND,
		CONTRACT
	};

	int64_t bones[XR_HAND_JOINT_COUNT_EXT];
	void _set_motion_range();
	void finger_movements(int b, int f, Transform t);

public:
	static void _register_methods();

	void _init();
	void _ready();
	void _physics_process(float delta);

	OpenXRSkeleton();
	~OpenXRSkeleton();

	int get_hand() const;
	void set_hand(int p_hand);

	int get_motion_range() const;
	void set_motion_range(int p_motion_range);

	int get_movement_thumb() const;
	void set_movement_thumb(int p_movement_thumb);

	int get_movement_index() const;
	void set_movement_index(int p_movement_index);

	int get_movement_middle() const;
	void set_movement_middle(int p_movement_middle);

	int get_movement_ring() const;
	void set_movement_ring(int p_movement_ring);

	int get_movement_little() const;
	void set_movement_little(int p_movement_little);

	Dictionary get_hand_pose();
	void set_hand_pose(Dictionary p_hand_pose);
};
} // namespace godot

#endif // !OPENXR_SKELETON_H
