#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

int sum(int * a, int size) {
    int sum = 0;
    for (int * p = a; p < a + size; p++) {
        sum += *p;
    }
    return sum;
}

void sort(int * a, int size) {
    for(int i = 0; i < size - 1; i++){
        for(int j = i + 1; j < size; j++){
            if (a[i] > a[j]) {
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }
}


#endif // MAIN_H_INCLUDED
