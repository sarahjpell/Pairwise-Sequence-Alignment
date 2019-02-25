//
// Created by Owner on 2/25/2019.
//

#include "localAlignment.h"
void localAlign(string seq1, string seq2){
    cout<<"local alignment: "<<endl;
    //get length of sequences
    int seq1Len = seq1.length() ;
    int seq2Len = seq2.length() ;

    //local alignment
    //start with initialization of matrix
    //since local, first row/col = 0
    int localMatrix[seq1Len+1][seq2Len+1];
    localMatrix[0][0] = 0;
    for (int i = 1; i <= seq1Len; i++){
        localMatrix[i][0] = 0;
    }
    for(int j = 1; j <= seq2Len; j++){
        localMatrix[0][j] = 0;
    }

    //fill in the rest of the matrix based on penalties
    for(int i = 1; i <= seq1Len ; i++){
        for (int j = 1; j <= seq2Len ; j++){
            int diagScore = 0;
            //match
            if(seq1[i-1] == seq2[j-1]){
                diagScore = localMatrix[i-1][j-1] + 2;
            }
            //mismatch
            else{
                diagScore = localMatrix[i-1][j-1] - 1;
            }
            //left and upper, align with gap
            int gapLeft = localMatrix[i][j-1] -2;
            int gapRight = localMatrix[i-1][j] -2;
            int zero = 0;

            //find max score and set at (i,j) in matrix
            int maxScore = max({gapLeft, gapRight, diagScore, zero});
            localMatrix[i][j] = maxScore;
        }
    }

    //now traceback matrix to find local alignment
    char seq1TraceLocal[seq1Len ];
    char seq2TraceLocal[seq2Len ];

    //put characters from sequences into array
    for(int c = 0; c<=seq1Len; c++){
        seq1TraceLocal[c] = seq1[c];
    }
    for(int c2 = 0; c2<=seq2Len; c2++){
        seq2TraceLocal[c2] = seq2[c2];
    }

    string alignment1, alignment2;

    //keep tracing back until we get back to m = 0 or n = 0
    //find max value in matrix
    int matrixMax = 0;
    int iMaxIndex = 0;
    int jMaxIndex = 0;
    int maxct = 0;
    for(int i = 1; i <= seq1Len; i++){
        for(int j = 1; j <= seq2Len; j++){
            if(localMatrix[i][j]>matrixMax){
                matrixMax = localMatrix[i][j];
                iMaxIndex = i;
                jMaxIndex = j;
            }
        }
    }

    int m = iMaxIndex;
    int n = jMaxIndex;

    //find all instances of max score in matrix and traceback to find all alignments

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
        if(m>0 && n>0 && localMatrix[m][n] == localMatrix[m-1][n-1]+diagScore){
            alignment1 = seq2TraceLocal[n-1] + alignment1;
            alignment2 = seq1TraceLocal[m-1] + alignment2;
            m -= 1;
            n -= 1;
        }
        else if(n>0 && localMatrix[m][n] == localMatrix[m][n-1]-2){
            alignment1 = seq2TraceLocal[n-1]+alignment1;
            alignment2 = "-" + alignment2;
            n -=1;
        }
        else if(localMatrix[m][n] == 0){
            m = 0;
            n = 0;
        }
        else{
            alignment1 = "-" + alignment1;
            alignment2 = seq1TraceLocal[m-1] + alignment2;
            m-=1;
        }

    }

    cout<<"optimal score "<<localMatrix[seq1Len][seq2Len]<<endl;

    for(int x = 0; x<= seq1Len; x++){
        for(int y = 0; y<= seq2Len; y++){
            cout<<localMatrix[x][y]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<alignment2<<endl<<alignment1<<endl;

    cout<<endl<<"YES"<<endl;


    //find all instances of max score in matrix and traceback to find all alignments
    for(int i = 1; i <= seq1Len; i++){
        for(int j = 1; j <= seq2Len; j++){
            if(localMatrix[i][j] == matrixMax){
                alignment1 = "";
                alignment2 = "";

                m = i;
                n = j;

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
                    if(m>0 && n>0 && localMatrix[m][n] == localMatrix[m-1][n-1]+diagScore){
                        alignment1 = seq2TraceLocal[n-1] + alignment1;
                        alignment2 = seq1TraceLocal[m-1] + alignment2;
                        m -= 1;
                        n -= 1;
                    }
                    else if(n>0 && localMatrix[m][n] == localMatrix[m][n-1]-2){
                        alignment1 = seq2TraceLocal[n-1]+alignment1;
                        alignment2 = "-" + alignment2;
                        n -=1;
                    }
                    else if(localMatrix[m][n] == 0){
                        m = 0;
                        n = 0;
                    }
                    else{
                        alignment1 = "-" + alignment1;
                        alignment2 = seq1TraceLocal[m-1] + alignment2;
                        m-=1;
                    }

                }
                cout<<endl<<alignment2<<endl<<alignment1<<endl;
                maxct++;
            }
        }
    }
    cout<<"number of possible optimal sequences: "<<maxct<<endl;


}