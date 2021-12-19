// Circular queue
// Here front, rear starts from "0"
// We can also initilize them as -1

#include <iostream>

using namespace std;

#define size 5

int arr[size];
int front = -1, rear = -1;

char* position(int x) {

    if(x==front) {
        return (char*)"(f)";
    } else if (x==rear) {
        return (char*)"(r)";
    } else {
        return (char*)" ";
    }
}

void display() {
    cout<<endl<<"Queue:"<<endl;
    for (int i = 0; i < size; ++i)
    {
        cout<<arr[i]<<position(i)<<" ";
    }
    cout<<endl;
}

void enqueue() {
    if (front == -1) {
        ++front;
        ++rear;
    } else {
        rear=(rear+1)%size;
    }
    cout<<"Enter data to add in queue: ";
    cin>>arr[rear];
    display();
}

void dequeue() {
    if (front == rear)
    {
        rear = -1;
        front = -1;
    } else {
        arr[front] = NULL;
        front = (front+1)%size;
    }
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
            if (front != (rear+1)%size) {
                enqueue();
            } else {
                cout<<"Queue full"<<endl;
            }
            break;

        case 2:
            if (front != -1) {
                dequeue();
            } else {
                cout<<"Queue is empty"<<endl;
                //front = (front+1)%size;
                //rear = 0;
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