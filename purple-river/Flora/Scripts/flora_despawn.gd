extends Area2D

func _ready() -> void:
	pass

func _on_body_entered(body: Node2D) -> void:
	print("flora despawn")
	
	var groups := body.get_groups()
	
	for g in groups:
		if(g.contains("Flora")):
			body.queue_free()


func _on_body_shape_entered(body_rid: RID, body: Node2D, body_shape_index: int, local_shape_index: int) -> void:
	print("flora despawn body shape")
	
	var groups := body.get_groups()
	
	for g in groups:
		if(g.contains("Flora")):
			body.queue_free()


func _on_area_entered(area: Area2D) -> void:
	print("area entered")
	var body_ref = area.get_parent()
	var groups := body_ref.get_groups()
	
	for g in groups:
		if(g.contains("Flora")):
			body_ref.queue_free()
