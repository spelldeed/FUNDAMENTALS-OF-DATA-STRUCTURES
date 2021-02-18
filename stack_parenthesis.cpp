#include <iostream>
using namespace std;

#define MAX 100

class Stack
{
    int top;
    int a[MAX];

public:
    Stack() { top = -1; }
    bool push(int x);
    int pop();
    void display();
    int topElement();
    bool isEmpty();
};

bool Stack::push(int x)
{
    if (top >= (MAX - 1))
    {
        cout << "Stack Overflow";
        return false;
    }
        else
    {
        a[++top] = x;
        return true;
    }
}

int Stack::pop()
{
    if (top < 0)
    {
        cout << "Stack Underflow";
        return 0;
    }
    else
    {
        int x = a[top--];
        return x;
    }
}

void Stack::display()
{
    int i;
    if (isEmpty())
    {
        cout << "Stack Is EMPTY" << '\n';
    }

    cout << '\n';
    for (i = top; i >= 0; --i)
    {
        cout << a[i] << '\n';
    }
    cout << '\n';
}

int Stack::topElement()
{
    return a[top];
}

bool Stack::isEmpty()
{
    return (top < 0);
}

bool areParanthesisBalanced(string expr)
{
    Stack s;
    char x;

    for (int i = 0; i < expr.length(); i++)
    {
        if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{')
        {
            s.push(expr[i]);
            continue;
        }

        if (s.isEmpty())
            return false;

        switch (expr[i])
        {
        case ')':

            x = (char)s.topElement();
            s.pop();
            if (x == '{' || x == '[')
                return false;
            break;

        case '}':

            x = (char)s.topElement();
            s.pop();
            if (x == '(' || x == '[')
                return false;
            break;

        case ']':

            x = (char)s.topElement();
            s.pop();
            if (x == '(' || x == '{')
                return false;
            break;
        }
    }

    return (s.isEmpty());
}

int main()
{
    string expr;
    cout << "Enter Expression of Paranthesis :";
    cin >> expr;
    if (areParanthesisBalanced(expr))
        cout << "Balanced";
    else
        cout << "Not Balanced";
    return 0;
}

