//
// Created by Owner on 2/23/2019.
//

#ifndef PAIRWISE_SEQUENCE_ALIGNMENT_LOCALALIGNMENT_H
#define PAIRWISE_SEQUENCE_ALIGNMENT_LOCALALIGNMENT_H

#include <string>;
using namespace std;

//read in file and display input

//smith-waterman algorithm for local alignment

void localMatrix(string seq1, string seq2, int len1, int len2);
double findMaxLocal(int arr[], int len);
double findScoreLocal(char i, char j);
void showScoresLocal();


#endif //PAIRWISE_SEQUENCE_ALIGNMENT_LOCALALIGNMENT_H
