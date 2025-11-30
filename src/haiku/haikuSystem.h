#ifndef HAIKUSYSTEM_H
#define HAIKUSYSTEM_H

#include <godot_cpp/classes/node2d.hpp>
#include <godot_cpp/classes/file_access.hpp>
#include <vector>
#include <unordered_map>


// reminder to not hardcode haiku's into game

namespace godot
{
    class HaikuSystem : public Node2D {
        GDCLASS(HaikuSystem, Node2D)

    private:
        // Possibly make a struct of all haiku vals instead of storing the seperately
        int chosenHaiku;
        int haikuNum;
        String haikuText;
        String haikuTextJapanese;
        String haikuAuthor;
        bool fileOpenStatus;
        bool fileReadStatus;
        
        std::vector<String> haikuLineVector;
        std::vector<String> haikuInfo;

        String const haikuFilePath = "res://haikuFile.txt";
        int const totalNumHaikus = 93;

        // use unordered map because I will be searching often
        std::unordered_map<int, std::vector<String>> haikuMap;
        std::vector<int> selectedHaikus; // no longer being used


    protected:
        static void _bind_methods();

    public:
        HaikuSystem();
        ~HaikuSystem();
        void _process(double delta) override;

        void OpenHaiku();
        void ReadHaiku_PH();
        void ReadHaiku(); // read and save haiku file in umap
        void CloseHaiku();
        void OutputHaikuFile(); // for debug and test only
        void ChooseHaiku(); // choose a random haiku and check if it has been read
        void SearchHaiku();
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
        std::vector<String> get_haikuLineVector() const;
        void set_haikuLineVector(const std::vector<String> p_vector);
        std::vector<String> get_haikuInfo() const;
        void set_haikuInfo(const std::vector<String> p_vector);
        
    };
    
} // namespace godot

#endif