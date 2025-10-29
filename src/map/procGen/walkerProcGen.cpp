#include "walkerProcGen.h"
#include <godot_cpp/classes/noise.hpp>
#include <godot_cpp/classes/fast_noise_lite.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/random_number_generator.hpp>

using namespace godot;

void WalkerProcGen::_bind_methods()
{
	// position
	ClassDB::bind_method(D_METHOD("get_position"), &WalkerProcGen::get_position);
	ClassDB::bind_method(D_METHOD("set_position", "p_pos"), &WalkerProcGen::set_position);
	ADD_PROPERTY(PropertyInfo(Variant::VECTOR2, "position"), "set_position", "get_position");

	// travelDirection
	ClassDB::bind_method(D_METHOD("get_travelDirection"), &WalkerProcGen::get_travelDirection);
	ClassDB::bind_method(D_METHOD("set_travelDirection", "p_direction"), &WalkerProcGen::set_travelDirection);
	ADD_PROPERTY(PropertyInfo(Variant::VECTOR2, "travel_direction"), "set_travelDirection", "get_travelDirection");

	// borders
	ClassDB::bind_method(D_METHOD("get_borders"), &WalkerProcGen::get_borders);
	ClassDB::bind_method(D_METHOD("set_borders", "p_box"), &WalkerProcGen::set_borders);
	ADD_PROPERTY(PropertyInfo(Variant::RECT2, "borders"), "set_borders", "get_borders");

	// stepHistory
	ClassDB::bind_method(D_METHOD("get_stepHistory"), &WalkerProcGen::get_stepHistory);
	ClassDB::bind_method(D_METHOD("set_stepHistory", "p_steps"), &WalkerProcGen::set_stepHistory);
	ADD_PROPERTY(PropertyInfo(Variant::PACKED_VECTOR2_ARRAY, "step_history"), "set_stepHistory", "get_stepHistory");

	// stepsSinceTurn
	ClassDB::bind_method(D_METHOD("get_stepsSinceTurn"), &WalkerProcGen::get_stepsSinceTurn);
	ClassDB::bind_method(D_METHOD("set_stepsSinceTurn", "p_step"), &WalkerProcGen::set_stepsSinceTurn);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "steps_since_turn"), "set_stepsSinceTurn", "get_stepsSinceTurn");

	// rngRange
	ClassDB::bind_method(D_METHOD("get_rngRange"), &WalkerProcGen::get_rngRange);
	ClassDB::bind_method(D_METHOD("set_rngRange", "p_rng"), &WalkerProcGen::set_rngRange);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "rng_range"), "set_rngRange", "get_rngRange");

	// rngDouble
	ClassDB::bind_method(D_METHOD("get_rngDouble"), &WalkerProcGen::get_rngDouble);
	ClassDB::bind_method(D_METHOD("set_rngDouble", "p_rng"), &WalkerProcGen::set_rngDouble);
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "rng_double"), "set_rngDouble", "get_rngDouble");

	// needRandom
	ClassDB::bind_method(D_METHOD("get_needRandom"), &WalkerProcGen::get_needRandom);
	ClassDB::bind_method(D_METHOD("set_needRandom", "p_status"), &WalkerProcGen::set_needRandom);
	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "need_random"), "set_needRandom", "get_needRandom");


	// methods
	ClassDB::bind_method(D_METHOD("walk", "p_steps"), &WalkerProcGen::Walk);
	ClassDB::bind_method(D_METHOD("step"), &WalkerProcGen::Step);
	ClassDB::bind_method(D_METHOD("change_direction"), &WalkerProcGen::ChangeDirection);
}

WalkerProcGen::WalkerProcGen()
{
	// Initialize any variables here.
	position = Vector2(0, 0);
	travelDirection = Vector2(1, 0);
	stepsSinceTurn = 0;
	borders = Rect2(1, 1, 80, 45);
	stepHistory = {};
	stepsSinceTurn = 0;

	rngRange = 0;
	rngDouble = 0.0;
	needRandom = true;
}


WalkerProcGen::~WalkerProcGen()
{
	// Add your cleanup here.
}

void WalkerProcGen::_process(double delta)
{

}

PackedVector2Array WalkerProcGen::Walk(int p_steps)
{

	for (int i = 0; i <= p_steps; i++)
	{
		if ((rngDouble <= TURN_CHANCE) || (stepsSinceTurn >= MAX_NON_TURNS))
		{
			needRandom = true;
			ChangeDirection();
		}

		if (Step())
		{
			stepHistory.append(position);
		}
		else
		{
			needRandom = true;
			ChangeDirection();
		}
	}
	

	return stepHistory;
}

bool WalkerProcGen::Step()
{
	Vector2 targetPos = position + travelDirection;

	if (borders.has_point(targetPos))
	{
		stepsSinceTurn += 1;
		position = targetPos;
		return true;
	}
	else
	{
		return false;
	}
}

bool WalkerProcGen::ChangeDirection()
{
	int count = 0;
	needRandom = true;

	stepsSinceTurn = 0;
	PackedVector2Array temp_directions = DIRECTIONS.duplicate();

	for (auto i : temp_directions)
	{
		if (i == travelDirection)
		{
			temp_directions.remove_at(count);
			break;
		}
		count++;
	}

	travelDirection = temp_directions[rngRange];
	temp_directions.remove_at(rngRange);
	

	while (!(borders.has_point(position + travelDirection)))
	{
		temp_directions.reverse();
		travelDirection = temp_directions[0];
		temp_directions.remove_at(0);
	}
	

	return true;
}


// getters & setters
#pragma region GetSet
Vector2 WalkerProcGen::get_position() const
{
	return position;
}

void WalkerProcGen::set_position(const Vector2 p_pos)
{
	position = p_pos;
}

Vector2 WalkerProcGen::get_travelDirection() const
{
	return travelDirection;
}

void WalkerProcGen::set_travelDirection(const Vector2 p_direction)
{
	travelDirection = p_direction;
}

Rect2 WalkerProcGen::get_borders() const
{
	return borders;
}

void WalkerProcGen::set_borders(const Rect2 p_box)
{
	borders = p_box;
}

PackedVector2Array WalkerProcGen::get_stepHistory() const
{
	return stepHistory;
}

void WalkerProcGen::set_stepHistory(const PackedVector2Array p_steps)
{
	stepHistory = p_steps;
}

int WalkerProcGen::get_stepsSinceTurn() const
{
	return stepsSinceTurn;
}

void WalkerProcGen::set_stepsSinceTurn(const int p_step)
{
	stepsSinceTurn = p_step;
}

int WalkerProcGen::get_rngRange() const
{
	return rngRange;
}

void WalkerProcGen::set_rngRange(const int p_rng)
{
	rngRange = p_rng;
}

double WalkerProcGen::get_rngDouble() const
{
	return rngDouble;
}

void WalkerProcGen::set_rngDouble(const double p_rng)
{
	rngDouble = p_rng;
}

bool WalkerProcGen::get_needRandom() const
{
	return needRandom;
}

void WalkerProcGen::set_needRandom(const bool p_status)
{
	needRandom = p_status;
}

#pragma endregion
