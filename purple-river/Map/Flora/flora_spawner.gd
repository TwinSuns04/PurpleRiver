extends Node

@export var randSeedVal = 1
@export var spawnPoint: Vector2i
@export var spawnAreaSize: Vector2
@export var spawnDelay: float
@export var floraType: int
@onready var rectColl = $CollisionShape2D

func _ready():
	rectColl.shape.extents = spawnAreaSize
	$CollisionShape2D/Marker2D.position = Vector2(0,0)
	$SpawnTimer.wait_time = spawnDelay
	flora_type()
	
func _process(delta: float):
	pass

func flora_type(): # choose which flora scene to instance
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
	print("spawnPoint: ", spawnPoint)
	$CollisionShape2D/Marker2D/Sprite2D.position = spawnPoint
	var x_coord: int

func place_flora():
	gen_spawn_point()
	
