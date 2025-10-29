extends PlayerCharacter

var screen_size
signal collisionHit

# Called when the node enters the scene tree for the first time.
func _ready():
	screen_size = get_viewport_rect().size


# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta: float):
	movementSpeed = movementSpeedBase * speedBoostMult
	velocity = Vector2.ZERO
	
	if Input.is_action_pressed("moveRight"):
		velocity.x += 1
	if Input.is_action_pressed("moveLeft"):
		velocity.x -= 1
	if Input.is_action_pressed("moveDown"):
		velocity.y += 1
	if Input.is_action_pressed("moveUp"):
		velocity.y -= 1
		
	if velocity.length() > 0:
		velocity = velocity.normalized() * movementSpeed
	
	position += velocity * delta
	#position = position.clamp(Vector2.ZERO, screen_size)


func _on_body_entered(body: Node2D):
	hide()
	collisionHit.emit()
	
	$PCCollision.set_deferred("disabled", true)
