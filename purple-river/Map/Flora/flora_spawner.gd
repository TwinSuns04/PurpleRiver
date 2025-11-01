extends Node

@export var randSeedVal = 1
@export var spawnPoint: Vector2i
@export var spawnAreaSize: Vector2
@onready var rectColl = $CollisionShape2D

func _ready():
	rectColl.shape.extents = spawnAreaSize
	$CollisionShape2D/Marker2D.position = Vector2(0,0)
	
func _process(delta: float):
	pass

func gen_spawn_point():
	var randomness = RandomNumberGenerator.new()
	randomness.randomize()
	
	var areaBoundsPos: Vector2i
	var areaBoundsNeg: Vector2i
	areaBoundsPos.x = spawnAreaSize.x / 2
	areaBoundsNeg.x = -areaBoundsPos.x
	areaBoundsPos.y = spawnAreaSize.y / 2
	areaBoundsNeg.y = -areaBoundsPos.y
	
	spawnPoint.x = randi_range(areaBoundsNeg.x, areaBoundsPos.x)
	spawnPoint.y = randi_range(areaBoundsNeg.y, areaBoundsNeg.y)
	var x_coord: int

func place_flora():
	pass
