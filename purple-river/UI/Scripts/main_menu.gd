extends Control

@onready var mm_button_container: VBoxContainer = $"MM-ButtonContainer"
@onready var options_sub_menu: Panel = $Options_Sub_Menu
@onready var back_button: Button = $Options_Sub_Menu/Options_ButtonContainer/Back_Button
@onready var volume_button: Button = $Options_Sub_Menu/Options_ButtonContainer/Volume_Button
@onready var credits_button: Button = $Options_Sub_Menu/Options_ButtonContainer/Credits_Button
@onready var volume_sub_menu: Panel = $Volume_Sub_Menu
@onready var volume_label: Label = $Volume_Sub_Menu/Volume_Label


# Called when the node enters the scene tree for the first time.
func _ready() -> void:
	mm_button_container.visible = true
	options_sub_menu.visible = false
	volume_sub_menu.visible = false

# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta: float) -> void:
	pass


func _on_start_button_pressed():
	print("start button pressed")
	#Global.scene_manager.change_world2d_scene("res://Scenes_Misc/game.tscn")
	get_tree().change_scene_to_file("res://Scenes_Misc/game.tscn")


func _on_options_button_pressed():
	print("options button pressed")
	mm_button_container.visible = false
	options_sub_menu.visible = true
	volume_sub_menu.visible = false

func _on_quit_button_pressed():
	print("quit button pressed")
	get_tree().quit()


func _on_back_button_pressed() -> void:
	mm_button_container.visible = true
	options_sub_menu.visible = false
	volume_sub_menu.visible = false

func _on_credits_button_pressed() -> void:
	print("Credits")


func _on_volume_button_pressed() -> void:
	print("Volume Settings")
	options_sub_menu.visible = false
	volume_sub_menu.visible = true

func _on_back_button_2_pressed() -> void:
	print("Back2 button")
	_on_options_button_pressed()
