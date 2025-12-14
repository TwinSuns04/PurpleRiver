extends Control

class_name SceneTransitioner

@onready var animation_tex = $TextureRect
@onready var anim_player = $AnimationPlayer
@export var game : GameManager
@export var load_credits_scene : PackedScene

func _ready() -> void:
	animation_tex.visible = false
	load_credits_scene = load("res://UI/Scenes/game_credits.tscn")

func set_animation_type(fade_out : bool):
	print("set_anim")
	if(fade_out):
		anim_player.play("fade_out")
	else:
		anim_player.play("fade_in")

func _on_animation_player_animation_finished(anim_name: StringName) -> void:
	#if((anim_name == "fade_out") && (load_credits_scene != null)):
		#var credits_instance = load_credits_scene.instantiate()
		#game.add_child(credits_instance )
	pass
