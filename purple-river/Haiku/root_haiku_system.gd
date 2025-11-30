extends Node2D

func _on_haiku_system_g_open_file(p_fileStatus: bool, p_filePath: String) -> void:
	print("g_open_file")
	if(!p_fileStatus):
		$HaikuSystem.Open_Haiku(p_filePath)

func _on_haiku_system_g_close_file(p_fileStatus: bool) -> void:
	print("g_close_file")
	if(p_fileStatus):
		$HaikuSystem.Close_Haiku()

func _on_haiku_system_g_update_haiku(p_tempCount: int) -> void:
	print("g_update_haiku")
	$HaikuSystem.Update_Haiku(p_tempCount)
