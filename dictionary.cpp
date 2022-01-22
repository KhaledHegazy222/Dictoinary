
#include <string.h>

#include "dictionary.h"




node* hashTable[HASH_TABLE_SIZE];


void init(){
    for(int i = 0;i < HASH_TABLE_SIZE;i++)
        hashTable[i] = NULL;
}

void load(char *fileName){
    std::ifstream fileReader;
    fileReader.open(fileName);
    
    std::string word;
    while(fileReader >> word)
        add(word);

}

void add(std::string word){
    for(auto &letter : word)
        letter = tolower(letter);
    int row = hash(word);
    node* ptr = (node *) malloc(sizeof(node));
    strcpy(ptr->word,word.c_str());
    
    node *cur = hashTable[row];
    if(cur == NULL){
        hashTable[row] = ptr;
    }
    else{
        while(cur->next != NULL){
            cur = cur->next;
        }
        cur->next = ptr;
    }
}

int check(std::string word){
    for(auto &letter : word)
        letter = tolower(letter);
    int row = hash(word);
    node *cur = hashTable[row];
    int found = 0;
    while(cur != NULL){
        if(!strcmp(cur->word,word.c_str())){
            found = 1;
            break;
        }
        else{
            cur = cur->next;
        }
    }
    return found;
}

void clear(){
    for(int i = 0;i < HASH_TABLE_SIZE;i++){
        node *ptr1 = hashTable[i];
        while(ptr1 != NULL){
            node *ptr2 = ptr1->next;
            free(ptr1);
            ptr1 = ptr2;
        }
        hashTable[i] = NULL;
    }
}

int hash(std::string word){
    int sum = 0;
    for(auto letter : word){
        sum += letter;
    }
    return sum % HASH_TABLE_SIZE;
}
