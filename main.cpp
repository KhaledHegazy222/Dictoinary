#include <iostream>
#include <set>
#include "dictionary.h"

using namespace std;



int main(int argc,char **argv){

    if(argc < 2){
        cout << "Add More Files Please\n";
        return 1;
    }

    init();
    load(argv[1]);

    for(int i = 2;i < argc;i++){
        std::ifstream fileReader;
        fileReader.open(argv[i]);


        set<string>missSpelled;
        int correctCnt = 0,missSpelledCnt = 0;
        string word;
        while(fileReader >> word){
            if(check(word)){
                correctCnt++;
            }
            else{
                missSpelledCnt++;
                missSpelled.insert(word);
            }
        }

        int totalWords = correctCnt + missSpelledCnt;
        double accuracy = (correctCnt * 100.0) / (correctCnt + missSpelledCnt); 
        cout << "Accuracy = " << accuracy << "%" << endl;

        cout << "Number of Correct Words = " << correctCnt << endl;
        cout << "Number of Miss Spelled Words = " << missSpelledCnt << endl;

        cout << "Miss Spelled Word(s): ";
        for(auto word : missSpelled){
            cout << word << endl;
        }




        fileReader.close();
    }

    clear();


}