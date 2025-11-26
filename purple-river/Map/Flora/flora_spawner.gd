extends Node

@export var randSeedVal = 1
@export var spawnPoint: Vector2i
@export var spawnAreaSize: Vector2
@export var spawnDelay: float
@export var floraType: int
var floraScene
var floraInstance
@onready var rectColl = $CollisionShape2D

func _ready():
	rectColl.shape.extents = spawnAreaSize
	$CollisionShape2D/Marker2D.position = Vector2(0,0)
	$SpawnTimer.wait_time = spawnDelay
	flora_type()
	place_flora()
	
func _process(delta: float):
	pass

func flora_type(): # choose which flora scene to instance
	if(floraType == 1): #flora is kiku
		floraScene = load("res://Map/Flora/Kiku.tscn")
	elif(floraType == 2): #flora is momiji
		floraScene = load("res://Map/Flora/Momiji.tscn")
	elif(floraType == 3): #flora is sakura
		floraScene = load("res://Map/Flora/Sakura.tscn")
	else:
		floraScene = load("res://Map/Flora/Kiku.tscn")
		
	floraInstance = floraScene.instantiate()
	add_child(floraInstance)

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
	floraInstance.position = spawnPoint
	print("floraPosition: ", floraInstance.position)

func place_flora():
	gen_spawn_point()
	
