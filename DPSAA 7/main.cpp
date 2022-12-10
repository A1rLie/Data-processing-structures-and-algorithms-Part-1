#include <iostream>
#include <vector>

using namespace std;

#define MAX_SIZE 100

class Stack
{
private:
    int stack[MAX_SIZE] = { 0 };
    int size = 0;

public:
    
    int getSize()
    {
        return this->size;
    }

    void push_back(int newData)
    {
        if (size == MAX_SIZE) cout << "Переполнение стека" << endl;
        else
        {
            stack[size] = newData;
            size++;
        }
    }

    int pop()
    {
        if (getSize() == 0) return 0;
        size--;
        int data = stack[size];
        stack[size] = 0;
        return data;
    }
};

bool isOperand(char symb)
{
    if (symb >= 48 && symb <= 57) return true;
    else return false;
}

int solePostfix(string postfix)
{
    Stack postfixStack; //Stack - собственная структура данных
    for (int i = 0; i < postfix.size(); i++)
    {
        if (isOperand(postfix[i])) postfixStack.push_back(postfix[i] - '0');
        else
        {
            int operand2 = postfixStack.pop();
            int operand1 = postfixStack.pop();

            switch (postfix[i])
            {
            case '+':
                postfixStack.push_back(operand1 + operand2);
                break;
            case '-':
                postfixStack.push_back(operand1 - operand2);
                break;
            case '*':
                postfixStack.push_back(operand1 * operand2);
                break;
            case '/':
                postfixStack.push_back(operand1 / operand2);
                break;
            }
        }
    }
    return postfixStack.pop();
}

int main()
{
    cout << "Введите выражение в постфиксной форме >>> ";
    string postfix;
    cin >> postfix;
    cout << "Значение выражения: " << solePostfix(postfix);
}
