extends CharacterBody2D

func _ready() -> void:
	add_to_group("Flora")
	flora_type()

func flora_type() -> void:
	var floraTexture: CompressedTexture2D
	var randVal = randi_range(0,4)
	if(randVal == 1):
		floraTexture = load("res://Flora/Assets/Kiku-1.png")
	elif(randVal == 2):
		floraTexture = load("res://Flora/Assets/Kiku-2.png")
	elif(randVal == 3):
		floraTexture = load("res://Flora/Assets/Kiku-3.png")
	else:
		floraTexture = load("res://Flora/Assets/Kiku-1.png")
	
	$Sprite2D.texture = floraTexture
	
	#scale = Vector2(0.04, 0.04);
