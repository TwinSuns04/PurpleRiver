extends PlayerCharacter

var screen_size

func _ready():
	screen_size = get_viewport_rect().size
	position = pcPosition
	
func _process(delta):
	pcVelocity = Vector2.ZERO
	
	if Input.is_action_pressed("moveRight"):
		print("moveRight pressed")
		pcVelocity.x += 1
		
	if Input.is_action_pressed("moveLeft"):
		print("moveLeft pressed")
		pcVelocity.x -= 1
		
	if Input.is_action_pressed("moveUp"):
		print("moveUp pressed")
		pcVelocity.y -= 1
		
	if Input.is_action_pressed("moveDown"):
		print("moveDown pressed")
		pcVelocity.y += 1
		
	if Input.is_action_pressed("swimBoost"):
		print("swimBoost pressed")
		movementSpeed = movementSpeed * speedBoostMult
	else:
		movementSpeed = movementSpeedBase
	
	if pcVelocity.length() > 0:
		pcVelocity = pcVelocity.normalized() * movementSpeed
	
	position += pcVelocity * delta
	position = position.clamp(Vector2.ZERO, screen_size)
	

func _input(event):
	if event is InputEventKey and event.pressed:
		if event.keycode == KEY_1:
			print("Debug_1")
			print("Screen_size: ", screen_size)
