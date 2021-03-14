#include <iostream>

    using namespace std;

    struct Node{
        int item;
        Node * next;
        Node * previous;
    };

    struct SortedList{
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
                //cout<<"First element added!"<<endl;
                return;
            }

            if(value >= tail->next->item){
                if (value == tail->next->item){
                    //cout<<"Such value are already exist and wont be added again!"<<endl;
                    return;
                }
                Node * node = new Node;
                node->item = value;
                node->next = 0;
                node->previous = tail->next;
                tail->next->next = node;
                tail->next = node;
                //cout<<"Element added to the tail!"<<endl;
                return;
            }

            if (head->next->item > value) { //Добавить элемент в начало
                Node * node = new Node;
                node->item = value;
                node->next = head->next;
                node->previous = 0;
                head->next->previous = node;
                head->next = node;
                //cout<<"Element added to the beginning!"<<endl;
                return;
            }

            int s = size();
            Node * copyOfTail = tail->next;
            while(value < copyOfTail->item) {

                s--;
                if (s < 1) {
                   cout<<"Element not found"<<endl;
                   return;
                }
                copyOfTail = copyOfTail->previous;

                if(value == copyOfTail->item){
                    //cout<<"Such value are already exist and wont be added again!"<<endl;
                    return;
                }
            }

            Node * node = new Node;
            node->item = value;
            node->next = copyOfTail->next;
            copyOfTail->next->previous = node;
            copyOfTail->next = node;
            node->previous = copyOfTail;

            //cout<<"Element added somethere!"<<endl;
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

        int get(int id){
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

        void remove(int id){
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

        };

        SortedList* unionLists(SortedList * a, SortedList * b){
            SortedList * unioN = new SortedList;

            int aSize = a->size();
            int bSize = b->size();

            if((aSize == 0) && (bSize == 0)) {
                cout<<"Your lists are empty!"<<endl;
                return unioN;
            }

            for(int i = 0; i < aSize; i++){
                unioN->add(a->get(i));
            }

            for(int i = 0; i < bSize; i++){
                unioN->add(b->get(i));
            }

            return unioN;
        };

        SortedList * intersect(SortedList * a, SortedList * b){
            SortedList * intersec = new SortedList;

            int aSize = a->size();
            int bSize = b->size();

            if((aSize == 0) || (bSize == 0)) {
                cout<<"Your list or lists are empty!"<<endl;
                return intersec;
            }

            if((a->get(0) > b->get(bSize - 1)) || (b->get(0) > a->get(aSize - 1))) {
                cout<<"Lists have not same elements"<<endl;
                return intersec;
            }

            int shortestListSize;
            SortedList * shortestList = new SortedList;
            SortedList * longestList = new SortedList;

            if(aSize > bSize) {
                shortestListSize = bSize;
                shortestList = b;
                longestList = a;

            }else{
                shortestListSize = aSize;
                shortestList = a;
                longestList = b;
            }

                for(int i = 0; i < shortestListSize; i++) {
                    int elementOfShortList = shortestList->get(i);

                    if((longestList->head->next->item > elementOfShortList) || (longestList->tail->next->item < elementOfShortList)){
                        continue;
                    }

                    int k = 0;
                    Node * CopyOfHead = longestList->head->next;
                    while(CopyOfHead->item != elementOfShortList){
                        if(CopyOfHead->next == 0){
                            k = 1;
                            break;
                        }

                        CopyOfHead = CopyOfHead->next;
                    }
                    if(k == 1) {
                        continue;
                    }

                    intersec->add(elementOfShortList);
                }
                return intersec;
        };


        SortedList * difference(SortedList * a, SortedList * b) {
            SortedList * elementsFromFirstList = new SortedList;

            int aSize = a->size();
            int bSize = b->size();

            if((aSize == 0) && (bSize == 0)) {
                cout<<"Your list or lists are empty!"<<endl;
                return elementsFromFirstList;
            }

            if(aSize == 0){
                cout<<"List A is empty"<<endl;
                return elementsFromFirstList;
            }


                for(int i = 0; i < aSize; i++) {
                    int elementOfListA = a->get(i);

                    int k = 0;
                    Node * CopyOfHead = b->head->next;
                    while(CopyOfHead->item != elementOfListA){
                        if(CopyOfHead->next == 0){
                            k = 1;
                            break;
                        }
                        CopyOfHead = CopyOfHead->next;
                    }
                    if(k == 1) {
                        elementsFromFirstList->add(elementOfListA);
                        continue;
                    }
                }
                return elementsFromFirstList;

        };
    };



    int main()
    {
        SortedList * list = new SortedList;

        list->add(2);
        list->add(3);
        list->add(4);
        list->add(6);
        list->add(3); // центр
        list->add(1); // в начало

        for(int i = 0; i < list->size(); i++){
            cout<<list->get(i)<<endl;
        }

        cout<<"Size: "<<list->size()<<endl;

        list->remove(1);
        cout<<"Size: "<<list->size()<<endl;

        SortedList * list2 = new SortedList;
        list2->add(5);
        list2->add(7);
        list2->add(4);
        list2->add(3);
        list2->add(1);
        list2->add(9);
        list2->add(11);

        for(int i = 0; i < list2->size(); i++){
            cout<<list2->get(i)<<endl;
        }

        cout<<endl<<"Now we will join two lists"<<endl; // Task 3.1
        SortedList * list3 = list->unionLists(list, list2);
        cout<<"Size: "<<list3->size()<<endl;
        for(int i = 0; i < list3->size(); i++) {
            cout<<list3->get(i)<<endl;
        }


        cout<<"Intersected list"<<endl;
        SortedList * list4 = list->intersect(list, list2);
        cout<<"Size: "<<list4->size()<<endl;
        for(int i = 0; i < list4->size(); i++) {
            cout<<list4->get(i)<<endl;
        }

        cout<<"Elements which has only first list"<<endl;
        SortedList * list5 = list->difference(list, list2);
        for(int i = 0; i < list5->size(); i++){
            cout<<list5->get(i)<<endl;
        }

        delete list5;
        delete list4;
        delete list3;
        delete list2;
        delete list;

        return 0;
    }

