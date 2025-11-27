#include "haikuSystem.h"

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/file_access.hpp>

using namespace godot;

void HaikuSystem::_bind_methods()
{

}

HaikuSystem::HaikuSystem()
{
    chosenHaiku = 0;
    haikuNum;
    haikuText = "";
    haikuAuthor = "";

   if(FileAccess::file_exists(haikuFilePath))
   {
        UtilityFunctions::print("Haiku file exists");
   }
   else
   {
        UtilityFunctions::print("Haiku file does not exist");
   }
    
}

HaikuSystem::~HaikuSystem()
{
    haikuFile->close();
    haikuFile->flush();
}

void HaikuSystem::_process(double delta)
{
    
}

void HaikuSystem::OpenHaiku()
{
    UtilityFunctions::print("OpenHaiku() exec");
    haikuFile = FileAccess::open(haikuFilePath, FileAccess::READ);
    int tempLineCount = 0;
    int tempHaikuVal = 0;
    String tempHaikuLine = "";
    std::vector<String> tempHaikuVector;

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

    OutputHaikuFile();
    
}

void HaikuSystem::OutputHaikuFile()
{
    for(auto& h: haikuMap)
    {
        UtilityFunctions::print("num: ", h.first, " author: ", h.second[0], " haiku: ", h.second[1]);
    }
}

void HaikuSystem::CloseHaiku()
{
    UtilityFunctions::print("CloseHaiku() exec");
    haikuFile->close();
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

void HaikuSystem::ReadHaiku()
{
    // read haiku file

    // search for haiku num
    // set haikuVals
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
#pragma endregion
