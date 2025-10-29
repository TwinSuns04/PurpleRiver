#include "pcCamera.h"
#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void PCCamera::_bind_methods()
{
}

PCCamera::PCCamera()
{
	// Initialize any variables here.
	set_zoom(CUSTOM_ZOOM_QUARTER);
	
}

PCCamera::~PCCamera()
{
	// Add your cleanup here.
}

void PCCamera::_process(double delta)
{
	
}