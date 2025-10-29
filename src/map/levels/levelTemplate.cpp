#include "map/levels/levelTemplate.h"
#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void LevelTemplate::_bind_methods()
{
	// levelNum
	ClassDB::bind_method(D_METHOD("get_levelNum"), &LevelTemplate::get_levelNum);
	ClassDB::bind_method(D_METHOD("set_levelNum", "p_num"), &LevelTemplate::set_levelNum);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "levelNum"), "set_levelNum", "get_levelNum");
}

LevelTemplate::LevelTemplate()
{
	// Initialize any variables here.
	levelNum = 0;
}

LevelTemplate::~LevelTemplate()
{
	// Add your cleanup here.
}

void LevelTemplate::_process(double delta)
{
	
}

// getters & setters
#pragma region GetSet
int LevelTemplate::get_levelNum() const
{
	return levelNum;
}

void LevelTemplate::set_levelNum(const int p_num)
{
	levelNum = p_num;
}

#pragma endregion
