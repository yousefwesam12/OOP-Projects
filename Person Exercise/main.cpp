#include <iostream>
using namespace std;

class clsPerson
{
    int _ID;
    string _FirstName;
    string _LastName;
    string _Email;
    string _Phone;

    static bool IsValidEmail(string Email)
    {
        return Email.find('@') != std::string::npos;
    }

public:
    clsPerson(int ID,string FirstName,string LastName,string Email,string Phone)
    {
        _ID = ID;
        _FirstName = FirstName;
        _LastName = LastName;
        _Phone = Phone;

        if (IsValidEmail(Email))
            _Email = Email;
        else
            _Email = "user@gmail.com";
    }

    void SetFirstName(string FirstName)
    {
        _FirstName = FirstName;
    }
    string GetFirstName()
    {
        return _FirstName;
    }
    void SetLastName(string LastName)
    {
        _LastName = LastName;
    }
    string GetLastName()
    {
        return _LastName;
    }
    void SetEmail(string Email)
    {
        if (IsValidEmail(Email))
            _Email = Email;
        else
            _Email = "User@gmail.com";
    }
    string GetEmail()
    {
        return _Email;
    }
    string GetFullName()
    {
        return GetFirstName() + "  " + GetLastName();
    }
    void SetPhone(string Phone)
    {
        _Phone = Phone;
    }
    string GetPhone() {
        return _Phone;
    }
    int GetID()
    {
        return _ID;
    }

    void SendEmail(string Subject,string Body)
    {
        cout << "\nThe Following message sent successfully to email: " << GetEmail();
        cout << "\nSubject: " <<Subject;
        cout << "\nBody: " <<Body;
    }
    void SendSMS(string SMS)
    {
        cout << "\nThe Following SMS sent successfully to Phone: " << GetPhone();
        cout << "\n" << SMS << endl;
    }
    void Print()
    {
        cout<<"Info:\n";
        cout<<"_________________________\n";
        cout<<"ID       : "<<GetID()<<endl;
        cout<<"FirstName: "<<GetFirstName()<<endl;
        cout<<"LastName : "<<GetLastName()<<endl;
        cout<<"Full Name: "<<GetFullName()<<endl;
        cout<<"Email    : "<<GetEmail()<<endl;
        cout<<"Phone    : "<<GetPhone()<<endl;
        cout<<"_________________________\n";

    }


};

int main()
{
    clsPerson Person1(10,"Mohammad","Abu-Hadhoud","my@gmail.com","0098376727");

    Person1.Print();

    Person1.SendEmail("Hi","How are you?");

    Person1.SendSMS("How are you?");

}
