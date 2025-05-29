#ifndef PCCAMERA_H
#define PCCAMERA_H

#include <godot_cpp/classes/camera2d.hpp>

namespace godot {

	class PCCamera : public Camera2D {
		GDCLASS(PCCamera, Camera2D)

	private:
		

	protected:
		static void _bind_methods();

	public:
		PCCamera();
		~PCCamera();

		void _process(double delta) override;
	};

}

#endif
