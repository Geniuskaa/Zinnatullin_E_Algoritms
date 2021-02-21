#include <iostream>
#include "main.h"

using namespace std;

int main()
{
    int size = 9;
    const int finalSize = size;
    int a[size];
    for (int i = 0; i < size; i++) {
        a[i] = i;
    }
    int s = sum(a, size);

    cout << s << endl;
///////////////////////////////////////////////////

    int *q = new int[5]{1,2,3,4,5};
    int *w = new int[5]{6,7,8,9,10};
    int *arrSum = new int[10];
    for(int i = 0; i < 10; i++) {
        if(i < 5) {
            arrSum[i] = q[i];
        }
        arrSum[i] = w[i - 5];
    }
    delete[] q;
    delete[] w;
    cout<<arrSum[1]<<endl<<arrSum[9]<<endl;
//////////////////////////////////////////////////

    int k = 7;
    const int f = k;
    int unsorted[f]{7,15,84,1,8,23,7};
    sort(unsorted, k);
    for(int i = 0; i < k; i++){
        cout<<unsorted[i]<<" ";
    }


    return 0;
}






