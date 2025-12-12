extends Node

class_name GameManager

@onready var game_soundtrack : AudioStreamPlayer2D = $Music/Soundtrack

var audio_evening_calm : AudioStreamMP3

#@export var map_scene: PackedScene
signal toggle_game_paused(is_paused : bool)
@export var pause_status : bool = false:
	get:
		return pause_status
	set(p_status):
		pause_status = p_status
		get_tree().paused = pause_status
		emit_signal("toggle_game_paused", pause_status)

# Called when the node enters the scene tree for the first time.
func _ready() -> void:
	game_soundtrack.bus = "Soundtrack"
	game_soundtrack.play(0.0)
	randomize()
	#$PlayerCharacterCB2.scale = Vector2(0.08, 0.08)

func _input(event: InputEvent) -> void:
	if(event.is_action_pressed("Escape")):
		print("pause event")
		pause_status = !pause_status

# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta: float) -> void:
	pass
