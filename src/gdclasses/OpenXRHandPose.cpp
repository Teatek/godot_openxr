#include "OpenXRHandPose.h"
#include "gdclasses/OpenXRHandPose.h"

using namespace godot;

void OpenXRHandPose::_register_methods() {
	register_method("get_movement_thumb", &OpenXRHandPose::get_movement_thumb);
	register_method("set_movement_thumb", &OpenXRHandPose::set_movement_thumb);
	register_property<OpenXRHandPose, int>("movement_thumb", &OpenXRHandPose::set_movement_thumb, &OpenXRHandPose::get_movement_thumb, 0, GODOT_METHOD_RPC_MODE_DISABLED, GODOT_PROPERTY_USAGE_DEFAULT, GODOT_PROPERTY_HINT_ENUM, "Free,Static,Extend,Contract");

	register_method("get_movement_index", &OpenXRHandPose::get_movement_index);
	register_method("set_movement_index", &OpenXRHandPose::set_movement_index);
	register_property<OpenXRHandPose, int>("movement_index", &OpenXRHandPose::set_movement_index, &OpenXRHandPose::get_movement_index, 0, GODOT_METHOD_RPC_MODE_DISABLED, GODOT_PROPERTY_USAGE_DEFAULT, GODOT_PROPERTY_HINT_ENUM, "Free,Static,Extend,Contract");

	register_method("get_movement_middle", &OpenXRHandPose::get_movement_middle);
	register_method("set_movement_middle", &OpenXRHandPose::set_movement_middle);
	register_property<OpenXRHandPose, int>("movement_middle", &OpenXRHandPose::set_movement_middle, &OpenXRHandPose::get_movement_middle, 0, GODOT_METHOD_RPC_MODE_DISABLED, GODOT_PROPERTY_USAGE_DEFAULT, GODOT_PROPERTY_HINT_ENUM, "Free,Static,Extend,Contract");

	register_method("get_movement_ring", &OpenXRHandPose::get_movement_ring);
	register_method("set_movement_ring", &OpenXRHandPose::set_movement_ring);
	register_property<OpenXRHandPose, int>("movement_ring", &OpenXRHandPose::set_movement_ring, &OpenXRHandPose::get_movement_ring, 0, GODOT_METHOD_RPC_MODE_DISABLED, GODOT_PROPERTY_USAGE_DEFAULT, GODOT_PROPERTY_HINT_ENUM, "Free,Static,Extend,Contract");

	register_method("get_movement_little", &OpenXRHandPose::get_movement_little);
	register_method("set_movement_little", &OpenXRHandPose::set_movement_little);
	register_property<OpenXRHandPose, int>("movement_little", &OpenXRHandPose::set_movement_little, &OpenXRHandPose::get_movement_little, 0, GODOT_METHOD_RPC_MODE_DISABLED, GODOT_PROPERTY_USAGE_DEFAULT, GODOT_PROPERTY_HINT_ENUM, "Free,Static,Extend,Contract");

	register_method("get_hands", &OpenXRHandPose::get_hands);
	register_method("set_hands", &OpenXRHandPose::set_hands);
	register_property<OpenXRHandPose, Dictionary>("hands", &OpenXRHandPose::set_hands, &OpenXRHandPose::get_hands, OpenXRHandPose::get_default_pose(), GODOT_METHOD_RPC_MODE_DISABLED, GODOT_PROPERTY_USAGE_DEFAULT, GODOT_PROPERTY_HINT_NONE);
	
}

OpenXRHandPose::OpenXRHandPose() {
	movement_thumb = 0;
	movement_index = 0;
	movement_middle = 0;
	movement_ring = 0;
	movement_little = 0;
	hands = get_default_pose();
}

OpenXRHandPose::~OpenXRHandPose() {
    // add your cleanup here
}

Dictionary OpenXRHandPose::get_default_pose() {
	// certainly a better way to do this
	PoolVector3Array pl = PoolVector3Array();
	Array rl = Array();
	PoolVector3Array pr = PoolVector3Array();
	Array rr = Array();

	// left hand
	pl.append(Vector3(0.008, 0.009, -0.051));
	pl.append(Vector3(0, 0, 0.001));
	pl.append(Vector3(0.029, -0.018, 0.001));
	pl.append(Vector3(-0, 0, -0.040406));
	pl.append(Vector3(-0, -0.000001, -0.032518));
	pl.append(Vector3(0, -0, -0.030462));
	pl.append(Vector3(0.021073, -0.001557, -0.014787));
	pl.append(Vector3(-0, 0, -0.073798));
	pl.append(Vector3(0, 0.000001, -0.043285));
	pl.append(Vector3(-0, 0, -0.028277));
	pl.append(Vector3(-0, -0, -0.022822));
	pl.append(Vector3(0.00712, 0.002177, -0.016319));
	pl.append(Vector3(-0, 0, -0.070885));
	pl.append(Vector3(0, 0, -0.043108));
	pl.append(Vector3(-0, 0, -0.033266));
	pl.append(Vector3(-0, -0, -0.025892));
	pl.append(Vector3(-0.006545, 0.000513, -0.016348));
	pl.append(Vector3(-0, -0, -0.065974));
	pl.append(Vector3(0, 0, -0.040332));
	pl.append(Vector3(0, 0, -0.028491));
	pl.append(Vector3(0, 0, -0.02243));
	pl.append(Vector3(-0.018981, -0.002478, -0.015214));
	pl.append(Vector3(0.000001, -0, -0.062855));
	pl.append(Vector3(-0, 0, -0.029875));
	pl.append(Vector3(-0, -0.000001, -0.017978));
	pl.append(Vector3(-0, 0.000002, -0.018018));

	rl.append(Dictionary::make("x", 0.101224, "y", -0.012462, "z", -0.040788, "w", 0.101224));
	rl.append(Dictionary::make("x", 0, "y", 0, "z", 0.707107, "w", 0));
	rl.append(Dictionary::make("x", 0.113287, "y", -0.345129, "z", -0.609936, "w", 0.113287));
	rl.append(Dictionary::make("x", -0.246378, "y", 0.001372, "z", -0.000061, "w", -0.246378));
	rl.append(Dictionary::make("x", -0.153335, "y", -0.001403, "z", -0.000098, "w", -0.153335));
	rl.append(Dictionary::make("x", -0, "y", 0, "z", 0, "w", 0));
	rl.append(Dictionary::make("x", 0.095399, "y", -0.10392, "z", -0.084223, "w", 0.095399));
	rl.append(Dictionary::make("x", -0.241404, "y", 0.052887, "z", -0.001623, "w", -0.241404));
	rl.append(Dictionary::make("x", -0.184762, "y", -0.005042, "z", 0.000086, "w", -0.184762));
	rl.append(Dictionary::make("x", -0.076458, "y", 0.001166, "z", -0.000031, "w", -0.076458));
	rl.append(Dictionary::make("x", -0, "y", 0, "z", 0, "w", 0));
	rl.append(Dictionary::make("x", 0.101224, "y", -0.012462, "z", -0.040788, "w", 0.101224));
	rl.append(Dictionary::make("x", -0.229163, "y", 0.000186, "z", -0, "w", -0.229163));
	rl.append(Dictionary::make("x", -0.157396, "y", 0.003688, "z", -0.000093, "w", -0.157396));
	rl.append(Dictionary::make("x", -0.141276, "y", -0.004125, "z", 0.000107, "w", -0.141276));
	rl.append(Dictionary::make("x", 0, "y", 0, "z", 0, "w", 0));
	rl.append(Dictionary::make("x", 0.0707, "y", 0.049556, "z", 0.016104, "w", 0.0707));
	rl.append(Dictionary::make("x", -0.220369, "y", 0.040957, "z", 0.000901, "w", -0.220369));
	rl.append(Dictionary::make("x", -0.13383, "y", -0.002531, "z", 0.000073, "w", -0.13383));
	rl.append(Dictionary::make("x", -0.135355, "y", 0.004263, "z", -0.000199, "w", -0.135355));
	rl.append(Dictionary::make("x", 0, "y", 0, "z", 0, "w", 0));
	rl.append(Dictionary::make("x", 0.019661, "y", 0.14892, "z", 0.11935, "w", 0.019661));
	rl.append(Dictionary::make("x", -0.110308, "y", -0.028164, "z", -0.003942, "w", -0.110308));
	rl.append(Dictionary::make("x", -0.132523, "y", 0.011456, "z", -0.000383, "w", -0.132523));
	rl.append(Dictionary::make("x", -0.108581, "y", -0.012703, "z", 0.000538, "w", -0.108581));
	rl.append(Dictionary::make("x", 0, "y", 0, "z", 0, "w", 0));

	// right hand
	pr.append(Vector3(-0.00829, 0.009273, -0.051025));
	pr.append(Vector3(0.00016, 0.000626, 0.000032));
	pr.append(Vector3(-0.029178, -0.017914, -0.025298));
	pr.append(Vector3(-0, 0, -0.040406));
	pr.append(Vector3(0, 0, -0.032517));
	pr.append(Vector3(-0.000001, -0.000001, -0.030464));
	pr.append(Vector3(-0.021073, -0.001557, -0.014787));
	pr.append(Vector3(0, 0, -0.073798));
	pr.append(Vector3(0, -0, -0.043287));
	pr.append(Vector3(0, -0, -0.028275));
	pr.append(Vector3(-0, -0, -0.022821));
	pr.append(Vector3(-0.00712, 0.002177, -0.016319));
	pr.append(Vector3(0, -0, -0.070886));
	pr.append(Vector3(-0, -0.000001, -0.043107));
	pr.append(Vector3(0, 0.000001, -0.033266));
	pr.append(Vector3(0, 0, -0.025892));
	pr.append(Vector3(0.006545, 0.000513, -0.016348));
	pr.append(Vector3(-0, -0, -0.065975));
	pr.append(Vector3(0, -0, -0.040331));
	pr.append(Vector3(0, 0, -0.02849));
	pr.append(Vector3(-0, -0.000002, -0.022428));
	pr.append(Vector3(0.018981, -0.002478, -0.015214));
	pr.append(Vector3(0, 0, -0.062855));
	pr.append(Vector3(0, -0, -0.029873));
	pr.append(Vector3(-0, 0, -0.017978));
	pr.append(Vector3(-0, -0, -0.018018));

	rr.append(Dictionary::make("x", 0.101224, "y", 0.012462, "z", 0.040788, "w", 0.101224));
	rr.append(Dictionary::make("x", 0.5, "y", 0.5, "z", 0.5, "w", 0.5));
	rr.append(Dictionary::make("x", 0.113287, "y", 0.345129, "z", 0.609936, "w", 0.113287));
	rr.append(Dictionary::make("x", -0.246377, "y", -0.001372, "z", 0.000061, "w", -0.246377));
	rr.append(Dictionary::make("x", -0.153335, "y", 0.001403, "z", 0.000098, "w", -0.153335));
	rr.append(Dictionary::make("x", 0, "y", 0, "z", 0, "w", 0));
	rr.append(Dictionary::make("x", 0.095399, "y", 0.10392, "z", 0.084223, "w", 0.095399));
	rr.append(Dictionary::make("x", -0.241404, "y", -0.052887, "z", 0.001624, "w", -0.241404));
	rr.append(Dictionary::make("x", -0.184762, "y", 0.005041, "z", -0.000086, "w", -0.184762));
	rr.append(Dictionary::make("x", -0.076458, "y", -0.001166, "z", 0.000031, "w", -0.076458));
	rr.append(Dictionary::make("x", 0, "y", 0, "z", 0, "w", 0));
	rr.append(Dictionary::make("x", 0.101224, "y", 0.012462, "z", 0.040788, "w", 0.101224));
	rr.append(Dictionary::make("x", -0.229163, "y", -0.000186, "z", 0, "w", -0.229163));
	rr.append(Dictionary::make("x", -0.157395, "y", -0.003688, "z", 0.000093, "w", -0.157395));
	rr.append(Dictionary::make("x", -0.141277, "y", 0.004125, "z", -0.000107, "w", -0.141277));
	rr.append(Dictionary::make("x", 0, "y", 0, "z", 0, "w", 0));
	rr.append(Dictionary::make("x", 0.0707, "y", -0.049556, "z", -0.016104, "w", 0.0707));
	rr.append(Dictionary::make("x", -0.220369, "y", -0.040957, "z", -0.000901, "w", -0.220369));
	rr.append(Dictionary::make("x", -0.13383, "y", 0.002531, "z", -0.000073, "w", -0.13383));
	rr.append(Dictionary::make("x", -0.135355, "y", -0.004263, "z", 0.000199, "w", -0.135355));
	rr.append(Dictionary::make("x", 0, "y", 0, "z", 0, "w", 0));
	rr.append(Dictionary::make("x", 0.019661, "y", -0.148919, "z", -0.11935, "w", 0.019661));
	rr.append(Dictionary::make("x", -0.110308, "y", 0.028164, "z", 0.003942, "w", -0.110308));
	rr.append(Dictionary::make("x", -0.132523, "y", -0.011456, "z", 0.000383, "w", -0.132523));
	rr.append(Dictionary::make("x", -0.108581, "y", 0.012702, "z", -0.000538, "w", -0.108581));
	rr.append(Dictionary::make("x", 0, "y", 0, "z", 0, "w", 0));


	return Dictionary::make(
		"left",
		Dictionary::make(
			"positions", pl,
			"rotations", rl
		),
		"right",
		Dictionary::make(
			"positions", pr,
			"rotations", rr
		)
	);
}

int OpenXRHandPose::get_movement_thumb() const {
	return movement_thumb;
}

void OpenXRHandPose::set_movement_thumb(int p_movement_thumb) {
	movement_thumb = p_movement_thumb;
}

int OpenXRHandPose::get_movement_index() const {
	return movement_index;
}

void OpenXRHandPose::set_movement_index(int p_movement_index) {
	movement_index = p_movement_index;
}

int OpenXRHandPose::get_movement_middle() const {
	return movement_middle;
}

void OpenXRHandPose::set_movement_middle(int p_movement_middle) {
	movement_middle = p_movement_middle;
}

int OpenXRHandPose::get_movement_ring() const {
	return movement_ring;
}

void OpenXRHandPose::set_movement_ring(int p_movement_ring) {
	movement_ring = p_movement_ring;
}

int OpenXRHandPose::get_movement_little() const {
	return movement_little;
}

void OpenXRHandPose::set_movement_little(int p_movement_little) {
	movement_little = p_movement_little;
}

Dictionary OpenXRHandPose::get_hands() const {
	return hands;
}

void OpenXRHandPose::set_hands(Dictionary p_hands) {
	hands = p_hands;
}
