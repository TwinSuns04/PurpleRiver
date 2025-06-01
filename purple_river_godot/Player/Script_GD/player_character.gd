extends PlayerCharacter

var screen_size
var horizontalDirection
var verticalDirection

func _ready():
	print("Player ready")
	screen_size = get_viewport_rect().size

func _physics_process(delta):
	horizontalDirection = Input.get_axis("moveLeft", "moveRight")
	verticalDirection = Input.get_axis("moveUp", "moveDown")
	
	if Input.is_action_just_pressed("swimBoost"):
		print("swimBoost pressed")
		movementSpeed = movementSpeed * speedBoostMult
	else:
		movementSpeed = movementSpeedBase
	
	velocity.x = horizontalDirection * movementSpeed
	velocity.y = verticalDirection * movementSpeed
	move_and_slide()
	
	#possibly use velocity instead of input (i.e. player cannot move down
		# but has to let the river carry them down)

#func _process(delta: float) -> void:

func _input(event):
	if event is InputEventKey and event.pressed:
		if event.keycode == KEY_1:
			print("Debug_1")
			print("global_pos: ", global_position)
