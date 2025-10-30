#ifndef TILESETCURRENT_H
#define TILESETCURRENT_H

#include <godot_cpp/classes/tile_set.hpp>

namespace godot {

	class TileSetCurrent : public TileSet {
		GDCLASS(TileSetCurrent, TileSet)

	private:
		Vector2 riverCurrentVector;
		int rCurrentMult;
		bool collisionStatus;
		String rCV = "riverCurrentVector";
		String rCM = "riverCurrentMultiplier";
		String rTCS = "riverTileCollisionStatus";
		const Vector2i tileSize = Vector2i(32, 32);

	protected:
		static void _bind_methods();

	public:
		TileSetCurrent();
		~TileSetCurrent();

		// getters & setters
		Vector2 get_riverCurrentVector() const;
		void set_riverCurrentVector(const Vector2 p_vector);
		int get_rCurrentMult() const;
		void set_rCurrentMult(const int p_mult);
		bool get_collisionStatus() const;
		void set_collisionStatus(const bool p_status);

		void ApplyRiverCurrent();
		void CreateCustomDataLayer(int p_index, String p_name, Variant::Type p_type);
		
	};

}

#endif