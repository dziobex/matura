#include <iostream>
#include <algorithm>
#include <fstream>

int main () {
    std::ifstream reader("dane6.txt");
    std::ofstream writer("zadanie6_2.txt");
    std::string str;

    std::pair<std::string, int> counters[9];

    while (reader >> str) {
        int index = *std::max_element(str.begin(), str.end()) - 49;
        int sum = 0;
        std::for_each(str.begin(), str.end(), [&sum](char c) { sum += (c - 48); });
        if (counters[index].second < sum)
            counters[index] = std::make_pair(str, sum);
    }

    for (int i = 0; i < 9; ++i)
        writer << i + 2 << ' ' << counters[i].first << '\n';

    return 0;
}