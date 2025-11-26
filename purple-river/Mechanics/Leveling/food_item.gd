extends FoodItem

# Called when the node enters the scene tree for the first time.
func _ready() -> void:
	food_val = 20
	pass


# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta: float) -> void:
	pass



func _on_body_entered(body: Node2D) -> void:
	if is_eaten:
		pass
		
	var playerRef: CharacterBody2D = get_tree().get_first_node_in_group("Player")
	playerRef.eat_food(food_val)
	is_eaten = true
	self.queue_free()
