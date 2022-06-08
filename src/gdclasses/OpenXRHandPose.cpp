#include "OpenXRHandPose.h"
#include "gdclasses/OpenXRHandPose.h"

using namespace godot;

void OpenXRHandPose::_register_methods() {
	register_method("get_left_movement_thumb", &OpenXRHandPose::get_left_movement_thumb);
	register_method("set_left_movement_thumb", &OpenXRHandPose::set_left_movement_thumb);
	register_property<OpenXRHandPose, int>("left_movement_thumb", &OpenXRHandPose::set_left_movement_thumb, &OpenXRHandPose::get_left_movement_thumb, 1, GODOT_METHOD_RPC_MODE_DISABLED, GODOT_PROPERTY_USAGE_DEFAULT, GODOT_PROPERTY_HINT_ENUM, "Free,Static,Extend,Contract");

	register_method("get_left_movement_index", &OpenXRHandPose::get_left_movement_index);
	register_method("set_left_movement_index", &OpenXRHandPose::set_left_movement_index);
	register_property<OpenXRHandPose, int>("left_movement_index", &OpenXRHandPose::set_left_movement_index, &OpenXRHandPose::get_left_movement_index, 1, GODOT_METHOD_RPC_MODE_DISABLED, GODOT_PROPERTY_USAGE_DEFAULT, GODOT_PROPERTY_HINT_ENUM, "Free,Static,Extend,Contract");

	register_method("get_left_movement_middle", &OpenXRHandPose::get_left_movement_middle);
	register_method("set_left_movement_middle", &OpenXRHandPose::set_left_movement_middle);
	register_property<OpenXRHandPose, int>("left_movement_middle", &OpenXRHandPose::set_left_movement_middle, &OpenXRHandPose::get_left_movement_middle, 1, GODOT_METHOD_RPC_MODE_DISABLED, GODOT_PROPERTY_USAGE_DEFAULT, GODOT_PROPERTY_HINT_ENUM, "Free,Static,Extend,Contract");

	register_method("get_left_movement_ring", &OpenXRHandPose::get_left_movement_ring);
	register_method("set_left_movement_ring", &OpenXRHandPose::set_left_movement_ring);
	register_property<OpenXRHandPose, int>("left_movement_ring", &OpenXRHandPose::set_left_movement_ring, &OpenXRHandPose::get_left_movement_ring, 1, GODOT_METHOD_RPC_MODE_DISABLED, GODOT_PROPERTY_USAGE_DEFAULT, GODOT_PROPERTY_HINT_ENUM, "Free,Static,Extend,Contract");

	register_method("get_left_movement_little", &OpenXRHandPose::get_left_movement_little);
	register_method("set_left_movement_little", &OpenXRHandPose::set_left_movement_little);
	register_property<OpenXRHandPose, int>("left_movement_little", &OpenXRHandPose::set_left_movement_little, &OpenXRHandPose::get_left_movement_little, 1, GODOT_METHOD_RPC_MODE_DISABLED, GODOT_PROPERTY_USAGE_DEFAULT, GODOT_PROPERTY_HINT_ENUM, "Free,Static,Extend,Contract");

	register_method("get_right_movement_thumb", &OpenXRHandPose::get_right_movement_thumb);
	register_method("set_right_movement_thumb", &OpenXRHandPose::set_right_movement_thumb);
	register_property<OpenXRHandPose, int>("right_movement_thumb", &OpenXRHandPose::set_right_movement_thumb, &OpenXRHandPose::get_right_movement_thumb, 1, GODOT_METHOD_RPC_MODE_DISABLED, GODOT_PROPERTY_USAGE_DEFAULT, GODOT_PROPERTY_HINT_ENUM, "Free,Static,Extend,Contract");

	register_method("get_right_movement_index", &OpenXRHandPose::get_right_movement_index);
	register_method("set_right_movement_index", &OpenXRHandPose::set_right_movement_index);
	register_property<OpenXRHandPose, int>("right_movement_index", &OpenXRHandPose::set_right_movement_index, &OpenXRHandPose::get_right_movement_index, 1, GODOT_METHOD_RPC_MODE_DISABLED, GODOT_PROPERTY_USAGE_DEFAULT, GODOT_PROPERTY_HINT_ENUM, "Free,Static,Extend,Contract");

	register_method("get_right_movement_middle", &OpenXRHandPose::get_right_movement_middle);
	register_method("set_right_movement_middle", &OpenXRHandPose::set_right_movement_middle);
	register_property<OpenXRHandPose, int>("right_movement_middle", &OpenXRHandPose::set_right_movement_middle, &OpenXRHandPose::get_right_movement_middle, 1, GODOT_METHOD_RPC_MODE_DISABLED, GODOT_PROPERTY_USAGE_DEFAULT, GODOT_PROPERTY_HINT_ENUM, "Free,Static,Extend,Contract");

	register_method("get_right_movement_ring", &OpenXRHandPose::get_right_movement_ring);
	register_method("set_right_movement_ring", &OpenXRHandPose::set_right_movement_ring);
	register_property<OpenXRHandPose, int>("right_movement_ring", &OpenXRHandPose::set_right_movement_ring, &OpenXRHandPose::get_right_movement_ring, 1, GODOT_METHOD_RPC_MODE_DISABLED, GODOT_PROPERTY_USAGE_DEFAULT, GODOT_PROPERTY_HINT_ENUM, "Free,Static,Extend,Contract");

	register_method("get_right_movement_little", &OpenXRHandPose::get_right_movement_little);
	register_method("set_right_movement_little", &OpenXRHandPose::set_right_movement_little);
	register_property<OpenXRHandPose, int>("right_movement_little", &OpenXRHandPose::set_right_movement_little, &OpenXRHandPose::get_right_movement_little, 1, GODOT_METHOD_RPC_MODE_DISABLED, GODOT_PROPERTY_USAGE_DEFAULT, GODOT_PROPERTY_HINT_ENUM, "Free,Static,Extend,Contract");

	register_method("get_hands", &OpenXRHandPose::get_hands);
	register_method("set_hands", &OpenXRHandPose::set_hands);
	register_property<OpenXRHandPose, Array>("hands", &OpenXRHandPose::set_hands, &OpenXRHandPose::get_hands, OpenXRHandPose::get_default_pose(), GODOT_METHOD_RPC_MODE_DISABLED, GODOT_PROPERTY_USAGE_DEFAULT, GODOT_PROPERTY_HINT_NONE);
	
}

OpenXRHandPose::OpenXRHandPose() {
	left_movement_thumb = 1;
	left_movement_index = 1;
	left_movement_middle = 1;
	left_movement_ring = 1;
	left_movement_little = 1;
	right_movement_thumb = 1;
	right_movement_index = 1;
	right_movement_middle = 1;
	right_movement_ring = 1;
	right_movement_little = 1;
	hands = get_default_pose();
}

OpenXRHandPose::~OpenXRHandPose() {
    // add your cleanup here
}

Array OpenXRHandPose::get_default_pose() {
	Array result = Array();
	Array ltab = Array();
	Array rtab = Array();

	ltab.append(PoolVector3Array());
	ltab.append(Array());

	rtab.append(PoolVector3Array());
	rtab.append(Array());

	result.append(ltab);
	result.append(rtab);
	return result;
}

int OpenXRHandPose::get_left_movement_thumb() const {
	return left_movement_thumb;
}

void OpenXRHandPose::set_left_movement_thumb(int p_left_movement_thumb) {
	left_movement_thumb = p_left_movement_thumb;
}

int OpenXRHandPose::get_left_movement_index() const {
	return left_movement_index;
}

void OpenXRHandPose::set_left_movement_index(int p_left_movement_index) {
	left_movement_index = p_left_movement_index;
}

int OpenXRHandPose::get_left_movement_middle() const {
	return left_movement_middle;
}

void OpenXRHandPose::set_left_movement_middle(int p_left_movement_middle) {
	left_movement_middle = p_left_movement_middle;
}

int OpenXRHandPose::get_left_movement_ring() const {
	return left_movement_ring;
}

void OpenXRHandPose::set_left_movement_ring(int p_left_movement_ring) {
	left_movement_ring = p_left_movement_ring;
}

int OpenXRHandPose::get_left_movement_little() const {
	return left_movement_little;
}

void OpenXRHandPose::set_left_movement_little(int p_left_movement_little) {
	left_movement_little = p_left_movement_little;
}

int OpenXRHandPose::get_right_movement_thumb() const {
	return right_movement_thumb;
}

void OpenXRHandPose::set_right_movement_thumb(int p_right_movement_thumb) {
	right_movement_thumb = p_right_movement_thumb;
}

int OpenXRHandPose::get_right_movement_index() const {
	return right_movement_index;
}

void OpenXRHandPose::set_right_movement_index(int p_right_movement_index) {
	right_movement_index = p_right_movement_index;
}

int OpenXRHandPose::get_right_movement_middle() const {
	return right_movement_middle;
}

void OpenXRHandPose::set_right_movement_middle(int p_right_movement_middle) {
	right_movement_middle = p_right_movement_middle;
}

int OpenXRHandPose::get_right_movement_ring() const {
	return right_movement_ring;
}

void OpenXRHandPose::set_right_movement_ring(int p_right_movement_ring) {
	right_movement_ring = p_right_movement_ring;
}

int OpenXRHandPose::get_right_movement_little() const {
	return right_movement_little;
}

void OpenXRHandPose::set_right_movement_little(int p_right_movement_little) {
	right_movement_little = p_right_movement_little;
}

Array OpenXRHandPose::get_hands() const {
	return hands;
}

void OpenXRHandPose::set_hands(Array p_hands) {
	hands = p_hands;
}
