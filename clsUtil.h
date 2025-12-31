#include <iostream>
#include "clsDate.h"

using namespace std;

class clsUtil
{
    public:
    static void Srand()
    {
        srand((unsigned)time(NULL));
    }
    
    static int RandomNumber(const int From,const int To)
    {
        return rand() % (To-From+1) + From;
    }
    enum enCharType {CapitalLetter=1,SmallLetter,Digit,MixChars,Special}; 
    static char GetRandomChar(enCharType CharType)
    {
        if(CharType == MixChars)
        {
            CharType = enCharType(RandomNumber(1,3));
        }

        switch(CharType)
        {
            case CapitalLetter:
                return char(RandomNumber(65,90));
            case SmallLetter:
                return char(RandomNumber(97,122));
            case Special:
                return char(RandomNumber(33,47));
            case Digit:
                return char(RandomNumber(48,57)); 
            default:
                break; 
        }

    }
    static string GenerateWord(enCharType CharType,short Length)
    {
        string Word;

        for (int i = 0;i<Length;i++)
        {
            Word += GetRandomChar(CharType);
        }
        return Word;
    }
    static string GenerateKey(enCharType CharType)
    {
        string Key;

        Key  = GenerateWord(CharType,4) + "-";
        Key += GenerateWord(CharType,4) + "-";
        Key += GenerateWord(CharType,4) + "-";
        Key += GenerateWord(CharType,4);

        return Key;
    }
    static void GenerateKeys(short NumOfKeys,enCharType CharType)
    {
        for(int i = 1;i<=NumOfKeys;i++)
        {
            cout << "Key ["<<i<<"] : ";
            cout << GenerateKey(CharType);
            cout << "\n";
        }
    }
    static void Swap(int &A,int &B)
    {
        int Temp = A;
        A = B;
        B = Temp;
    }
    static void Swap(double &A,double &B)
    {
        double Temp = A;
        A = B;
        B = Temp;
    }
    static void Swap(string &A,string &B)
    {
        string Temp = A;
        A = B;
        B = Temp;
    }
    static void Swap(clsDate &Date1,clsDate &Date2)
    {
        clsDate::SwapDates(Date1,Date2);
    }
    static void ShuffleArray(int Arr1[],int ArrLen)
    {
        // {1,2,3,4,5}
        // {2,3,1,4,5}
        for(int i = 0;i<ArrLen;i++)
        {
            Swap(Arr1[RandomNumber(1,ArrLen)-1],Arr1[RandomNumber(1,ArrLen)-1]);
        }
    }
    static void ShuffleArray(string Arr1[],int ArrLen)
    {
        // {1,2,3,4,5}
        // {2,3,1,4,5}
        for(int i = 0;i<ArrLen;i++)
        {
            Swap(Arr1[RandomNumber(1,ArrLen)-1],Arr1[RandomNumber(1,ArrLen)-1]);
        }
    }

};
