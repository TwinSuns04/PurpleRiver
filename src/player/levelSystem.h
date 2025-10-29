// NOT IN USE
#ifndef LEVELSYSTEM_H
#define LEVELSYSTEM_H

#include <godot_cpp/classes/node.hpp>

namespace godot {

	class LevelSystem : public Node {
		GDCLASS(LevelSystem, Node)

	private:
		int playerLevel;
		double const speedScaler = 1.10;
		double const boostScaler = 1.25;



	protected:
		static void _bind_methods();

	public:
		LevelSystem();
		~LevelSystem();
		void _process(double delta) override;

		void LevelUp();

		// getters & setters
		int get_playerLevel() const;
		void set_playerLevel(const int p_level);
	};

}

#endif
