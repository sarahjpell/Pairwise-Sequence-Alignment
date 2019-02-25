//
// Created by sarah pell on 2/23/2019.
//

#include "globalAlignment.h"

//s(i,j) = {+2 match, -1 mismatch}
//gap = -2g
//dna seq len 5-50

void globalAlign(string seq1, string seq2){
    cout<<"global alignment"<<endl;

    int seq1Len = seq1.length() ;
    int seq2Len = seq2.length() ;

    //global alignment
    //start with initialization of matrix
    //since global, first row/col = -2g
    int globalMatrix[seq1Len+1][seq2Len+1];
    globalMatrix[0][0] = 0;
    for (int i = 1; i <= seq1Len; i++){
        globalMatrix[i][0] = globalMatrix[i-1][0] - 2;
    }
    for(int j = 1; j <= seq2Len; j++){
        globalMatrix[0][j] = globalMatrix[0][j-1] - 2;
    }

    //fill in the rest of the matrix based on penalties
    for(int i = 1; i <= seq1Len ; i++){
        for (int j = 1; j <= seq2Len ; j++){
            int diagScore = 0;
            if(seq1[i-1] == seq2[j-1]){
                diagScore = globalMatrix[i-1][j-1] + 2;
            }
            else{
                diagScore = globalMatrix[i-1][j-1] - 1;
            }

            int gapLeft = globalMatrix[i][j-1] -2;
            int gapRight = globalMatrix[i-1][j] -2;

            int maxScore = max({gapLeft, gapRight, diagScore});
            globalMatrix[i][j] = maxScore;
        }
    }

    //now traceback matrix to find global alignment
    char seq1TraceGlobal[seq1Len ];
    char seq2TraceGlobal[seq2Len ];

    for(int c = 0; c<=seq1Len; c++){
        seq1TraceGlobal[c] = seq1[c];
    }
    for(int c2 = 0; c2<=seq2Len; c2++){
        seq2TraceGlobal[c2] = seq2[c2];
    }

    string alignment1, alignment2;
    int m = seq1Len;
    int n = seq2Len;

    while(m > 0 && n > 0){
        int diagScore;
        //match
        if(seq2[n-1] == seq1[m-1]){
            diagScore = 2;
        }
            //mismatch
        else{
            diagScore = -1;
        }
        if(m>0 && n>0 && globalMatrix[m][n] == globalMatrix[m-1][n-1]+diagScore){
            alignment1 = seq2TraceGlobal[n-1] + alignment1;
            alignment2 = seq1TraceGlobal[m-1] + alignment2;
            m -= 1;
            n -= 1;
        }
        else if(n>0 && globalMatrix[m][n] == globalMatrix[m][n-1]-2){
            alignment1 = seq2TraceGlobal[n-1]+alignment1;
            alignment2 = "-" + alignment2;
            n -=1;
        }
        else{
            alignment1 = "-" + alignment1;
            alignment2 = seq1TraceGlobal[m-1] + alignment2;
            m-=1;
        }
    }

    cout<<"optimal score "<<globalMatrix[seq1Len][seq2Len]<<endl;

    for(int x = 0; x<= seq1Len; x++){
        for(int y = 0; y<= seq2Len; y++){
            cout<<globalMatrix[x][y]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<alignment2<<endl<<alignment1<<endl;
    cout<<endl<<"YES"<<endl;

}