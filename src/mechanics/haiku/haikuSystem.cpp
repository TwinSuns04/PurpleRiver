#include "haikuSystem.h"

#include <godot_cpp/core/class_db.hpp>

using namespace godot;

RandomNumberGenerator randomizer;

void HaikuSystem::_bind_methods()
{

}

HaikuSystem::HaikuSystem()
{
    chosenHaiku = 0;
    haikuTitle = "untitled";
    haikuText = "";
    haikuAuthor = "";

    
    randomizer.randomize();
}

HaikuSystem::~HaikuSystem()
{

}

void HaikuSystem::_process(double delta)
{

}

void HaikuSystem::ChooseHaiku()
{
    
    // randomly choose a haiku from the list
    chosenHaiku = randomizer.randi_range(1, totalNumHaikus);
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

String HaikuSystem::get_haikuTitle() const
{
    return haikuTitle;
}

void HaikuSystem::set_haikuTitle(const String p_title)
{
    haikuTitle = p_title;
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
