extends Control

func resume():
	get_tree().paused = false

func pause():
	get_tree().paused = true

func testEscape():
	if Input.is_action_just_pressed("Escape") and !get_tree().paused:
		pause()
	elif Input.is_action_just_pressed("Escape") and get_tree().paused:
		resume()

func _on_quit_button_pressed() -> void:
	get_tree().change_scene_to_file("res://UI/Scenes/main_menu.tscn")


func _on_settings_button_pressed() -> void:
	print("In-game settings menu")


func _on_resume_button_pressed() -> void:
	resume()
