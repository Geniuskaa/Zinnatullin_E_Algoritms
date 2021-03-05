    #include <iostream>

    using namespace std;

    struct Node
    {
        int item;
        Node * next;
        Node * previous;
    };

    struct DoubleLinkedList
    {
        Node * head = 0;
        Node * tail = 0;

        void add(int value){
            if(!head && !tail){
                Node * node = new Node;
                node->item = value;
                node->next = 0;
                node->previous = 0;

                Node * nodeHead = new Node;
                nodeHead->item = 0;
                nodeHead->previous = 0;
                nodeHead->next = node;
                head = nodeHead;

                Node * nodeTail = new Node;
                nodeTail->item = 0;
                nodeTail->previous = 0;
                nodeTail->next = node;
                tail = nodeTail;

                return;
            }
            Node * node = new Node;
            node->item = value;
            node->next = 0;
            node->previous = tail->next;
            tail->next->next = node;
            tail->next = node;
        }

        int size() {
            if(head != 0 && tail != 0) {
                int counter = 1;
                Node * temp = head->next;
                while(temp->next != 0) {
                counter++;
                temp = temp->next;
                }
                return counter;
            }
            cout<<"List is empty!"<<endl;
            return 0;
        }

        int get(int id) {

            if(id < 0){
                cout<<"Id can`t be negative!"<<endl;
                return -1;
            }

            if(size() <= id) {
                cout<<"Id is bigger than list capacity"<<endl;
                return -1;
            }

            int counter = 0;
            Node * temp = head->next;
            while(counter != id) {
            counter++;
            temp = temp->next;
            }
            return temp->item;
        }

        void insertAt(int value, int id){
            int s = size();
            if(id < 0){
                cout<<"Id can`t be negative!"<<endl;
                return;
            }

            if(s <= id) {
                cout<<"Id is bigger than list capacity"<<endl;
                return;
            }

            if (id == 0) {
                Node * node = new Node;
                node->item = value;
                node->next = head->next;
                node->previous = 0;
                head->next->previous = node;
                head->next = node;
                return;
            }

            if (s - 1 == id) {
                Node * node = new Node;
                node->item = value;
                node->next = 0;
                node->previous = tail->next;
                tail->next->next = node;
                tail->next = node;
                return;
            }


            int counter = 0;
            Node * temp = head->next;
            while(counter != id) {
            counter++;
            temp = temp->next;
            }
            Node * node = new Node;
            node->item = value;
            node->next = temp;
            node->previous = temp->previous;
            temp->previous->next = node;
            temp->previous = node;
        }


        void removeAt(int id){
            int s = size();
            if(id < 0){
                cout<<"Id can`t be negative!"<<endl;
                return;
            }

            if(s <= id) {
                cout<<"Id is bigger than list capacity"<<endl;
                return;
            }

            if (id == 0) {
                head->next->next->previous = 0;
                head->next = head->next->next;
                return;
            }

            if (s - 1 == id) {
                tail->next->previous->next = 0;
                tail->next = tail->next->previous;
                return;
            }

            int counter = 0;
            Node * temp = head->next;
            while(counter != id) {
            counter++;
            temp = temp->next;
            }
            temp->previous->next = temp->next;
            temp->next->previous = temp->previous;
        }

    };

    struct Queue
    {
        Node * first = 0;
        Node * last = 0;

        void enqueue(int value) {
             if(!first && !last){
                Node * node = new Node;
                node->item = value;
                node->next = 0;
                node->previous = 0;

                Node * nodeFirst = new Node;
                nodeFirst->item = 0;
                nodeFirst->previous = 0;
                nodeFirst->next = node;
                first = nodeFirst;

                Node * nodeLast = new Node;
                nodeLast->item = 0;
                nodeLast->previous = 0;
                nodeLast->next = node;
                last = nodeLast;

                return;
            }
            Node * node = new Node;
            node->item = value;
            node->next = 0;
            node->previous = 0;
            last->next->next = node;
            last->next = node;
        }

        int dequeue(){
            if(!first && !last){
                cout<<"Queue is empty!"<<endl;
                return -1;
            }

            int value = first->next->item;
            first->next = first->next->next;
            return value;
        }
    };


    int main()
    {

        DoubleLinkedList * list = new DoubleLinkedList;

        list->add(10);
        list->add(30);
        list->add(70);

        cout<<list->size()<<endl;

        cout<<list->get(-2)<<endl;
        cout<<list->get(1)<<endl;

        list->insertAt(20,2);
        cout<<list->size()<<endl;
        cout<<list->get(1)<<endl;

        list->removeAt(0);
        cout<<list->get(0);
        delete list;
        cout<<endl;
    //////////////////////////////////////////
        cout<<"Let`s use the Queue!"<<endl;
        Queue * queue = new Queue;

        queue->enqueue(1);
        queue->enqueue(2);
        queue->enqueue(3);
        queue->enqueue(4);

        cout<<queue->dequeue()<<endl;
        cout<<queue->dequeue();


        delete queue;
        return 0;
    }
