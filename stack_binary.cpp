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
        cout << a[i];
    }
}

bool Stack::isEmpty()
{
    return (top < 0);
}

int main()
{
    class Stack st;
    int n,r;
    printf("Enter a decimal number:");
    scanf("%d",&n);
    while(n!=0){
        r = n%2;
        n = n/2;
        st.push(r);
    }

    cout << "Binary is :";
    st.display();
    return 0;
}

