#ifndef HAIKUAREA_H
#define HAIKUAREA_H

#include <godot_cpp/classes/area2d.hpp>

namespace godot {

    class HaikuArea : public Area2D {
        GDCLASS(HaikuArea, Area2D)

    private:

    protected:
        static void _bind_methods();

    public:
        HaikuArea();
        ~HaikuArea();
        void _process(double delta) override;
    };

}

#endif