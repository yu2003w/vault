/*
 * Initiated by Jared on Feb 23, 2017.
 *
 *
 * Code to test C++ 14 features.
 *
 *
 */

#ifndef __MISC_HPP__
#define __MISC_HPP__

class MiscFeature
{

public:
    MiscFeature();
    int getData();
    bool setData(int);

    // c++11 only support deduce type for lambda functions
    //auto testauto() { return 7;}

private:
    int data;

};

#endif

