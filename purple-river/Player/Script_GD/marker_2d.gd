extends Marker2D


# Called when the node enters the scene tree for the first time.
func _ready() -> void:
	global_rotation = get_angle_to(get_global_mouse_position())


# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta: float) -> void:
	look_at(get_global_mouse_position())
	$"..".basisRotation = global_rotation
