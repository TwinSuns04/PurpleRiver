extends FoodItem

@onready var animation_player: AnimationPlayer = $AnimationPlayer

# Called when the node enters the scene tree for the first time.
func _ready() -> void:
	food_val = 20
	


# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta: float) -> void:
	pass



func _on_body_entered(body: Node2D) -> void:
	if is_eaten:
		pass
	
	var playerRef: CharacterBody2D = get_tree().get_first_node_in_group("Player")
	if(body.name == playerRef.name):
		playerRef.eat_food(food_val)
		is_eaten = true
		animation_player.play("Omnom")
