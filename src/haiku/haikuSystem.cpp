#include "haikuSystem.h"

#include <godot_cpp/core/class_db.hpp>
#include <typeinfo>

using namespace godot;

void HaikuSystem::_bind_methods()
{
    ClassDB::bind_method(D_METHOD("get_chosenHaiku"), &HaikuSystem::get_chosenHaiku);
    ClassDB::bind_method(D_METHOD("set_chosenHaiku", "p_val"), &HaikuSystem::set_chosenHaiku);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "chosenHaiku"), "set_chosenHaiku", "get_chosenHaiku");

    ClassDB::bind_method(D_METHOD("get_haikuNum"), &HaikuSystem::get_haikuNum);
    ClassDB::bind_method(D_METHOD("set_haikuNum", "p_num"), &HaikuSystem::set_haikuNum);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "haikuNum"), "set_haikuNum", "get_haikuNum");

    ClassDB::bind_method(D_METHOD("get_haikuText"), &HaikuSystem::get_haikuText);
    ClassDB::bind_method(D_METHOD("set_haikuText", "p_text"), &HaikuSystem::set_haikuText);
    ADD_PROPERTY(PropertyInfo(Variant::STRING, "haikuText"), "set_haikuText", "get_haikuText");

    ClassDB::bind_method(D_METHOD("get_haikuTextJapanese"), &HaikuSystem::get_haikuTextJapanese);
    ClassDB::bind_method(D_METHOD("set_haikuTextJapanese", "p_text"), &HaikuSystem::set_haikuTextJapanese);
    ADD_PROPERTY(PropertyInfo(Variant::STRING, "haikuTextJapanese"), "set_haikuTextJapanese", "get_haikuTextJapanese");

    ClassDB::bind_method(D_METHOD("get_haikuAuthor"), &HaikuSystem::get_haikuAuthor);
    ClassDB::bind_method(D_METHOD("set_haikuAuthor", "p_author"), &HaikuSystem::set_haikuAuthor);
    ADD_PROPERTY(PropertyInfo(Variant::STRING, "haikuAuthor"), "set_haikuAuthor", "get_haikuAuthor");

    ClassDB::bind_method(D_METHOD("get_fileOpenStatus"), &HaikuSystem::get_fileOpenStatus);
    ClassDB::bind_method(D_METHOD("set_fileOpenStatus", "fileOpenStatus"), &HaikuSystem::set_fileOpenStatus);
    ADD_PROPERTY(PropertyInfo(Variant::BOOL, "fileOpenStatus"), "set_fileOpenStatus", "get_fileOpenStatus");

    ClassDB::bind_method(D_METHOD("get_fileReadStatus"), &HaikuSystem::get_fileReadStatus);
    ClassDB::bind_method(D_METHOD("set_fileReadStatus", "p_status"), &HaikuSystem::set_fileReadStatus);
    ADD_PROPERTY(PropertyInfo(Variant::BOOL, "fileReadStatus"), "set_fileReadStatus", "get_fileReadStatus");

    ClassDB::bind_method(D_METHOD("get_haikuAdded"), &HaikuSystem::get_haikuAdded);
    ClassDB::bind_method(D_METHOD("set_haikuAdded", "p_status"), &HaikuSystem::set_haikuAdded);
    ADD_PROPERTY(PropertyInfo(Variant::BOOL, "haikuAdded"), "set_haikuAdded", "get_haikuAdded");

    ADD_SIGNAL(MethodInfo("g_open_file", PropertyInfo(Variant::BOOL, "p_fileStatus"), PropertyInfo(Variant::STRING, "p_filePath")));
    ADD_SIGNAL(MethodInfo("g_read_file", PropertyInfo(Variant::BOOL, "p_haikuAdded")));
    ADD_SIGNAL(MethodInfo("g_close_file", PropertyInfo(Variant::BOOL, "p_fileStatus")));
    ADD_SIGNAL(MethodInfo("g_update_haiku", PropertyInfo(Variant::INT, "p_tempCount")));
    ADD_SIGNAL(MethodInfo("g_display_haiku", PropertyInfo(Variant::INT, "p_chosenHaiku")));

    // Additional methods
    ClassDB::bind_method(D_METHOD("ReadHaiku"), &HaikuSystem::ReadHaiku_GA);
    ClassDB::bind_method(D_METHOD("OutputHaikuFile"), &HaikuSystem::OutputHaikuFile_PH);
    ClassDB::bind_method(D_METHOD("SaveHaikuInfo", "p_num", "p_author", "p_text", "p_textJ"), &HaikuSystem::SaveHaikuInfo_GA);
    ClassDB::bind_method(D_METHOD("ChooseHaiku"), &HaikuSystem::ChooseHaiku);
    
}

HaikuSystem::HaikuSystem()
{
    chosenHaiku = 0;
    haikuNum = 0;
    haikuText = "";
    haikuAuthor = "";
    fileOpenStatus = false;
    fileReadStatus = false;
    haikuAdded = false;

    haikuInfo = {};
    haikuMap = {};

    bool fileExists = FileAccess::file_exists(haikuFilePath);
    if(fileExists)
    {
        UtilityFunctions::print("Haiku file exists");
        OpenHaiku();
    }
    else
    {
        UtilityFunctions::print("Haiku file does not exist");
    }
    
}

HaikuSystem::~HaikuSystem()
{
    // Need to close file
    CloseHaiku();
}

void HaikuSystem::_process(double delta)
{
    
}

// Open file in godot using signal
void HaikuSystem::OpenHaiku()
{
    UtilityFunctions::print("OpenHaiku() exec");
    //emit signal to godot to open file
    call_deferred("emit_signal", "g_open_file", fileOpenStatus, haikuFilePath);
}

void HaikuSystem::ReadHaiku_GA()
{
    //UtilityFunctions::print("ReadHaiku_GA() exec");
    ReadHaiku();
}

// Part of reading haikuFile.txt. Weird interactions with Godot
void HaikuSystem::ReadHaiku()
{
    //UtilityFunctions::print("ReadHaiku() exec");

    if(!fileReadStatus)
    {
        if(haikuAdded)
        {
            // flip haikuAdded to add next haiku
            haikuAdded = false;
            haikuInfo.clear();
            call_deferred("emit_signal", "g_read_file", haikuAdded);
        }
        else
        {
            UtilityFunctions::print("File not read but haiku not added yet");
        }
    }
    else
    {
        CloseHaiku();
    }
}

void HaikuSystem::SaveHaikuInfo_GA(int p_num, String p_author, String p_text, String p_textJ)
{
    //UtilityFunctions::print("SaveHaikuInfo_GH() exec");

    set_haikuNum(p_num);
    set_haikuAuthor(p_author);
    set_haikuText(p_text);
    set_haikuTextJapanese(p_textJ);
    SaveHaikuInfo();
}

// Save haiku info to map
void HaikuSystem::SaveHaikuInfo()
{
    haikuInfo.emplace_back(haikuAuthor);
    haikuInfo.emplace_back(haikuText);
    haikuInfo.emplace_back(haikuTextJapanese);

    haikuMap.emplace(haikuNum, haikuInfo);

    if(haikuMap.count(haikuNum) == 1)
    {
        // above haiku was successfully added
        //UtilityFunctions::print("Haiku Added Successfully - map size: ", haikuMap.size());
        haikuAdded = true;
        ReadHaiku();
    }
    else
    {
        UtilityFunctions::print("Haiku not added successfully");
    }
}

// Close Haiku file
void HaikuSystem::CloseHaiku()
{
    call_deferred("emit_signal", "g_close_file", fileOpenStatus);
    UtilityFunctions::print("CloseHaiku() exec");
}

// Placedholder for Godot Access, Godot doesn't like maps or umaps for some reason
void HaikuSystem::OutputHaikuFile_PH()
{
    //UtilityFunctions::print("OutputHaikuFile_PH() exec");
    //UtilityFunctions::print("map size: ", haikuMap.size());
    OutputHaikuFile();
}

// for debug and test only
void HaikuSystem::OutputHaikuFile()
{
    UtilityFunctions::print("OutputHaikuFile() exec");

    if(haikuMap.empty())
    {
        UtilityFunctions::print("haikuMap is empty");
    }
    
    UtilityFunctions::print("map size: ", haikuMap.size());

    for(auto& h: haikuMap)
    {
        UtilityFunctions::print("Haiku Num: ", h.first, " author: ", h.second[0], " haiku: ", h.second[1], " haiku (Japanese): ", h.second[2]);
    }
    
}


void HaikuSystem::ChooseHaiku(int p_rand)
{
    // Get rand num from godot
    chosenHaiku = p_rand;
    UtilityFunctions::print("chosenHaiku: ", chosenHaiku);

    // check if haiku has already been used
    // if no, display it. If yes, choose new one
    if(selectedHaikus.count(chosenHaiku) == 0)
    {
        haikuAuthor = haikuMap.find(chosenHaiku)->second[0];
        haikuText = haikuMap.find(chosenHaiku)->second[1];
        haikuTextJapanese = haikuMap.find(chosenHaiku)->second[2];
        selectedHaikus.emplace(chosenHaiku, true);
        OutputChosenHaiku();
    }
    else
    {
        if(chosenHaiku < 93)
        {
            ChooseHaiku(chosenHaiku + 1);
        }
        else
        {
            ChooseHaiku(chosenHaiku - 1);
        }
    }
}

// Emit signal to godot to display haiku in game
void HaikuSystem::OutputChosenHaiku()
{
    // output chosen haiku to game
    call_deferred("emit_signal", "g_display_haiku", chosenHaiku);

}

#pragma region GetSet
int HaikuSystem::get_chosenHaiku() const
{
    return chosenHaiku;
}

void HaikuSystem::set_chosenHaiku(const int p_val)
{
    chosenHaiku = p_val;
}

int HaikuSystem::get_haikuNum() const
{
    return haikuNum;
}

void HaikuSystem::set_haikuNum(const int p_num)
{
    haikuNum = p_num;
}

String HaikuSystem::get_haikuText() const
{
    return haikuText;
}

void HaikuSystem::set_haikuText(const String p_text)
{
    haikuText = p_text;
}

String HaikuSystem::get_haikuTextJapanese() const
{
    return haikuTextJapanese;
}

void HaikuSystem::set_haikuTextJapanese(const String p_text)
{
    haikuTextJapanese = p_text;
}

String HaikuSystem::get_haikuAuthor() const
{
    return haikuAuthor;
}

void HaikuSystem::set_haikuAuthor(const String p_author)
{
    haikuAuthor = p_author;
}

bool HaikuSystem::get_fileOpenStatus() const
{
    return fileOpenStatus;
}

void HaikuSystem::set_fileOpenStatus(const bool p_status)
{
    fileOpenStatus = p_status;
}

bool HaikuSystem::get_fileReadStatus() const
{
    return fileReadStatus;
}

void HaikuSystem::set_fileReadStatus(const bool p_status)
{
    fileReadStatus = p_status;
}

bool HaikuSystem::get_haikuAdded() const
{
    return haikuAdded;
}

void HaikuSystem::set_haikuAdded(const bool p_status)
{
    haikuAdded = p_status;
}
#pragma endregion
