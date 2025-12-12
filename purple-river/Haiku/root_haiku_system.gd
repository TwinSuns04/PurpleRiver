extends Node2D

func _on_haiku_system_g_open_file(p_fileStatus: bool, p_filePath: String) -> void:
	#print("g_open_file")
	if(!p_fileStatus):
		$HaikuSystem.Open_Haiku(p_filePath)

func _on_haiku_system_g_close_file(p_fileStatus: bool) -> void:
	#print("g_close_file")
	#print("p_fileStatus: ", p_fileStatus)
	if(p_fileStatus):
		$HaikuSystem.Close_Haiku()

func _on_haiku_system_g_read_file(p_haikuAdded: bool) -> void:
	#print("g_read_file")
	$HaikuSystem.Status_Haiku(p_haikuAdded)

func _on_haiku_area_body_entered(body: Node2D) -> void:
	var playerRef: CharacterBody2D 
	playerRef = get_tree().get_first_node_in_group("Player")
	
	if(playerRef.name.match(body.name)):
		$HaikuSystem.Choose_Haiku()

func _on_haiku_system_g_display_haiku(_p_chosenHaiku: int) -> void:
	$HaikuSystem.Display_Chosen_Haiku()


func _on_timer_timeout() -> void:
	$HaikuSystem/Haiku_Textbox.hide_textbox()
