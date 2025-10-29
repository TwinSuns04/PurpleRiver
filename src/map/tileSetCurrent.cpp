#include "tileSetCurrent.h"
#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void TileSetCurrent::_bind_methods()
{
}

TileSetCurrent::TileSetCurrent()
{
	set_tile_size(tileSize);
	CreateCustomDataLayer(0, rCV, Variant::VECTOR2); // create riverCurrentVector custom data
	CreateCustomDataLayer(1, rCM, Variant::INT); // create riverCurrentMult custom data
	CreateCustomDataLayer(2, rTCS, Variant::BOOL); // create riverTileCollisionStatus custom data
}

TileSetCurrent::~TileSetCurrent()
{
	// Add your cleanup here.
}

Vector2 TileSetCurrent::get_riverCurrentVector() const
{
	return riverCurrentVector;
}

void TileSetCurrent::set_riverCurrentVector(const Vector2 p_vector)
{
	riverCurrentVector = p_vector;
}

int TileSetCurrent::get_rCurrentMult() const
{
	return rCurrentMult;
}

void TileSetCurrent::set_rCurrentMult(const int p_mult)
{
	rCurrentMult = p_mult;
}

bool TileSetCurrent::get_collisionStatus() const
{
	return false;
}

void TileSetCurrent::set_collisionStatus(const bool p_status)
{
	if (collisionStatus != get_collisionStatus())
	{
		collisionStatus = !collisionStatus;
	}
}

void TileSetCurrent::ApplyRiverCurrent()
{
	
}


void TileSetCurrent::CreateCustomDataLayer(int p_index, String p_name, Variant::Type p_type)
{
	add_custom_data_layer(p_index);
	set_custom_data_layer_name(p_index, p_name);
	set_custom_data_layer_type(p_index, p_type);
}
