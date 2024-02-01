#include <iostream>
#include <windows.h>

void left_click() {
    INPUT input = { 0 };
    input.type = INPUT_MOUSE;
    input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
    SendInput(1, &input, sizeof(INPUT));

    // something i need
    Sleep(50);

    input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
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
        left_click();
        
        Sleep(10000); 
    }

    return 0;
}