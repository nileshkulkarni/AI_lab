#ifndef PRIORITY_H
#define PRIORITY_H

#include<stdio.h>
#include<iostream>
#include<vector>
#include<list>
#include "header.h"
using namespace std;

class PriorityQueue
{
    vector<int> pq_keys;
    void shiftRight(int low, int high);
    void shiftLeft(int low, int high);
    void buildHeap();
public:
    PriorityQueue(){}
    PriorityQueue(vector<int>& items)
    {
        pq_keys = items;
        buildHeap();
    }
    /*Insert a new item into the priority queue*/
    void enqueue(int item);
    /*Get the maximum element from the priority queue*/
    int dequeue();
    /*Just for testing*/
    void print();
};

#endif