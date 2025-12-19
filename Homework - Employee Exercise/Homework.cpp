#include <iostream>
using namespace std;

class clsEmployee
{
private:
    int _ID;
    string _FirstName;
    string _LastName;
    string _Phone;
    string _Email;
    string _Title;
    double _Salary;
    string _Department;   
public:
        clsEmployee(int ID,string FirstName,string LastName,string Phone,string Title,string Email,double Salary,string Department)
        {
            _ID = ID;
            _FirstName = FirstName;
            _LastName = LastName;
            _Phone = Phone;
            _Title = Title;
            _Email = Email;
            _Salary = Salary;
            _Department = Department;
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
         void SetPhone(string Phone)
        {
            _Phone = Phone;
        }
        string GetPhone()
        {
            return _Phone;
        }
        void SetTitle(string Title)
        {
            _Title = Title;
        }
        string GetTitle()
        {
            return _Title;
        }
        void SetEmail(string Email)
        {
            _Email = Email;
        }
        string GetEmail()
        {
            return _Email;
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
        int GetID()
        {
            return _ID;
        }
        string FullName()
        {
            return _FirstName + " " + _LastName;
        }
        void SendEmail(string Subject)
        {
            cout << "\n" << "This email is sent to : " << GetEmail() << endl;
            cout << "Email Subject : " << Subject << endl;
        }
        void SendSMS(string Message)
        {
            cout << "\n" << "This SMS is sent to : " << GetPhone() << endl;
            cout << "Message : " << Message << endl;
        }
        void Print()
        {
            cout << "------------------------------------\n";
            cout << "First Name     : " << GetFirstName() << endl;
            cout << "Last Name      : " << GetLastName() << endl;
            cout << "Full Name      : " << FullName() << endl;
            cout << "ID             : " << GetID() << endl;
            cout << "Title          : " << GetTitle() << endl;
            cout << "Email          : " << GetEmail() << endl;
            cout << "Phone          : " << GetPhone() << endl;
            cout << "Salary         : " << GetSalary() << endl;
            cout << "Department     : " << GetDepartment() << endl;
            cout << "------------------------------------\n";
        }


};

int main()
{
    clsEmployee Employee1(1234,"Yousef","Ali","01553210063","Tech Leader","yousefwesam398@gmail.com",4000,"Programming");
    
    Employee1.SendEmail("Hi, Where are you?");

    Employee1.SendSMS("Please Answer your phone.");

    Employee1.Print();

    return 0;
}