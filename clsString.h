#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

enum enWhatToCount {CapitalLetters = 1 , SmallLetters = 2 , All = 3 };


class clsString
{

    private:
    string _Value;
    vector <string> vClass;

    public:
    clsString()
    {
        this->_Value = "";
    }
    clsString(string Value)
    {
        this->_Value = Value;
    }
    void SetValue(string Value)
    {
        this->_Value = Value;
    }
    string GetValue()
    {
        return this->_Value;
    }
    static short CountWords(string S1) 
    {
    string delim = " ";
    std::string::size_type pos = 0;
    short counter = 0;
    string sWord;
    while ((pos = S1.find(delim)) != std::string::npos) 
    {
        
        sWord = S1.substr(0, pos);

        if (sWord != "")
        {
            counter++;
        }

        S1.erase(0, pos + delim.length());
        
    }
    if (S1 != "") 
    {
        counter++;
    }
    return counter;
    }

    short CountWords() 
    {
        return CountWords(this->_Value);
    }

    static string TrimLeft(string S1)
    {
        for (std::string::size_type i = 0; i < S1.length(); ++i) 
        {
            if (S1[i] != ' ') 
            {
                return S1.substr(i, S1.length() - i);
            }
        }
    }
    string TrimLeft()
    {
        return TrimLeft(this->_Value);
    }
    static string TrimRight(string S1)
    {
        if (S1.empty()) return S1;
        for (std::string::size_type i = S1.length(); i-- > 0; )
        {
            if (S1[i] != ' ')
            {
                return S1.substr(0, i+1);
            }
        }
        return string("");
    }
    string TrimRight()
    {
        return TrimRight(this->_Value);
    }
    static string Trim(string S1) 
    {
    return TrimLeft(TrimRight(S1));
    }   
    string Trim()
    {
        return TrimLeft(TrimRight(this->_Value));
    }
    static void PrintFirstLetterOfEachWord(string S1) 
    {
    bool isFirstLetter = true;
    cout << "\nFirst Letters Of this String : \n";
        for (std::string::size_type i = 0 ; i < S1.length(); ++i) 
        {
            if (S1[i] != ' ' && isFirstLetter) 
            {
                cout << S1[i] << endl;
            }
            isFirstLetter = (S1[i] == ' ' ? true : false);
        }
    }
    void PrintFirstLetterOfEachWord() 
    {
        PrintFirstLetterOfEachWord(this->_Value); 
    }
    static string UpperFirstLetterOfEachWord(string S1) 
    {
        bool isFirstLetter = true;

        for (std::string::size_type i = 0; i < S1.length(); ++i) 
        {

           if (S1[i] != ' ' && isFirstLetter) 
            {
             S1[i] = toupper(S1[i]);
            }
             isFirstLetter = (S1[i] == ' ' ? true : false);
        }
        return S1;
    }
    string UpperFirstLetterOfEachWord() 
    {
        return UpperFirstLetterOfEachWord(this->_Value); 
    }
    static string LowerFirstLetterOfEachWord(string S1) 
    {
        bool isFirstLetter = true;

        for (std::string::size_type i = 0; i < S1.length(); ++i) 
        {
            if (S1[i] != ' ' && isFirstLetter) 
            {
              S1[i] = tolower(S1[i]);
            }
              isFirstLetter = (S1[i] == ' ' ? true : false);
        }
        return S1;
    }
    string LowerFirstLetterOfEachWord()
    {
        return LowerFirstLetterOfEachWord(this->_Value);
    }
    static string UpperAllString(string S1) 
    {
        for (std::string::size_type i = 0; i < S1.length(); ++i) 
        {
            S1[i] = toupper(S1[i]);
        }
        return S1;
    }
    string UpperAllString() 
    {
        return UpperAllString(this->_Value);
    }

    static string LowerAllString(string S1) 
    {
        for (std::string::size_type i = 0; i < S1.length(); ++i) 
        {
            S1[i] = tolower(S1[i]);
        }
            return S1;
    }
    string LowerAllString()
    {
        return LowerAllString(this->_Value);
    }

    static char InvertLetterCase(char Ch1) 
    {
        return isupper(Ch1) ? tolower(Ch1) : toupper(Ch1);
    }
    static string InvertAllStringLettersCase(string S1) 
    {
        for (std::string::size_type i = 0; i < S1.length(); ++i) 
        {
            S1[i] = InvertLetterCase(S1[i]);
        }
            return S1;
    }
    string InvertAllStringLettersCase()
    {
        return InvertAllStringLettersCase(this->_Value);
    }
    static short CountLetters(string S1, enWhatToCount WhatToCount = enWhatToCount::All) 
    {  
        if (WhatToCount == enWhatToCount::All) 
        {
            return S1.length();
        }

        short counter = 0;

        for (std::string::size_type i = 0; i < S1.length(); ++i)
        {
            if (WhatToCount == enWhatToCount::CapitalLetters && isupper(S1[i])) 
            {
            counter++;
            }
            if (WhatToCount == enWhatToCount::SmallLetters && islower(S1[i])) 
            {
            counter++;
            }
        }
        return counter;
    }
    short CountLetters()
    {
        return CountLetters(this->_Value);
    }

    static short CountCapitalLetters(string S1) 
    {
    short counter = 0;

        for (std::string::size_type i = 0; i < S1.length(); ++i) 
        {
            if (isupper(S1[i]))
            {
                counter++;
            }
        }
    return counter;
    }
    short CountCapitalLetters()
    {
        return CountCapitalLetters(this->_Value);
    }
    static short CountSmallLetters(string S1) 
    {
    short counter = 0;

        for (std::string::size_type i = 0; i < S1.length(); ++i) 
        {
            if (islower(S1[i]))
            {
                counter++;
            }
        }
    return counter;
    }
    short CountSmallLetters()
    {
        return CountSmallLetters(this->_Value);
    }
    static short CountLetterInString(string S1 , char Letter) 
    {

    short counter = 0;

        for (std::string::size_type i = 0; i < S1.length(); ++i) 
        {
            if (S1[i]== Letter) 
            {
                counter++;
            }

        }
        return counter;
    }
    short CountLetterInString(char Letter)
    {
        return CountLetterInString(this->_Value,Letter);
    }

    static short CountLetter(string S1 , char Letter , bool MatchCase = true) 
    {

    short counter = 0;

    for (std::string::size_type i = 0; i < S1.length(); ++i) 
    {

        if (MatchCase) 
        {

            if (S1[i] == Letter) 
            {
                counter++;
            }

        }
        else 
        {
            if (tolower(S1[i]) == tolower(Letter)) 
            {
                counter++;
            }
        }
    }
    return counter;
    }
    short CountLetter(char Letter)
    {
        return CountLetter(this->_Value,Letter);
    }
    static bool IsVowel(char Ch1) 
    {
        Ch1 = tolower(Ch1);
        return ((Ch1 == 'a') || (Ch1 == 'e') || (Ch1 == 'i') || (Ch1 == 'o') || (Ch1 == 'u'));
    }
    static short CountVowels(string S1) 
    {
    short counter = 0;

    for (std::string::size_type i = 0; i < S1.length(); ++i)
     {

        if (IsVowel(S1[i])) 
        {
            counter++;
        }

    }
    return counter;
    }
    short CountVowels()
    {
        return CountVowels(this->_Value);
    }
    static void PrintVowels(string S1) 
    {
        for (std::string::size_type i = 0; i < S1.length(); ++i)
        {

            if (IsVowel(S1[i])) 
            {
                cout << S1[i] << "   ";
            }
        }
    }
    void PrintVowels()
    {
        PrintVowels(this->_Value);
    }
    static void PrintEachWordInString(string S1) 
    {

    string delim = " ";
    std::string::size_type pos = 0;
    string sWord;

    cout << "\nYour String Words Are : \n\n";

    while ((pos = S1.find(delim)) != std::string::npos) 
    {

        sWord = S1.substr(0, pos);

           if (sWord != "")
            {
            cout << sWord << endl;
            }

        S1 = S1.erase(0, pos + delim.length());
    }


        if (S1 != "") 
        {
        cout << S1 << endl;
        }
    }
    void PrintEachWordInString()
    {
        PrintEachWordInString(this->_Value);
    }
    static vector <string> Split(string S1 , string Delim = " ") 
    {

    vector <string> vString;
    string sWord;
    std::string::size_type pos = 0;

    while ((pos = S1.find(Delim)) != string::npos) 
    {

        sWord = S1.substr(0, pos);

        if (sWord != "") {

            vString.push_back(sWord);

        }

        S1 = S1.erase(0, pos + Delim.length());

    }

  
    if (S1 != "") 
    {

        vString.push_back(S1);

    }

    return vString;

    }
    vector <string> Split(string Delim)
    {
        return Split(this->_Value,Delim);
    }
    static string JoinString(vector <string> vString , string delim) 
    {

	string S1 = "";

	for (string& s : vString) 
    {

		S1 = S1 + s + delim;

	}

	S1 = S1.substr(0, S1.length() - delim.length());

	return S1;
    }
    string JoinString(string Delim)
    {
        this->vClass = Split(this->_Value,Delim);

        return JoinString(this->vClass,Delim);
    }

    static string ReverseWordsInString(string S1) 
    {

        vector <string> vString;
        string S2 = "";
    
        vString = Split(S1, " ");

        vector <string>::iterator iter = vString.end();

        while (iter != vString.begin()) 
        {   

            --iter;

            S2 += *iter + " ";
        }

        S2 = S2.substr(0, S2.length() - 1);

        return S2;

    }
    string ReverseWordsInString()
    {
        return ReverseWordsInString(this->_Value);
    }
    static string RemovePunctuationsFromString(string S1) 
    {

    string S2 = "";

    for (std::string::size_type i = 0; i < S1.length(); ++i) 
    {
        
        if (!ispunct(S1[i]))
              S2 += S1[i];
        
    }
    return S2;

    }
    string RemovePunctuationsFromString()
    {
        return RemovePunctuationsFromString(this->_Value);
    }
    
    static string ReplaceWordInStringUsingSplit(string S1 , string StringToReplace , string sReplaceTo ,bool MatchCase = true )
    {

    vector <string> vString;
    vString = Split(S1 , " ");

    for (string& s : vString) 
    {
        
        if (s == StringToReplace && MatchCase) 
        {
            s = sReplaceTo;
        }
        else if (LowerAllString(s) == LowerAllString(StringToReplace) && !MatchCase) 
        {
            s = sReplaceTo;
        }

    }
    return  JoinString(vString," ");
    }
 
    string ReplaceWordInStringUsingSplit(string StringToReplace,string sReplaceTo,bool MatchCase)
    {
        return ReplaceWordInStringUsingSplit(this->_Value,StringToReplace,sReplaceTo,MatchCase);
    }

};