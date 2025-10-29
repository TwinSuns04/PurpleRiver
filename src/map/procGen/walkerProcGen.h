#ifndef WALKERPROCGEN_H
#define WALKERPROCGEN_H

#include <godot_cpp/classes/node2d.hpp>


namespace godot {

	class WalkerProcGen : public Node2D {
		GDCLASS(WalkerProcGen, Node2D)

	private:
		PackedVector2Array DIRECTIONS = { Vector2(1, 0), Vector2(0, 1), Vector2(-1, 0), Vector2(0, -1) };
		const int MAX_NON_TURNS = 8; // number of steps without a turn maximum
		const double TURN_CHANCE = 0.20; // chance to change direction while Walk() is executing
		
		Vector2 position;
		Vector2 travelDirection;
		Rect2 borders;
		PackedVector2Array stepHistory;
		int stepsSinceTurn;

		int rngRange;
		double rngDouble;
		bool needRandom;

	protected:
		static void _bind_methods();

	public:
		WalkerProcGen();
		~WalkerProcGen();
		void _process(double delta) override;
		

		PackedVector2Array Walk(int p_steps);
		bool Step();
		bool ChangeDirection();

		Vector2 get_position() const;
		void set_position(Vector2 const p_pos);
		Vector2 get_travelDirection() const;
		void set_travelDirection(const Vector2 p_direction);
		Rect2 get_borders() const;
		void set_borders(const Rect2 p_box);
		PackedVector2Array get_stepHistory() const;
		void set_stepHistory(const PackedVector2Array p_steps);
		int get_stepsSinceTurn() const;
		void set_stepsSinceTurn(const int p_step);
		int get_rngRange() const;
		void set_rngRange(const int p_rng);
		double get_rngDouble() const;
		void set_rngDouble(const double p_rng);
		bool get_needRandom() const;
		void set_needRandom(const bool p_status);
	};

}

#endif