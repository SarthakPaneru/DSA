#include <iostream>

using namespace std;

char stack[20];
int tos = -1;

bool isAlNum(char c) {
    if((c >= '0' && c <= '9') || (c >= 'a' && c<= 'z') || (c >= 'A' && c <= 'Z')) {
        return true;
    } else {
        return false;
    }
}

void push(char c) {
    //++tos;
    stack[++tos] = c;
}

char pop() {
    if(tos == -1) {
        return -1;
    } else {
        return stack[tos--];
    }
}

int priority(char c) {
    if (c == '(') {
        return 0;
    }
    if (c == '+' || c=='-') {
        return 1;
    }
    if (c == '*' || c == '/') {
        return 2;
    }
    //return -1;
}

int main()
{
    char exp[20];
    char *e, x;

    cout<<"Enter expression: "<<endl;
    cin>>exp;

    e = exp;

    while(*e != '\0') {
        if(isAlNum(*e)) {
            cout<<*e;
        } else if (*e == '(') {
            push(*e);
        } else if (*e == ')') {
            while((x = pop()) != '(') {
                cout<<x;
            }
        } else {
            while(priority(stack[tos]) >= priority(*e)) {
                cout<<pop();
            }
            push(*e);
        }
        e++;
    }
    while(tos != -1) {
        cout<<pop();
    }
    cout<<endl;
    return 0;
}