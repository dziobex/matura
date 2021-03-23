#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

// Average performance: O (n) + performance of the single bucket sort //

void bucketSort(int arr[], int size, int max, int min) {
    std::vector<std::vector <int>> buckets;

    for (int i = 0; i < size; ++i)
        buckets.push_back(std::vector<int>());

    for (int i = 0; i < size; ++i) {
        buckets[abs(((size - 1 + min) * arr[i]) / (max + min))].push_back(arr[i]);
    }

    for (int i = 0, iArr = 0; i < size; ++i) {
        std::sort(buckets[i].begin(), buckets[i].end());
        for (int j = 0; j < buckets[i].size(); ++j)
            arr[iArr++] = buckets[i][j];
    }
}

int main() {
    srand(time(NULL));
    int arr[20], max = 0, min = 200;

    printf("Before sort:\n");
    for (int i = 0; i < 20; ++i) {
        arr[i] = rand() % 170 - 20;
        printf("%i%s", arr[i], i == 19 ? "\n" : ", ");
        max = arr[i] > max ? arr[i] : max;
        min = arr[i] < min ? arr[i] : min;
    }

    bucketSort(arr, 20, max, min);
    printf("After sort:\n");
    for (int i = 0; i < 20; ++i)
        printf("%i%s", arr[i], i == 19 ? "\n" : ", ");

    return 0;
}
