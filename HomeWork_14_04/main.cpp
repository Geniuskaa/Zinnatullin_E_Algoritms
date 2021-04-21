#include <iostream>
#define TABLE_SIZE_X 3
#define TABLE_SIZE_Y 4

#define SECTABLE_SIZE_X 4
#define SECTABLE_SIZE_Y 4
#include <bits/stdc++.h>

using namespace std;

void binarySearchInArray(int * a, int x, int length){
    int start = 0, end = length - 1;
    int temp = end - start;

    while(temp > 0){
        if((a[start] == x) && (a[end] == x)){
            break;
        }

        temp = (temp / 2) + start;

        if(a[temp] > x){
            end = temp - 1;
        }else if(a[temp] < x){
            start = temp + 1;
        }else{
            if((a[temp-1] == x) && (a[temp+1] == x)){
                if(a[end] != x){
                    end--;
                }
                if(a[start] != x){
                    start++;
                }

            }else if(a[temp-1] != x){
                start = temp;
            }else if(a[temp+1] != x){
                end = temp;
            }
        }

        temp = end - start;

    }

    cout<<start<<" - "<<end<<endl;
}


void binarySearchInMatrix(int a[TABLE_SIZE_X][TABLE_SIZE_Y], int x){
    bool found = false;
    int firstStart = 0;
    int n = TABLE_SIZE_X, m = TABLE_SIZE_Y;
    int firstEnd = n - 1;
    int firstTemp = (firstEnd - firstStart) / 2;
    int secondStart = 0;
    int secondEnd = m - 1;
    int secondTemp = (secondEnd - secondStart) /2;


    while((firstTemp > -1) && (secondTemp > -1)){
        if(a[firstTemp][secondTemp] == x){
            found = true;
            break;
        }

        if(secondStart == secondEnd){ // выход из цикла
            break;
        }

        if((a[firstTemp][secondStart] == x) || (a[firstTemp][secondEnd] == x)){
            found = true;
            break;
        }

        if(a[firstTemp][secondTemp] > x){
            if(a[firstTemp][secondStart] > x){
                firstTemp--;
                secondStart = 0;
                secondEnd = m - 1;
            }else if(secondTemp - 1 > 0){
                secondEnd = secondTemp - 1;
                secondStart++;
            }
            secondTemp = (secondEnd - secondStart) / 2 + secondStart;
        }else if(a[firstTemp][secondTemp] < x){
            if(a[firstTemp][secondEnd] < x){
                firstTemp++;
                secondStart = 0;
                secondEnd = m - 1;
            }else if(secondTemp + 1 < secondEnd){
                secondStart = secondTemp + 1;
                secondEnd--;
            }
            secondTemp = (secondEnd - secondStart)/2 + secondStart;
        }else{
            found = true;
            break;
        }
    }

    if(found == true){
        cout<<"We found it!"<<endl;
    }else{
        cout<<"Not such element!"<<endl;
    }
}


void binaryRootOfNum(int x){
    int answer = -1;
    int start = 0;
    int end = INT_MAX;
    int temp = (end - start) / 2;

    while(temp > 0){
        if(x == 1){
            answer = 1;
            break;
        }else if(x == 0){
            answer = 0;
            break;
        }else if(x < 0){
            cout<<"Error! You wrote negative value!"<<endl;
            break;
        }


        if((temp*temp) == x){
            answer = temp;
            break;
        }

        if(temp > x){
            end = x - 1;
            temp = (end - start) / 2 + start;
            continue;
        }


        if(((start + 1) == end) || (start == end)){
            if(start == end){
                end++;
            }

            if((x - (start*start)) > (end*end) - x){
                answer = end;
            }else{
                answer = start;
            }
            break;
        }

        if((temp*temp) > x){
            end = temp - 1;
            temp = (end - start) / 2 + start;
        }else if((temp*temp) < x){
            start = temp + 1;
            temp = (end - start) / 2 + start;
        }
    }

    cout<<"Root is "<<answer<<endl;
}


void binarySearchMedian(int a[SECTABLE_SIZE_X][SECTABLE_SIZE_Y]){

    int min = a[0][0], max = a[0][0];
    int n = SECTABLE_SIZE_X, m = SECTABLE_SIZE_Y;
    for (int i = 0; i < n; i++) {
        if (a[i][0] < min){
            min = a[i][0];
        }
        if (a[i][m-1] > max){
           max = a[i][m-1];
        }
    }

    int median = (n * m + 1) / 2; // на этой позиции будет наша медиана, если мы абстрактно представим нащу матрицу в виде отсортированного массива
    while (min < max) {
        int mid = (max - min) / 2 + min;
        int temp = 0;
        for (int i = 0; i < n; i++)
            temp += upper_bound(&a[i][0], &a[i][m], mid) - &a[i][0];
        if (temp < median)
            min = mid + 1;
        else
            max = mid;
    }

    cout<<"This is median: "<<min<<endl;

}

int main()
{
    int a[]{0,0,0,0,1,1,1,1,1,1,1,1,2,2,2,2,3,5,5,5,5,6,9,9,9,9,9,9};
    binarySearchInArray(a,5,28);

    int b[TABLE_SIZE_X][TABLE_SIZE_Y] = {
        {1,2,3,7},
        {8,9,10,15},
        {45,67,72,78}
        };

    binarySearchInMatrix(b,1);

    binaryRootOfNum(30);  // Если мы делим число, у которого нет целого корня, то оно округляется по 0.X,
                          // например корень из 30 = 5.477 - округлили до 5


    int c[SECTABLE_SIZE_X][SECTABLE_SIZE_Y] = {
        {1,3,8,9},
        {8,11,15,16},
        {11,12,16,18},
        {13,15,17,20}
        };

    binarySearchMedian(c);
    return 0;
}
