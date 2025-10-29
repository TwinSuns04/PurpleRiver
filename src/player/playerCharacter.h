#ifndef PLAYERCHARACTER_H
#define PLAYERCHARACTER_H

#include <godot_cpp/classes/area2d.hpp>

namespace godot {

	class PlayerCharacter : public Area2D {
		GDCLASS(PlayerCharacter, Area2D)

	private:

		//Vector2 position; Use global transform pos for now
		Vector2 velocity;
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
		//Vector2 get_position() const;
		//void set_position(const Vector2 p_pos);
		Vector2 get_velocity() const;
		void set_velocity(const Vector2 p_velocity);
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