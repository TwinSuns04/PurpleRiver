extends CharacterBody2D

var positionalRCV: Vector2
var positionalRCM: int
var positionalRCCS: bool

const FLOWER_SCALE := Vector2(0.04, 0.04)

func _ready() -> void:
	velocity = Vector2(0, 20.0)
	add_to_group("Flora")
	flora_type()
	

func _physics_process(delta: float) -> void:
	var tempVelocity: Vector2
	tempVelocity = positionalRCM * positionalRCV
	velocity += tempVelocity
	
	move_and_slide()

func flora_type() -> void:
	var floraTexture: CompressedTexture2D
	var randVal = randi_range(0,4)
	if(randVal == 1):
		floraTexture = load("res://Flora/Assets/Momiji-1.png")
	elif(randVal == 2):
		floraTexture = load("res://Flora/Assets/Momiji-2.png")
	elif(randVal == 3):
		floraTexture = load("res://Flora/Assets/Momiji-3.png")
	else:
		floraTexture = load("res://Flora/Assets/Momiji-1.png")
	
	$Sprite2D.texture = floraTexture
	
	scale = FLOWER_SCALE;

func despawn() -> void:
	pass

func _on_area_2d_body_shape_entered(body_rid: RID, body: Node2D, body_shape_index: int, local_shape_index: int) -> void:
	var tileMap: TileMapLayer = body
	
	var local_pos = tileMap.to_local(global_position)
	var cell := tileMap.local_to_map(local_pos)
	var tile_data: TileData = null
	
	if(cell):
		tile_data = tileMap.get_cell_tile_data(cell)
	else:
		tile_data = null
	
	if(tile_data):
		positionalRCV = get_river_current_vector(tile_data)
		positionalRCM = get_river_current_mult(tile_data)
		positionalRCCS = get_rCurrent_collision_status(tile_data)
	else:
		positionalRCV = Vector2(0, 0)
		positionalRCM = 0
		positionalRCCS = false

func get_river_current_vector(p_tileData: TileData) -> Vector2i:
	var riverCurrentVector = Vector2i.ZERO
	
	if(p_tileData):
		riverCurrentVector = p_tileData.get_custom_data("currentVector")
		if not riverCurrentVector:
			riverCurrentVector = Vector2i.ZERO
		
	return riverCurrentVector

func get_river_current_mult(p_tileData: TileData) -> int:
	var riverCurrentMult = 1
	
	if(p_tileData):
		riverCurrentMult = p_tileData.get_custom_data("currentMult")
		if not riverCurrentMult:
			print("Failed to get custom data for rcm")
			riverCurrentMult = 1
	
	return riverCurrentMult

func get_rCurrent_collision_status(p_tileData: TileData) -> bool:
	var rCurrentCollisionStatus = false
	
	if(p_tileData):
		rCurrentCollisionStatus = p_tileData.get_custom_data("collisionStatus")
	
		if(rCurrentCollisionStatus == null):
			rCurrentCollisionStatus = false
	
	return rCurrentCollisionStatus
