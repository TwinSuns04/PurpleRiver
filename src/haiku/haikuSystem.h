#ifndef HAIKUSYSTEM_H
#define HAIKUSYSTEM_H

#include <godot_cpp/classes/node2d.hpp>
#include <godot_cpp/classes/file_access.hpp>
#include <vector>
#include <map>
#include <unordered_map>


// reminder to not hardcode haiku's into game

namespace godot
{
    class HaikuSystem : public Node2D {
        GDCLASS(HaikuSystem, Node2D)

    private:
        int chosenHaiku;
        int haikuNum;
        String haikuText;
        String haikuTextJapanese;
        String haikuAuthor;
        bool fileOpenStatus;
        bool fileReadStatus;
        bool haikuAdded;

        std::vector<String> haikuInfo;

        String const haikuFilePath = "res://haikuFile.txt";
        int const totalNumHaikus = 94;

        std::map<int, std::vector<String>> haikuMap;
        std::unordered_map<int, bool> selectedHaikus;

    protected:
        static void _bind_methods();

    public:
        HaikuSystem();
        ~HaikuSystem();
        void _process(double delta) override;

        void OpenHaiku();
        void ReadHaiku_GA();
        void ReadHaiku(); // read and save haiku file in umap
        void SaveHaikuInfo_GA(int p_num, String p_author, String p_text, String p_textJ); // Godot access point, for some reason using SaveHaikuInfo() with params crashed godot but this doesn't
        void SaveHaikuInfo();
        void CloseHaiku();
        void OutputHaikuFile(); // for debug and test only
        void OutputHaikuFile_PH(); // Godot Access point placeholder
        void ChooseHaiku(int p_rand); // choose a random haiku and check if it has been read
        void OutputChosenHaiku();

        // getset
        int get_chosenHaiku() const;
        void set_chosenHaiku(const int p_val);
        int get_haikuNum() const;
        void set_haikuNum(const int p_num);
        String get_haikuText() const;
        void set_haikuText(const String p_text);
        String get_haikuTextJapanese() const;
        void set_haikuTextJapanese(const String p_text);
        String get_haikuAuthor() const;
        void set_haikuAuthor(const String p_author);
        bool get_fileOpenStatus() const;
        void set_fileOpenStatus(const bool p_status);
        bool get_fileReadStatus() const;
        void set_fileReadStatus(const bool p_status);
        bool get_haikuAdded() const;
        void set_haikuAdded(const bool p_status);
    };
    
}

#endif