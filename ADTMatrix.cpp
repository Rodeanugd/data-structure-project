#include "adtmatrix.h"

int ADTMatrix::searchDLL(int i, int j) {
    if (this->DLL.head == -1)
        return 0;

    int current_node = this->DLL.head;
    while (current_node != this->DLL.tail) {
        if (this->DLL.nodes[current_node].info.line == i)
            if (this->DLL.nodes[current_node].info.column == j)
                return this->DLL.nodes[current_node].info.value;
        current_node = this->DLL.nodes[current_node].next;
    }
    if (current_node == this->DLL.tail)
        if (this->DLL.nodes[current_node].info.line == i)
            if (this->DLL.nodes[current_node].info.column == j)
                return this->DLL.nodes[current_node].info.value;
    return 0;
}

int ADTMatrix::modifyDLL(int i, int j, int val) {
    //If the matrix is empty
    if (this->DLL.head == -1) {
        this->DLL.head = this->DLL.firstEmpty;
        this->DLL.tail = this->DLL.firstEmpty;
        this->DLL.nodes[this->DLL.head].info.line = i;
        this->DLL.nodes[this->DLL.head].info.column = j;
        this->DLL.nodes[this->DLL.head].info.value = val;

        this->DLL.firstEmpty = this->DLL.nodes[this->DLL.firstEmpty].next;
        this->DLL.nodes[this->DLL.firstEmpty].prev = -1;

        this->DLL.nodes[this->DLL.head].next = -1;
        this->DLL.nodes[this->DLL.head].prev = -1;

        return 0;
    }

    int ret;
    int current_node = this->DLL.head;
    while (current_node != this->DLL.tail) {
        if (this->DLL.nodes[current_node].info.line == i)
            if (this->DLL.nodes[current_node].info.column == j)
            {
                ret = this->DLL.nodes[current_node].info.value; this->DLL.nodes[current_node].info.value = val; return ret;
            }
        current_node = this->DLL.nodes[current_node].next;
    }
    if (current_node == this->DLL.tail)
        if (this->DLL.nodes[current_node].info.line == i)
            if (this->DLL.nodes[current_node].info.column == j)
            {
                ret = this->DLL.nodes[current_node].info.value; this->DLL.nodes[current_node].info.value = val; return ret;
            }

    this->DLL.nodes[this->DLL.firstEmpty].info.line = i;
    this->DLL.nodes[this->DLL.firstEmpty].info.column = j;
    this->DLL.nodes[this->DLL.firstEmpty].info.value = val;

    this->DLL.nodes[current_node].next = this->DLL.firstEmpty;
    this->DLL.nodes[this->DLL.firstEmpty].prev = current_node;

    this->DLL.firstEmpty = this->DLL.nodes[this->DLL.firstEmpty].next;

    this->DLL.nodes[this->DLL.nodes[current_node].next].next = -1;
    this->DLL.nodes[this->DLL.firstEmpty].prev = -1;
    this->DLL.tail = this->DLL.nodes[current_node].next;

    return 0;
}

int ADTMatrix::removeDLL(int i, int j) {
    if (this->DLL.head == -1)
        return 0;

    int current_node = this->DLL.head;
    int ret;

    if (this->DLL.nodes[current_node].info.line == i)
        if (this->DLL.nodes[current_node].info.column == j) {
            ret = this->DLL.nodes[current_node].info.value;
            this->DLL.head = this->DLL.nodes[current_node].next;
            if (this->DLL.head == -1)
                this->DLL.tail = -1;
            this->DLL.nodes[current_node].next = this->DLL.firstEmpty;
            this->DLL.nodes[this->DLL.firstEmpty].prev = current_node;
            this->DLL.firstEmpty = current_node;

            return ret;
        }

    while (current_node != this->DLL.tail) {
        if (this->DLL.nodes[current_node].info.line == i)
            if (this->DLL.nodes[current_node].info.column == j) {
                ret = this->DLL.nodes[current_node].info.value;

                this->DLL.nodes[this->DLL.nodes[current_node].prev].next = this->DLL.nodes[current_node].next;
                this->DLL.nodes[this->DLL.nodes[current_node].next].prev = this->DLL.nodes[current_node].prev;

                this->DLL.nodes[current_node].prev = -1;
                this->DLL.nodes[current_node].next = this->DLL.firstEmpty;
                this->DLL.nodes[this->DLL.firstEmpty].prev = current_node;
                this->DLL.firstEmpty = current_node;



                return ret;
            }
        current_node = this->DLL.nodes[current_node].next;
    }
    if (current_node == this->DLL.tail)
        if (this->DLL.nodes[current_node].info.line == i)
            if (this->DLL.nodes[current_node].info.column == j) {
                ret = this->DLL.nodes[current_node].info.value;
                this->DLL.tail = this->DLL.nodes[current_node].prev;
                this->DLL.nodes[this->DLL.nodes[current_node].prev].next = -1;
                this->DLL.nodes[current_node].prev = -1;
                this->DLL.nodes[current_node].next = this->DLL.firstEmpty;
                this->DLL.nodes[this->DLL.firstEmpty].prev = current_node;
                this->DLL.firstEmpty = current_node;

                return ret;
            }

    return 0;

}







ADTMatrix::ADTMatrix() {
    this->nrL = 20;
    this->nrC = 20;

    //making an empty DLL
    this->DLL.nodes[1].prev = -1;
    this->DLL.nodes[this->DLL.cap].next = -1;
    for (int i = 1; i < this->DLL.cap; i++) {
        this->DLL.nodes[i].next = i + 1;
        this->DLL.nodes[i + 1].prev = i;
    }
    this->DLL.firstEmpty = 1;
    this->DLL.head = -1;
    this->DLL.tail = -1;
}

ADTMatrix::ADTMatrix(int nrL, int nrC) {
    if (nrL < 1 || nrC < 1)
        throw "The number or rows / columns can't be smaller than 1!";
    this->nrL = nrL;
    this->nrC = nrC;

    //making an empty DLL
    this->DLL.nodes[1].prev = -1;
    this->DLL.nodes[this->DLL.cap].next = -1;
    for (int i = 1; i < this->DLL.cap; i++) {
        this->DLL.nodes[i].next = i + 1;
        this->DLL.nodes[i + 1].prev = i;
    }
    this->DLL.firstEmpty = 1;
    this->DLL.head = -1;
    this->DLL.tail = -1;
}

ADTMatrix::~ADTMatrix() {

}

int ADTMatrix::nrLines() {
    return this->nrL;
}

int ADTMatrix::nrCols() {
    return this->nrC;
}

int ADTMatrix::element(int i, int j) {
    if (i < 1 || i > nrL || j < 1 || j > nrC)
        throw "The given position is not in the matrix!";

    return this->searchDLL(i, j);
}

int ADTMatrix::modify(int i, int j, int val) {
    if (i < 1 || i > nrL || j < 1 || j > nrC)
        throw "The given position is not in the matrix!";

    if (val == 0)
        return this->removeDLL(i, j);
    else
        return this->modifyDLL(i, j, val);
}


