#include "procGenMap.h"
#include <godot_cpp/classes/noise.hpp>
#include <godot_cpp/classes/fast_noise_lite.hpp>
#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void ProcGenMap::_bind_methods()
{
	// mapSize
	ClassDB::bind_method(D_METHOD("get_mapSize"), &ProcGenMap::get_mapSize);
	ClassDB::bind_method(D_METHOD("set_mapSize", "p_size"), &ProcGenMap::set_mapSize);
	ADD_PROPERTY(PropertyInfo(Variant::VECTOR2I, "mapSize"), "set_mapSize", "get_mapSize");

	// noiseSeedVal, for testing not final game
	ClassDB::bind_method(D_METHOD("get_noiseSeedVal"), &ProcGenMap::get_noiseSeedVal);
	ClassDB::bind_method(D_METHOD("set_noiseSeedVal", "p_val"), &ProcGenMap::set_noiseSeedVal);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "noiseSeedVal"), "set_noiseSeedVal", "get_noiseSeedVal");


	ClassDB::bind_method(D_METHOD("generate_map"), &ProcGenMap::GenerateMap);
}

ProcGenMap::ProcGenMap()
{
	// Initialize any variables here.
	mapSize = Vector2i(600, 600);
	noiseSeedVal = 100;
}

ProcGenMap::~ProcGenMap()
{
	// Add your cleanup here.
}

void ProcGenMap::_process(double delta)
{

}

void ProcGenMap::GenerateMap()
{
	Array waterCells = {};
	Array landCells = {};
	FastNoiseLite genNoise;
	genNoise.set_seed(noiseSeedValConst);

	for (int i = 0; i < mapSize.x; i++)
	{
		for (int j = 0; j < mapSize.y; j++)
		{
			double tempNoise = genNoise.get_noise_2d(i, j);
			if (tempNoise < waterCap)
			{
				waterCells.append(Vector2(i,j));
			}
		}
	}
}

// getters & setters
#pragma region GetSet
Vector2i ProcGenMap::get_mapSize() const
{
	return mapSize;
}

void ProcGenMap::set_mapSize(Vector2i const p_size)
{
	mapSize = p_size;
}

int ProcGenMap::get_noiseSeedVal() const
{
	return noiseSeedVal;
}

void ProcGenMap::set_noiseSeedVal(int const p_noise)
{
	noiseSeedVal = p_noise;
}

#pragma endregion
