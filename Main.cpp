//
// Created by sarah pell on 2/23/2019.
//

#include "localAlignment.h"
#include "globalAlignment.h"

#include <iostream>;
#include <string>;
#include <memory>;

using namespace std;

//read in file with sequences
string inputFile(){

}

//write output to file
string outputFile(){

}

int main(){
    int choice;
    string file;

    //ask user for file name
    cout<<"Pairwise Sequence Alignment"<<endl;
    cout<<"What is the name of your file?"<<endl;
    cin>>file;

    //ask if local or global alignment
    while(choice != 1 && choice != 2 && choice != 3){
        cout<<"What would you like to do?"<<endl<<"1. local pairwise alignment"<<endl<<"2. global pairwise alignment"<<endl<<"3. Exit"<<endl<<"Enter a number: ";
        cin>>choice;

        switch(choice){
            case 1: cout<<"local"<<endl;
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