extends Node

@export var map_scene: PackedScene

# Called when the node enters the scene tree for the first time.
func _ready() -> void:
	randomize()
	#$PlayerCharacterCB2.scale = Vector2(0.08, 0.08)


# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta: float) -> void:
	pass
