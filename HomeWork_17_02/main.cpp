#include <iostream>
#include "main.h"
#include "math.h"

using namespace std;

int main() {

    int countOfNums;   // Задание 1
    cin >> countOfNums;
    cout << sumOfNums(countOfNums);
    /////////////////////////////////////////////////////

    int a, b, c;
    cin >> a >> b >>c;
    valuesOfEquation(a, b, c); // Задание 2
    ////////////////////////////////////////////////////

    int x;
    cin >> x;
    int log = biggestExtentOfTwo(x); // Задание 3
    if (log == -999) {
        cout << "Something incorrect.";
        return 0;
    }
    cout << log;
    ////////////////////////////////////////////////////

    int number;
    unsigned int extent;
    cin >> number >> extent;
    int total = power(number, extent); // Задание 4
    cout << total;


    return 0;
}


int sumOfNums(int count) {
    int number;
    int sum = 0;
    for (int i = 0; i < count; i++) {
        cin >> number;
        sum += number;
    }

    return sum;
}

void valuesOfEquation(int a, int b, int c) {
    int d;
    d = b * b - (4*a*c);
    if (d < 0) {
        cout << "There are not values!";
        return;
    }

    if (d == 0) {
        cout << "Value is: " << -(b/2*a);
        return;
    }

    cout << "First value is: "<< (-b + sqrt(d))/(2*a) << endl;
    cout << "Second value is: "<< (-b - sqrt(d))/(2*a) << endl;

}

int biggestExtentOfTwo(int x) {
    if (x <= 0) {
        cout << "Inputed incorrect value!";
        return -999;
    }

    if (x == 1) {
        return -1;
    }

    int p = 0;
    int sum = 1;
    while (sum < x) {
        sum = sum * 2;
        p++;
    }

    return --p;
}

int power(int x, unsigned p) {
    int sum = 1;
    while (p > 0) {
        sum *= x;
        p--;
    }

    return sum;
}
