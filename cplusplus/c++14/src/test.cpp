/*
 *
 * Initiated by Jared on Feb 23, 2017.
 *
 * Test new features for C++.
 *
 */

#include<iostream>
#include<utility>
#include<algorithm>
#include<vector>

#include "misc.hpp"

using namespace std;

void
test_move()
{
    string val1 = "String 1 for testing std::move()";
    string val2 = "string 2 for testing std::move()";
    cout<<"before run std::move()"<<endl<<"string1-->"<<val1<<endl<<"string2-->"<<val2<<endl;
    val2 = move(val1);
    cout<<"after run std::move()"<<endl<<"string1-->"<<val1<<endl<<"string2-->"<<val2<<endl;
}

void
printVec(const vector<string> & vec)
{
    for (string val:vec)
         cout<<val<<" ";
}

void
test_moverange()
{
    vector<string> vec1 = {"This", "is", "testing", "data", "in", "vector."};
    vector<string> vec2(10);
    // default capacity is 0
    cout<<"vector<string> vec2; capacity is "<<vec2.capacity()<<endl;
    
    cout<<"before run std::move()"<<endl<<"vector1-->";
    printVec(vec1);
    cout<<endl<<"vector2-->";
    printVec(vec2);
    move(vec1.begin(), vec1.end(), vec2.begin());
    cout<<endl<<"after run std::move()"<<endl<<"vector1-->";
    printVec(vec1);
    cout<<endl<<"vector2-->";
    printVec(vec2);
    
    vec1 = move(vec2);
    cout<<endl<<"after call move(vec2)"<<endl<<"vec1-->";
    printVec(vec1);
    cout<<endl<<"vec2-->";
    printVec(vec2);
    cout<<endl;
}

int
main(int argc, char** argv)
{

    auto * misc = new MiscFeature();
    
    auto val = misc->getData();
    cout<<val<<endl;
    auto ret = misc->setData(6);
    cout<<ret<<endl;
    auto val1 = misc->testauto();
    cout<<val1<<endl;
    
    test_move();   
    test_moverange();
}

