#ifndef PCCOLLISION_H
#define PCCOLLISION_H

#include <godot_cpp/classes/collision_shape2d.hpp>

namespace godot {

	class PCCollision : public CollisionShape2D {
		GDCLASS(PCCollision, CollisionShape2D)

	private:


	protected:
		static void _bind_methods();

	public:
		PCCollision();
		~PCCollision();

		void _process(double delta) override;
	};

}

#endif
