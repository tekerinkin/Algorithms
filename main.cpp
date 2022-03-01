#include "sorts/sorts.h"
#include "test/benchmark.h"
#include <vector>
#include <iostream>

using namespace std;

int main() {

    vector<int> v = {2, 3, 1, 5, 4};

    Sorts::quick_sort(v.begin(), v.end(), std::less<int>());

    for(auto i : v)
        cout << i << " ";

    return 0;
}
