#ifndef PCSPRITE_H
#define PCSPRITE_H

#include <godot_cpp/classes/sprite2d.hpp>

namespace godot {

	class PCSprite : public Sprite2D {
		GDCLASS(PCSprite, Sprite2D)

	private:
		

	protected:
		static void _bind_methods();

	public:
		PCSprite();
		~PCSprite();

		void _process(double delta) override;
	};

}

#endif