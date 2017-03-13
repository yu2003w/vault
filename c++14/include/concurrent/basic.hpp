/*
 * Initiated by Jared on March 05, 2017.
 *
 * Header for basic concept of mult-thread supporting in C++11/14.
 */

#ifndef __BASIC_CONCURRENT_HPP__
#define __BASIC_CONCURRENT_HPP__

#include <atomic>
#include <iostream>

class BasicConcurrent
{
public:
    static void test_join();
    static void test_yield();
    static void test_detach();

private:
    static void funny();
    static void fun1(int, const std::string&);
    
    static void pause_thread(int);

    static void count_num(int);

    static std::atomic<bool> ready;
    static std::atomic_flag winner;
};

#endif
 
