#ifndef PCCOLLISION_H
#define PCCOLLISION_H

#include <godot_cpp/classes/collision_polygon2d.hpp>

namespace godot {

	class PCCollision : public CollisionPolygon2D {
		GDCLASS(PCCollision, CollisionPolygon2D)

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
