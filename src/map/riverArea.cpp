#include "riverArea.h"
#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void RiverArea::_bind_methods()
{
	// riverCurrentVector
	ClassDB::bind_method(D_METHOD("get_riverCurrentVector"), &RiverArea::get_riverCurrentVector);
	ClassDB::bind_method(D_METHOD("set_riverCurrentVector", "p_vector"), &RiverArea::set_riverCurrentVector);
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "riverCurrentVector"), "set_riverCurrentVector", "get_riverCurrentVector");

}

RiverArea::RiverArea()
{
	// Initialize any variables here.
	riverCurrentVector = Vector2(0,-1);
	rCurrentMult = 1;
	collisionStatus = false;
	set_monitoring(true);
}

RiverArea::~RiverArea()
{
	// Add your cleanup here.
}

void RiverArea::_process(double delta)
{

}

Vector2 RiverArea::get_riverCurrentVector() const
{
	return riverCurrentVector;
}

void RiverArea::set_riverCurrentVector(const Vector2 p_vector)
{
	riverCurrentVector = p_vector;
}

int RiverArea::get_rCurrentMult() const
{
	return rCurrentMult;
}

void RiverArea::set_rCurrentMult(const int p_mult)
{
	rCurrentMult = p_mult;
}

bool RiverArea::get_collisionStatus() const
{
	return riverCollider->get_isColliding();
}

void RiverArea::set_collisionStatus(const bool p_status)
{
	if (collisionStatus != get_collisionStatus())
	{
		collisionStatus = !collisionStatus;
	}
}

void RiverArea::ApplyRiverCurrent()
{

}
