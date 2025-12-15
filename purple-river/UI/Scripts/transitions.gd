extends Control

class_name SceneTransitioner

@onready var animation_tex = $TextureRect
@onready var anim_player = $AnimationPlayer
@onready var timer_two = $Game_End_Area/Timer_Two
@export var game_end_scene : PackedScene

func _ready() -> void:
	animation_tex.visible = false


func set_animation_type(fade_out : bool):
	print("set_anim")
	if(fade_out):
		anim_player.play("fade_out")
	else:
		anim_player.play("fade_in")

func _on_animation_player_animation_finished(anim_name: StringName) -> void:
	if((anim_name == "fade_out") && (game_end_scene != null)):
		timer_two.start(4.0)

func _on_timer_two_timeout() -> void:
	get_tree().change_scene_to_packed(game_end_scene)
