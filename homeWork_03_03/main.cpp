#include <iostream>

using namespace std;

struct Node
{
    int item;
    Node * next;
};

struct Stack
{
    Node * pHead = 0;

    void Push(int item)
    {
        Node * node = new Node;
        node->item = item;
        node->next = pHead;
        pHead = node;
    }

    int Pop()
    {
        if (!pHead)
            throw 1;

        Node * temp = pHead;
        int x = temp->item;
        pHead = temp->next;
        delete temp;
        return x;
    }

    int Peek()
    {
        if (!pHead)
            throw 1;

        return pHead->item;
    }

    void PrintAll() {
        if (!pHead) {
            cout<<"Stack is empty!"<<endl;
            return;
        }

        Node *copyOfPHead = this->pHead;
        cout<<copyOfPHead->item<<endl;
        while(copyOfPHead->next != 0) {

            copyOfPHead = copyOfPHead->next;
            cout<<copyOfPHead->item<<endl;
        }
    }
};


struct LinkedList
{
    Node * root = 0;

    void Add(int item) {
        if(!root) {
            Node * node = new Node;
            node->item = item;
            node->next = 0;
            root = node;
            return;
        }

        Node * copyOfRoot = root;
        while(copyOfRoot->next != 0){
            copyOfRoot = copyOfRoot->next;
        }
        Node * node = new Node;
        node->item = item;
        node->next = 0;
        copyOfRoot->next = node;
    }

    int Size() {
        if(!root) {
            return 0;
        }
        int counter = 1;
        Node * copyOfRoot = root;
        while(copyOfRoot->next != 0) {
            counter++;
            copyOfRoot = copyOfRoot->next;
        }
        return counter;
    }

    int Get(int id) {
        if(this->Size() <= id) {
            cout<<"Id is bigger than list size!"<<endl;
            return -1;
        }

        if(id < 0) {
            cout<<"Id can`t be negative!"<<endl;
            return -1;
        }

        int counter = 0;
        Node *copyOfRoot = root;
        while(counter != id) {
            counter++;
            copyOfRoot = copyOfRoot->next;
        }
        return copyOfRoot->item;
    }

    void PrintAll() {
        if (!root) {
            cout<<"List is empty!"<<endl;
            return;
        }

        Node *copyOfRoot = this->root;
        cout<<copyOfRoot->item<<endl;
        while(copyOfRoot->next != 0) {
            copyOfRoot = copyOfRoot->next;
            cout<<copyOfRoot->item<<endl;
        }
    }
};


int main()
{

    Stack * stack = new Stack;

    stack->Push(10);
    stack->Push(20);
    stack->Push(30);
    stack->Push(40);
    stack->Push(50);

    stack->PrintAll();

    cout<<stack->Pop()<<endl;

    delete stack;

    cout<<"Now we are going to test LinkedList"<<endl;

    LinkedList * list = new LinkedList;

    list->Add(10);
    list->Add(20);
    list->Add(30);

    cout<<"This is size: "<<list->Size()<<endl;
    cout<<list->Get(2)<<endl;

    cout<<"Now we are going to print all items of LinkedList"<<endl;
    list->PrintAll();

    delete list;

    return 0;







}
