//SHORTEST PATH - NONRECURSIVE
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int NUM_ROWS = 5, NUM_COLS = 6;
int minRow, minLength;
string path[NUM_ROWS][NUM_COLS];

void calculateCost() {
    static int weight[NUM_ROWS][NUM_COLS] = {{3, 4, 1, 2, 8, 6},
                                            {6, 1, 8, 2, 7, 4},
                                            {5, 9, 3, 9, 9, 5},
                                            {8, 4, 1, 3, 2, 6},
                                            {3, 7, 2, 8, 6, 4}};
    static int cost[NUM_ROWS][NUM_COLS] = {};
    
    for(int i = 0; i < NUM_ROWS; ++i) {
        cost[i][0] = weight[i][0];
        path[i][0] = to_string(i);
    }
    for (int j = 1; j < NUM_COLS; ++j)
        for(int i = 0; i < NUM_ROWS; ++i){
            int up = cost[(i+NUM_ROWS-1)%NUM_ROWS][j-1];
            int left = cost[i%NUM_ROWS][j-1];
            int down = cost[(i+1)%NUM_ROWS][j-1];
            int minCost = min(min(up, left), down);
            
            if (minCost == up)
                path[i][j] = path[(i+NUM_ROWS-1)%NUM_ROWS][j-1] + to_string(i);
            else if ( minCost == left)
                path[i][j] = path[i][j-1] + to_string(i);
            else
                path[i][j] = path[(i+1)%NUM_ROWS][j-1] + to_string(i);
            cost[i][j] = minCost + weight[i][j];
        }
    minRow = 0, minLength = cost[0][NUM_COLS-1];
    for( int i = 1; i < NUM_ROWS; ++i)
        if(cost[i][NUM_COLS-1] < minLength)
            minRow = i, minLength = cost[i][NUM_COLS-1];
}
int main() {
    calculateCost();
    cout<< "The length of the shortest path is: " << minLength << endl;
    cout<< "The rows of the path from left to right are " << path[minRow][NUM_COLS-1] << "." << endl;
    
    return 0;
}

