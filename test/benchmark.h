//
// Created by Дима Шестаков on 01.03.2022.
//

#pragma once

#include <iostream>
#include <string>
#include <chrono>
#include <functional>
#include <vector>
#include <random>
#include <iomanip>

using std::cout;
using std::setw;
using std::endl;

struct result
{
    std::string func_name_;
    std::vector<long long> durations_;
    std::vector<int> size_of_range;
};

class Timer
{
public:
    explicit Timer(std::vector<long long>* results);
    ~Timer();
    void Stop();
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> startPoint_;
    std::vector<long long>* results_;
};

template<typename ForwardIterator, typename Type>
void test_sorts(std::function<void(ForwardIterator, ForwardIterator)> func,
                const std::string& name,
                int number_of_tests);


// Random number from interval [a, b]
int random_number(int a, int b);

void print_result(const result& res);







Timer::Timer(std::vector<long long>* results)
{
    startPoint_ = std::chrono::high_resolution_clock::now();
    results_ = results;
}

Timer::~Timer() {
    Stop();
}

void Timer::Stop() {
    auto endPoint_ = std::chrono::high_resolution_clock::now();

    auto start = std::chrono::time_point_cast<std::chrono::microseconds>(startPoint_).time_since_epoch().count();
    auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endPoint_).time_since_epoch().count();

    auto duration = end - start;
    results_->push_back(duration);
}


template<typename ForwardIterator, typename Type>
void test_sorts(std::function<void(ForwardIterator, ForwardIterator)> func,
                const std::string& name,
                int number_of_tests)
{
    result res;
    res.func_name_ = name;

    std::vector<Type> vec;

    for(int i = 0; i < number_of_tests; ++i)
    {
        int size = random_number(1, 1000);
        vec.resize(size);
        res.size_of_range.push_back(size);
        for(auto& j : vec)
            j = random_number(0, 1000);
        {
            Timer timer(&res.durations_);
            func(vec.begin(), vec.end());
        }

    }

    print_result(res);
}

int random_number(int a, int b)
{
    std::random_device random_device;
    std::mt19937 generator(random_device());
    std::uniform_int_distribution<> distribution(a, b);

    return distribution(generator);
}

void print_result(const result& res)
{
    int n = 10;

    cout << setw(10) << "Test of " << res.func_name_ << " function" << endl;

    cout<<"-------------------------------------------\n";
    cout<<"|"<<setw(10)<<"Size of range"<<setw(7)<<"|"<<setw(10)<<"Duration"<<setw(12)<<"|"<<endl;
    cout<<"-------------------------------------------\n";
    for(auto i = 0; i < res.durations_.size(); ++i)
    {
        cout<<"|"<<setw(10)<<res.size_of_range[i]<<setw(10)<<"|"<<
            setw(10)<<res.durations_[i]<<"us"<<setw(10)<<"|"<<endl;
    }

    cout<<"--------------------------------------------\n";
}


template<typename ForwardIterator, typename Type>
void test_two_sorts(std::function<void(ForwardIterator, ForwardIterator)> func1,
                    std::function<void(ForwardIterator, ForwardIterator)> func2,
                    const std::string& name1,
                    const std::string& name2,
                    int number_of_tests)
{
    result res1;
    result res2;

    res1.func_name_ = name1;
    res2.func_name_ = name2;

    std::vector<Type> vec1;
    std::vector<Type> vec2;

    for(int i = 0; i < number_of_tests; ++i)
    {
        int size = random_number(1, 1000);
        vec1.resize(size);
        vec2.resize(size);
        res1.size_of_range.push_back(size);
        res2.size_of_range.push_back(size);

        for(auto j = 0; j < vec1.size(); ++j)
        {
            int rand_num = random_number(0, 1000);
            vec1[i] = rand_num;
            vec2[i] = rand_num;
        }

        {
            Timer timer(&res1.durations_);
            func1(vec1.begin(), vec1.end());
        }

        {
            Timer timer(&res2.durations_);
            func2(vec2.begin(), vec2.end());
        }

    }

    print_result(res1);

    cout << "\n\n";

    print_result(res2);

    cout << "\n\n";
}