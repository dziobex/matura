#include <iostream>
#include <fstream>
#include <algorithm>

int main () {
    std::ifstream reader("dane6.txt");
    std::ofstream writer("jestemtabelkom.txt");
    std::string str;

    int counters[9]{};
    while (reader >> str)
        counters[*std::max_element(str.begin(), str.end()) - 49]++;

    for (int i = 0; i < 9; ++i)
        writer << i + 2 << ' ' << counters[i] << '\n';

    return 0;
}
