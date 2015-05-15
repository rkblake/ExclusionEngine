#include "InputManager.h"

#include "Script.h"

void InputManager::init() {
    Script keys("scripts/keys.lua");
    for(std::string* i = &Commands[0];*i != "\0";++i) {
        Button temp;
        int code = (int)keys.GetNumber(*i->c_str());
        //TODO: need way of determining whether int retrieved is keycode, scancode, or mousebutton
        input_map.insert(map_item(temp, i));
    }
}
