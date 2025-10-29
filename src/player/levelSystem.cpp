// NOT IN USE
#include "levelSystem.h"
#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void LevelSystem::_bind_methods()
{
	// functions bind to GDscript methods
	ClassDB::bind_method(D_METHOD("level_up"), &LevelSystem::LevelUp);

	// bind getters & setters
	ClassDB::bind_method(D_METHOD("get_playerLevel"), &LevelSystem::get_playerLevel);
	ClassDB::bind_method(D_METHOD("set_playerLevel", "p_level"), &LevelSystem::set_playerLevel);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "playerLevel"), "set_playerLevel", "get_playerLevel");
}

LevelSystem::LevelSystem()
{
	// Initialize any variables here.
	playerLevel = 1;
}

LevelSystem::~LevelSystem()
{
	// Add your cleanup here.
}

void LevelSystem::_process(double delta)
{
	
}

void LevelSystem::LevelUp()
{

}

// getters & setters
int LevelSystem::get_playerLevel() const
{
	return playerLevel;
}

void LevelSystem::set_playerLevel(const int p_level)
{
	playerLevel = p_level;
}
