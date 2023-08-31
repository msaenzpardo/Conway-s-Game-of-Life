
#include "life.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



int main() {
    const char* fName = "C:\\Users\\melan\\CLionProjects\\untitled8\\world.txt";
    const int genCount = 2;

    const int MAX_ROWS = 80;
    char *world[MAX_ROWS];

    int numRows;
    int numCols;

    populateWorld(fName, world, &numRows, &numCols);

    for (int iteration = 0; iteration < genCount; iteration++) {
        if (iteration > 0) {
            system("clear");
        }
        iterateGeneration(world, numRows, numCols);
    }

    showWorld(world, numRows, numCols);

    /*for (int i = 0; i < numRows; i++){
        free(world[i]);
    }*/
    free(*world);
    return 0;
}