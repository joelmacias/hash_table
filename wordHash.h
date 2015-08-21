// Joel Macias
// Section 1002
// CS302
// Assignment 8
//wordHash.cpp implementation file for wordHash.h
// wordHash will be used to test a concordance, words will be inserted from test files one at a time
// the words will then be passed through a hash function and placed in their apporiate location
// in our dynamic array

#ifndef __ast8__wordHash__
#define __ast8__wordHash__

#include <iostream>                  // Provides cout
#include <algorithm>                 // Provides max
#include <cstdlib>                   // Provides NULL
#include <cassert>                   // Provides assert
#include <string>


using namespace std;



class   wordHash{
public:
    
    wordHash();
    //  The wordHash() constructor should initialize the hash table to an empty state.
    
    ~wordHash();
    // The ~wordHash() destructor should recover all dynamically allocated memory.
    
    void insert(string);
    // The insert() function should increment the word count if the item is already in the hash table and if not, use the private function to insert the passed item into the hash table.
    
    bool incCount(string);
    // The incCount() function should search the hash table for the passed string and, if found, increment the word count associated with that string and return true. If the passed string is not found, the function should return false.
    
    unsigned int hash(string) const;
    // The hash() function should return a hash from the passed string. The hash should be created with the Jenkins One-At-A-Time Hash function2. The final returned hash must be mod'ed with the current hash size.
    
    void getMaxNode(unsigned int&, string&) const;
    // The getMaxNode() function should search for the word string associated with the largest count and return, via reference, the word string and count.
    
    void rehash();
    /* The rehash() function should create a new hash table approximately twice the size of the existing hash table (based on the provided table below), extract all entries from the current hash table, insert them into the new table, and delete the old hash table. The hash table resize counter should be updated. The entries should be placed with the private insert() function into the new hash table (which may place them at a different location). The next largest hash size should be obtained from the below table.
    static const unsigned int hashSizes[12]=
    {30011, 60013, 120017, 240089, 480043, 960017, 1920013, 3840037, 7680103, 30720299, 15360161, 61440629};
    If the the hash size needs to exceed the last entry and error message should be displayed.
    */
    
    void printHash() const;
    // The printHash() function should print all non-empty entries in the hash table. Note, this
    // function is primarily used for testing on small hash tables for testing.
    
    void showHashStats() const;
    /* The showHashStats() function is a utility function to print the current hash size, current
    hash table resize count, and the collision count.
     */
    
    
    unsigned int getUniqueWordCount() const;
    /* The showUniqueWordCount() function should display the formatted unique word count by calling the red-black tree countNodes() function. See the sample output for formatting.
     */
    
    unsigned int getWordCount(string) const;
    /*The getWordCount() function should return the count of the passed word (0 if not found).
     Note, since the words are all lower case, must search for only lower case words.
     */
    
    
    
private:
    void insert(string, unsigned int);
    /*The private insert() function should insert the passed item into the hash table. If the hash
    table entries exceeds the load factor (count/tableSize), the table must be rehashed via the private rehash() function. The hash() function must be used determine the table location. If a collision occurs, the collision count should be incremented and the next() function should be called to implement quadratic probing. The appropriate counts should be updated accordingly which may be called repeatedly. The collision count should be incremented appropriately.*/
    
    unsigned int next(unsigned int, unsigned int) const;
    // The private next() function should be called when there is a collision and should implement a quadratic probing approach.
    
    unsigned int hashSize;
    
    unsigned int reSizeCount;
    
    unsigned int collisionCount;
    
    unsigned int uniqueWordCount;
    
    string* wordList;
    
    unsigned int* wordCounts;
    
    static const double loadFactor = 0.65;
    
    static const int initialHashSize = 30011;
    
    
    
    
    
    
};





#endif /* defined(__ast8__wordHash__) */
