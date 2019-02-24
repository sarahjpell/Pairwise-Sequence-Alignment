//
// Created by sarah pell on 2/23/2019.
//

#include "localAlignment.h"
#include "globalAlignment.h"

#include <iostream>;
#include <fstream>;
#include <string>;
#include <memory>;

using namespace std;


//write output to file
string outputFile(string fileName, string seq){
    ofstream file(fileName);
    if(file.is_open()){
        file<<seq;
        file.close();
    }
    else cout<<"unable to open file";
}

int main(){
    int choice;
    string fileName;
    string sequences[] = {};

    //ask user for file name
    cout<<"Pairwise Sequence Alignment"<<endl;
    cout<<"What is the name of your file?"<<endl;
    cin>>fileName;

    //read through file and get sequences
    string line;
    int count = 0;
    ifstream file(fileName);
    if(file.is_open()){
        while(getline(file,line)){
            sequences[count] = line;
            count++;
        }
        file.close();
    }
    else{
        cout<<"unable to find file"<<endl;
    }
    string seq1 = sequences[0];
    string seq2 = sequences[1];

    int seq1Len = seq1.length();
    int seq2Len = seq2.length();

    //ask if user wants to do local or global alignment
    while(choice != 1 && choice != 2 && choice != 3){
        cout<<"What would you like to do?"<<endl<<"1. local pairwise alignment"<<endl<<"2. global pairwise alignment"<<endl<<"3. Exit"<<endl<<"Enter a number: ";
        cin>>choice;

        switch(choice){
            case 1:
                cout<<"local alignment"<<endl;
                //initialize matrix
                //populate matrix
                localMatrix(seq1, seq2, seq1Len, seq2Len);
                //print scoring matrix
                //find max score
                //traceback
                //consensus sequences
                break;

            case 2: cout<<"global"<<endl;
                break;

            case 3:
                break;

            default: cout<<"That wasn't an option"<<endl;
                break;
        }

    }

    return 0;
    //2.01: optimal score, int

    //2.02: dynamic programming matrix
    //first dna has length m
    //second dna has length n
    //output: m+1 lines containing n+1 int vals, sep w/single space

    //2.03:best alignment of the two input sequences on two lines

    //2.04: are there multiple alignments? YES/NO

    //2.05: bonus -- report all possible optimal alignments
    //first line write num of optimal alignments
    //put every alignment in two lines separated by an empty line


}