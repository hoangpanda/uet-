#include <iostream>
#include <cstdlib>
using namespace std;

void result(int num1, int num2, char op) 
{
    switch(op) 
    {
        case '+': 
            cout << num1 + num2 << endl;
            break;
        case '-':
            cout << num1 - num2 << endl;
        case '/':
            if(num2 == 0) 
                cout << "Invalid divisor" << endl;
            else 
                cout << num1 / num2 << endl;
            break;
        case '*':
            cout << num1 * num2 << endl;
            break;
        case '%':
            if(num2 == 0)
                cout << "Invalid divisor" << endl;
            else 
                cout << num1 % num2 << endl;
            break;
        default:
            cout << "Invalid operator" << endl;
    }
}

int main(int argc, char* argv[]) {
    int num1,num2;
    char op;

    num1 = atoi(argv[1]);
    op = argv[2][0];
    num2 = atoi(argv[3]);

    result(num1,num2,op);

    return 0;
}