#ifndef LEVELTEMPLATE_H
#define LEVELTEMPLATE_H

#include <godot_cpp/classes/node2d.hpp>

namespace godot {

	class LevelTemplate : public Node2D {
		GDCLASS(LevelTemplate, Node2D)

	private:
		int levelNum;

	protected:
		static void _bind_methods();

	public:
		LevelTemplate();
		~LevelTemplate();

		void _process(double delta) override;

		// getters & setters
		int get_levelNum() const;
		void set_levelNum(const int p_num);
	};

}

#endif