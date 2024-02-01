#include <iostream>
#include <windows.h>

void no_afk(WORD key) {
    INPUT input = { 0 };
    input.type = INPUT_KEYBOARD;
    input.ki.wVk = key;
    SendInput(1, &input, sizeof(INPUT));
    Sleep(50);
    input.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &input, sizeof(INPUT));
}

int main() {
    std::string command;
    std::cout << "Enter command: ";
    std::cin >> command;

    if (command != "!afk") {
        std::cout << "Invalid command. Aborting..." << std::endl;
        return 1;
    }

    while (true) {
        no_afk(VK_PAUSE);
        
        Sleep(10000); 
    }

    return 0;
}
