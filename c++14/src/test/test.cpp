/*
 * Initiated by Jared on March 5, 2017.
 *
 * Test suite for features introduced in C++11/14.
 *
 */

#include <iostream>

#include "concurrent/basic.hpp"

using namespace std;

int
main(int argc, char** argv)
{
    BasicConcurrent::test_join();
    BasicConcurrent::test_detach();
    BasicConcurrent::test_yield();
    cout<<"all theads related tests are completed."<<endl;

}

