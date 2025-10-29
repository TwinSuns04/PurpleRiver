#include "riverAreaCollision.h"
#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void RiverAreaCollision::_bind_methods()
{
	// numPoints
	ClassDB::bind_method(D_METHOD("get_numPoints"), &RiverAreaCollision::get_numPoints);
	ClassDB::bind_method(D_METHOD("set_numPoints", "p_num"), &RiverAreaCollision::set_numPoints);
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "numPoints"), "set_numPoints", "get_numPoints");

	// isColliding
	ClassDB::bind_method(D_METHOD("get_isColliding"), &RiverAreaCollision::get_isColliding);
	ClassDB::bind_method(D_METHOD("set_isColliding", "p_coll"), &RiverAreaCollision::set_isColliding);
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "isColliding"), "set_isColliding", "get_isColliding");
}

RiverAreaCollision::RiverAreaCollision()
{
	// Initialize any variables here.
	numPoints = 0;
	isColliding = false;
}

RiverAreaCollision::~RiverAreaCollision()
{
	// Add your cleanup here.
}

void RiverAreaCollision::_process(double delta)
{

}

int RiverAreaCollision::get_numPoints() const
{
	return numPoints;
}

void RiverAreaCollision::set_numPoints(const int p_num)
{
	numPoints = p_num;
}

bool RiverAreaCollision::get_isColliding() const
{
	return isColliding;
}

void RiverAreaCollision::set_isColliding(const bool p_coll)
{
	isColliding = p_coll;
}
