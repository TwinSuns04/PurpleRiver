extends Control

@onready var mm_button_containter: VBoxContainer = $"MM-ButtonContainter"
@onready var options_sub_menu: Panel = $Options_Sub_Menu


# Called when the node enters the scene tree for the first time.
func _ready() -> void:
	mm_button_containter.visible = true
	options_sub_menu.visible = false


# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta: float) -> void:
	pass


func _on_start_button_pressed():
	print("start button pressed")
	get_tree().change_scene_to_file("res://Scenes_Misc/game.tscn")


func _on_options_button_pressed():
	print("options button pressed")
	mm_button_containter.visible = false
	options_sub_menu.visible = true


func _on_quit_button_pressed():
	print("quit button pressed")
	get_tree().quit()


func _on_back_button_pressed() -> void:
	mm_button_containter.visible = true
	options_sub_menu.visible = false
