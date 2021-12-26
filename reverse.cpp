#include <iostream>
#include <string.h>

using namespace std;


void strrevs(char *c) {
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
    char c[100] = "ab";
    cout<<c<<endl;
    strrevs(c);
    cout<<c<<endl;

    return 0;
}