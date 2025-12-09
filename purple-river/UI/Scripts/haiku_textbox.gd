extends CanvasLayer

@onready var tb_ref : MarginContainer = $Textbox_Container
@onready var start_symbol : Label = $Textbox_Container/MarginContainer/HBoxContainer/Start_Text
@onready var haiku_text : RichTextLabel = $Textbox_Container/MarginContainer/HBoxContainer/Haiku_Text
@onready var end_symbol : Label = $Textbox_Container/MarginContainer/HBoxContainer/End_Text

func _ready() -> void:
	start_symbol.text = "--"
	haiku_text.text = ""
	end_symbol.text = "--"
	hide_textbox()

func show_textbox(p_haiku_info : Array) -> void:
	for line in p_haiku_info:
		haiku_text.append_text(line)
	tb_ref.show()

func hide_textbox() -> void:
	tb_ref.hide()
	reset_textbox()

func reset_textbox() -> void:
	haiku_text.text = ""
