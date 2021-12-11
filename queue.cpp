// Linear queue
// Here front, rear starts from "0"
// We can also initilize them as -1

#include <iostream>

using namespace std;

#define max 10

int arr[max];
int front = 0, rear = 0;

void display() {
    cout<<endl<<"Queue:"<<endl;
    for (int i = front; i < rear; ++i)
    {
        cout<<arr[i]<<"("<<i<<") ";
    }
    cout<<endl;
}

void enqueue() {
    cout<<"Enter data to add in queue: ";
    cin>>arr[rear];
    rear++;
    display();
}

void dequeue() {
    ++front;
    display();
}

int main()
{
    int choice;
    while(true)
    {
        cout<<"Chose an option:"<<endl<<"1. Enqueue"<<endl<<"2. Dequeue"<<endl<<"3. Display"<<endl<<"4. End Program"<<endl;
        cin>>choice;

        switch (choice)
        {
        case 1:
            if (rear != max) {
                enqueue();
            } else {
                cout<<"Queue full"<<endl;
            }
            break;

        case 2:
            if (front != rear) {
                dequeue();
            } else {
                cout<<"Array is empty now resetting"<<endl;
                front = 0;
                rear = 0;
            }
            break;

        case 3:
            display();
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