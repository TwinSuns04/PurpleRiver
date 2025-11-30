extends HaikuSystem

const TOTAL_HAIKU_NUM = 93

var haiku_file
var haiku_file_pos

func _ready() -> void:
	haiku_file_pos = 0
	
func _process(delta: float) -> void:
	pass
	
func Open_Haiku(c_haiku_file_path: String) -> void:
	print("Open_Haiku() exec")
	haiku_file = FileAccess.open(c_haiku_file_path, FileAccess.READ)
	
	if(haiku_file != null):
		print("haiku_file !null")
		fileOpenStatus = true
		ReadHaiku()
	else:
		fileOpenStatus = false
		print("File not successfully opened")

func Update_Haiku(_p_haiku_num: int) -> void:
	print("Update_Haiku() exec")
	var temp_haiku_line
	if(haiku_file_pos < haiku_file.get_length()):
		haiku_file.seek(haiku_file_pos)
		haikuNum = haiku_file.get_line().to_int()
		haikuAuthor = haiku_file.get_line()
		haikuText = haiku_file.get_line()
		haikuTextJapanese = haiku_file.get_line()
		temp_haiku_line = haiku_file.get_line()
		haiku_file_pos = haiku_file.get_position()
	

	
func Close_Haiku() -> void:
	haiku_file.close()
	
func Choose_Haiku() -> void:
	pass
	
func Output_Chosen_Haiku() -> void:
	pass
