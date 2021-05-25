#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <fstream>
#include <ctime>

using namespace std;

struct Point{

    int x;
    int y;

    Point(int x, int y){
        this->x = x;
        this->y = y;
    }

    void PrintPoint(){
        cout<<"("<<x<<"; ";
        cout<<y<<")"<<endl;
    }
};

int OrientTriangl(Point &p1, Point &p2, Point &p3)
{
    return p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y);
}

bool isInside(Point &p1, Point &p, Point &p2)
{
    return ( (p1.x <= p.x && p.x <= p2.x) &&
             (p1.y <= p.y && p.y <= p2.y));
}

void JarvisAlgorithm(vector<Point> &points, vector<int> &indexesOfTheShell){
    int base = 0;
    int n = points.size();
    for(int i=1; i < n; i++){
        if (points[i].y < points[base].y){
            base = i;
        }else if(points[i].y == points[base].y &&
            points[i].x < points[base].x){
            base = i;
            //cout<<points[i].y<<endl;
        }
    }
    indexesOfTheShell.push_back(base);

    int first = base;
    int current = base;
    int countOfIterations = 0;

    do{
        int next = (current + 1) % n;
        for (int i=0; i<n; i++)
        {
          int sign = OrientTriangl(points[current], points[next], points[i]);
          if (sign < 0){
            next = i;
          }

          else if (sign == 0){
            if (isInside(points[current],points[next],points[i]))
              next = i;
          }
          // или засунуть переменную сюда
        }
        current = next;
        indexesOfTheShell.push_back(next);
        countOfIterations++;
    }
    while (current != first);

    cout<<"Count of iterations are: "<<countOfIterations<<endl;

}


void writeFromFileToArray(vector<Point> &points){
        ifstream file;
        file.open("files\\data_4194304.txt"); // Название файла менять тут, менять только число точек
        int x;
        int y;
        int switcher = 0;
        int counter = 0;
        while(!file.eof()){
            if(switcher == 0){
                file >> x;
                switcher = 1;
            }else{
                file >> y;
                points.push_back(Point(x,y));
                switcher = 0;
                counter++;
            }

        }
        cout<<"How many points have been written: "<<counter<<endl;
        file.close();
    }

int main()
{
    vector<int> indexesOfTheShell;
    vector<Point> points;

    writeFromFileToArray(points); // Чтение из файла в точки

    double startTime = clock();
    JarvisAlgorithm(points, indexesOfTheShell);
    double endTime = clock();
    double totalTime = (endTime - startTime) / CLOCKS_PER_SEC;
    cout<<"Duration: "<<totalTime<<endl;


    //for(int i=0; i < indexesOfTheShell.size() - 1; i++){
        //cout<<points[indexesOfTheShell[i]].x<<","<<points[indexesOfTheShell[i]].y<<endl; // Это проверка для себя, чтобы знать сколько точек соединено
    //}                                                                                    // в оболочке


    cout<<"Wall is from: "<<indexesOfTheShell.size()<<endl; // Инфо из скольких точек состоит оболочка


    return 0;
}
