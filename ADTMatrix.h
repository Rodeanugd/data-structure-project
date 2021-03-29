#ifndef ADTMATRIX_H
#define ADTMATRIX_H
#include <iostream>
/*
 Taking into consideration the fact that I don't need to implement a resize, i chose to take the size of a maximum matrix to be 50*50
 Even if this number doesn't exactly fit in with my problem statement (as countries have more than 50 cities), I hope it serves the 'demonstrative'
 purposes of this example.
 As such, I took the capacity of the array for my doubly linked list to be 50*5 = 250 (I considered a city to be directly connected to at most 5 others)
 */


struct Triple {
    int line;
    int column;
    int value;
};

struct DLLANode {
    Triple info;
    int next;
    int prev;
};

struct DLLA {
    DLLANode nodes[251];
    int cap = 250;
    int head;
    int tail;
    int firstEmpty;
};

class ADTMatrix {
private:
    int nrL;
    int nrC;
    DLLA DLL;

    int searchDLL(int i, int j);
    int modifyDLL(int i, int j, int val);
    int removeDLL(int i, int j);

public:




    ADTMatrix();
    ADTMatrix(int nrL, int nrC);
    ~ADTMatrix();
    int nrLines();
    int nrCols();
    int element(int i, int j);
    int modify(int i, int j, int val);

};

#endif // ADTMATRIX_H
