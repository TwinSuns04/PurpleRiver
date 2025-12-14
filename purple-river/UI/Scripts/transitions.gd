extends Control

class_name SceneTransitioner

@onready var animation_tex = $TextureRect
@onready var anim_player = $AnimationPlayer

func _ready() -> void:
	animation_tex.visible = false

func set_animation_type(fade_out : bool):
	print("set_anim")
	if(fade_out):
		anim_player.play("fade_out")
	else:
		anim_player.play("fade_in")


func _on_timer_two_timeout() -> void:
	pass # Replace with function body.
