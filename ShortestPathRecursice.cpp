//SHORTEST PATH - RECURSIVE

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int NUM_ROWS = 5, NUM_COLS = 6;
string path[NUM_ROWS][NUM_COLS];

int calculateCost(int i, int j) {
    static int weight[NUM_ROWS][NUM_COLS] = {{3, 4, 1, 2, 8, 6},
                                            {6, 1, 8, 2, 7, 4},
                                            {5, 9, 3, 9, 9, 5},
                                            {8, 4, 1, 3, 2, 6},
                                            {3, 7, 2, 8, 6, 4}};
    static int cost[NUM_ROWS][NUM_COLS] = {};
    if (cost[i][j] != 0)
        return cost[i][j];
    
    if (j==0){
        path[i][j] = to_string(i);
        return weight[i][j];
    }
    int up = calculateCost((i+NUM_ROWS-1)%NUM_ROWS, j-1);
    int left = calculateCost(i, j-1);
    int down = calculateCost((i+1)%NUM_ROWS, j-1);
    int minCost = min(min(up,left), down);
    
    if (minCost == up)
        path[i][j] = path[(i+NUM_ROWS-1)%NUM_ROWS][j-1] + to_string(i);
    else if (minCost == left)
        path[i][j] = path[i][j-1] + to_string(i);
    else
        path[i][j] = path[(i+1)%NUM_ROWS][j-1] + to_string(i);
    cost[i][j] = minCost + weight[i][j];
    return cost[i][j];
}
int main() {
    int minRow = 0;
    for (int i=1; i < NUM_ROWS; ++i)
        if(calculateCost(i, NUM_COLS-1) < calculateCost(minRow, NUM_COLS-1))
            minRow=i;
    cout<< "The length of the shortest path is " << calculateCost(minRow, NUM_COLS-1) << "." << endl;
    cout<< "The rows of the path from the left to right are " << path[minRow][NUM_COLS-1] << "." << endl;
    
    return 0;
}
