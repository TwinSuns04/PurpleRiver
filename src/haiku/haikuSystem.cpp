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

    ADD_SIGNAL(MethodInfo("g_open_file", PropertyInfo(Variant::BOOL, "p_fileStatus"), PropertyInfo(Variant::STRING, "p_filePath")));
    ADD_SIGNAL(MethodInfo("g_close_file", PropertyInfo(Variant::BOOL, "p_fileStatus")));
    ADD_SIGNAL(MethodInfo("g_update_haiku", PropertyInfo(Variant::INT, "p_tempCount")));

    // Additional methods
    ClassDB::bind_method(D_METHOD("ReadHaiku"), &HaikuSystem::ReadHaiku_PH);
    
}

HaikuSystem::HaikuSystem()
{
    chosenHaiku = 0;
    haikuNum = 0;
    haikuText = "";
    haikuAuthor = "";
    fileOpenStatus = false;
    fileReadStatus = false;

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
    //emit signal to godot to open file
    call_deferred("emit_signal", "g_open_file", fileOpenStatus, haikuFilePath);
}

void HaikuSystem::ReadHaiku_PH()
{
    UtilityFunctions::print("ReadHaiku_PH() exec");
    ReadHaiku();
}

void HaikuSystem::ReadHaiku()
{
    if(!fileOpenStatus)
    {
        UtilityFunctions::print("ERROR: ReadHaiku() exec on !fileOpenStatus");
        return;
    }
    UtilityFunctions::print("ReadHaiku() exec");
    // read and store file info in umap
    int tempHaikuCount = 0;
    int tempHaikuVal = 0;

    // Missing a check for if above values don't update if "godot_read_file fails"
    
    /*
    while(!fileReadStatus)
    {
        tempHaikuCount++;
        call_deferred("emit_signal", "g_update_haiku", totalNumHaikus);
        
        // get hakiuNum for packed array and convert to int
        //tempHaikuVal = haikuLineArray[0].to_int();
        
        // get haiku info and and to temp array
        //tempHaikuVector[0] = haikuLineArray[1];
        //tempHaikuVector[1] = haikuLineArray[2];
        //tempHaikuVector[2] = haikuLineArray[3];

        // add pair to umap
        //haikuMap.emplace(tempHaikuVal, tempHaikuVector);

        //tempHaikuVector.clear();
    }
        */

    for(int i = 0; i < totalNumHaikus; i++)
    {
        call_deferred("emit_signal", "g_update_haiku", totalNumHaikus);

        
    }
    
    CloseHaiku();
    OutputHaikuFile();
}

void HaikuSystem::CloseHaiku()
{
    call_deferred("emit_signal", "g_close_file", fileOpenStatus);
    UtilityFunctions::print("CloseHaiku() exec");
}

// for debug and test only
void HaikuSystem::OutputHaikuFile()
{
    UtilityFunctions::print("OutputHaikuFile() exec");
    /*
    for(auto& h: haikuMap)
    {
        UtilityFunctions::print("num: ", h.first, " author: ", h.second[0], " haiku: ", h.second[1]);
    }
        */
}

// will execute from godot when signal recieved
void HaikuSystem::ChooseHaiku()
{
    
    // randomly choose a haiku from the list
    //chosenHaiku = randomizer.randi_range(1, totalNumHaikus);
    UtilityFunctions::print("need random num from godot");
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
            //ReadHaiku();
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

std::vector<String> HaikuSystem::get_haikuLineVector() const
{
    return haikuLineVector;
}

void HaikuSystem::set_haikuLineVector(const std::vector<String> p_vector)
{
    haikuLineVector = p_vector;
}

std::vector<String> HaikuSystem::get_haikuInfo() const
{
    return haikuInfo;
}

void HaikuSystem::set_haikuInfo(const std::vector<String> p_vector)
{
    haikuInfo = p_vector;
}
#pragma endregion
