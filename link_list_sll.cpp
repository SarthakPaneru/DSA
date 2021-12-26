// Dynamic Implementation of Singly linear linked list
// INSERTION
#include <iostream>

using namespace std;

struct Singly
{
    int data;
    struct Singly *next;
};

int main()
{
    Singly *headptr = NULL, *p, *temp, *newNode;

    newNode = (Singly *)(malloc(sizeof(struct Singly)));
    int item;
    int choice;
    while(1)
    {
        cout<<"*** Enter choice ***"<<endl<<"1.Insert at last \n2. Insert in between \n3. Insert at first \n4. Display \n5. Exit"<<endl;
        cin>>choice;

        switch (choice)
        {
        case 1:
            cout<<"Enter data to add: ";
            cin>>item;
            temp = (struct Singly*)malloc(sizeof(struct Singly));
            temp->data = item;
            temp->next = NULL;
            if(headptr == NULL) {
                headptr = temp;
            } else {
                p = headptr;
                while(p->next != NULL) {
                    p = p->next;
                }
                p->next = temp;
            }
            break;

        case 2:
            cout<<"Enter data to add: ";
            cin>>item;
            cout<<"Enter position: ";
            int n;
            cin>>n;
            temp = (struct Singly*)malloc(sizeof(struct Singly));
            temp->data = item;
            p = headptr;
            while(n>2) {
                p = p->next;
                n--;
            }
            temp->next = p->next;
            p->next = temp;
            break;

        case 3:
            cout<<"Enter data to add: ";
            cin>>item;
            temp = (struct Singly*)malloc(sizeof(struct Singly));
            temp->data = item;
            temp->next = headptr;
            headptr = temp;
            break;

        case 4:
        {
            temp = headptr;
            cout<<endl<<"Elements in list:"<<endl;
            if(headptr == NULL) {
                cout<<"Empty List"<<endl;
                break;
            }
            do {
                cout<<temp->data<<" ";
                //temp = temp->next;
            } while((temp = temp->next) != NULL);
            cout<<endl;
            break;
        }

        case 5:
            exit(0);
        
        default:
            cout<<"Invalid Input"<<endl;
            break;
        }
    }
}