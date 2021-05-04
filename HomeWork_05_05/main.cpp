#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#define SECTABLE_SIZE_X 7 // Attention, если входные данные второй задачи изменились, меняем тут тоже

using namespace std;

    void minCountCoins(int x){
        int ten = 0;
        int five = 0;
        int one = 0;

        if(x == 0){
            cout<<"You entered Zero, please be more attentive!"<<endl;
            return;
        }

        while(x > 9){
            x -= 10;
            ten++;
        }

        while(x >= 5){
            x -= 5;
            five++;
        }

        while(x > 0){
            x -= 1;
            one++;
        }

        cout<<"Total number of coins is "<<ten+five+one<<endl;
        cout<<"Number of ten-coins is "<<ten<<endl;
        cout<<"Number of five-coins is "<<five<<endl;
        cout<<"Number of one-coins is "<<one<<endl;
    }


    void richProgrammerWork(int * workingDays, int tasks[SECTABLE_SIZE_X][3], int countOfDays){

        for (int startIndex = 0; startIndex < SECTABLE_SIZE_X - 1; startIndex++){
		int biggestIndex = startIndex;
		for (int currentIndex = startIndex + 1; currentIndex < SECTABLE_SIZE_X; currentIndex++)
		{
			if (tasks[currentIndex][1] > tasks[biggestIndex][1])
				biggestIndex = currentIndex;
		}
		std::swap(tasks[startIndex],tasks[biggestIndex]);
        }


        int orderOfTasks[countOfDays];
        for(int t=0; t < countOfDays; t++){
            orderOfTasks[t] = 0;
        }


        for(int i=0; i < SECTABLE_SIZE_X; i++){
            if(workingDays[tasks[i][2] - 1] != -1){
                workingDays[tasks[i][2] - 1] = -1;
                orderOfTasks[tasks[i][2] - 1] = tasks[i][0];
                continue;
            }

            for(int w=tasks[i][2]-1; w > -1; w--){
                if(workingDays[w] != -1){
                    workingDays[w] = -1;
                    orderOfTasks[w] = tasks[i][0];
                    break;
                }
            }

        }

        for(int j=0; j < countOfDays; j++){
            cout<<orderOfTasks[j];
        }
        cout<<endl;
    }



int main()
{
    int sum = 27;
    minCountCoins(sum);

    int workingDays[6] = {1,2,3,4,5,6}; // Если поменяли кол-во дней, то меняем и 3-ий аргумент в ф-ции ниже.

    int tasks[SECTABLE_SIZE_X][3] = {
    {1,23,2},
    {2,16,3},
    {3,10,6},
    {4,15,4},
    {5,2,1},
    {6,15,5},
    {7,13,3}
    };

    richProgrammerWork(workingDays, tasks, 6);


    return 0;
}
