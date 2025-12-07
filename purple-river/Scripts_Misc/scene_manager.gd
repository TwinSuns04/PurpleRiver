class_name SceneManager extends Node

@export var world_2d : Node2D
@export var gui : Control

var current_2D_scene
var current_gui_scene

func _ready() -> void:
	Global.scene_manager = self
	current_gui_scene = $GUI/Main_Menu

func change_gui_scene(p_scene: String, p_delete: bool = true, p_keep_running: bool = false) -> void:
	if(current_gui_scene != null):
		if (p_delete):
			current_gui_scene.queue_free()
		elif (p_keep_running):
			current_gui_scene.visible = false
		else:
			gui.remove_child(current_gui_scene)
		
	var new_scene = load(p_scene)
	gui.add_child(new_scene)
	current_gui_scene = new_scene

func change_world2d_scene(p_scene: String, p_delete: bool = true, p_keep_running: bool = false) -> void:
	if(current_2D_scene != null):
		if (p_delete):
			current_2D_scene.queue_free()
		elif (p_keep_running):
			current_2D_scene.visible = false
		else:
			world_2d.remove_child(current_2D_scene)
	
	var new_scene = load(p_scene).instantiate()
	world_2d.add_child(new_scene)
	current_2D_scene = new_scene
