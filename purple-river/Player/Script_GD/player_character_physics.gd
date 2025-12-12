extends PlayerCharacterCB2

const VELOCITY_CAP_MAX : float = 400.0
const VELOCITY_CAP_MIN : float = -400.0

var screen_size
var horizontalDirection
var verticalDirection
var temp_river_velocity

signal position_at_game_pause(p_pos : Vector2)

func _ready():
	print("Player ready")
	print("Player name: ", name)
	add_to_group("Player")
	screen_size = get_viewport_rect().size
	$PCCamera.zoom.x = 2.0
	$PCCamera.zoom.y = 2.0
	
	
	#change mouse mode
	#Input.mouse_mode = Input.MOUSE_MODE_CONFINED

func _physics_process(delta):
	
	#Start character rotation on moouse movement
	#Not currently implemented
	#$PCSprite.global_rotation = $Marker2D.global_rotation
	#$PCCollision.global_rotation = $Marker2D.global_rotation
	#$PCArea.global_rotation = $Marker2D.global_rotation
	#End character rotation mouse movement
	
	
	#player movement start
	horizontalDirection = Input.get_axis("moveLeft", "moveRight")
	verticalDirection = Input.get_axis("moveUp", "moveDown")
	
	if Input.is_action_pressed("swimBoost"):
		print("swimBoost pressed")
		if staminaVal > 0:
			movementSpeed = movementSpeed * speedBoostMult
			boostStatus = true
		else:
			print("No mucho boosto")
	if Input.is_action_just_released("swimBoost"):
		print("swimBoost released")
		movementSpeed = movementSpeedBase * movementSpeedMult
		boostStatus = false

	temp_river_velocity = calc_river_velocity()
	velocity.x = horizontalDirection * movementSpeed
	velocity.x = velocity.x + temp_river_velocity.x
	velocity.y = verticalDirection * movementSpeed
	velocity.y = velocity.y + temp_river_velocity.y
	
	#cap values
	if(velocity.x < VELOCITY_CAP_MIN):
		velocity.x = VELOCITY_CAP_MIN
	elif(velocity.x > VELOCITY_CAP_MAX):
		velocity.x = VELOCITY_CAP_MAX
		
	if(velocity.y < VELOCITY_CAP_MIN):
		velocity.y = VELOCITY_CAP_MIN
	elif(velocity.y > VELOCITY_CAP_MAX):
		velocity.y = VELOCITY_CAP_MAX
	
	#velocity = calc_basis_transform(basisRotation)
	# above line implements control of sprite with mouse movement vs keyboard input
	
	#sprite rotation based on movement
	if(velocity.y < 0):
		if(velocity.x == 0):
			global_rotation_degrees = 0
		elif(velocity.x > 0):
			global_rotation_degrees = 45
		elif(velocity.x < 0):
			global_rotation_degrees = -45
		else:
			global_rotation_degrees = 0
	elif(velocity.y > 0):
		if(velocity.x == 0):
			global_rotation_degrees = 180
		elif(velocity.x > 0):
			global_rotation_degrees = 135
		elif(velocity.x < 0):
			global_rotation_degrees = -135
		else:
			global_rotation_degrees = 180
	elif(velocity.y == 0):
		if(velocity.x > 0):
			global_rotation_degrees = 90
		elif(velocity.x < 0):
			global_rotation_degrees = -90
		else:
			global_rotation_degrees = 0
	
	move_and_slide()
	#player movement end
	#possibly use velocity instead of input (i.e. player cannot move down
		# but has to let the river carry them down)
		


#func _process(delta: float) -> void:

func _input(event):
	if event is InputEventKey and event.pressed:
		if event.keycode == KEY_1:
			print("\n\nDebug_1")
			print("staminaVal: ", staminaVal)
			print("\n\n")
			#print("localPos: ", PlayerCharacterCB2.to_local(position))


func _on_pc_area_entered(area: Area2D):
	print("pcArea entered")
	print("Area name: ", area.name)
	movementSpeed = movementSpeedBase / 4.0


func _on_pc_area_body_shape_entered(body_rid: RID, body: Node2D, body_shape_index: int, local_shape_index: int):
	#print("\n\npc_area_body_shaped_entered() exec \n")
	#print("body: ", body)
	
	var tileMap: TileMapLayer = body
	#print("tileMap var created")
	
	#if not tileMap:
		#print("tileMap invalid")
		#return
	
	#print("tileMap is valid")
	var local_pos = tileMap.to_local(position)
	var cell := tileMap.local_to_map(local_pos)
	var tile_data: TileData = null
	
	if(cell):
		tile_data = tileMap.get_cell_tile_data(cell)
		#print("cell is valid")
		#if(tile_data):
			#print("tile_data is immediatley valid")
		#else:
			#print("tile_data is immediatley invalid")
	else:
		tile_data = null
		#print("cell invalid")
	
	if(tile_data):
		#print("tile_data is valid")
		positionalRCV = get_river_current_vector(tile_data)
		positionalRCM = get_river_current_mult(tile_data)
		positionalRCCS = get_rCurrent_collision_status(tile_data)
		
	else:
		#print("tile_data invalid")
		positionalRCV = Vector2(0, 0)
		positionalRCM = 0
		positionalRCCS = false
	
	#old code attempt
	#print("_on_pc_area_body_shape_entered() exec")
	#if body is TileMapLayer:
		#if body.name == "TileMapLayer_Current":
			#print("Player entered current area")
			#
			#if is_instance_valid(body.tile_set.has_custom_data_layer_by_name("currentVelocity")):
				#print("body.tile_set has currentVelocity custom data")
			#else:
				#print("body.tile_set invalid")

func get_river_current_vector(p_tileData: TileData) -> Vector2i:
	var riverCurrentVector = Vector2i.ZERO
	#print("get_river_current_vector()")
	
	if(p_tileData):
		riverCurrentVector = p_tileData.get_custom_data("currentVector")
		if not riverCurrentVector:
			#print("Failed to get custom data for rcv")
			riverCurrentVector = Vector2i.ZERO
		#print("riverCurrentVector val updated")
	
	return riverCurrentVector

func get_river_current_mult(p_tileData: TileData) -> int:
	var riverCurrentMult = 1
	#print("get_river_current_mult()")
	
	if(p_tileData):
		riverCurrentMult = p_tileData.get_custom_data("currentMult")
		if not riverCurrentMult:
			print("Failed to get custom data for rcm")
			riverCurrentMult = 1
		#print("riverCurrentMult val updated")
	
	return riverCurrentMult

func get_rCurrent_collision_status(p_tileData: TileData) -> bool:
	var rCurrentCollisionStatus = false
	#print("get_rCurrent_collision_status()")
	
	if(p_tileData):
		rCurrentCollisionStatus = p_tileData.get_custom_data("collisionStatus")
		#print("rCurrentCollisionStatus updated")
		if(rCurrentCollisionStatus == null):
			#print("Failed to get custom data for rccs")
			rCurrentCollisionStatus = false
	
	return rCurrentCollisionStatus
