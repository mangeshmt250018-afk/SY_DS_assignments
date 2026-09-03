#include<bits/stdc++.h>
using namespace std;

struct Node
{
    char data;
    Node *next;
};

class Stack
{
    Node *top;


public:
    Stack()
    {
        top = NULL;
    }

    void push(char x)
    {
        Node *p = new Node;
        p->data = x;
        p->next = top;
        top = p;
    }

    char pop()
    {
        if (top == NULL)
            return '\0';

        Node *p = top;
        char x = p->data;
        top = top->next;
        delete p;
        return x;
    }

    char peek()
    {
        if (top == NULL)
            return '\0';

        return top->data;
    }

    bool isEmpty()
    {
        return top == NULL;
    }
};

int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;

    if (op == '*' || op == '/')
        return 2;

    if (op == '^')
        return 3;

    return 0;
}

string infixToPostfix(string Q)
{
    Stack s;
    string P = "";

    s.push('(');
    Q = Q + ')';

    for (int i = 0; i < Q.length(); i++)
    {
        char ch = Q[i];

        if (isalnum(ch))
        {
            P = P + ch;
        }
        else if (ch == '(')
        {
            s.push(ch);
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
        {
            while (!s.isEmpty() && s.peek() != '(' &&
                   precedence(s.peek()) >= precedence(ch))
            {
                P = P + s.pop();
            }

            s.push(ch);
        }
        else if (ch == ')')
        {
            while (s.peek() != '(')
            {
                P = P + s.pop();
            }

            s.pop();
        }
    }

    return P;
}

string infixToPrefix(string Q)
{
    Stack s;
    string P = "";

    s.push(')');
    Q = ")" + Q;

    for (int i = Q.length() - 1; i >= 0; i--)
    {
        char ch = Q[i];

        if (isalnum(ch))
        {
            P = P + ch;
        }
        else if (ch == ')')
        {
            s.push(ch);
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
        {
            while (!s.isEmpty() && s.peek() != ')' &&
                   precedence(s.peek()) >= precedence(ch))
            {
                P = P + s.pop();
            }

            s.push(ch);
        }
        else if (ch == '(')
        {
            while (s.peek() != ')')
            {
                P = P + s.pop();
            }

            s.pop();
        }
    }
    string prefix = "";

    for (int i = P.length() - 1; i >= 0; i--)
    {
        prefix = prefix + P[i];
    }

    return prefix;
}


int calculate(int a, int b, char op)
{
    if (op == '+')
        return a + b;

    if (op == '-')
        return a - b;

    if (op == '*')
        return a * b;

    if (op == '/')
        return a / b;

    if (op == '^')
        return pow(a, b);

    return 0;
}

int evaluatePostfix(string exp)
{
    Stack s;

    for (int i = 0; i < exp.length(); i++)
    {
        char ch = exp[i];

        if (isdigit(ch))
        {
            s.push(ch);
        }
        else
        {
            int b = s.pop() - '0';
            int a = s.pop() - '0';

            int result = calculate(a, b, ch);

            s.push(result + '0');
        }
    }

    return s.pop() - '0';
}
int evaluatePrefix(string exp)
{
    Stack s;

    for (int i = exp.length() - 1; i >= 0; i--)
    {
        char ch = exp[i];

        if (isdigit(ch))
        {
            s.push(ch);
        }
        else
        {
            int a = s.pop() - '0';
            int b = s.pop() - '0';

            int result = calculate(a, b, ch);

            s.push(result + '0');
        }
    }

    return s.pop() - '0';
}

int main()
{
    string infix;

    cout << "Enter Infix expression: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    string prefix = infixToPrefix(infix);

    cout << "\nPostfix Expression : " << postfix;

    cout << "\nPrefix Expression : " << prefix;

    cout << "\nEnter postfix expression: ";
    cin >> postfix;

    cout << "\nPostfix Evaluation : " << evaluatePostfix(postfix);

    cout << "\nEnter prefix expression: ";
    cin >> prefix;

    cout << "\nPrefix Evaluation : " << evaluatePrefix(prefix);

    return 0;
}
