// Joel Macias
// Section 1002
// CS302
// Assignment 8
// This main will be using wordCount.h and wordHash. to implement a hash table for a concordance
// Words will be read from test files one at a time, and then will be passed through the hash function,
// and ultimately stored in their proper location in hopes of constant time retriveal. 


#include <iostream>

//  Main program for word counting.

#include <iostream>
#include <fstream>
#include <string>

#include "wordCount.h"
#include "wordHash.h"

using namespace std;

int main()
{
    
    // *****************************************************************
    //  Headers...
    
    string	bars, stars;
    bars.append(65, '-');
    stars.append(65, '*');
    
    cout << bars << endl << "CS 302 - Assignment #8" << endl;
    cout << endl;
    
    // *****************************************************************
    
    wordCount	myDoc0;
    unsigned int	max0;
    string	word0;
    string	testDoc0 = "data/smallTest.txt";
    
    cout << bars << endl << "Test Document #0" << endl << endl;
    
    if (myDoc0.readDocument(testDoc0) ) {
        myDoc0.showTotalWordCount();
        myDoc0.showUniqueWordCount();
        myDoc0.showHashStats();
        myDoc0.showDocumentFileName();
        myDoc0.getMaxNode(max0, word0);
        cout << endl;
        
        cout << "Most Frequent Word is: " << word0 <<
        " occurring " << max0 << " times." << endl << endl;
        
        cout << "Count for 'is': " <<
        myDoc0.getWordCount("is") << endl;
        cout << "Count for 'a': " <<
        myDoc0.getWordCount("a") << endl;
        cout << "Count for 'the': " <<
        myDoc0.getWordCount("the") << endl;
        cout << "Count for 'word': " <<
        myDoc0.getWordCount("word") << endl;
        cout << "Count for 'words': " <<
        myDoc0.getWordCount("words") << endl;
        cout << "Count for 'nonword': " <<
        myDoc0.getWordCount("nonword") << endl;
        cout << "Count for 'hard': " <<
        myDoc0.getWordCount("hard") << endl;
        cout << "Count for '(': " <<
        myDoc0.getWordCount("(") << endl;
        cout << "Count for '!': " <<
        myDoc0.getWordCount("!") << endl;
        cout << endl;
        
        myDoc0.printHash();
        cout << endl;
    }
    cout << endl;
    
    // ------------------------------
    
    wordCount	myDoc1;
    unsigned int	max1;
    string	word1;
    string	testDoc1 = "data/test.txt";
    
    cout << bars << endl << "Test Document #1" << endl << endl;
    
    if (myDoc1.readDocument(testDoc1) ) {
        myDoc1.showTotalWordCount();
        myDoc1.showUniqueWordCount();
        myDoc1.showHashStats();
        myDoc1.showDocumentFileName();
        myDoc1.getMaxNode(max1, word1);
        cout << endl;
        
        cout << "Most Frequent Word is: " << word1 <<
        " occurring " << max1 << " times." << endl << endl;
        
        cout << "Count for 'Nevermore': " <<
        myDoc1.getWordCount("Nevermore") << endl;
        cout << "Count for 'Prophet': " <<
        myDoc1.getWordCount("Prophet") << endl;
        cout << "Count for '-': " <<
        myDoc1.getWordCount("-") << endl;
        cout << endl;
        
        // myDoc1.printHash();
        // cout << endl;
    }
    cout << endl;
    
    // ------------------------------
    
    wordCount	myDoc2;
    unsigned int	max2;
    string	word2;
    string	testDoc2 = "data/nv.txt";
    
    cout << bars << endl << "Test Document #2" << endl << endl;
    
    if (myDoc2.readDocument(testDoc2) ) {
        myDoc2.showTotalWordCount();
        myDoc2.showUniqueWordCount();
        myDoc2.showHashStats();
        myDoc2.showDocumentFileName();
        myDoc2.getMaxNode(max2, word2);
        cout << endl;
        
        cout << "Most Frequent Word is: " << word2 <<
        " occurring " << max2 << " times." << endl << endl;
        
        cout << "Count for 'Nevada': " <<
        myDoc2.getWordCount("Nevada") << endl;
        cout << "Count for 'State': " <<
        myDoc2.getWordCount("State") << endl;
        cout << "Count for 'or': " <<
        myDoc2.getWordCount("or") << endl;
        cout << "Count for 'calendar': " <<
        myDoc2.getWordCount("calendar") << endl;
        cout << "Count for 'amended': " <<
        myDoc2.getWordCount("amended") << endl;
        cout << "Count for 'chamber': " <<
        myDoc2.getWordCount("chamber") << endl;
        cout << "Count for 'things': " <<
        myDoc2.getWordCount("things") << endl;
        cout << "Count for 'Home': " <<
        myDoc2.getWordCount("Home") << endl;
    }
    cout << endl;
    
    // ------------------------------
    
    wordCount	myDoc3;
    unsigned int	max3;
    string	word3;
    string	testDoc3 = "data/sw.txt";
    
    cout << bars << endl << "Test Document #3" << endl << endl;
    
    if (myDoc3.readDocument(testDoc3) ) {
        myDoc3.showTotalWordCount();
        myDoc3.showUniqueWordCount();
        myDoc3.showHashStats();
        myDoc3.showDocumentFileName();
        myDoc3.getMaxNode(max3, word3);
        cout << endl;
        
        cout << "Most Frequent Word is: " << word3 <<
        " occurring " << max3 << " times." << endl << endl;
        
        cout << "Count for 'Shareware': " <<
        myDoc3.getWordCount("Shareware") << endl;
        cout << "Count for 'PQLITE': " <<
        myDoc3.getWordCount("PQLITE") << endl;
        cout << "Count for 'bytes': " <<
        myDoc3.getWordCount("bytes") << endl;
        cout << "Count for 'modem': " <<
        myDoc3.getWordCount("modem") << endl;
        cout << "Count for 'handling': " <<
        myDoc3.getWordCount("handling") << endl;
        cout << "Count for 'modem': " <<
        myDoc3.getWordCount("modem") << endl;
        cout << "Count for 'TSR': " <<
        myDoc3.getWordCount("TSR") << endl;
        cout << "Count for 'PC-Draft-CAD': " <<
        myDoc3.getWordCount("PC-Draft-CAD") << endl;
        
        // myDoc3.printHash();
        // cout << endl;
    }
    cout << endl;
    
    // *****************************************************************
    //  All done.
    
    cout << bars << endl << "Game Over, thank you for playing." << endl;
    
    return 0;
}
