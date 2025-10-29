extends ProcGenMap

@onready var tm_layer = $TileMapLayer

const WATER_CAP = 0.6

# Called when the node enters the scene tree for the first time.
func _ready():
	gen_map_gd()


# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta: float) -> void:
	pass

func gen_map_gd() -> void:
	var noise = FastNoiseLite.new()
	noise.seed = 44 #randi() eventually after test
	
	var cells = []
	for x in mapSize.x:
		for y in mapSize.y:
			var temp_val = noise.get_noise_2d(x,y)
			if temp_val < WATER_CAP:
				cells.append(Vector2(x, y))
			else:
				tm_layer.set_cell(Vector2(x, y), 1, Vector2(1, 0), 0)
	
	tm_layer.set_cells_terrain_connect(cells, 0, 0, 0)
