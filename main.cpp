#include "sorts/sorts.h"
#include "test/benchmark.h"
#include <vector>
#include <iostream>

using namespace std;

int main() {

    vector<int> v = {2, 3, 1, 5, 4};

    test_two_sorts<vector<int>::iterator, int>(Sorts::insertionSort<vector<int>::iterator>,
                                            Sorts::bubbleSort<vector<int>::iterator>,
                                            "insertion_sort", "bubble_sort",10);

    return 0;
}
