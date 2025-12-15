extends Control

class_name MainMenu

@onready var mm_button_container: VBoxContainer = $"MM-ButtonContainer"
@onready var options_sub_menu: Panel = $Options_Sub_Menu
@onready var back_button: Button = $Options_Sub_Menu/Options_ButtonContainer/Back_Button
@onready var volume_button: Button = $Options_Sub_Menu/Options_ButtonContainer/Volume_Button
@onready var credits_button: Button = $Options_Sub_Menu/Options_ButtonContainer/Credits_Button
@onready var volume_sub_menu: Panel = $Volume_Sub_Menu
@onready var volume_label: Label = $Volume_Sub_Menu/Volume_Label
@onready var game_credits: Node = $Game_Credits_Node/Control
@onready var music: AudioStreamPlayer = $Music/Soundtrack

signal toggle_game_start(is_running : bool)
@export var start_status : bool = false:
	get:
		return start_status
	set(p_status):
		start_status = p_status
		emit_signal("toggle_game_start", start_status)

# Called when the node enters the scene tree for the first time.
func _ready() -> void:
	mm_button_container.visible = true
	options_sub_menu.visible = false
	volume_sub_menu.visible = false
	game_credits.visible = false
	music.play(0.0)

# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta: float) -> void:
	pass

func _on_start_button_pressed():
	print("start button pressed")
	music.stop()
	#Global.scene_manager.change_world2d_scene("res://Scenes_Misc/game.tscn")
	get_tree().change_scene_to_file("res://Scenes_Misc/game.tscn")

func _on_options_button_pressed():
	print("options button pressed")
	mm_button_container.visible = false
	options_sub_menu.visible = true
	volume_sub_menu.visible = false
	game_credits.visible = false

func _on_quit_button_pressed():
	print("quit button pressed")
	get_tree().quit()


func _on_back_button_pressed() -> void:
	mm_button_container.visible = true
	options_sub_menu.visible = false
	volume_sub_menu.visible = false

func _on_credits_button_pressed() -> void:
	print("Credits")
	game_credits.visible = true
	options_sub_menu.visible = false


func _on_volume_button_pressed() -> void:
	print("Volume Settings")
	options_sub_menu.visible = false
	volume_sub_menu.visible = true

func _on_back_button_2_pressed() -> void:
	print("Back2 button")
	_on_options_button_pressed()


func _on_back_button_3_pressed() -> void:
	options_sub_menu.visible = true
	volume_sub_menu.visible = false


func _input(event: InputEvent) -> void:
	if(event.is_action_pressed("Escape")):
		if(mm_button_container.visible):
			_on_quit_button_pressed()
		elif(options_sub_menu.visible):
			_on_back_button_pressed()
		elif(volume_sub_menu.visible):
			_on_back_button_3_pressed()
		elif(game_credits.visible):
			_on_options_button_pressed()
		else:
			_on_back_button_pressed()
	
