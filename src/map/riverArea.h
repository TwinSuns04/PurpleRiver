#ifndef RIVERAREA_H
#define RIVERAREA_H

#include <godot_cpp/classes/area2d.hpp>
#include <riverAreaCollision.h>

namespace godot {

	class RiverArea : public Area2D {
		GDCLASS(RiverArea, Area2D)

	private:
		Vector2 riverCurrentVector;
		int rCurrentMult;
		bool collisionStatus;

		RiverAreaCollision* riverCollider;

	protected:
		static void _bind_methods();

	public:
		RiverArea();
		~RiverArea();

		void _process(double delta) override;

		// getters & setters
		Vector2 get_riverCurrentVector() const;
		void set_riverCurrentVector(const Vector2 p_vector);
		int get_rCurrentMult() const;
		void set_rCurrentMult(const int p_mult);
		bool get_collisionStatus() const;
		void set_collisionStatus(const bool p_status);

		void ApplyRiverCurrent();
	};

}

#endif