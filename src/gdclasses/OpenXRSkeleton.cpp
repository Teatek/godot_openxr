/////////////////////////////////////////////////////////////////////////////////////
// Our OpenXR hand GDNative object implemented through skeleton (bones)

#include <ARVRServer.hpp>

#include "gdclasses/OpenXRSkeleton.h"

using namespace godot;

void OpenXRSkeleton::_register_methods() {
	register_method("_ready", &OpenXRSkeleton::_ready);
	register_method("_physics_process", &OpenXRSkeleton::_physics_process);

	register_method("get_hand", &OpenXRSkeleton::get_hand);
	register_method("set_hand", &OpenXRSkeleton::set_hand);
	register_property<OpenXRSkeleton, int>("hand", &OpenXRSkeleton::set_hand, &OpenXRSkeleton::get_hand, 0, GODOT_METHOD_RPC_MODE_DISABLED, GODOT_PROPERTY_USAGE_DEFAULT, GODOT_PROPERTY_HINT_ENUM, "Left,Right");

	register_method("get_motion_range", &OpenXRSkeleton::get_motion_range);
	register_method("set_motion_range", &OpenXRSkeleton::set_motion_range);
	register_property<OpenXRSkeleton, int>("motion_range", &OpenXRSkeleton::set_motion_range, &OpenXRSkeleton::get_motion_range, 0, GODOT_METHOD_RPC_MODE_DISABLED, GODOT_PROPERTY_USAGE_DEFAULT, GODOT_PROPERTY_HINT_ENUM, "Unobstructed,Conform to controller");

	register_method("get_movement_thumb", &OpenXRSkeleton::get_movement_thumb);
	register_method("set_movement_thumb", &OpenXRSkeleton::set_movement_thumb);
	register_property<OpenXRSkeleton, int>("movement_thumb", &OpenXRSkeleton::set_movement_thumb, &OpenXRSkeleton::get_movement_thumb, 0, GODOT_METHOD_RPC_MODE_DISABLED, GODOT_PROPERTY_USAGE_DEFAULT, GODOT_PROPERTY_HINT_ENUM, "Free,Static,Extend,Contract");

	register_method("get_movement_index", &OpenXRSkeleton::get_movement_index);
	register_method("set_movement_index", &OpenXRSkeleton::set_movement_index);
	register_property<OpenXRSkeleton, int>("movement_index", &OpenXRSkeleton::set_movement_index, &OpenXRSkeleton::get_movement_index, 0, GODOT_METHOD_RPC_MODE_DISABLED, GODOT_PROPERTY_USAGE_DEFAULT, GODOT_PROPERTY_HINT_ENUM, "Free,Static,Extend,Contract");

	register_method("get_movement_middle", &OpenXRSkeleton::get_movement_middle);
	register_method("set_movement_middle", &OpenXRSkeleton::set_movement_middle);
	register_property<OpenXRSkeleton, int>("movement_middle", &OpenXRSkeleton::set_movement_middle, &OpenXRSkeleton::get_movement_middle, 0, GODOT_METHOD_RPC_MODE_DISABLED, GODOT_PROPERTY_USAGE_DEFAULT, GODOT_PROPERTY_HINT_ENUM, "Free,Static,Extend,Contract");

	register_method("get_movement_ring", &OpenXRSkeleton::get_movement_ring);
	register_method("set_movement_ring", &OpenXRSkeleton::set_movement_ring);
	register_property<OpenXRSkeleton, int>("movement_ring", &OpenXRSkeleton::set_movement_ring, &OpenXRSkeleton::get_movement_ring, 0, GODOT_METHOD_RPC_MODE_DISABLED, GODOT_PROPERTY_USAGE_DEFAULT, GODOT_PROPERTY_HINT_ENUM, "Free,Static,Extend,Contract");

	register_method("get_movement_little", &OpenXRSkeleton::get_movement_little);
	register_method("set_movement_little", &OpenXRSkeleton::set_movement_little);
	register_property<OpenXRSkeleton, int>("movement_little", &OpenXRSkeleton::set_movement_little, &OpenXRSkeleton::get_movement_little, 0, GODOT_METHOD_RPC_MODE_DISABLED, GODOT_PROPERTY_USAGE_DEFAULT, GODOT_PROPERTY_HINT_ENUM, "Free,Static,Extend,Contract");

	register_method("get_hand_pose", &OpenXRSkeleton::get_hand_pose);
	register_method("set_hand_pose", &OpenXRSkeleton::set_hand_pose);
	register_property<OpenXRSkeleton, Array>("hand_pose", &OpenXRSkeleton::set_hand_pose, &OpenXRSkeleton::get_hand_pose, OpenXRSkeleton::get_default_pose(), GODOT_METHOD_RPC_MODE_DISABLED, GODOT_PROPERTY_USAGE_DEFAULT, GODOT_PROPERTY_HINT_NONE);
}

OpenXRSkeleton::OpenXRSkeleton() {
	hand = 0;
	motion_range = 0;
	movement_thumb = 0;
	movement_index = 0;
	movement_middle = 0;
	movement_ring = 0;
	movement_little = 0;
	openxr_api = OpenXRApi::openxr_get_api();
	hand_tracking_wrapper = XRExtHandTrackingExtensionWrapper::get_singleton();

	for (int i = 0; i < XR_HAND_JOINT_COUNT_EXT; i++) {
		bones[i] = -1;
	}
	hand_pose = get_default_pose();
}

OpenXRSkeleton::~OpenXRSkeleton() {
	if (openxr_api != NULL) {
		OpenXRApi::openxr_release_api();
	}

	hand_tracking_wrapper = nullptr;
}

void OpenXRSkeleton::_init() {
	// nothing to do here
}

Array OpenXRSkeleton::get_default_pose() {
	return Array();
}

void OpenXRSkeleton::_ready() {
	const char *bone_names[XR_HAND_JOINT_COUNT_EXT] = {
		"Palm",
		"Wrist",
		"Thumb_Metacarpal",
		"Thumb_Proximal",
		"Thumb_Distal",
		"Thumb_Tip",
		"Index_Metacarpal",
		"Index_Proximal",
		"Index_Intermediate",
		"Index_Distal",
		"Index_Tip",
		"Middle_Metacarpal",
		"Middle_Proximal",
		"Middle_Intermediate",
		"Middle_Distal",
		"Middle_Tip",
		"Ring_Metacarpal",
		"Ring_Proximal",
		"Ring_Intermediate",
		"Ring_Distal",
		"Ring_Tip",
		"Little_Metacarpal",
		"Little_Proximal",
		"Little_Intermediate",
		"Little_Distal",
		"Little_Tip",
	};

	// We cast to spatials which should allow us to use any subclass of that.
	for (int i = 0; i < XR_HAND_JOINT_COUNT_EXT; i++) {
		char bone_name[250];
		if (hand == 0) {
			sprintf(bone_name, "%s_L", bone_names[i]);
		} else {
			sprintf(bone_name, "%s_R", bone_names[i]);
		}

		bones[i] = find_bone(bone_name);
		if (bones[i] == -1) {
			Godot::print("Couldn't obtain bone for {0}", bone_name);
		}
	}

	_set_motion_range();
}

void OpenXRSkeleton::_physics_process(float delta) {
	if (openxr_api == nullptr || hand_tracking_wrapper == nullptr) {
		return;
	} else if (!openxr_api->is_initialised()) {
		return;
	}

	// we cache our transforms so we can quickly calculate local transforms
	Transform transforms[XR_HAND_JOINT_COUNT_EXT];
	Transform inv_transforms[XR_HAND_JOINT_COUNT_EXT];

	const HandTracker *hand_tracker = hand_tracking_wrapper->get_hand_tracker(hand);
	const float ws = ARVRServer::get_singleton()->get_world_scale();

	if (hand_tracker->is_initialised && hand_tracker->locations.isActive) {
		// get our transforms
		for (int i = 0; i < XR_HAND_JOINT_COUNT_EXT; i++) {
			openxr_api->transform_from_location(hand_tracker->joint_locations[i], ws, transforms[i]);
			inv_transforms[i] = transforms[i].inverse();
		}

		// now update our skeleton
		for (int i = 0; i < XR_HAND_JOINT_COUNT_EXT; i++) {
			if (bones[i] != -1) {
				int bone = bones[i];
				int parent = get_bone_parent(bone);

				Transform t = transforms[i];

				// get local translation, parent should already be processed
				if (parent == -1) {
					// use our palm location here, that is what we are tracking
					t = inv_transforms[XR_HAND_JOINT_PALM_EXT] * t;
				} else {
					int found = false;
					for (int b = 0; b < XR_HAND_JOINT_COUNT_EXT && !found; b++) {
						if (bones[b] == parent) {
							t = inv_transforms[b] * t;
							found = true;
						}
					}
				}

				// get difference with rest
				Transform rest = get_bone_rest(bones[i]);
				t = rest.inverse() * t;
				int finger_numb = 0;

				if (i > 1 && i < 6)
				{
					finger_numb = movement_thumb;
				} else if (i > 5 && i < 11)
				{
					finger_numb = movement_index;
				} else if (i > 10 && i < 16)
				{
					finger_numb = movement_middle;
				} else if (i > 15 && i < 21)
				{
					finger_numb = movement_ring;
				} else if (i > 20)
				{
					finger_numb = movement_little;
				}
				int bones_size = (Array(Array((Array)hand_pose[hand])[1])).size();
				Transform hp = Transform();
				if (bones_size == 26)
				{
					hp.origin = (PoolVector3Array(Array((Array)hand_pose[hand])[0])[i]);
					hp.basis = Basis((Quat)(Array(Array((Array)hand_pose[hand])[1])[i]));
				}
				Vector3 new_pose_vect = hp.basis.get_euler();
				Quat q = Quat();
				q.set_euler(Vector3(t.basis.get_euler().x, new_pose_vect.y, new_pose_vect.z));

				switch (finger_numb) {
					case MovementType::FREE:
						set_bone_pose(bones[i], t);
						break;
					case MovementType::EXTEND:
						// min (need a reference pose)
						if (t.basis.get_euler().x <= new_pose_vect.x)
						{
							set_bone_pose(bones[i], hp);
						} else {
							hp.basis = Basis(q);
							set_bone_pose(bones[i], hp);
						}
						break;
					case MovementType::CONTRACT:
						// max (need a reference pose)
						if (t.basis.get_euler().x >= new_pose_vect.x)
						{
							set_bone_pose(bones[i], hp);
						} else {
							hp.basis = Basis(q);
							set_bone_pose(bones[i], hp);
						}
						break;
					default:
						/* static */
						set_bone_pose(bones[i], hp);
						break;
				}
			}
		}

		// show it
		set_visible(true);
	} else {
		// hide it
		set_visible(false);
	}
}

int OpenXRSkeleton::get_hand() const {
	return hand;
}

void OpenXRSkeleton::set_hand(int p_hand) {
	hand = p_hand == 1 ? 1 : 0;
}

int OpenXRSkeleton::get_motion_range() const {
	return motion_range;
}

void OpenXRSkeleton::set_motion_range(int p_motion_range) {
	motion_range = p_motion_range;
	_set_motion_range();
}

void OpenXRSkeleton::_set_motion_range() {
	if (hand_tracking_wrapper == nullptr) {
		return;
	}

	XrHandJointsMotionRangeEXT xr_motion_range;
	switch (motion_range) {
		case 0:
			xr_motion_range = XR_HAND_JOINTS_MOTION_RANGE_UNOBSTRUCTED_EXT;
			break;
		case 1:
			xr_motion_range = XR_HAND_JOINTS_MOTION_RANGE_CONFORMING_TO_CONTROLLER_EXT;
			break;
		default:
			xr_motion_range = XR_HAND_JOINTS_MOTION_RANGE_CONFORMING_TO_CONTROLLER_EXT;
			break;
	}

	hand_tracking_wrapper->set_motion_range(hand, xr_motion_range);
}

int OpenXRSkeleton::get_movement_thumb() const {
	return movement_thumb;
}

void OpenXRSkeleton::set_movement_thumb(int p_movement_thumb) {
	movement_thumb = p_movement_thumb;
}

int OpenXRSkeleton::get_movement_index() const {
	return movement_index;
}

void OpenXRSkeleton::set_movement_index(int p_movement_index) {
	movement_index = p_movement_index;
}

int OpenXRSkeleton::get_movement_middle() const {
	return movement_middle;
}

void OpenXRSkeleton::set_movement_middle(int p_movement_middle) {
	movement_middle = p_movement_middle;
}

int OpenXRSkeleton::get_movement_ring() const {
	return movement_ring;
}

void OpenXRSkeleton::set_movement_ring(int p_movement_ring) {
	movement_ring = p_movement_ring;
}

int OpenXRSkeleton::get_movement_little() const {
	return movement_little;
}

void OpenXRSkeleton::set_movement_little(int p_movement_little) {
	movement_little = p_movement_little;
}

Array OpenXRSkeleton::get_hand_pose() {
	return hand_pose;
}

void OpenXRSkeleton::set_hand_pose(Array p_hand_pose) {
	hand_pose = p_hand_pose;
}
