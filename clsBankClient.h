#include <iostream>
#include <fstream>
#include "clsUtil.h"
#include "clsString.h"
#include "clsPerson.h"

class clsBankClient : public clsPerson
{
    private:
    string _AccountNumber; // Read-Only Property
    string _PinCode;
    double _AccountBalance;
    bool _MarkedForDelete = false;
    enum enMode {EmptyMode = 0 , UpdateMode = 1,AddNewMode = 2};
    enMode _Mode;

    static clsBankClient _ConvertLineToClientObject(string Line,string Sep)
    {
        vector <string> vClientData = clsString::Split(Line,"#//#");

        return clsBankClient(UpdateMode,vClientData[0],vClientData[1],vClientData[2],vClientData[3],vClientData[4],vClientData[5],stod(vClientData[6]));
    }
    
    static clsBankClient _GetEmptyClientObject()
    {
        return clsBankClient(EmptyMode,"","","","","","",0);
    }

    static string _ConvertClientObjectToLine(clsBankClient Client,string Sep = "#//#")
    {
        string Line = "";
        Line += Client.GetFirstName() + Sep;
        Line += Client.GetLastName()  + Sep;
        Line += Client.GetEmail()     + Sep;
        Line += Client.GetPhone()     + Sep;
        Line += Client.GetAccountNumber() + Sep;
        Line += Client.GetPinCode()   + Sep;
        Line += to_string(Client.GetAccountBalance());

        return Line;
    }

    static vector <clsBankClient> _LoadClientsDataFromFile()
    {
        vector <clsBankClient> vClientsData;

        fstream MyFile;
        MyFile.open("Clients.txt",ios::in);

        if(MyFile.is_open())
        {
            string Line;

            while(getline(MyFile,Line))
            {
                clsBankClient Client = _ConvertLineToClientObject(Line,"#//#");
                vClientsData.push_back(Client);
            }

            MyFile.close();
        }

        return vClientsData;
    }

    static void _SaveClientsDataToFile(vector <clsBankClient> vClients)
    {
        fstream MyFile;
        MyFile.open("Clients.txt",ios::out);

        if(MyFile.is_open())
        {
            string DataLine = "";

            for(clsBankClient &Client : vClients)
            {
                if(Client._MarkedForDelete == false)
                {
                     DataLine = _ConvertClientObjectToLine(Client);

                     MyFile << DataLine << endl;
                }
            }

            MyFile.close();
        }
    }

    void _Update()
    {
        vector <clsBankClient> vClients = _LoadClientsDataFromFile();

        for(clsBankClient &C : vClients)
        {
            if(C._AccountNumber == _AccountNumber)
            {
                C = *this; // Updated Object.
            }
        }
        _SaveClientsDataToFile(vClients);
    }

    void _AddDataLineToFile(string Line)
    {
        fstream MyFile;
        MyFile.open("Clients.txt",ios::out|ios::app);

        if(MyFile.is_open())
        {
            MyFile << Line << endl;

            MyFile.close();
        }
    }

    void _AddNew()
    {
        // Adds the new object to the file.
        _AddDataLineToFile(_ConvertClientObjectToLine(*this));
    }

    public:
    clsBankClient(enMode Mode,string FirstName,string LastName,string Phone,string Email,string AccountNumber,string PinCode,double AccountBalance)
    : clsPerson(FirstName,LastName,Email,Phone)
    {
        _Mode = Mode;
        _AccountNumber = AccountNumber;
        _AccountBalance = AccountBalance;
        _PinCode = PinCode;
    }

    string GetAccountNumber()
    {
        return this->_AccountNumber;
    }
    
    void SetPinCode(string PinCode)
    {
        this->_PinCode = PinCode;
    }
    
    string GetPinCode()
    {
        return this->_PinCode;
    }
    
    void SetAccountBalance(double AccountBalance)
    {
        this->_AccountBalance = AccountBalance;
    }
    
    double GetAccountBalance()
    {
        return this->_AccountBalance;
    }

    void Print()
    {
        cout << "\n" << clsUtil::Tabs(1) << "Client Card:";
        cout << "\n" << "------------------------";
        cout << "\n" << "First Name        : " << GetFirstName();
        cout << "\n" << "Last  Name        : " << GetLastName();
        cout << "\n" << "Full  Name        : " << GetFullName();
        cout << "\n" << "Email             : " << GetEmail();
        cout << "\n" << "Phone             : " << GetPhone();
        cout << "\n" << "Acc. Number       : " << GetAccountNumber();
        cout << "\n" << "Password          : " << GetPinCode();
        cout << "\n" << "Balance           : " << GetAccountBalance();
        cout << "\n" << "------------------------\n";
    }

    static clsBankClient Find(string AccountNumber)
    {
        fstream MyFile;
        MyFile.open("Clients.txt",ios::in); // ReadMode

        if(MyFile.is_open())
        {

            string Line = "";
            while(getline(MyFile,Line))
            {
                clsBankClient Client = _ConvertLineToClientObject(Line,"#//#");

                if(Client._AccountNumber == AccountNumber)
                {
                    MyFile.close();
                    return Client;
                }
            }

            MyFile.close();  
        }

        return _GetEmptyClientObject();
    }

    static clsBankClient Find(string AccountNumber,string PinCode)
    {
        fstream MyFile;
        MyFile.open("Clients.txt",ios::in); // ReadMode

        if(MyFile.is_open())
        {

            string Line = "";
            while(getline(MyFile,Line))
            {
                clsBankClient Client = _ConvertLineToClientObject(Line,"#//#");

                if(Client._AccountNumber == AccountNumber && Client._PinCode == PinCode)
                {
                    MyFile.close();
                    return Client;
                }
            }

            MyFile.close();  
        }

        return _GetEmptyClientObject();
    }

    bool IsEmpty()
    {
        return _Mode == EmptyMode;
    }
    
    static bool IsClientExist(string AccountNumber)
    {
        clsBankClient Client = Find(AccountNumber);

        return !(Client.IsEmpty());
    }

    enum enSaveResults {svFailedEmptyObject = 0,svSucceeded = 1,svFailedAccountNumberUsed = 2,svFailedAccountNumberIsNotFound=3};
    
    enSaveResults Save()
    {
        switch(_Mode)
        {
            case enMode::EmptyMode:
                return svFailedEmptyObject;

            case enMode::UpdateMode:
                _Update();
                return svSucceeded;

            case enMode::AddNewMode:
                if(IsClientExist(_AccountNumber))
                {
                    return enSaveResults::svFailedAccountNumberUsed;
                }
                else
                {
                   _AddNew();
                   this->_Mode = enMode::UpdateMode; 
                   return enSaveResults::svSucceeded;
                }
        }
    }

    static clsBankClient GetAddNewClientObject(string AccountNumber)
    {
        return clsBankClient(enMode::AddNewMode,"","","","",AccountNumber,"",0);
    }

    bool Delete()
    {
        vector <clsBankClient> vClients = _LoadClientsDataFromFile();

        for(clsBankClient &C : vClients)
        {
            if(C._AccountNumber == _AccountNumber)
            {
                C._MarkedForDelete = true;
                break;
            }
        }
        _SaveClientsDataToFile(vClients);
        *this = _GetEmptyClientObject();
        return true;
    }

    static vector <clsBankClient> GetClientsList()
    {
        return _LoadClientsDataFromFile();
    }

    static double GetTotalBalances()
    {
        double Balance = 0;

        vector <clsBankClient> vClientData = _LoadClientsDataFromFile();

        for(clsBankClient &C : vClientData)
        {
            Balance += C._AccountBalance;
        }

        return Balance;
    }

};
