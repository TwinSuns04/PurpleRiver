// Not currently in use

#ifndef PCADVANCEDCONTROLLER_H
#define PCADVANCEDCONTROLLER_H

#include <godot_cpp/classes/node.hpp>

namespace godot {

	class PCAdvancedController : public Node {
		GDCLASS(PCAdvancedController, Node)

	private:
		// need screen size at some point

		double movementSpeed;


	protected:
		static void _bind_methods();

	public:
		PCAdvancedController();
		~PCAdvancedController();
		void _process(double delta) override;

		void set_movementSpeed(const double p_speed);
		double get_movementSpeed() const;

		//virtual void _input(const Ref<InputEvent>& p_event) override;
		
	};

}

#endif

