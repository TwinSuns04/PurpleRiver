#ifndef PROCGENMAP_H
#define PROCGENMAP_H

#include <godot_cpp/classes/node2d.hpp>


namespace godot {

	class ProcGenMap : public Node2D {
		GDCLASS(ProcGenMap, Node2D)

	private:
		Vector2i mapSize;
		int noiseSeedVal;


		const int noiseSeedValConst = 100;
		const double waterCap = 0.8;

	protected:
		static void _bind_methods();

	public:
		ProcGenMap();
		~ProcGenMap();
		void _process(double delta) override;

		void GenerateMap();

		// getters & setters
		Vector2i get_mapSize() const;
		void set_mapSize(Vector2i const p_size);
		int get_noiseSeedVal() const;
		void set_noiseSeedVal(int const p_noise);
	};

}

#endif