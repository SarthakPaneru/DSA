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
    char exp[20], temp[20]={};
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
            //temp += x;
            //strcat(temp, &x);
            cout<<*e;
        } else if (*e == ')') {
            push(*e);
        } else if (*e == '(') {
            while((x = pop()) != ')') {
                str += x;
                //strcat(temp, &x);
                cout<<x;
            }
        } else {
            while(priority(stack[tos]) > priority(*e)) {
                x = pop();
                str += x;
                //strcat(temp, &x);
                cout<<x;
            }
            push(*e);
        }
        e++;
    }
    while(tos != -1) {
        x = pop();
        str += x;
        //strcat(temp, &x);
        cout<<x;
    }
    cout<<endl;
    cout<<str<<endl;
    str.copy(temp, strlen(exp), 0);
    strrev(temp);
    cout<<temp;
    cout<<endl;
    return 0;
}