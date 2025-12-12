extends Node

@export var randSeedVal = 1
@export var spawnPoint: Vector2i
@export var spawnAreaSize: Vector2
@export var spawnDelay: float
@export var floraType: int
@export var floraCount: int
@export var floraCountMax: int
@export var floraScene: PackedScene
@onready var rectColl = $CollisionShape2D
var randomness = RandomNumberGenerator.new()

const FLOWER_SCALE := Vector2(0.08, 0.08)

#If time, I would like to implement a system so multiple flora
# don't spawn on top of one another. Could possible implement
# using collision shapes and areas?

func _ready():
	spawnAreaSize = rectColl.shape.size
	print("rectSize: ", rectColl.shape.size)
	$CollisionShape2D/Marker2D.position = Vector2(0,0)
	
	if(spawnDelay == 0):
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
			floraScene = load("res://Flora/Scenes/kiku.tscn")
			spawnDelay = 0.1
		elif(floraType == 2): #flora is momiji
			floraScene = load("res://Flora/Scenes/momiji.tscn")
			spawnDelay = 2.0
		elif(floraType == 3): #flora is sakura
			floraScene = load("res://Flora/Scenes/sakura.tscn")
			spawnDelay = 2.0
		else:
			floraScene = load("res://Flora/Scenes/kiku.tscn")
		
	if(floraCountMax == 0):
		floraCountMax = 16
	

func place_flora():
	if(floraCount <= floraCountMax):
		var floraInstance = floraScene.instantiate()
		add_child(floraInstance)
		floraInstance.position = gen_spawn_point()
		floraInstance.scale = FLOWER_SCALE
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
	return spawnPoint

func _on_spawn_timer_timeout() -> void:
	place_flora()
