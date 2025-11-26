extends RigidBody2D

func _ready() -> void:
	flora_type()
	
func _process(delta: float) -> void:
	pass

func _physics_process(delta: float) -> void:
	pass
	
func flora_type():
	var floraTexture: CompressedTexture2D
	var randVal = randi_range(1,3)
	if(randVal == 1):
		floraTexture = load("res://Assets_Misc/Flora/Momiji-1.png")
	elif(randVal == 2):
		floraTexture = load("res://Assets_Misc/Flora/Momiji-2.png")
	elif(randVal == 3):
		floraTexture = load("res://Assets_Misc/Flora/Momiji-3.png")
	else:
		floraTexture = load("res://Assets_Misc/Flora/Kiku-1.png")
	
	$Sprite2D.texture = floraTexture
	

func despawn():
	pass
