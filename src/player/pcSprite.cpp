#include "pcSprite.h"
#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void PCSprite::_bind_methods()
{
}

PCSprite::PCSprite()
{
	// Initialize any variables here.
	UtilityFunctions::print("PCSprite Ready");
	set_global_scale(Vector2(0.08, 0.08));
}

PCSprite::~PCSprite() 
{
	// Add your cleanup here.
}

void PCSprite::_process(double delta)
{
	
}