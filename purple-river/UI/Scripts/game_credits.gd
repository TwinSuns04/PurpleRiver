extends Node

const FILE_PATH : String = "res://credits.txt"
var file
var game_credits : Array

@onready var ctrl : Control = $Control
@onready var rtl : RichTextLabel = $Control/RichTextLabel

func _ready() -> void:
	var file_exits : bool = FileAccess.file_exists(FILE_PATH)
	if (file_exits):
		print("file exists")
		load_from_file()
		read_file()
		display_file()

func load_from_file():
	file = FileAccess.open(FILE_PATH, FileAccess.READ)

func read_file():
	while file.get_position() < file.get_length():
		game_credits.append(file.get_line())

func display_file():
	for c in game_credits:
		
		if (c == ""):
			c = "\n\n"
		rtl.append_text(c)
