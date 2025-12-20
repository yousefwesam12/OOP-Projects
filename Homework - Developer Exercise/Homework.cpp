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

    clsPerson()
    {

    };

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
    string GetPhone(){
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

class clsEmployee : public clsPerson
{
    string _Title;
    double _Salary;
    string _Department;

public:

    clsEmployee(int ID,string FirstName,string LastName,string Email,string Phone,string Title,double Salary,string Department) // Put as many parameters as you want.
     : clsPerson(ID,FirstName,LastName,Email,Phone) // after : you write the super class constructor, and note that we didn't write the data type.
    {
        _Title = Title;
        _Department = Department;
        _Salary = Salary;
    }
     void SetTitle(string Title)
    {
        _Title = Title;
    }
    string GetTitle()
    {
        return _Title;
    }
    void SetSalary(double Salary)
    {
         _Salary = Salary;
    }
    double GetSalary()
    {
        return _Salary;
    }
    void SetDepartment(string Department)
    {
         _Department = Department;
    }
    string GetDepartment()
    {
        return _Department;
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
        cout<<"Department:"<<GetDepartment()<<endl;
        cout<<"Salary    :"<<GetSalary() << endl;
        cout<<"Title     :"<<GetTitle()<<endl;
        cout<<"_________________________\n";
    }
  
};

class clsDeveloper : public clsEmployee
{
    private:
    string _MainProgrammingLangauge;

    public:

    clsDeveloper(int ID,string FirstName,string LastName,string Email,string Phone,string Title,double Salary,string Department,string MainProgrammingLanguage) 
    : clsEmployee(ID,FirstName,LastName,Email,Phone,Title,Salary,Department)
    {
        _MainProgrammingLangauge = MainProgrammingLanguage;
    }

    void SetMainProgrammingLanguage(string MainProgrammingLangauge)
    {
        _MainProgrammingLangauge = MainProgrammingLangauge;
    }
    string GetMainProgrammingLanguage()
    {
        return _MainProgrammingLangauge;
    }
    void Print() // Override for developer.
    {
        cout<<"Info:\n";
        cout<<"_________________________\n";
        cout<<"ID       : "<<GetID()<<endl;
        cout<<"FirstName: "<<GetFirstName()<<endl;
        cout<<"LastName : "<<GetLastName()<<endl;
        cout<<"Full Name: "<<GetFullName()<<endl;
        cout<<"Email    : "<<GetEmail()<<endl;
        cout<<"Phone    : "<<GetPhone()<<endl;
        cout<<"Department:"<<GetDepartment()<<endl;
        cout<<"Salary    :"<<GetSalary() << endl;
        cout<<"Title     :"<<GetTitle()<<endl;
        cout<<"Programming Language:"<<GetMainProgrammingLanguage()<<endl;
        cout<<"_________________________\n";
    }
};

int main()
{
    clsDeveloper Developer(1234,"Yousef","Wesam","yousef@gmail.com","092194214","Tecg Leader",3000,"Tech","C++");

    Developer.Print();
}   