// Implementing stack
#include <iostream>

using namespace std;

#define max 10

void display(int arr[], int &x)
{
    cout<<"The Array is: "<<endl;
    for(int i=0; i<=x; ++i)
    {
        cout<<arr[i]<<"("<<i<<")  ";
    }
    cout<<endl;
}

void push(int *arr, int &tos)
{
    if (tos<max)
    {
        ++tos;
        int num;
        cout<<"Enter number to add in stack: ";
        cin>>num;

        arr[tos] = num;

        display(arr, tos);
    }
    else {
        cout<<"Stack is full"<<endl;
    }
}

void pop(int *arr, int &tos)
{
    if (tos != -1)
    {
        arr[tos] = '\0';
        --tos;

        display(arr, tos);
    }
    else
    {
        cout<<"Stack Empty"<<endl;
    }
    
}

int main()
{
    int arr[max];

    int tos = -1, num, choice;

    while(1)
    {
        cout<<endl<<"*** Enter a choice ***"<<endl;
        cout<<"1. Push \n2. Pop \n3. Display \n4.End Program"<<endl;
        cin>>choice;

        switch (choice)
        {
            case 1:
                
                push(arr, tos);
                break;

            case 2:
                pop(arr, tos);
                break;

            case 3:
                display(arr, tos);
                break;

            case 4:
                exit(0);
            
            default:
                cout<<"Invalid Input"<<endl;
                break;
        }
    }
    return 0;
}