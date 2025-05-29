#include "playerCharacter.h"
#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void PlayerCharacter::_bind_methods() 
{
	// pcPosition
	ClassDB::bind_method(D_METHOD("get_pcPosition"), &PlayerCharacter::get_pcPosition);
	ClassDB::bind_method(D_METHOD("set_pcPosition", "p_pos"), &PlayerCharacter::set_pcPosition);
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "pcPosition"), "set_pcPosition", "get_pcPosition");

	// movementSpeed
	ClassDB::bind_method(D_METHOD("get_movementSpeedBase"), &PlayerCharacter::get_movementSpeedBase);
	ClassDB::bind_method(D_METHOD("set_movementSpeedBase", "p_speed"), &PlayerCharacter::set_movementSpeedBase);
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "movementSpeedBase"), "set_movementSpeedBase", "get_movementSpeedBase");
	ClassDB::bind_method(D_METHOD("get_movementSpeed"), &PlayerCharacter::get_movementSpeed);
	ClassDB::bind_method(D_METHOD("set_movementSpeed", "p_speed"), &PlayerCharacter::set_movementSpeed);
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "movementSpeed"), "set_movementSpeed", "get_movementSpeed");

	// pcVelocity
	ClassDB::bind_method(D_METHOD("get_pcVelocity"), &PlayerCharacter::get_pcVelocity);
	ClassDB::bind_method(D_METHOD("set_pcVelocity", "p_velocity"), &PlayerCharacter::set_pcVelocity);
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "pcVelocity"), "set_pcVelocity", "get_pcVelocity");

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
	pcPosition = Vector2(400, 400);
	movementSpeedBase = 400;
	movementSpeed = movementSpeedBase * 1;
	pcVelocity = Vector2(0, 0);
	speedBoostMult = 1.5;

	amplitude = 10.0;
	
}

PlayerCharacter::~PlayerCharacter() 
{
	// Add your cleanup here.
}

void PlayerCharacter::_process(double delta) 
{
	/*
	timePassed += delta;

	Vector2 newPos = Vector2(
		amplitude + (amplitude * sin(timePassed * 2.0)),
		amplitude + (amplitude * cos(timePassed * 1.5))
	);

	set_position(newPos);
	*/
}

Vector2 PlayerCharacter::get_pcPosition() const
{
	return pcPosition;
}

void PlayerCharacter::set_pcPosition(const Vector2 p_pos)
{
	pcPosition = p_pos;
}

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

Vector2 PlayerCharacter::get_pcVelocity() const
{
	return pcVelocity;
}

void PlayerCharacter::set_pcVelocity(const Vector2 p_velocity)
{
	pcVelocity = p_velocity;
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
