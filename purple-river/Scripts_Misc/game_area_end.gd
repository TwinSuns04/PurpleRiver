extends Area2D

@export var transitioner : SceneTransitioner
@onready var timer_one : Timer = $Timer_One
@onready var timer_two : Timer = $Timer_Two

func _on_area_entered(area: Area2D) -> void:
	print("end game area entered")
	timer_one.start(2.0)


func _on_timer_one_timeout() -> void:
	transitioner.set_animation_type(true)
	timer_two.start(4.0)


func _on_timer_two_timeout() -> void:
	transitioner.set_animation_type(false)
