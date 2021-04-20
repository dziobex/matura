#include <iostream>
#include <fstream>

bool palindroment(std::string str);

int main () {
    std::ifstream reader("dane6.txt");
    std::ofstream writer("zadanie6_3.txt");
    std::string str;

    while (reader >> str)
        if (palindroment(str))
            writer << str << '\n';

    return 0;
}

bool palindroment(std::string str) {
    for (int i = 0; i < str.size() / 2; ++i)
        if (str[i] == str[str.size() - 1 - i])
            return false;
    return true;
}