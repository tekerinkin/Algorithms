#include "sorts/sorts.h"
#include <vector>
#include <iostream>

using namespace std;

int main() {

    vector<int> v = {2, 3, 1, 5, 4};

    Sorts::selectionSort(v.begin(), v.end());

    for(auto i : v)
        cout << i << " ";

    return 0;
}
