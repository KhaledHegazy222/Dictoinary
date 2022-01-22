

#include <fstream>


#ifndef DICTIONARY
    #define DICTIONARY

    #define HASH_TABLE_SIZE (int)1e6
    #define WORD_SIZE  50
    
    
    extern std::ifstream fileReader;


    struct node{
        char word[WORD_SIZE];
        node *next;
    };





    void init();
    void load(char *);
    void add(std::string);
    int check(std::string);
    int hash(std::string);
    void clear();




#endif