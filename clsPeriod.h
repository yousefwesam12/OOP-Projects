#pragma once
#include <iostream>
#include "clsDate.h"
using namespace std;

class clsPeriod
{

    private:
    clsDate StartDate;
    clsDate EndDate;

    public:
    clsPeriod(clsDate DateFrom,clsDate DateTo)
    {
        this->StartDate = DateFrom;
        this->EndDate = DateTo;
    }
    static bool IsOverlapDates(clsPeriod Period1,clsPeriod Period2)
    {
    if
    (
        clsDate::CompareDates(Period2.EndDate,Period1.StartDate) == clsDate::Before
        ||
        clsDate::CompareDates(Period2.StartDate,Period1.EndDate) == clsDate::After
    ) 
        return false;
    else
    return true;
    }
    bool IsOverlapDates(clsPeriod Period2)
    {
        return IsOverlapDates(*this,Period2);
    }

    static short CountPeriodDays(clsPeriod Period1,bool IncludedLastDay = false)
    {
    short Counter = 0;

    while(clsDate::CompareDates(Period1.StartDate,Period1.EndDate)== clsDate::Before)
    {
        Counter ++;
        Period1.StartDate = clsDate::IncreaseDateByOneDay(Period1.StartDate);
    }
    return IncludedLastDay? ++Counter : Counter;
    }
    short CountPeriodDays(bool IncludedLastDay = false)
    {
        return CountPeriodDays(*this,IncludedLastDay);
    }


    
};

