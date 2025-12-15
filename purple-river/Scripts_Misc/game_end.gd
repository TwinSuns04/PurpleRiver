extends Node

@onready var game_credits = $Game_Credits/Control
@onready var timer_credits = $Timer_Credits
@onready var river_anim = $level_nine_b/RiverCurrentAnim

func _ready() -> void:
	game_credits.visible = false
	timer_credits.start(4.0)


func _on_timer_credits_timeout() -> void:
	print("timer")
	game_credits.visible = true
