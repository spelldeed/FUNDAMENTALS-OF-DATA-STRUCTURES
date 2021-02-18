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
        cout << x << " pushed into stack\n";
        cout << "Top is -> " << a[top] << '\n';
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
    	cout << "Popped Element is :" << a[top]<< '\n';
        int x = a[top--];
        cout << "Top is -> " << a[top] << '\n';
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

    cout << "Top is -> " << a[top] << '\n';
}

bool Stack::isEmpty()
{
    return (top < 0);
}

int main()
{
    class Stack s;
    int ch, loop = 1;
    while (loop)
    {
        cout << "\nEnter a Choice :\n1. Push\n2. Pop\n3. Display\n4. EXIT" << '\n';
        cout << "Choice :";
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            int i;
            cout << "Enter value to push :" << '\n';
            cin >> i;
            s.push(i);
            break;
        }
        case 2:
        {
            s.pop();
            break;
        }
        case 3:
        {
            s.display();
            break;
        }
        default:
        {
            loop = 0;
            break;
        }
        }
    }

    return 0;
}

