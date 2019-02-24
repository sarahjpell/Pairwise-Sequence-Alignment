//
// Created by sarah pell on 2/23/2019.
//

#include "localAlignment.h"

//s(i,j) = {+2 match, -1 mismatch}
//gap = -2g
//dna seq len 5-50


/*
void initializeMatrix();
void populateMatrix();
double findMax();
double findScore(char i, char j);
void showScores();
*/

int gap = -2;
int match = 2;
int mismatch = -1;

void localMatrix(string seq1, string seq2, int len1, int len2){
    int matrix[len1+1][len2+1];
    for (int i = 0; i <= len1; i++){
        for (int j = 0; j <= len2; j++){
            matrix[i][j] = 0;
        }
    }

    int scoreI[len1+1][len2+1];
    int scoreJ[len1+1][len2+1];
    int traceback[4];

    for(int i = 0; i <= len1; i++){
        for(int j = 0; j <= len2; j++){
            traceback[0] = matrix[i-1][j-1]+findScoreLocal(seq1[i-1],seq2[j-1]);
            traceback[1] = matrix[i-1][j]+gap;
            traceback[2] = matrix[i][j-1]+gap;
            traceback[3] = 0;
            matrix[i][j] = findMaxLocal(traceback,4);
        }
    }
}

double findMaxLocal(int arr[], int len){

}

double findScore(char i, char j){
    int score = 0;
    if(i == j){
        score = match;
    }
    else {
        score = mismatch;
    }
    return score;
}
//initialize matrix

//fill with appropriate scores

//trace back sequences for suitable alignment