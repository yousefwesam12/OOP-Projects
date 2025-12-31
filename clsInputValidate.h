#include <iostream>
#include "clsDate.h"
#include "clsUtil.h"

using namespace std;

class clsInputValidate
{
    public:
    static bool IsNumberBetween(int Number,int From,int To)
    {
        return !(Number<From || Number>To);
    }
    static bool IsNumberBetween(double Number,double From,double To)
    {
         return !(Number<From || Number>To);
    }
    static bool IsNumberBetween(short Number,short From,short To)
    {
         return !(Number<From || Number>To);
    }
    static bool IsNumberBetween(float Number,float From,float To)
    {
         return !(Number<From || Number>To);
    }
    static bool IsDateBetween(clsDate Date,clsDate Date1,clsDate Date2)
    {
        if(clsDate::IsDate1AfterDate2(Date1,Date2))
        {
            clsUtil::Swap(Date1,Date2);
        }
        return !(Date.IsDate1BeforeDate2(Date1) || Date.IsDate1AfterDate2(Date2));
    }
    static bool IsValidDate(clsDate Date)
    {
        return clsDate::IsValidDate(Date);
    }
    static int  ReadIntNumber(string ErrorMessage = "Invalid Number, Enter again\n")
    {
        int Number = 0;
        cin >> Number;

        while (cin.fail())   
       {
        // user didn't input a number    
        cin.clear();  
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');   

        cout << ErrorMessage << endl; 
        cin >> Number;     
        } 
       return Number; 
    }
    static int  ReadIntNumberBetween(int From,int To,string ErrorMessage = "Number is not within range, Enter again:\n")
    {
        int Number = ReadIntNumber();
        while(!IsNumberBetween(Number,From,To))
        {
            cout << ErrorMessage << endl;
            int Number = ReadIntNumber();
        }   
        return Number;
    }
    static double ReadDoubleNumber(string ErrorMessage = "Invalid Number, Enter again\n")
    {
        double Number = 0;
        cin >> Number;

        while (cin.fail())   
       {
        // user didn't input a number    
        cin.clear();  
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');   

        cout << ErrorMessage<< endl; 
        cin >> Number;     
        } 
        return Number;
    }
    static double ReadDoubleNumberBetween(double From,double To,string ErrorMessage = "Number is not within range, Enter again:\n")
    {
        double Number = ReadDoubleNumber();

        while(!IsNumberBetween(Number,From,To))
        {
            cout << ErrorMessage << endl;
            double Number = ReadDoubleNumber();
        }
        return Number;
    
    }

};  
