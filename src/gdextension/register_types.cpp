#include "register_types.h"

#include "gdexample.h"

// haiku system
#include "haiku/haikuSystem.h"
#include "haiku/haikuArea.h"

// map related
#include "map/riverArea.h"
#include "map/riverAreaCollision.h"
#include "map/tileMapLayerCurrent.h"
#include "map/tileSetCurrent.h"
//#include "map/flora/floraSpawner.h"
#include "map/levels/levelTemplate.h"
#include "map/procGen/procGenMap.h"
#include "map/procGen/walkerProcGen.h"

// mechanics related
#include "mechanics/leveling/foodItem.h"

// player related
#include "player/levelSystem.h"
#include "player/pcAdvancedController.h"
#include "player/pcArea.h"
#include "player/pcCamera.h"
#include "player/pcCollision.h"
#include "player/pcSprite.h"
#include "player/playerCharacter.h"
#include "player/playerCharacterPhysicsBase.h"
#include "player/testScons.h"

#include <gdextension_interface.h>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>

using namespace godot;

void initialize_example_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}

	GDREGISTER_RUNTIME_CLASS(GDExample);

	// haiku system related classes
	GDREGISTER_RUNTIME_CLASS(HaikuSystem);
	GDREGISTER_RUNTIME_CLASS(HaikuArea);

	// map related classes
	GDREGISTER_RUNTIME_CLASS(RiverArea);
	GDREGISTER_RUNTIME_CLASS(RiverAreaCollision)
	GDREGISTER_RUNTIME_CLASS(TileMapLayerCurrent);
	GDREGISTER_RUNTIME_CLASS(TileSetCurrent);
	//GDREGISTER_CLASS(FloraSpawner);
	GDREGISTER_RUNTIME_CLASS(LevelTemplate);
	GDREGISTER_RUNTIME_CLASS(ProcGenMap);
	GDREGISTER_RUNTIME_CLASS(WalkerProcGen);

	// mechanics related
	GDREGISTER_RUNTIME_CLASS(FoodItem);

	// player related
	GDREGISTER_RUNTIME_CLASS(LevelSystem);
	GDREGISTER_RUNTIME_CLASS(PCAdvancedController); // not in use
	GDREGISTER_RUNTIME_CLASS(PCArea);
	GDREGISTER_RUNTIME_CLASS(PCCamera);
	GDREGISTER_RUNTIME_CLASS(PCCollision);
	GDREGISTER_RUNTIME_CLASS(PCSprite);
	GDREGISTER_RUNTIME_CLASS(PlayerCharacter);
	GDREGISTER_RUNTIME_CLASS(PlayerCharacterCB2);
	GDREGISTER_CLASS(TestScons);
}

void uninitialize_example_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}
}

extern "C" {
// Initialization.
GDExtensionBool GDE_EXPORT example_library_init(GDExtensionInterfaceGetProcAddress p_get_proc_address, const GDExtensionClassLibraryPtr p_library, GDExtensionInitialization *r_initialization) {
	godot::GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);

	init_obj.register_initializer(initialize_example_module);
	init_obj.register_terminator(uninitialize_example_module);
	init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

	return init_obj.init();
}
}