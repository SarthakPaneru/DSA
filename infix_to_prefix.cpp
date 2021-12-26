#include <iostream>
#include <string.h>

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
    if (c == '(' || c == ')') {
        return 0;
    }
    if (c == '+' || c=='-') {
        return 1;
    }
    if (c == '*' || c == '/') {
        return 2;
    }
    if (c == '^') {
        return 3;
    }
}

void strrev(char *c) {
    int size = strlen(c);
    int a = size;
    char temp[100];
    for(int i = 0; i<=a; ++i) {
        temp[i] = *(c+(size-1));
        --size;
    }
    //return temp;
    strcpy(c, temp);
}

int main()
{
    char exp[100], temp[100]= {};
    string str;
    
    char *e, x;

    cout<<"Enter expression: "<<endl;
    cin>>exp;

    strrev(exp);
    e = exp;
    

    while(*e != '\0') {
        if(isAlNum(*e)) {
            x = *e;
            str += x;            
        } else if (*e == ')') {
            push(*e);
        } else if (*e == '(') {
            while((x = pop()) != ')') {
                str += x;
            }
        } else {
            while(priority(stack[tos]) > priority(*e)) {
                x = pop();
                str += x;
            }
            push(*e);
        }
        e++;
    }
    while(tos != -1) {
        x = pop();
        str += x;
    }
    cout<<endl;
    cout<<str<<endl;
    //cout<<strlen(str);
    str.copy(temp, strlen(exp), 0);
    //cout<<strlen(temp);
    strrev(temp);
    cout<<temp;
    //cout<<strlen(str);
    cout<<endl;
    return 0;
}