extends Node

@export var randSeedVal = 1
@export var spawnPoint: Vector2i
@export var spawnAreaSize: Vector2
@export var spawnDelay: float
@export var floraType: int
@export var floraCount: int
@export var floraScene: PackedScene
@onready var rectColl = $CollisionShape2D
var randomness = RandomNumberGenerator.new()

#If time, I would like to implement a system so multiple flora
# don't spawn on top of one another. Could possible implement
# using collision shapes and areas?

func _ready():
	rectColl.shape.extents = spawnAreaSize
	$CollisionShape2D/Marker2D.position = Vector2(0,0)
	spawnDelay = 0.1
	$SpawnTimer.wait_time = spawnDelay
	flora_type()
	place_flora()
	randomness.randomize()
	
func _process(delta: float):
	pass

func flora_type(): # choose which flora scene to instance
	if(floraScene == null):
		if(floraType == 1): #flora is kiku
			floraScene = load("res://Map/Flora/Kiku.tscn")
			spawnDelay = 0.1
		elif(floraType == 2): #flora is momiji
			floraScene = load("res://Map/Flora/Momiji.tscn")
			spawnDelay = 2.0
		elif(floraType == 3): #flora is sakura
			floraScene = load("res://Map/Flora/Sakura.tscn")
			spawnDelay = 2.0
		else:
			floraScene = load("res://Map/Flora/Kiku.tscn")
		
	

func place_flora():
	if(floraCount < 20):
		var floraInstance = floraScene.instantiate()
		add_child(floraInstance)
		floraInstance.position = gen_spawn_point()
		floraCount+= 1

func gen_spawn_point() -> Vector2:
	var areaBoundsPos: Vector2i
	var areaBoundsNeg: Vector2i
	areaBoundsPos.x = spawnAreaSize.x / 2
	areaBoundsNeg.x = -areaBoundsPos.x
	areaBoundsPos.y = spawnAreaSize.y / 2
	areaBoundsNeg.y = -areaBoundsPos.y
	
	spawnPoint.x = randi_range(areaBoundsNeg.x, areaBoundsPos.x)
	spawnPoint.y = randi_range(areaBoundsNeg.y, areaBoundsPos.y)
	print("spawnPoint: ", spawnPoint)
	return spawnPoint




func _on_spawn_timer_timeout() -> void:
	place_flora()
