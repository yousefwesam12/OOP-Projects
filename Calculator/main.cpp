#include <iostream>
using namespace std;

class clsCalculator
{
private:
    int _Num = 0;
    int _EnterdNum = 0;
    char Operation = ' ';

    void SetNum(int Num)
    {
        _Num = Num;
    }
    int GetNum()
    {
        return _Num;
    }
    string GetOperation(char Operation)
    {
        switch (Operation)
        {
            case '+':
                return "Adding";

            case '-':
                return "Subtracting";

            case '*':
                return "Multiplying";

            case '/':
                return "Dividing";

            default:
                return "Clear";
        }
    }

public:
    void Add(int Num)
    {
        Operation = '+';
        _EnterdNum = Num;
        SetNum(GetNum() + Num);
    }
    void Subtract(int Num)
    {
        Operation = '-';
        _EnterdNum = Num;
        SetNum(GetNum() - Num);
    }
    void Multiply(int Num)
    {
        Operation = '*';
        _EnterdNum = Num;
        SetNum(GetNum() * Num);
    }
    void Divide(int Num)
    {
        Operation = '/';
        if (Num == 0)
            Num = 1;
        _EnterdNum = Num;
        SetNum(GetNum()/Num);
    }
    void Clear()
    {
        Operation = ' ';
        _EnterdNum = 0;
        SetNum(0);
    }
    void PrintResult()
    {
        cout<<"Result After "<<GetOperation(Operation)<<" "<<_EnterdNum<<" is "<<GetNum()<<endl;
    }

};

int main()
{
    clsCalculator Calculator1;

    Calculator1.Clear();
    Calculator1.Add(10);
    Calculator1.PrintResult();

    Calculator1.Add(100);
    Calculator1.PrintResult();

    Calculator1.Subtract(20);
    Calculator1.PrintResult();

    Calculator1.Divide(0);
    Calculator1.PrintResult();

    Calculator1.Divide(2);
    Calculator1.PrintResult();

    Calculator1.Multiply(3);
    Calculator1.PrintResult();

    Calculator1.Clear();
    Calculator1.PrintResult();

    return 0;
}
