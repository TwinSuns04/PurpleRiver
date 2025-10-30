#ifndef GDEXTENSIONACCESS_H
#define GDEXTENSIONACCESS_H

#include <godot_cpp/classes/node.hpp>

namespace godot {

class GDExtensionAccess : public Node {
	GDCLASS(GDExtensionAccess, Node)

private:
	

protected:
	static void _bind_methods();

public:
	GDExtensionAccess();
	~GDExtensionAccess();
	void _process(double delta) override;
};

}

#endif