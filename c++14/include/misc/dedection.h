/*
Initialized by Jared on Dec 22, 2023.
To test some features for type deduction defined by C++ 11/14.
*/

#ifndef _DEDUCTION_H_
#define _DEDUCTION_H_
// function templates

// parameters passed by value
template<typename T>
void funcbyvalue(const T para);

// parameters passed by reference
template<typename T>
void funcbyref(const T& para);

// parameters passed by pointer
template<typename T>
void funcbypointer(T* para);

// parameters passed by universal reference
template<typename T>
void funcbyuniref(const T&& para);


#endif