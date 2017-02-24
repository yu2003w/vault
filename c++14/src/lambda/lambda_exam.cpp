/*
 *
 * Initiated by Jared on March 2, 2017.
 *
 */

#include <iostream>
#include <lambda/lambda_exam.hpp>

using namespace std;

void
LambdaExam::test_basic()
{
    int a = 2;
    auto f = [=]() { return a*2; };
    auto val = f();
    cout<<val<<endl;
    return; 
}
