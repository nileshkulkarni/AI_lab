#ifndef PUZZLE_H
#define PUZZLE_H
#include <iostream>
#include <list>
#include <stdio.h>
#include <vector>
#include "node.h"
#include "header.h"
#include <cmath>
using namespace std;
//Note: the grid is assumed to be a vector of 9x1 as opposed to 3x3

//finds the position of the blank tile
int findpos(vector<int>&);

//prints the current state
void printstate(vector<int>&);

//returns a vector of neighbours
vector< Node > getNeighbours(Node);

//print the node given its id
void printNode(long long int);
long long int getHash(vector<int> _state);

#endif
