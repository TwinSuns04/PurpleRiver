#include "testScons.h"

#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void TestScons::_bind_methods()
{

}

TestScons::TestScons()
{
    UtilityFunctions::print("TestScons ready");
}

TestScons::~TestScons()
{

}

void TestScons::_process(double delta)
{
    UtilityFunctions::print("TestScons _process");
}
