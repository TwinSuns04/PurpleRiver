#ifndef TESTSCONS_H
#define TESTSCONS_H

#include <godot_cpp/classes/node2d.hpp>

namespace godot {
    class TestScons : public Node2D {
        GDCLASS(TestScons, Node2D)

    private:

    protected:
        static void _bind_methods();

    public:
        TestScons();
        ~TestScons();
        void _process(double delta) override;


    };
}

#endif