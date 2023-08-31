// life.h
// -- EE 312 Project 2
/* Student information for project:
*
* Replace <NAME> with your name.
*
* On my honor, <NAME>, this programming project is my own work
* and I have not provided this code to any other student.
*
* Name:
* email address:
* UTEID:
* Section 5 digit ID:
*
*///
// Created by priebe on 9/5/2018.
//
#ifndef UNTITLED8_LIFE_H
#define UNTITLED8_LIFE_H
#endif //UNTITLED1_LIFE_H
void populateWorld(char fname[], char *grid[], int *numRows, int *numCols);
void showWorld(char *grid[], int numRows, int numCols);
int countNeighbors (char *grid[], int numRows, int numCols, int m, int n);
void iterateGeneration(char *grid[], int numRows, int numCols);