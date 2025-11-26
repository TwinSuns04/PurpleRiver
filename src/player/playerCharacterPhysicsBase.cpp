#include "playerCharacterPhysicsBase.h"
#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void PlayerCharacterCB2::_bind_methods()
{
	/*
	// position
	ClassDB::bind_method(D_METHOD("get_position"), &PlayerCharacter::get_position);
	ClassDB::bind_method(D_METHOD("set_position", "p_pos"), &PlayerCharacter::set_position);
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "position"), "set_position", "get_position");
	

	// velocity
	ClassDB::bind_method(D_METHOD("get_playerVelocity"), &PlayerCharacterCB2::get_playerVelocity);
	ClassDB::bind_method(D_METHOD("set_playerVelocity", "p_velocity"), &PlayerCharacterCB2::set_playerVelocity);
	ADD_PROPERTY(PropertyInfo(Variant::VECTOR2, "player_velocity"), "set_playerVelocity", "get_playerVelocity");
	*/

	// playerLevel
	ClassDB::bind_method(D_METHOD("get_playerLevel"), &PlayerCharacterCB2::get_playerLevel);
	ClassDB::bind_method(D_METHOD("set_playerLevel", "p_level"), &PlayerCharacterCB2::set_playerLevel);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "playerLevel"), "set_playerLevel", "get_playerLevel");

	// playerHealth
	ClassDB::bind_method(D_METHOD("get_playerHealth"), &PlayerCharacterCB2::get_playerHealth);
	ClassDB::bind_method(D_METHOD("set_playerHealth", "p_health"), &PlayerCharacterCB2::set_playerHealth);
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "playerHealth"), "set_playerHealth", "get_playerHealth");

	// movementSpeed
	ClassDB::bind_method(D_METHOD("get_movementSpeedBase"), &PlayerCharacterCB2::get_movementSpeedBase);
	ClassDB::bind_method(D_METHOD("set_movementSpeedBase", "p_speed"), &PlayerCharacterCB2::set_movementSpeedBase);
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "movementSpeedBase"), "set_movementSpeedBase", "get_movementSpeedBase");
	ClassDB::bind_method(D_METHOD("get_movementSpeedMult"), &PlayerCharacterCB2::get_movementSpeedMult);
	ClassDB::bind_method(D_METHOD("set_movementSpeedMult", "p_mult"), &PlayerCharacterCB2::set_movementSpeedMult);
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "movementSpeedMult"), "set_movementSpeedMult", "get_movementSpeedMult");
	ClassDB::bind_method(D_METHOD("get_movementSpeed"), &PlayerCharacterCB2::get_movementSpeed);
	ClassDB::bind_method(D_METHOD("set_movementSpeed", "p_speed"), &PlayerCharacterCB2::set_movementSpeed);
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "movementSpeed"), "set_movementSpeed", "get_movementSpeed");

	// speedBoost mult, duration, status
	ClassDB::bind_method(D_METHOD("get_speedBoostMult"), &PlayerCharacterCB2::get_speedBoostMult);
	ClassDB::bind_method(D_METHOD("set_speedBoostMult", "p_boost"), &PlayerCharacterCB2::set_speedBoostMult);
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "speedBoostMult"), "set_speedBoostMult", "get_speedBoostMult");
	ClassDB::bind_method(D_METHOD("get_speedBoostDuration"), &PlayerCharacterCB2::get_speedBoostDuration);
	ClassDB::bind_method(D_METHOD("set_speedBoostDuration", "p_boost"), &PlayerCharacterCB2::set_speedBoostDuration);
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "boostDuration"), "set_speedBoostDuration", "get_speedBoostDuration");
	ClassDB::bind_method(D_METHOD("get_boostStatus"), &PlayerCharacterCB2::get_boostStatus);
	ClassDB::bind_method(D_METHOD("set_boostStatus", "p_status"), &PlayerCharacterCB2::set_boostStatus);
	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "boostStatus"), "set_boostStatus", "get_boostStatus");

	// staminaVal & staminaRegen
	ClassDB::bind_method(D_METHOD("get_staminaVal"), &PlayerCharacterCB2::get_staminaVal);
	ClassDB::bind_method(D_METHOD("set_staminaVal", "p_stamina"), &PlayerCharacterCB2::set_staminaVal);
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "staminaVal"), "set_staminaVal", "get_staminaVal");
	ClassDB::bind_method(D_METHOD("get_staminaRegenVal"), &PlayerCharacterCB2::get_staminaRegenVal);
	ClassDB::bind_method(D_METHOD("set_staminaRegenVal", "p_stamina"), &PlayerCharacterCB2::set_staminaRegenVal);
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "staminaRegenVal"), "set_staminaRegenVal", "get_staminaRegenVal");

	// foodEaten
	ClassDB::bind_method(D_METHOD("get_foodEaten"), &PlayerCharacterCB2::get_foodEaten);
	ClassDB::bind_method(D_METHOD("set_foodEaten", "p_val"), &PlayerCharacterCB2::set_foodEaten);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "foodEaten"), "set_foodEaten", "get_foodEaten");

	// positional river current custom data for tile sets
	ClassDB::bind_method(D_METHOD("get_positionalRCV"), &PlayerCharacterCB2::get_positionalRCV);
	ClassDB::bind_method(D_METHOD("set_positionalRCV", "p_val"), &PlayerCharacterCB2::set_positionalRCV);
	ADD_PROPERTY(PropertyInfo(Variant::VECTOR2, "positionalRCV"), "set_positionalRCV", "get_positionalRCV");
	ClassDB::bind_method(D_METHOD("get_positionalRCM"), &PlayerCharacterCB2::get_positionalRCM);
	ClassDB::bind_method(D_METHOD("set_positionalRCM", "p_mult"), &PlayerCharacterCB2::set_positionalRCM);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "positionalRCM"), "set_positionalRCM", "get_positionalRCM");
	ClassDB::bind_method(D_METHOD("get_positionalRCCS"), &PlayerCharacterCB2::get_positionalRCCS);
	ClassDB::bind_method(D_METHOD("set_positionalRCCS", "p_status"), &PlayerCharacterCB2::set_positionalRCCS);
	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "positionalRCCS"), "set_positionalRCCS", "get_positionalRCCS");

	// basisRotation
	ClassDB::bind_method(D_METHOD("get_basisRotation"), &PlayerCharacterCB2::get_basisRotation);
	ClassDB::bind_method(D_METHOD("set_basisRotation", "p_angle"), &PlayerCharacterCB2::set_basisRotation);
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "basisRotation"), "set_basisRotation", "get_basisRotation");
	

	// signals
	ADD_SIGNAL(MethodInfo("enteredRiverArea", PropertyInfo(Variant::OBJECT, "node"), PropertyInfo(Variant::STRING_NAME, "nodeName")));
	ADD_SIGNAL(MethodInfo("ate_food", PropertyInfo(Variant::OBJECT, "node"), PropertyInfo(Variant::STRING_NAME, "nodeName")));

	// methods
	// need to calculate new player speed based off custom tile data
	ClassDB::bind_method(D_METHOD("calc_river_velocity"), &PlayerCharacterCB2::CalcRiverVelocity);
	ClassDB::bind_method(D_METHOD("calc_basis_transform"), &PlayerCharacterCB2::CalcBasisTransform);
	ClassDB::bind_method(D_METHOD("level_up"), &PlayerCharacterCB2::LevelUp);
	ClassDB::bind_method(D_METHOD("eat_food"), &PlayerCharacterCB2::EatFood);
	ClassDB::bind_method(D_METHOD("regen_stamina", "p_val"), &PlayerCharacterCB2::RegenStamina);
}

PlayerCharacterCB2::PlayerCharacterCB2()
{
	// Initialize any variables here.
	//position = Vector2(0, 0);
	//velocity = Vector2(0, 0);
	playerLevel = 1;
	movementSpeedBase = 100;
	movementSpeedMult = 3.6;
	movementSpeed = movementSpeedBase * movementSpeedMult;
	speedBoostMult = 1.5;
	boostDuration = 50.0;
	boostStatus = false;
	staminaVal = 100;
	strengthVal = 1;
	foodEaten = 0;
	positionalRCV = Vector2i (0, 0);
	positionalRCM = 1;
	positionalRCCS = false;
	basisRotation = 0.0;
	UtilityFunctions::print("PlayerCharacterCB2 init");

}

PlayerCharacterCB2::~PlayerCharacterCB2()
{
	// Add your cleanup here.
}

void PlayerCharacterCB2::_process(double delta)
{
	//position = get_global_position();


	if (boostStatus)
	{
		DepleteStamina(1);
	}
	else
	{
		RegenStamina(1);
	}

}

bool PlayerCharacterCB2::is_on_wall() const
{
	return true;
}

Vector2i PlayerCharacterCB2::CalcRiverVelocity()
{
	Vector2i tempRiverVelocity = get_positionalRCV();
	int tempRiverMult = get_positionalRCM();
	tempRiverMult *= riverCurrentScaler;

	if (tempRiverVelocity != Vector2i(0, 0))
	{
		tempRiverVelocity *= tempRiverMult;
	}
	
	return tempRiverVelocity;
}

Vector2 PlayerCharacterCB2::CalcBasisTransform(double p_angle)
{
	Vector2 newVelocity = Vector2(0, 0);
	Vector2 playerVelocity = get_velocity();
	p_angle += (Math_PI / 4); // Angle offset for base sprite rotation

	double xPrime = (playerVelocity.x * (cos(p_angle))) + (playerVelocity.y * (sin(p_angle)));
	newVelocity.x = xPrime;
	double yPrime = (playerVelocity.y * (cos(p_angle))) - (playerVelocity.x * (sin(p_angle)));
	newVelocity.y = yPrime;

	return newVelocity;
}

void PlayerCharacterCB2::LevelUp()
{
	double tempMovementSpeedBase = get_movementSpeedBase();
	tempMovementSpeedBase *= speedScaler;
	set_movementSpeed(tempMovementSpeedBase);

	double tempSpeedBoostMult = get_speedBoostMult();
	tempSpeedBoostMult *= boostMultScaler;
	set_speedBoostMult(tempSpeedBoostMult);

	double tempBoostDuration = get_speedBoostDuration();
	tempBoostDuration *= boostDurationScaler;
	set_speedBoostDuration(tempBoostDuration);

	double tempStamina = get_staminaVal();
	tempStamina *= staminaScaler;
	set_staminaVal(tempStamina);

	double tempStaminaRegen = get_staminaRegenVal();
	tempStaminaRegen *= staminaScaler;
	set_staminaRegenVal(tempStaminaRegen);

	int tempStrength = get_strengthVal();
	tempStrength *= strengthScaler;
	set_strengthVal(tempStrength);

	int tempLevel = get_playerLevel();
	tempLevel++;
	set_playerLevel(tempLevel);
}

void PlayerCharacterCB2::EatFood(int p_val)
{
	int tempFood = get_foodEaten();
	tempFood += p_val;

	if (tempFood >= 100)
	{
		LevelUp();
		tempFood = 0;
	}

	RegenStamina(p_val);
	set_foodEaten(tempFood);
}

void PlayerCharacterCB2::RegenStamina(int p_val)
{
	if (staminaVal < 100)
	{
		staminaVal += p_val;
		if (staminaVal > 100)
		{
			staminaVal = 100;
		}
	}
}

void PlayerCharacterCB2::DepleteStamina(int p_val)
{
	if (staminaVal > 0)
	{
		staminaVal -= p_val;
	}
}

// getters & setters
#pragma region GetSet
// Position
/*
Vector2 PlayerCharacter::get_position() const
{
	return position;
}

void PlayerCharacter::set_position(const Vector2 p_pos)
{
	position = p_pos;
}

Vector2 PlayerCharacterCB2::get_playerVelocity() const
{
	return playerVelocity;
}

void PlayerCharacterCB2::set_playerVelocity(const Vector2 p_velocity)
{
	playerVelocity = p_velocity;
}
*/

int PlayerCharacterCB2::get_playerLevel() const
{
	return playerLevel;
}

void PlayerCharacterCB2::set_playerLevel(const int p_level)
{
	playerLevel = p_level;
}

int PlayerCharacterCB2::get_playerHealth() const
{
	return playerHealth;
}

void PlayerCharacterCB2::set_playerHealth(const int p_Health)
{
	playerHealth = p_Health;
}

double PlayerCharacterCB2::get_movementSpeedBase() const
{
	return movementSpeedBase;
}

void PlayerCharacterCB2::set_movementSpeedBase(const double p_speed)
{
	movementSpeedBase = p_speed;
}

double PlayerCharacterCB2::get_movementSpeedMult() const
{
	return movementSpeedMult;
}

void PlayerCharacterCB2::set_movementSpeedMult(const double p_mult)
{
	movementSpeedMult = p_mult;
}

double PlayerCharacterCB2::get_movementSpeed() const
{
	return movementSpeed;
}

void PlayerCharacterCB2::set_movementSpeed(const double p_speed)
{
	movementSpeed = p_speed;
}

double PlayerCharacterCB2::get_speedBoostMult() const
{
	return speedBoostMult;
}

void PlayerCharacterCB2::set_speedBoostMult(const double p_boost)
{
	speedBoostMult = p_boost;
}

double PlayerCharacterCB2::get_speedBoostDuration() const
{
	return boostDuration;
}

void PlayerCharacterCB2::set_speedBoostDuration(const double p_boost)
{
	boostDuration = p_boost;
}

bool PlayerCharacterCB2::get_boostStatus() const
{
	return boostStatus;
}

void PlayerCharacterCB2::set_boostStatus(const bool p_status)
{
	boostStatus = p_status;
}

double PlayerCharacterCB2::get_staminaVal() const
{
	return staminaVal;
}

void PlayerCharacterCB2::set_staminaVal(const double p_stamina)
{
	staminaVal = p_stamina;
}

double PlayerCharacterCB2::get_staminaRegenVal() const
{
	return staminaRegenVal;
}

void PlayerCharacterCB2::set_staminaRegenVal(const double p_stamina)
{
	staminaRegenVal = p_stamina;
}

int PlayerCharacterCB2::get_strengthVal() const
{
	return strengthVal;
}

void PlayerCharacterCB2::set_strengthVal(const int p_strength)
{
	strengthVal = p_strength;
}

int PlayerCharacterCB2::get_foodEaten() const 
{
	return foodEaten;
}

void PlayerCharacterCB2::set_foodEaten(const int p_val)
{
	foodEaten = p_val;
}

Vector2i PlayerCharacterCB2::get_positionalRCV() const
{
	return positionalRCV;
}

void PlayerCharacterCB2::set_positionalRCV(const Vector2i p_vector)
{
	positionalRCV = p_vector;
}

int PlayerCharacterCB2::get_positionalRCM() const
{
	return positionalRCM;
}

void PlayerCharacterCB2::set_positionalRCM(const int p_mult)
{
	positionalRCM = p_mult;
}

bool PlayerCharacterCB2::get_positionalRCCS() const
{
	return positionalRCCS;
}

void PlayerCharacterCB2::set_positionalRCCS(const bool p_status)
{
	positionalRCCS = p_status;
}

double PlayerCharacterCB2::get_basisRotation() const
{
	return basisRotation;
}

void PlayerCharacterCB2::set_basisRotation(const double p_angle)
{
	basisRotation = p_angle;
}

#pragma endregion
