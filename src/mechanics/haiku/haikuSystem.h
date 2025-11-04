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
    int chosenHaiku;
    String haikuTitle;
    String haikuText;
    String haikuAuthor;
    std::vector<int> selectedHaikus;

    String const haikuFile = "---file path here ---";
    int const totalNumHaikus = 44;

    protected:
    static void _bind_methods();

    public:
    HaikuSystem();
    ~HaikuSystem();
    void _process(double delta) override;

    void ChooseHaiku();
    void ReadHaiku(); // read/search haiku file for required haiku
    void OutputChosenHaiku();

    // getset
    int get_chosenHaiku() const;
    void set_chosenHaiku(const int p_val);
    String get_haikuTitle() const;
    void set_haikuTitle(const String p_title);
    String get_haikuText() const;
    void set_haikuText(const String p_text);
    String get_haikuAuthor() const;
    void set_haikuAuthor(const String p_author);

    };
}

#endif