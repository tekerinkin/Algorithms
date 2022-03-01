#include "sorts/sorts.h"
#include "test/benchmark.h"
#include <vector>
#include <iostream>

using namespace std;

struct MyClass
{
    int first;
    int second;
};

bool comp(MyClass& m1, MyClass& m2)
{
    return m1.first > m2.first || m1.second > m2.second;
}



int main() {

   vector<MyClass> v = {{1,2}, {3, 2}, {2, 3}, {2, 2}};

   Sorts::mergeSort(v, comp);


    for(auto& i : v)
        cout << i.first  << ", " << i.second << "\n";

    return 0;
}
