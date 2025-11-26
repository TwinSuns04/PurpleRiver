#ifndef HAIKUSYSTEM_H
#define HAIKUSYSTEM_H

#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/file_access.hpp>
#include <godot_cpp/classes/random_number_generator.hpp>
#include <vector>

// reminder to not hardcode haiku's into game

namespace godot {

    class HaikuSystem : public Node {
        GDCLASS(HaikuSystem, Node)

    private:
    // Possibly make a struct of all haiku vals instead of storing the seperately
    int chosenHaiku;
    int haikuNum;
    String haikuText;
    String haikuAuthor;
    std::vector<int> selectedHaikus;

    String const c_haikuFilePath = "haikuFile.txt";
    int const c_totalNumHaikus = 93;

    protected:
    static void _bind_methods();

    public:
    HaikuSystem();
    ~HaikuSystem();
    void _process(double delta) override;

    void ChooseHaiku(); // choose a random haiku and check if it has been read
    void ReadHaiku(); // read/search haiku file for required haiku
    void OutputChosenHaiku();

    // getset
    int get_chosenHaiku() const;
    void set_chosenHaiku(const int p_val);
    int get_haikuNum() const;
    void set_haikuNum(const int p_num);
    String get_haikuText() const;
    void set_haikuText(const String p_text);
    String get_haikuAuthor() const;
    void set_haikuAuthor(const String p_author);

    };
}

#endif