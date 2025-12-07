class_name AnimationComponent extends Node

@export var from_center : bool = true
@export var time : float = 0.1
@export var base_color := Color.hex(0x433753)
@export var new_color := Color.hex(0xffb7c5)
@export var transition_type : Tween.TransitionType

var target : Control
var default_scale : Vector2
var color_change : Color

func _ready() -> void:
	target = get_parent()
	connect_signals()
	call_deferred("setup")

func connect_signals() -> void:
	target.mouse_entered.connect(on_hover)
	target.mouse_exited.connect(off_hover)


func setup() -> void:
	if from_center:
		target.pivot_offset = target.size / 2
	
	default_scale = target.scale

func _process(delta: float) -> void:
	pass

func on_hover() -> void:
	color_change = new_color

func off_hover() -> void:
	color_change = base_color

func add_tween(property: String, value, seconds: float) -> void:
	var tween = get_tree().create_tween()
	tween.tween_property(target, property, value, seconds).set_trans(transition_type)
