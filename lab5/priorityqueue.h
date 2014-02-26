#ifndef PRIORITY_H
#define PRIORITY_H

#include <stdio.h>
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class PriorityQueue
{
public:
    vector<int> pq_keys;
    void shiftRight(int low, int high);
    void shiftLeft(int low, int high);
    void buildHeap();
    PriorityQueue();
    PriorityQueue(vector<int>& items);
    /*Insert a new item into the priority queue*/
    void enqueue(int item);
    /*Get the maximum element from the priority queue*/
    int dequeue();
    /*Just for testing*/
    void print();
};

#endif