// Not currently in use

#include "PCAdvancedController.h"
#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void PCAdvancedController::_bind_methods()
{
	// movementSpeed
	ClassDB::bind_method(D_METHOD("set_movementSpeed", "p_speed"), &PCAdvancedController::set_movementSpeed);
	ClassDB::bind_method(D_METHOD("get_movementSpeed"), &PCAdvancedController::get_movementSpeed);
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "movementSpeed"), "set_movementSpeed", "get_movementSpeed");


}

PCAdvancedController::PCAdvancedController()
{
	//set_process_input(true);

	movementSpeed = 1.00;
}

PCAdvancedController::~PCAdvancedController()
{
	// Add your cleanup here.
}

void PCAdvancedController::_process(double delta)
{
	
}

void PCAdvancedController::set_movementSpeed(const double p_speed)
{
	movementSpeed = p_speed;
}

double PCAdvancedController::get_movementSpeed() const
{
	return movementSpeed;
}

/*
void PCAdvancedController::_input(const Ref<InputEvent>& p_event)
{

}
*/
