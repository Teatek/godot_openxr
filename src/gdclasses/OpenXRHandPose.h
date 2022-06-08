#ifndef OPENXR_HANDPOSE_H
#define OPENXR_HANDPOSE_H

#include <Godot.hpp>
#include <Resource.hpp>
#include <Dictionary.hpp>
#include <PoolArrays.hpp>
#include <Array.hpp>
#include <Quat.hpp>

namespace godot {

class OpenXRHandPose : public Resource {
    GODOT_CLASS(OpenXRHandPose, Resource)

private:
    int left_movement_thumb;
    int left_movement_index;
    int left_movement_middle;
    int left_movement_ring;
    int left_movement_little;

    int right_movement_thumb;
    int right_movement_index;
    int right_movement_middle;
    int right_movement_ring;
    int right_movement_little;
    Array hands;

public:
    static void _register_methods();

    OpenXRHandPose();
    ~OpenXRHandPose();
    
    static Array get_default_pose();
    
    Array get_hands() const;
    void set_hands(Array p_hands);
    
    int get_left_movement_thumb() const;
    void set_left_movement_thumb(int p_left_movement_thumb);

    int get_left_movement_index() const;
    void set_left_movement_index(int p_left_movement_index);

    int get_left_movement_middle() const;
    void set_left_movement_middle(int p_left_movement_middle);

    int get_left_movement_ring() const;
    void set_left_movement_ring(int p_left_movement_ring);

    int get_left_movement_little() const;
    void set_left_movement_little(int p_left_movement_little);

    int get_right_movement_thumb() const;
    void set_right_movement_thumb(int p_right_movement_thumb);

    int get_right_movement_index() const;
    void set_right_movement_index(int p_right_movement_index);

    int get_right_movement_middle() const;
    void set_right_movement_middle(int p_right_movement_middle);

    int get_right_movement_ring() const;
    void set_right_movement_ring(int p_right_movement_ring);

    int get_right_movement_little() const;
    void set_right_movement_little(int p_right_movement_little);
};

}

#endif // !OPENXR_HANDPOSE_H
