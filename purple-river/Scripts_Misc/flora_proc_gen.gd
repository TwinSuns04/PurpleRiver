extends Node2D

@export var noise_height_texture : NoiseTexture2D
@onready var tile_map = $TileMapLayer

var noise : Noise
var width : int = 100
var height : int = 100
var source_id = 1
var kiku_atlas = Vector2i(0, 0)
var momiji_atlas = Vector2i(0, 1)
var sakura_atlas = Vector2i(0, 2)

func _ready():
	noise = noise_height_texture.noise
	generate_world()
	
func generate_world():
	for i in range(width):
		for j in range(height):
			var noise_val = noise.get_noise_2d(i,j)
			if noise_val > 0.0:
				#place flower
				tile_map.set_cell(Vector2i(i,j), source_id)
				
