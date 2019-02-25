//
// Created by sarah pell on 2/23/2019.
//


#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <algorithm>
#include "globalAlignment.h"
#include "localAlignment.h"
using namespace std;


int main(){
    int choice = 0;

    string fileName;
    string sequences[2] = {};

    //keep running program until the user wants to exit (enters 1)
    while(choice != 1){
        //ask user for file name
        cout<<"Pairwise Sequence Alignment"<<endl;
        cout<<"What is the name of your file?"<<endl;
        cin>>fileName;

        //read through file and get sequences
        string line;
        int count = 0;
        ifstream file(fileName);
        if(file.is_open()){
            cout<<"input: "<<endl;
            while(getline(file,line)){
                cout<<line<<endl;
                sequences[count] = line;
                count++;
            }
            file.close();
        }
        else{
            cout<<"unable to find file"<<endl;
        }
        cout<<"--------------------------------------------"<<endl;
        //global alignment
        globalAlign(sequences[0], sequences[1]);
        cout<<"--------------------------------------------"<<endl;
        //local alignment
        localAlign(sequences[0], sequences[1]);
        cout<<"--------------------------------------------"<<endl;
        cout<<"would you like to try another file?"<<endl<<"hit any number to continue"<< endl<<"1 to exit"<<endl;
        cin>>choice;
    }


    return 0;

}