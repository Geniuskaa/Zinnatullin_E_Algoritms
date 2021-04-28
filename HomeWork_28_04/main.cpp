#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <functional>

using namespace std;


void bruteForce(int A, int B, int C){
    int copyA = A;
    int copyB = B;
    const int s1 = 3; // Вот эти две константы нужно поменять когда меняем числа A, B, C
    const int s2 = 3; //

    int sizeA = 1;
    int sizeB = 1;

    int countOfCombinationsOfA = 1;
    int countOfCombinationsOfB = 1;

    while(copyA > 9){
        copyA /= 10;
        sizeA++;
        countOfCombinationsOfA *= sizeA;
    }
    sizeB = sizeA;
    countOfCombinationsOfB = countOfCombinationsOfA;

    copyA = A;
    array<int, s1> aNums;
    array<int, s2> bNums;

    for(int t=0; t<sizeA;t++){
        aNums[t] = copyA % 10;
        copyA /=10;
        bNums[t] = copyB % 10;
        copyB /=10;

    }
    sort(aNums.begin(), aNums.end());
    sort(bNums.begin(), bNums.end());

    do{
       string num = "";
       for(int e=0; e < sizeA; e++){
         num += std::to_string(aNums[e]);
       };

       do{
            string nuum = "";
            for(int e=0; e < sizeB; e++){
             nuum += std::to_string(bNums[e]);
            };

            int f = std::stoi(num);
            int s = std::stoi(nuum);
            if(f + s == C){
                cout<<f<<" + "<<s<<" = "<<C<<endl;
            }

            nuum = "";
        }
        while(next_permutation(bNums.begin(), bNums.end()));
        num = "";
    }
    while(next_permutation(aNums.begin(), aNums.end()));
}

    int countOfRoads(int size){
        int a[size];
        a[0] = 1;
        for(int i=1; i<size; i++){
            a[i] = 0;
        }

        for(int j=0; j<size-1; j++){

            if(j - 1 < 0){
                a[j+1] = a[j];
                continue;
            }

            a[j+1]= a[j] + a[j-1];
        }
        return a[size-1];
    }

    void countOfRoadsOfField(int x, int y){
        int a[x][y];
        a[x-1][0] = 1;
        for(int i = 0; i<x-1; i++){
            a[i][0] = 1;
        }

        for(int l=1; l<y; l++){
            a[x-1][l] = 1;
        }

        for(int t=x-1; t > 0; t--){
            for(int j=1; j<y; j++){ // верхний этаж заполнили, теперь увеличим верхний этаж
                a[t-1][j] = a[t][j];
            }
            for(int v=1; v<y; v++){
                a[t-1][v] = a[t-1][v] + a[t-1][v-1];
            }
        }
        cout<<"Total count of roads is: "<<a[0][y-1]<<endl;
    }



int main()
{
    int a = 351; // если поменяли кол-во цифр в числе, не забудь поменять константу в ф-ции
    int b = 362;
    int c = 398;
    bruteForce(a,b,c);

    cout<<countOfRoads(6)<<endl;

    countOfRoadsOfField(5,5);


    return 0;
}
