#ifndef PCAREA_H
#define PCAREA_H

#include <godot_cpp/classes/area2d.hpp>

namespace godot {

	class PCArea : public Area2D {
		GDCLASS(PCArea, Area2D)

	private:


	protected:
		static void _bind_methods();

	public:
		PCArea();
		~PCArea();
		void _process(double delta) override;



	};

}

#endif
