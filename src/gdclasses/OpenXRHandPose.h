#ifndef OPENXR_HANDPOSE_H
#define OPENXR_HANDPOSE_H

#include <Godot.hpp>
#include <Resource.hpp>
#include <Dictionary.hpp>
#include <PoolArrays.hpp>
#include <Array.hpp>

namespace godot {

class OpenXRHandPose : public Resource {
    GODOT_CLASS(OpenXRHandPose, Resource)

private:
	int movement_thumb;
	int movement_index;
	int movement_middle;
	int movement_ring;
	int movement_little;
	Dictionary hands;

public:
    static void _register_methods();

    OpenXRHandPose();
    ~OpenXRHandPose();
	
	static Dictionary get_default_pose();
	
	Dictionary get_hands() const;
	void set_hands(Dictionary p_hands);
	
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
};

}

#endif // !OPENXR_HANDPOSE_H
