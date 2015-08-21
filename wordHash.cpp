// Joel Macias
// Section 1002
// CS302
// Assignment 8
//wordHash.cpp implementation file for wordHash.h
// wordHash will be used to test a concordance, words will be inserted from test files one at a time
// the words will then be passed through a hash function and placed in their apporiate location
// in our dynamic array
#include "wordHash.h"
#include <iomanip>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cctype>
#include <string>
#include <cstdlib>
#include <cmath>
using namespace std;

//  The wordHash() constructor should initialize the hash table to an empty state.
wordHash::wordHash(){
    
    hashSize = initialHashSize;
    
    reSizeCount = 0;
    
    collisionCount = 0;
    
    uniqueWordCount = 0;
    
   
    
    wordCounts = new unsigned int[initialHashSize];     // dynamic wordCounts
    
    for (int i = 0; i < initialHashSize; i++) {         // wordList is set to null
        wordCounts[i] = 0;
    }
    
    wordList = new string[initialHashSize];             // dynamic wordList
    
    for (int i = 0; i < initialHashSize; i++) {         // wordList is set to null
        wordList[i] = "NULL";
    }
    
    
}

// The ~wordHash() destructor should recover all dynamically allocated memory.
wordHash::~wordHash(){
    
    delete [] wordList;
    
    wordList = NULL;
    
    delete [] wordCounts;
    
    wordCounts = NULL;
}


// The hash() function should return a hash from the passed string. The hash should be created with the Jenkins One-At-A-Time Hash function2. The final returned hash must be mod'ed with the current hash size.
unsigned int wordHash::hash(string wordToHash) const{
    
    //cout<<wordToHash<<endl;
    
    
        unsigned int hash, i;
        for(hash = i = 0; i < wordToHash.length(); ++i)
        {
            hash += wordToHash[i];
            hash += (hash << 10);
            hash ^= (hash >> 6);
        }
        hash += (hash << 3);
        hash ^= (hash >> 11);
        hash += (hash << 15);
    
        hash = hash % hashSize;
    
        return hash;
}


// *********************************************************************************************************************
//Public Insert
//Private Insert
// *********************************************************************************************************************


//Public insert
void wordHash::insert(string wordToBeInserted){
    //cout<<"i'm stuck inisde insert"<<endl;
    
    //  check if word already exists in table
    
    unsigned int hashLocation = hash(wordToBeInserted);         // run through hash to get insert location
    
    
    /*
    
    if (wordList[hashLocation] == wordToBeInserted) {           // if wordToBeInserted is already in table ++ count
        
        wordCounts[hashLocation]++;
        
        
        return;                                                 // exit function
    }
    */
    
    if (incCount(wordToBeInserted)) {                           // if the word is already found exit the function
        return;
    }
    
    
    insert(wordToBeInserted, hashLocation);                     // call insert if word is unique
}


// Private insert
void wordHash::insert(string wordToBeInserted , unsigned int hashLocation){
    
    
    if (double(uniqueWordCount)/double(hashSize) > loadFactor) {
       // cout<<"inside Rehash if"<<endl;
        reSizeCount++;
        rehash();
        //cout<<"i'm out"<<endl;
    }
    
    
    
    
    
    // insert word, increase uniqueWordCount
    
    if (wordList[hashLocation] == "NULL") {                     // if location is empty, insert word
        wordList[hashLocation] = wordToBeInserted;
        wordCounts[hashLocation]++;
        uniqueWordCount++;                                      // increment uniqueWordCount
        return;
    }
    
    
    
    
    // check for collision, if so quadProbe
    
    unsigned int tempCollisionCount = 1;
    
    unsigned int tempQuadProbe = hashLocation;
    
    //if (wordList[hashLocation] != "NULL") {
    
    while (wordList[tempQuadProbe] != "NULL") {                  // continue quad probing untill empty index is found
        
        //cout<<"i'm stuck"<<endl;
        //cout<<wordToBeInserted<<endl;
        collisionCount++;
        //cout<<collisionCount<<endl;
        tempQuadProbe = next(tempCollisionCount, hashLocation);
        
        
        if (wordList[tempQuadProbe] == "NULL") {
            wordList[tempQuadProbe] = wordToBeInserted;
            wordCounts[tempQuadProbe]++;
            uniqueWordCount++;
            return;                                                          // exit loop if word was inserted
        }
        
        tempCollisionCount++;                                   // increment for quad probing
    }
    
}



// *********************************************************************************************************************
// *********************************************************************************************************************

// *********************************************************************************************************************
// rehash
// *********************************************************************************************************************

void wordHash::rehash(){
    
    
    
    
    static const unsigned int hashSizes[12]=
    {30011, 60013, 120017, 240089, 480043, 960017, 1920013, 3840037, 7680103, 30720299, 15360161, 61440629};
    
    string* tempWordList = wordList;                                // temp pointer points to old wordList
    
    unsigned int* tempWordCounts = wordCounts;                      // temp pointer points to old wordCounts
    
    hashSize = hashSizes[reSizeCount];
    
    wordList = new string[hashSize];                                // resize list to new given size
    
    wordCounts = new unsigned int[hashSize];                        // resize wordcounts to new given size
    
    for (int i = 0; i < hashSize; i++) {         // wordList is set to null
        wordCounts[i] = 0;
    }
    
    
    for (int i = 0; i < hashSize; i++) {         // wordList is set to null
        wordList[i] = "NULL";
    
    }
    uniqueWordCount = 0;
    
   // cout<<hashSizes[reSizeCount - 1]<<endl;
   // cout<<reSizeCount<<endl;
    for (int i = 0; i < hashSizes[reSizeCount-1]; i++) {
        
        if (tempWordList[i] != "NULL") {
            for (int j = 0; j < tempWordCounts[i]; j++) {               // keep inserting untill count is accuarate
                //cout<<"im stuck rehasht"<<endl;
                //cout<<tempWordCounts[i]<<endl;
               // cout<<hashSize<<endl;
                //cout<<tempWordList[i]<<endl;
                insert(tempWordList[i]);                                // pass word
                //cout<<" i'm dead"<<endl;
                
            }
        }
    }

    //uniqueWordCount = 0;
    delete [] tempWordList;
    delete [] tempWordCounts;
    //cout<<"i left"<<endl;
    
}

// *********************************************************************************************************************
// next
// *********************************************************************************************************************

unsigned int wordHash::next(unsigned int tempCollisionCount , unsigned int hashLocation) const{
    //cout<<"inside quad"<<endl;
    //cout<<tempCollisionCount<<endl;
    
    return ((hashLocation + (unsigned int)pow(tempCollisionCount, 2.0)) % hashSize);
}






// *********************************************************************************************************************
// *********************************************************************************************************************


// *********************************************************************************************************************
// showHashStats
// *********************************************************************************************************************

void wordHash::showHashStats() const{
    cout << "Hash Stats" << endl;
    cout << "\t Current Hash Size: "<< hashSize << endl;
    cout << "\t Hash Resize Operations: "<< reSizeCount << endl;
    cout << "\t Hash Collisions: "<< collisionCount << endl;
    
}

// *********************************************************************************************************************
// *********************************************************************************************************************


// *********************************************************************************************************************
// printHash
// *********************************************************************************************************************

void wordHash::printHash() const{
    
    cout << "Word Hash Contents:" << endl;
    
    
    for (int i = 0; i < hashSize; i++) {
        if (wordList[i] != "NULL") {
            cout << "'"<< wordList[i] <<"' : "<< wordCounts[i] << endl;
        }
    }
    
}

// *********************************************************************************************************************
// *********************************************************************************************************************

// *********************************************************************************************************************
// getUniqueWordCount
// *********************************************************************************************************************
unsigned int wordHash::getUniqueWordCount () const{
    
    return uniqueWordCount;
}
// *********************************************************************************************************************
// *********************************************************************************************************************



// *********************************************************************************************************************
// getWordCount
// *********************************************************************************************************************
unsigned int wordHash::getWordCount(string wordBeingSearchedFor) const {
    
    for (int i = 0; i < hashSize; i++) {
        if (wordList[i] == wordBeingSearchedFor) {
            return wordCounts[i];
        }
    }
    
        return 0;
}


// *********************************************************************************************************************
// *********************************************************************************************************************



// *********************************************************************************************************************
// getMaxNode
// *********************************************************************************************************************

void wordHash::getMaxNode(unsigned int& maxCount, string& maxString) const {
    
    for (int i = 0; i < hashSize; i++) {
        if (wordCounts[i] > maxCount) {
            maxCount = wordCounts[i];
            maxString = wordList[i];
        }
    }
    
}
// *********************************************************************************************************************
// *********************************************************************************************************************





// *********************************************************************************************************************
// incCount
// *********************************************************************************************************************

bool wordHash::incCount(string wordBeingSearchedFor){
    //cout<<" i'm stuck inside inccCount"<<endl;
    unsigned int hashLocation = hash(wordBeingSearchedFor);             // get hash location
    
    if (wordList[hashLocation] == wordBeingSearchedFor) {               // if wordToBeInserted is already in table ++ count, return true
        wordCounts[hashLocation]++;
        return true;
    }
    
    int tempCollisions = 1;
    unsigned int tempQuadProbe = 0;
    
    while (wordList[hashLocation] != "NULL") {
        //cout<<"inside the inccCount loop"<<endl;
        ////cout<<wordBeingSearchedFor<<endl;
        //cout<<"hash size "<<hashSize<<endl;
        //cout<<"unique: "<<uniqueWordCount<<endl;
       // cout<<uniqueWordCount/hashSize<<endl;
        
        tempQuadProbe = next(tempCollisions, hashLocation);             // get quad probe index
        
        if (wordList[tempQuadProbe] == wordBeingSearchedFor) {          // if the word is in quad probe index, inc couunt, return true
            wordCounts[tempQuadProbe]++;
            return true;
        }
        
        if (wordList[tempQuadProbe] == "NULL") {
            return false;                                               // exit loop if a NULL is encountered
        }
        tempCollisions++;                                               // increment tempCollisions to find next location
    }
    
    return false;
}

