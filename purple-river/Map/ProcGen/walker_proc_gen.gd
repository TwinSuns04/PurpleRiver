extends WalkerProcGen
class_name WalkerPG

@onready var tml = $TileMapLayer

# Called when the node enters the scene tree for the first time.
func _ready() -> void:
	print("Walker Proc Gen")


# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(_delta: float):
	print("walkerpg process")
	if(need_random == true):
		print("if need random")
		gen_rng_range()
		gen_rng_double()

func _init(starting_pos, new_border):
	print("walkerpg init")
	assert(new_border.has_point(starting_pos))
	position = starting_pos
	print("pos: ", position)
	step_history.append(position)
	borders = new_border
	need_random = true
	print("need_random: ", need_random)

func gen_rng_range():
	var temp_rng = randi_range(0, 2)
	rng_range = temp_rng
	need_random = false
	print("gen_rng_range()")

func gen_rng_double():
	var temp_rng = randf()
	rng_double = temp_rng
	need_random = false
	print("gen_rng_double()")
