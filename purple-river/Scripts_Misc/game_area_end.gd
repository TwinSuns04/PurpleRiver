extends Area2D

@export var transitioner : SceneTransitioner
@onready var timer_one : Timer = $Timer_One

func _on_area_entered(area: Area2D) -> void:
	print("end game area entered")
	timer_one.start(2.0)


func _on_timer_one_timeout() -> void:
	print("t1")
	transitioner.set_animation_type(true)
