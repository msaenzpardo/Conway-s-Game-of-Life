#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "life.h"

void populateWorld(char fname[], char *grid[], int *numRows, int *numCols) {

    FILE* file = fopen(fname, "r");

    if (file == NULL){
        printf("Error opening file.\n"); // need to check this!
        exit(1);
    }

    char create[256];
    // impt
    *numRows = 0;
    *numCols = 0;

    while (fgets(create, sizeof(create), file)) {

        //strcspn: ret index of first char found
        create[strcspn(create, "\n")] = '\0'; // add null term
        grid[*numRows] = (char *)malloc((strlen(create) + 1) * sizeof(char));


        for (int i = 0; i < strlen(create); i++) {
            if (create[i] == '1') {
                grid[*numRows][i] = '1'; // alive
            } else {
                grid[*numRows][i] = '.'; // dead
            }
        }
        grid[*numRows][strlen(create)] = '\0';

        (*numRows)++;
        *numCols = strlen(create);
    }
    // how to end ?
    fclose(file);
}

void showWorld(char *grid[], int numRows, int numCols) {
    for (int x = 0; x < numRows; x++) {
        for (int y = 0; y < numCols; y++) {
            if (grid[x][y] == '1') { // alive
                printf("*"); // replace
            } else {
                printf("."); // otherwise dead
            }
        }
        printf("\n");
    }
    printf("\n");
}

// replace
void iterateGeneration(char *grid[], int numRows, int numCols) {

    char **newGrid = (char **)malloc(numRows * sizeof(char *));

    for (int s = 0; s < numRows; s++) {
        newGrid[s] = (char *)malloc((numCols + 1) * sizeof(char));
        //copy this grid onto new grid
        strcpy(newGrid[s], grid[s]);
    }

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            int neighborCt = 0;

            //check surrounding cells
            for (int x = i - 1; x <= i + 1; x++) {
                for (int y = j - 1; y <= j + 1; y++) {

                    if (x == i && y == j) {
                        continue; // replacement?
                    }

                    // check for 'within bounds'
                    if (x >= 0 && x < numRows && y >= 0 && y < numCols) {
                        if (grid[x][y] == '1') {
                            neighborCt++;
                        }
                    }
                }
            }

            if (grid[i][j] == '1') {
                if (neighborCt == 2 || neighborCt == 3) {
                    newGrid[i][j] = '1';  //surviving
                } else {
                    newGrid[i][j] = '.';  //dies
                }
            } else {
                if (neighborCt == 3) {
                    newGrid[i][j] = '1';  //becomes alive
                } else {
                    newGrid[i][j] = '.';  //stays dead
                }
            }
        }
    }

    //update and copy original and new grids
    for (int i = 0; i < numRows; i++) {
        strcpy(grid[i], newGrid[i]);
        free(newGrid[i]);
    }
    free(newGrid);
}