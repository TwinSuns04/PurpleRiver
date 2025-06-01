#include "playerCharacter.h"
#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void PlayerCharacter::_bind_methods() 
{
	/*
	// position
	ClassDB::bind_method(D_METHOD("get_position"), &PlayerCharacter::get_position);
	ClassDB::bind_method(D_METHOD("set_position", "p_pos"), &PlayerCharacter::set_position);
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "position"), "set_position", "get_position");
	// velocity
	ClassDB::bind_method(D_METHOD("get_velocity"), &PlayerCharacter::get_velocity);
	ClassDB::bind_method(D_METHOD("set_velocity", "p_velocity"), &PlayerCharacter::set_velocity);
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "velocity"), "set_velocity", "get_velocity");
	*/

	// movementSpeed
	ClassDB::bind_method(D_METHOD("get_movementSpeedBase"), &PlayerCharacter::get_movementSpeedBase);
	ClassDB::bind_method(D_METHOD("set_movementSpeedBase", "p_speed"), &PlayerCharacter::set_movementSpeedBase);
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "movementSpeedBase"), "set_movementSpeedBase", "get_movementSpeedBase");
	ClassDB::bind_method(D_METHOD("get_movementSpeed"), &PlayerCharacter::get_movementSpeed);
	ClassDB::bind_method(D_METHOD("set_movementSpeed", "p_speed"), &PlayerCharacter::set_movementSpeed);
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "movementSpeed"), "set_movementSpeed", "get_movementSpeed");

	// speedBoostMult
	ClassDB::bind_method(D_METHOD("get_speedBoostMult"), &PlayerCharacter::get_speedBoostMult);
	ClassDB::bind_method(D_METHOD("set_speedBoostMult", "p_boost"), &PlayerCharacter::set_speedBoostMult);
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "speedBoostMult"), "set_speedBoostMult", "get_speedBoostMult");

	// amplitude
	ClassDB::bind_method(D_METHOD("get_amplitude"), &PlayerCharacter::get_amplitude);
	ClassDB::bind_method(D_METHOD("set_amplitude", "p_amplitude"), &PlayerCharacter::set_amplitude);
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "amplitude"), "set_amplitude", "get_amplitude");

}

PlayerCharacter::PlayerCharacter() 
{
	// Initialize any variables here.
	timePassed = 0.0;
	//position = Vector2(0, 0);
	movementSpeedBase = 400;
	movementSpeed = movementSpeedBase * 1;
	//velocity = Vector2(0, 0);
	speedBoostMult = 1.5;

	amplitude = 10.0;
	
}

PlayerCharacter::~PlayerCharacter() 
{
	// Add your cleanup here.
}

void PlayerCharacter::_process(double delta) 
{
	//position = get_global_position();

	/*
	timePassed += delta;

	Vector2 newPos = Vector2(
		amplitude + (amplitude * sin(timePassed * 2.0)),
		amplitude + (amplitude * cos(timePassed * 1.5))
	);

	set_position(newPos);
	*/
}

/*
Vector2 PlayerCharacter::get_position() const
{
	return position;
}

void PlayerCharacter::set_position(const Vector2 p_pos)
{
	position = p_pos;
}

Vector2 PlayerCharacter::get_velocity() const
{
	return velocity;
}

void PlayerCharacter::set_velocity(const Vector2 p_velocity)
{
	velocity = p_velocity;
}
*/

double PlayerCharacter::get_movementSpeedBase() const
{
	return movementSpeedBase;
}

void PlayerCharacter::set_movementSpeedBase(const double p_speed)
{
	movementSpeedBase = p_speed;
}

double PlayerCharacter::get_movementSpeed() const
{
	return movementSpeed;
}

void PlayerCharacter::set_movementSpeed(const double p_speed)
{
	movementSpeed = p_speed;
}

double PlayerCharacter::get_amplitude() const
{
	return amplitude;
}

void PlayerCharacter::set_amplitude(const double p_amplitude)
{
	amplitude = p_amplitude;
}

double PlayerCharacter::get_speedBoostMult() const
{
	return speedBoostMult;
}

void PlayerCharacter::set_speedBoostMult(const double p_boost)
{
	speedBoostMult = p_boost;
}
