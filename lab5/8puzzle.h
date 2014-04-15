#ifndef PUZZLE_H
#define PUZZLE_H
#include <iostream>
#include <list>
#include <stdio.h>
#include <vector>
#include "Astar.h"
#include "graph.h"
#include "node.h"
#include "header.h"
using namespace std;
//Note: the grid is assumed to be a vector of 9x1 as opposed to 3x3

//finds the position of the blank tile
int findpos(vector<int>&);

//prints the current state
void printstate(vector<int>&);

//returns a vector of neighbours
vector< NodePtr > getNeighbours(NodePtr);

#endif
