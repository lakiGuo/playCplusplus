// ApplicationOfArrayQueue.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "arrayQueue.h"
using namespace std;
arrayQueue<int>* track;
arrayQueue<int> output;
int numberOfCars;
int numberOfTracks;
int smallestCar;
int itsTrack;
bool putInHoldingTrack(int c);
void outputFromHoldingTrack();

void outputFromHoldingTrack() {
    output.push(track[itsTrack].front());
    track[itsTrack].pop();
    cout << "Move car " << smallestCar << " from holding track " << itsTrack+1 << " to output track" << endl;
    smallestCar = numberOfCars+2;
    //加一会有未经处理的异常
    for (int i = 0; i <= numberOfTracks-1; i++) {
        if (!track[i].empty() && track[i].front() < smallestCar) {
            smallestCar = track[i].front();
            itsTrack=i;
        }
    }
}

bool putInHoldingTrack(int c) {
    int bestTrack = -1;
    int bestLast = 0;
    for (int i = 0; i <= numberOfTracks-1; i++) {
        if (!track[i].empty()) {
            int lastCar = track[i].back();
            if (c > lastCar&& lastCar > bestLast) {
                bestLast = lastCar;
                bestTrack = i;
            }
        }
        else if (bestTrack==-1){
            bestTrack = i;
        }
        
    }
    if (bestTrack == -1) return false;
    track[bestTrack].push(c);
    cout << "Move car " << c << " from input track " << "to holding track " << bestTrack+1 << endl;
    if (c < smallestCar) {
        smallestCar = c;
        itsTrack = bestTrack;
    }
    return true;
}

bool railroad(int inputOrder[], int theNumberOfcars, int theNumberOfTracks) {
    numberOfCars = theNumberOfcars;
    numberOfTracks = theNumberOfTracks;
    track = new arrayQueue<int>[numberOfTracks];
    int nextCarToOutput = 1;
    //store the minimum of HoldingTracks
    smallestCar = numberOfCars+1;
    for (int i = 1; i <= numberOfCars; i++) {
        if (inputOrder[numberOfCars - i] == nextCarToOutput) {
            cout << "Move car " << inputOrder[numberOfCars - i] << " from input track to output track"<<endl;
            output.push(inputOrder[numberOfCars - i]);
            nextCarToOutput++;
            //Move the car from HoldingTrack to OutputTrack
            while (smallestCar == nextCarToOutput) {
                outputFromHoldingTrack();
                nextCarToOutput++;
            }
        }
        else if(!putInHoldingTrack(inputOrder[numberOfCars - i])){
            return false;
        }
    }

    return true;
}

int* order_array(arrayQueue<int>& output) {
    int n = output.size();
    int* a = new int[n];
    for (int i = 1; i <=n; i++) {
        a[n - i] = output.front();
        output.pop();
    }
    return a;
}

int main()
{
    int a[9] = { 5,8,1,7,4,2,9,6,3 };
    int* b;
    /*需要增加缓冲通道的判断*/
    /*队列输入的是缓冲轨道个数不是总轨道个数*/
    railroad(a, 9, 2);
    cout << "output queue is: " << output << endl;
    b = order_array(output);
    for (int i = 0; i < 9; i++) cout << b[i] << " ";
}


