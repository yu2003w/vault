/*
 * Initiated by Jared on Feb 23, 2017,
 *
 */

#include <misc/misc.hpp>

MiscFeature::MiscFeature()
{
    data = 5;      
}

int MiscFeature::getData()
{
    return data;
}

bool MiscFeature::setData(int i)
{
    data = i;
    return true;
}

