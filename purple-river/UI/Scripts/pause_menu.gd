extends Control

@export var game_manager : GameManager
@export var player_char : PlayerCharacterCB2

@onready var volume_sub_menu = $Panel/Volume_Sub_Menu

func _ready() -> void:
	hide()
	volume_sub_menu.visible = false
	game_manager.connect("toggle_game_paused", _on_game_manager_toggle_game_paused)

func _on_game_manager_toggle_game_paused(is_paused : bool):
	print("signal")
	if(is_paused):
		show()
		position = player_char.position
	else:
		hide()


func _on_resume_button_pressed() -> void:
	game_manager.pause_status = false


func _on_quit_button_pressed() -> void:
	get_tree().quit()


func _on_volume_button_pressed() -> void:
	volume_sub_menu.visible = true


func _on_back_button_2_pressed() -> void:
	volume_sub_menu.visible = false
