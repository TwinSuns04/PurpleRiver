#ifndef RIVERAREACOLLISION_H
#define RIVERAREACOLLISION_H

#include <godot_cpp/classes/collision_polygon2d.hpp>

namespace godot {

	class RiverAreaCollision : public CollisionPolygon2D {
		GDCLASS(RiverAreaCollision, CollisionPolygon2D)

	private:
		int numPoints;
		bool isColliding;

	protected:
		static void _bind_methods();

	public:
		RiverAreaCollision();
		~RiverAreaCollision();

		void _process(double delta) override;

		// getters & setters
		int get_numPoints() const;
		void set_numPoints(const int p_num);

		bool get_isColliding() const;
		void set_isColliding(const bool p_coll);
	};

}

#endif