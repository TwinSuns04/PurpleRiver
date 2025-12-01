extends HaikuSystem

const TOTAL_HAIKU_NUM = 93

var haiku_file
var haiku_file_pos

func _ready() -> void:
	haiku_file_pos = 0
	
func _process(delta: float) -> void:
	pass
	
func Open_Haiku(c_haiku_file_path: String) -> void:
	#print("Open_Haiku() exec")
	haiku_file = FileAccess.open(c_haiku_file_path, FileAccess.READ)
	
	if(haiku_file != null):
		#print("haiku_file !null")
		fileOpenStatus = true
		haikuAdded = false;
		Read_Haiku()
	else:
		fileOpenStatus = false
		print("File not successfully opened")

func Read_Haiku() -> void:
	var num
	var author
	var textE
	var textJ
	var dummyText
	if(!haikuAdded):
		haiku_file.seek(haiku_file_pos)
		num = haiku_file.get_line().to_int()
		author = haiku_file.get_line()
		textE = haiku_file.get_line()
		textJ = haiku_file.get_line()
		dummyText = haiku_file.get_line()
		haiku_file_pos = haiku_file.get_position()
	
	SaveHaikuInfo(num, author, textE, textJ)

func Status_Haiku(p_status: bool) -> void:
	if(haiku_file.eof_reached()):
		fileReadStatus = true
	
	if(!haikuAdded):
		Read_Haiku()
	else:
		print("Status_Haiku() exec while haikuAdded true")
		SaveHaikuInfo(haikuNum, haikuAuthor, haikuText, haikuTextJapanese)

	
func Close_Haiku() -> void:
	#print("Close_Haiku() exec")
	haiku_file.close()
	fileOpenStatus = false
	OutputHaikuFile()
	
func Choose_Haiku() -> void:
	pass
	
func Output_Chosen_Haiku() -> void:
	pass
