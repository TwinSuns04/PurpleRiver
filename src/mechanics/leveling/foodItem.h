#ifndef FOODITEM_H
#define FOODITEM_H

#include <godot_cpp/classes/area2d.hpp>

namespace godot {

	class FoodItem : public Area2D {
		GDCLASS(FoodItem, Area2D)

	private:
		String foodName;
		int foodVal;
		bool isEaten;

	protected:
		static void _bind_methods();

	public:
		FoodItem();
		~FoodItem();
		void _process(double delta) override;

		// getters & setters
		String get_foodName() const;
		void set_foodName(String const p_name);
		int get_foodVal() const;
		void set_foodVal(const int p_val);
		bool get_isEaten() const;
		void set_isEaten(const bool p_val);
	};

}

#endif
