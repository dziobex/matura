#include <iostream>
#include <algorithm>
#include <fstream>

int main () {
    std::ifstream reader("dane6.txt");
    std::ofstream writer("jestemtabelkom.txt");
    std::string str;

    int counters[9]{};
    // szprytnie
    while (reader >> str)
        counters[*std::max_element(str.begin(), str.end()) - 49]++;

    auto fn = [&]() { writer.width(12); writer.fill('_'); writer << '\n'; };
    for (int i = 0, fn(); i < 9; ++i) {
        writer << "\n| "<< i + 2 << " | " << counters[i] << " |\n";
        fn();
    }

    return 0;
}
