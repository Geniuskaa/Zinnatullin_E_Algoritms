#include <cstdlib>
#include <iostream>
#include <vector>
#include <ctime>
#include <fstream>
#include <string>



using namespace std;

    struct Node{

        int16_t level; // 2 байта вместо одного
        int value;
        Node * leftChild;
        Node * rightChild;

        Node(){
            level = 1;
            value = 0;
            leftChild = 0;
            rightChild = 0;
        }

        Node(int item){
            level = 1;
            value = item;
            leftChild = 0;
            rightChild = 0;
        }

        Node(int item, Node * l, Node * r){
            level = 1;
            value = item;
            leftChild = l;
            rightChild = r;
        }

    };

    struct AAtree{
        Node * root;

        AAtree(){
            root = new Node();
        }


        bool isEmpty(Node * n){
            return n->value == 0;
        }

        Node* skew(Node * T){
            if ((T->leftChild == 0) && (T->rightChild == 0)){
                return T;
            }else if (T->leftChild == 0){
                return T;
            }else if (T->leftChild->level == T->level){
                Node* L = T->leftChild;
                T->leftChild = L->rightChild;
                L->rightChild = T;
                return L;
            }else{
                return T;
            }
        }

        Node* split(Node * T){
            if ((T->leftChild == 0) && (T->rightChild == 0)){
                return T;
            }else if (T->rightChild == 0 || T->rightChild->rightChild == 0){
                return T;
            }else if (T->level == T->rightChild->rightChild->level){
                Node * R = T->rightChild;
                T->rightChild = R->leftChild;
                R->leftChild = T;
                R->level = R->level + 1;
                return R;
            }else{
                return T;
            }
        }

        bool research(Node * r, int item){
            bool found = false;
            int rval;
            Node* temp = r;
            while(!found){
                rval = temp->value;
                if(item < rval){
                    if(temp->leftChild != 0){
                        temp = temp->leftChild;
                    }else{
                        break;
                    }

                }else if(item > rval){
                    if(temp->rightChild != 0){
                       temp = temp->rightChild;
                    }else{
                        break;
                    }

                }else{
                    found = true;
                }
            }
            return found;
        }

        void insert(int item){
            if(!research(root, item)){
                root = insert(item, root);
                return;
            }
            //cout<<"Such element we already have! It won`t be added!"<<endl;
        }

        Node* insert(int item, Node * T){
            if(isEmpty(T)){
                T = new Node(item);
            }else if(item < T->value){
                if(T->leftChild == 0){
                    T->leftChild = new Node(item);
                }else{
                    T->leftChild = insert(item, T->leftChild);
                }
            }else if(item > T->value){
                if(T->rightChild == 0){
                    T->rightChild = new Node(item);
                }else{
                    T->rightChild = insert(item, T->rightChild);
                }
            }else {
                return T;
            }

            T = skew(T);
            T = split(T);
            return T;
        }

        void countNodes(){
            cout<<"Now there are "<<countN(root)<<" elements"<<endl;
        }

        int countN(Node * r){
             if (isEmpty(r)){
                return 0;
             }else{
                int c = 1;
                if(r->leftChild != 0){
                    c += countN(r->leftChild);
                }
                if(r->rightChild != 0){
                    c += countN(r->rightChild);
                }

                return c;
            }
        }

        void printTree(){
            int size = root->level;
            vector<int> tr[size];
            printInorder(root, tr);

            for(int i = size - 1; i > -1; --i){

                int ak = tr[i].size();
                for(int w = 0; w < ak; w++){
                    cout<<tr[i][w]<<" ";
                }
                cout<<endl;
            }
            delete tr;
        }

        void printInorder(Node * r, vector<int> * arr){
            if(r->value == 0){
                return;
            }

            int position = r->level - 1;
            arr[position].push_back(r->value);

            if(r->leftChild != 0){
                printInorder(r->leftChild, arr);

            }
            if(r->rightChild != 0){
                printInorder(r->rightChild, arr);
            }
        }


        void search(int item){
            if(research(root, item)){
                cout<<"We found!"<<endl;
                return;
            }
            cout<<"There are not such element!"<<endl;
            //return research(root, item);
        }


        Node* predecessor(Node * curNode){

            curNode = curNode->leftChild;
            while (curNode->rightChild != 0)
            {
                curNode = curNode->rightChild;
            }
            return curNode;
        }

        Node* successor(Node * curNode){

            curNode = curNode->rightChild;
            while (curNode->leftChild != 0)
            {
                curNode = curNode->leftChild;
            }
            return curNode;
        }

        Node* decreaseLevel(Node* t){

        int wdo;
        if (t->leftChild != 0 && t->rightChild != 0){

            if(t->leftChild->level > t->rightChild->level){
                wdo = t->rightChild->level;
            }else{
                wdo = t->leftChild->level;
            }
            if (wdo < t->level)
            {
                t->level = wdo;
                if (t->rightChild != 0 && wdo < t->rightChild->level)
                {
                    t->rightChild->level = wdo;
                }
            }
        }

            return t;
        }


        Node* deleteData(Node * t, int item){

        Node * m;
        if (isEmpty(t))
        return 0;
        if (item < t->value){
            t->leftChild = deleteData(t->leftChild, item);
        }else if (item > t->value){
            t->rightChild = deleteData(t->rightChild, item);
        }else {
            if (t->leftChild == 0 && t->rightChild == 0){
                return 0;
            }
            if (t->leftChild == 0){

                Node* l;
                l = successor(t);
                t->value = l->value;
                t->rightChild = deleteData(t->rightChild, l->value);
            }else {
                Node * l;
                l = predecessor(t);
                t->value = l->value;
                t->leftChild = deleteData(t->leftChild, l->value);
            }
        }
        t = decreaseLevel(t);
        t = skew(t);
        if(t->rightChild != 0){
            m = t->rightChild;
            t->rightChild = skew(m);
            if (!isEmpty(m) && m->rightChild != 0){
                t->rightChild->rightChild = skew(m->rightChild);
            }
            t = split(t);
        }

        return t;
        }

        void deleteItem(int item){
            if(research(root, item)){
                root = deleteData(root, item);
                cout<<"Your item was deleted!"<<endl;
                return;
            }
            cout<<"There are no such element!"<<endl;
        }
    };


    void writeFromFileToArray(int * arr){
        ifstream file;
        file.open("C:\\code\\C++\\Zinnatullin_E_Algoritms\\Semistrovka\\files\\file_25.txt"); // Тут меняем цифру, чтобы читать разные файлы, потом
                                                                                              // нужно отправиться на строчку -> 328
        int num;
        int counter = 0;
        while(!file.eof()){
            file >> num;
            arr[counter] = num;
            counter++;
        }
        cout<<"How many nums have been written: "<<counter<<endl;
        file.close();
    }


int main()
{
    AAtree * tree = new AAtree();

    int * nums = new int[1000000];
    writeFromFileToArray(nums);


    double startTime = clock();
    for(int l = 0; l < 319696; l++){ // В зависимости от файла, который мы указали наверху, сюда вписываем максимальное количество чисел в файле.
        tree->insert(nums[l]);       // Если вы не знаете макс количества, то в excel таблице всё указано.
    }
    double endTime = clock();
    double totalTime = (endTime - startTime) / CLOCKS_PER_SEC;
    cout<<"Duration: "<<totalTime<<endl;

    startTime = clock();
    tree->search(24151);
    tree->search(22);
    tree->search(189212);
    endTime = clock();
    totalTime = (endTime - startTime) / CLOCKS_PER_SEC;
    cout<<"Duration: "<<totalTime<<endl;



    delete nums;

    delete tree;
    return 0;
}
