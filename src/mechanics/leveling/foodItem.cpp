#include "foodItem.h"
#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void FoodItem::_bind_methods()
{
	ClassDB::bind_method(D_METHOD("get_foodName"), &FoodItem::get_foodName);
	ClassDB::bind_method(D_METHOD("set_foodName", "p_name"), &FoodItem::set_foodName);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "food_name"), "set_foodName", "get_foodName");

	ClassDB::bind_method(D_METHOD("get_foodVal"), &FoodItem::get_foodVal);
	ClassDB::bind_method(D_METHOD("set_foodVal", "p_val"), &FoodItem::set_foodVal);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "food_val"), "set_foodVal", "get_foodVal");

	ClassDB::bind_method(D_METHOD("get_isEaten"), &FoodItem::get_isEaten);
	ClassDB::bind_method(D_METHOD("set_isEaten", "p_val"), &FoodItem::set_isEaten);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "is_eaten"), "set_isEaten", "get_isEaten");
}

FoodItem::FoodItem()
{
	// Initialize any variables here.
	foodName = "yum";
	foodVal = 20;
	isEaten = false;
}

FoodItem::~FoodItem()
{
	// Add your cleanup here.
}

void FoodItem::_process(double delta)
{

}

// getters & setterers
String FoodItem::get_foodName() const
{
	return foodName;
}

void FoodItem::set_foodName(const String p_name)
{
	foodName = p_name;
}

int FoodItem::get_foodVal() const
{
	return foodVal;
}

void FoodItem::set_foodVal(const int p_val)
{
	foodVal = p_val;
}

bool FoodItem::get_isEaten() const
{
	return isEaten;
}

void FoodItem::set_isEaten(const bool p_val)
{
	isEaten = p_val;
}
