#include "haikuSystem.h"

#include <godot_cpp/core/class_db.hpp>

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

    ClassDB::bind_method(D_METHOD("get_haikuAuthor"), &HaikuSystem::get_haikuAuthor);
    ClassDB::bind_method(D_METHOD("set_haikuAuthor", "p_author"), &HaikuSystem::set_haikuAuthor);
    ADD_PROPERTY(PropertyInfo(Variant::STRING, "haikuAuthor"), "set_haikuAuthor", "get_haikuAuthor");

    ClassDB::bind_method(D_METHOD("get_fileOpenStatus"), &HaikuSystem::get_fileOpenStatus);
    ClassDB::bind_method(D_METHOD("set_fileOpenStatus", "fileOpenStatus"), &HaikuSystem::set_fileOpenStatus);
    ADD_PROPERTY(PropertyInfo(Variant::BOOL, "fileOpenStatus"), "set_fileOpenStatus", "get_fileOpenStatus");

    ClassDB::bind_method(D_METHOD("get_haikuFileLine"), &HaikuSystem::get_haikuFileLine);
    ClassDB::bind_method(D_METHOD("set_haikuFileLine", "p_text"), &HaikuSystem::set_haikuFileLine);
    ADD_PROPERTY(PropertyInfo(Variant::STRING, "haikuFileLine"), "set_haikuFileLine", "get_haikuFileLine");

    ADD_SIGNAL(MethodInfo("godot_open_file", PropertyInfo(Variant::BOOL, "fileStatus")));
    ADD_SIGNAL(MethodInfo("godot_close_file", PropertyInfo(Variant::BOOL, "fileClosed")));
    ADD_SIGNAL(MethodInfo("godot_update_haiku", PropertyInfo(Variant::STRING, "haikuLine")));
}

HaikuSystem::HaikuSystem()
{
    chosenHaiku = 0;
    haikuNum = 0;
    haikuText = "";
    haikuAuthor = "";
    fileOpenStatus = false;

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
}

void HaikuSystem::_process(double delta)
{
    
}

void HaikuSystem::OpenHaiku()
{
    UtilityFunctions::print("OpenHaiku() exec");
    //emit_signal("godot_open_file", "fileStatus");
    int tempLineCount = 0;
    int tempHaikuVal = 0;
    String tempHaikuLine = "";
    std::vector<String> tempHaikuVector;
    
}

void HaikuSystem::ReadHaiku()
{
    /*
    // read and store file info
    while(haikuFile->get_position() < haikuFile->get_length())
    {
        tempLineCount++;
        tempHaikuLine = haikuFile->get_line();

        if((tempLineCount % 5) == 1)
        {
            tempHaikuVal = tempHaikuLine.to_int();
        }
        else if ((tempLineCount % 5) == 0)
        {
            haikuMap.emplace(tempHaikuVal, tempHaikuVector);
        }
        else
        {
            tempHaikuVector.push_back(tempHaikuLine);
        }
        
        tempHaikuVal = 0;
        tempHaikuLine = "";
        tempHaikuVector.clear();

    }

    if(haikuFile->eof_reached())
    {
        UtilityFunctions::print("End of haiku file reached");
        CloseHaiku();
    }
    */

    int fileLength = FileAccess::open(haikuFilePath, FileAccess::READ)->get_length();
}   

void HaikuSystem::CloseHaiku()
{
    UtilityFunctions::print("CloseHaiku() exec\n Still need to close file in code");
    
}

void HaikuSystem::OutputHaikuFile()
{
    for(auto& h: haikuMap)
    {
        UtilityFunctions::print("num: ", h.first, " author: ", h.second[0], " haiku: ", h.second[1]);
    }
}

void HaikuSystem::ChooseHaiku()
{
    
    // randomly choose a haiku from the list
    //chosenHaiku = randomizer.randi_range(1, totalNumHaikus);
    UtilityFunctions::print("chosenHaiku: ", chosenHaiku);
    bool haikuFound = false;

    // check if chosen haiku is in selectedHaikus
    if(selectedHaikus.size() == 0)
    {
        // set haikuTitle
        // set haikuText
        // set haikuAuthor
        selectedHaikus.push_back(chosenHaiku);
    }
    else
    {
        for (auto h: selectedHaikus)
        {
            if(h == chosenHaiku)
            {
                haikuFound = true;
                break;
            }
        }
        
        if(!haikuFound)
        {
            ReadHaiku();
            selectedHaikus.push_back(chosenHaiku);
        }
        else
        {
            ChooseHaiku();
        }

    }
        // if yes choose a new haiku
        // else
            // update haiku values
            // add haiku to selected Haikus
}

 

void HaikuSystem::SearchHaiku()
{

}

void HaikuSystem::OutputChosenHaiku()
{
    // output chosen haiku to game
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

String HaikuSystem::get_haikuFileLine() const
{
    return haikuFileLine;
}

void HaikuSystem::set_haikuFileLine(const String p_text)
{
    haikuFileLine = p_text;
}
#pragma endregion
