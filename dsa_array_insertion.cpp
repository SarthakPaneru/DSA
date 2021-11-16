// Program to insert an integer in existing array without overriding
// data and within the size of array.

#include <iostream>
#include <math.h>

using namespace std;

#define max 10

void display(int *arr)
{
    cout<<"\nThe array is"<<endl;
    for (int i = 0; i < max; ++i)
    {
        cout<<*(arr+i)<<" ";
    }
    cout<<endl;
}

int main()
{
    int arr[max] = {1, 2, 3, 4, 5};
    arr[max-1] = '\0'; // Null terminator
    int num, pos, choice;

    display(arr);

    // Continuous loop
    while(1)
    {
        cout<<endl<<"****** Enter a Choice ******"<<endl;
        cout<<"1. Insert data in array"<<endl<<"2. Delete data in array"<<endl<<"3. End Program"<<endl;
        cin>>choice;

        switch (choice)
        {
        // Insert into array
        case 1:
        {
            if(arr[max-1] == '\0')
            {
                cout<<"\nEnter a number to insert in array: ";
                cin>>num;

                cout<<"\nEnter the position to be inserted(0-9): ";
                cin>>pos;

                // Store value in temp var to be used in next step(as we need to change its value)
                int temp = max;

                // Copy the value in array to its next address
                for (int i = pos; i < max; ++i)
                {
                    //arr[max+pos-i-1] = arr[max+pos-i-2];
                    arr[temp-1] = arr[temp-2];
                    temp--;
                }
                // Insert the value in given position
                arr[pos] = num;

                display(arr);
            } else
            {
                cout<<"\nSorry! The array is full."<<endl;
                display(arr);
            }
            
            break;
            break;
        }

        // Delete the data in array
        case 2:
        {
            cout<<"\nEnter the position to be deleted(0-9): ";
            cin>>pos;

            for (int i = pos; i < max; ++i)
            {
                arr[i] = arr[i+1];
            }
            arr[max-1] = '\0';
            display(arr);
            break;
        }
        // End program
        case 3:
            // Its bad practice to end program using return
            exit(0);
        
        default:
            cout<<"Invalid Input"<<endl;
            break;
        }
    }

    cout<<"Hello World"<<endl;
    return 0;
}