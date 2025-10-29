extends Node2D

@onready var tileMap = $TileMapLayer_Walker

var borders_map = Rect2(1, 1, 200, 112)

# Called when the node enters the scene tree for the first time.
func _ready() -> void:
	randomize()
	generate_walker_map()


# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(_delta: float) -> void:
	pass

func generate_walker_map():
	var walker = WalkerPG.new(Vector2(20, 20), borders_map)
	var map = walker.walk(500)
	walker.queue_free()
	var map_cells = []
	for location in map:
		map_cells.append(location)
	tileMap.set_cells_terrain_connect(map_cells, 0, 1, 0)
