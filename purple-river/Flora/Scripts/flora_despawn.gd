extends Area2D

func _ready() -> void:
	pass

func _on_area_entered(area: Area2D) -> void:
	var body_ref = area.get_parent()
	var groups := body_ref.get_groups()
	
	for g in groups:
		if(g.contains("Flora")):
			body_ref.queue_free()
