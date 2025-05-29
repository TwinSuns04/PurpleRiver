#ifndef PLAYERCHARACTER_H
#define PLAYERCHARACTER_H

#include <godot_cpp/classes/character_body2d.hpp>

namespace godot {

	class PlayerCharacter : public CharacterBody2D {
		GDCLASS(PlayerCharacter, CharacterBody2D)

	private:

		double timePassed;
		Vector2 pcPosition;
		Vector2 pcVelocity;
		double movementSpeedBase;
		double movementSpeed;
		double speedBoostMult;
		double amplitude;
		
		

	protected:
		static void _bind_methods();

	public:
		PlayerCharacter();
		~PlayerCharacter();
		void _process(double delta) override;

		// getters and setters
		Vector2 get_pcPosition() const;
		void set_pcPosition(const Vector2 p_pos);
		Vector2 get_pcVelocity() const;
		void set_pcVelocity(const Vector2 p_velocity);
		double get_movementSpeedBase() const;
		void set_movementSpeedBase(const double p_speed);
		double get_movementSpeed() const;
		void set_movementSpeed(const double p_speed);
		double get_speedBoostMult() const;
		void set_speedBoostMult(const double p_boost);
		
		void set_amplitude(const double p_amplitude);
		double get_amplitude() const;

	};

}

#endif