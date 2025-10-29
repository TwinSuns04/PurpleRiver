#ifndef TILEMAPLAYERCURRENT_H
#define TILEMAPLAYERCURRENT_H

#include <godot_cpp/classes/tile_map_layer.hpp>


namespace godot {

	class TileMapLayerCurrent : public TileMapLayer {
		GDCLASS(TileMapLayerCurrent, TileMapLayer)

	private:
		Vector2 riverCurrentVector;
		int rCurrentMult;
		bool collisionStatus;

	protected:
		static void _bind_methods();

	public:
		TileMapLayerCurrent();
		~TileMapLayerCurrent();
		

		void _process(double delta) override;

		// getters & setters
		Vector2 get_riverCurrentVector() const;
		void set_riverCurrentVector(const Vector2 p_vector);
		int get_rCurrentMult() const;
		void set_rCurrentMult(const int p_mult);
		bool get_collisionStatus() const;
		void set_collisionStatus(const bool p_status);

		void ApplyRiverCurrent();
	};

}

#endif