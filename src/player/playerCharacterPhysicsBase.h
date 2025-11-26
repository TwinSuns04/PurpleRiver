#ifndef PLAYERCHARACTERPHYSICSBASE_H
#define PLAYERCHARACTERPHYSICSBASE_H

// Class based of CharacterBody2D class which is physics based, not input based

#include <godot_cpp/classes/character_body2d.hpp>
#include <godot_cpp/classes/tile_data.hpp>
#include "pcSprite.h"

namespace godot {

	class PlayerCharacterCB2 : public CharacterBody2D {
		GDCLASS(PlayerCharacterCB2, CharacterBody2D)

	private:
		//Vector2 position;
		//Vector2 playerVelocity;
		int playerLevel;
		double playerHealth;
		double movementSpeedBase;
		double movementSpeedMult;
		double movementSpeed;
		double speedBoostMult;
		double boostDuration;
		bool boostStatus;
		double staminaVal;
		double staminaRegenVal;
		int strengthVal;
		int foodEaten;
		bool levelUp;
		Vector2i positionalRCV;
		int positionalRCM;
		bool positionalRCCS;
		double basisRotation;


		double const speedScaler = 1.10;
		double const boostMultScaler = 1.25;
		double const boostDurationScaler = 1.10;
		double const staminaScaler = 1.10;
		int const strengthScaler = 2;
		int const riverCurrentScaler = 50;
		

	protected:
		static void _bind_methods();

	public:
		PlayerCharacterCB2();
		~PlayerCharacterCB2();
		void _process(double delta) override;
		bool is_on_wall() const;

		Vector2i CalcRiverVelocity();
		Vector2 CalcBasisTransform(double p_angle);
		void LevelUp();
		void EatFood(int p_val);
		void RegenStamina(int p_val);
		void DepleteStamina(int p_val);

		// getters and setters
		//Vector2 get_position() const;
		//void set_position(const Vector2 p_pos);
		//Vector2 get_playerVelocity() const;
		//void set_playerVelocity(const Vector2 p_velocity);
		int get_playerLevel() const;
		void set_playerLevel(const int p_level);
		int get_playerHealth() const;
		void set_playerHealth(const int p_health);
		double get_movementSpeedBase() const;
		void set_movementSpeedBase(const double p_speed);
		double get_movementSpeedMult() const;
		void set_movementSpeedMult(const double p_mult);
		double get_movementSpeed() const;
		void set_movementSpeed(const double p_speed);
		double get_speedBoostMult() const;
		void set_speedBoostMult(const double p_boost);
		double get_speedBoostDuration() const;
		void set_speedBoostDuration(const double p_boost);
		bool get_boostStatus() const;
		void set_boostStatus(const bool p_status);
		double get_staminaVal() const;
		void set_staminaVal(const double p_stamina);
		double get_staminaRegenVal() const;
		void set_staminaRegenVal(const double p_stamina);
		int get_strengthVal() const;
		void set_strengthVal(const int p_strength);
		int get_foodEaten() const;
		void set_foodEaten(const int p_val);
		bool get_levelUp() const;
		void set_levelUp(const bool p_status);
		Vector2i get_positionalRCV() const;
		void set_positionalRCV(const Vector2i p_vector);
		int get_positionalRCM() const;
		void set_positionalRCM(const int p_mult);
		bool get_positionalRCCS() const;
		void set_positionalRCCS(const bool p_status);
		double get_basisRotation() const;
		void set_basisRotation(const double p_angle);
		

	};

}

#endif