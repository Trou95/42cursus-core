#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <chrono>
#include <unistd.h>

#include "../vector.hpp"
#include "../map.hpp"
#include "../stack.hpp"

#include "tester.h"


inline std::chrono::high_resolution_clock::time_point gettime()
{
    return std::chrono::high_resolution_clock::now();
}


void vector_test_run()
{
    std::vector<int> vector_stl;
    ft::vector<int> vector_implement;

    int i = 0;

    std::cout << "Starting Vector Tester.." << std::endl;
    sleep(1);
    std::cout << "VECTOR: ";

    for(; i < 100; i++) {
        vector_stl.push_back(i);
        vector_implement.push_back(i);
    }
    for(i = 0; i < 100; i++) {
        if(vector_implement[i] != vector_stl[i])
            break;
    }
    printf(i == 100 ? "[OK] " : "[ERROR] ");
    std::cout << std::flush;
    sleep(1);

    printf(vector_stl.capacity() == vector_implement.capacity() ? "[OK] " : "[ERROR] ");
    std::cout << std::flush;
    sleep(1);

    vector_stl.insert(vector_stl.begin() + 2, 1);
    vector_implement.insert(vector_implement.begin() + 2, 1);
    for(i = 0; i < 100; i++) {
        if(vector_implement[i] != vector_stl[i])
        {
            std::cout << i << " " << vector_stl[i] << " " << vector_implement[i] << std::endl;
        }
    }
    printf(i == 100 ? "[OK] " : "[ERROR] ");
    std::cout << std::flush;
    sleep(1);

    vector_stl.erase(vector_stl.begin() + 2);
    vector_implement.erase(vector_implement.begin() + 2);
    for(i = 0; i < 100; i++) {
        if(vector_implement[i] != vector_stl[i])
            break;
    }
    printf(i == 100 ? "[OK] " : "[ERROR] ");
    std::cout << std::flush;
    sleep(1);

    vector_stl.clear();
    vector_implement.clear();
    printf(vector_stl.size() == vector_implement.size() ? "[OK] " : "[ERROR] ");
    std::cout << std::endl;
    sleep(1);

    vector_speed_test();

}

void vector_speed_test()
{
    std::vector<int> vector_stl;
    ft::vector<int> vector_implement;

    unsigned long long avarage_time_stl = 0;
    unsigned long long avarage_time = 0;



    std::cout << "Starting Vector Speed Test.." << std::endl;
    for(int i = 0; i < 30; i++) {
        std::cout << "-" << std::flush;
        usleep(1000 * 100);
    }

    std::cout << std::endl;

    std::cout << "\tPUSH BACK" << std::endl;
    std::cout << "------------------------------" << std::endl;

    for(int i = 0; i < TEST_COUNT; i++)
    {
        std::chrono::high_resolution_clock::time_point start = gettime();
        for(unsigned long long p = 0; p < COUNT; p++)
            vector_stl.push_back(1);
        avarage_time_stl += std::chrono::duration_cast<std::chrono::microseconds>(gettime() - start).count();
    }

    std::cout << "VECTOR STL: " << avarage_time_stl / TEST_COUNT << "ms" << std::endl;

    for(int i = 0; i < TEST_COUNT; i++)
    {
        std::chrono::high_resolution_clock::time_point start = gettime();
        for(unsigned long long p = 0; p < COUNT; p++)
            vector_implement.push_back(1);
        avarage_time += std::chrono::duration_cast<std::chrono::microseconds>(gettime() - start).count();
    }

    std::cout << "VECTOR: " << avarage_time / TEST_COUNT << "ms" << std::endl;


    vector_stl.resize(0);
    vector_implement.resize(0);
    avarage_time_stl = 0;
    avarage_time = 0;

    std::cout << "------------------------------" << std::endl;
    std::cout << "\tINSERT" << std::endl;
    std::cout << "------------------------------" << std::endl;




    {
        std::chrono::high_resolution_clock::time_point start = gettime();

        for(unsigned long long p = 0; p < COUNT; p++)
            vector_stl.insert(vector_stl.begin(), 1);

        std::cout << "VECTOR STL: " << std::chrono::duration_cast<std::chrono::milliseconds>(gettime() - start).count() << "ms" << std::endl;
    }

    {
        std::chrono::high_resolution_clock::time_point start = gettime();

        for(unsigned long long p = 0; p < COUNT; p++)
            vector_implement.insert(vector_implement.begin(), 1);

        std::cout << "VECTOR: " << std::chrono::duration_cast<std::chrono::milliseconds>(gettime() - start).count() << "ms" << std::endl;

    }




    ft::map<int,std::string> v3;
    std::map<int,std::string> v4;


    {
        std::chrono::high_resolution_clock::time_point start = gettime();

        for(int i = 0; i < 10000; i++)
            v4.insert(std::pair<int,std::string>(i * 2,"adasd"));

        std::cout << "MAP STL: " << std::chrono::duration_cast<std::chrono::milliseconds>(gettime() - start).count() << "ms" << std::endl;

    }

    {

        std::chrono::high_resolution_clock::time_point start = gettime();

        for(int i = 0; i < 10000; i++)
            v3.insert(ft::pair<int,std::string>(i * 2,"adasd"));

        std::cout << "MAP: " << std::chrono::duration_cast<std::chrono::milliseconds>(gettime() - start).count() << "ms" << std::endl;

    }







}


int main()
{
    vector_test_run();
}
