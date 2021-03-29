
#include "adtmatrix.h"
#include "tests.h"
#include <iostream>
#include <fstream>


#define max 50
#define INFINITY 999999999



std::ifstream f;


void loadData(ADTMatrix* matrix, int& nodenr, int& startnode, int& destinationNode) {

    f.open("example.in");

    if (!f.is_open()) {
        std::cerr << "Unable to open file";
        exit(1);
    }



    f >> nodenr;
    f >> startnode;
    f >> destinationNode;

    int line, col, val;
    for (int i = 1; i <= nodenr; i++) {
        f >> line;
        f >> col;
        f >> val;
        matrix->modify(line, col, val);
        matrix->modify(col, line, val);
    }
}

void dijkstra(ADTMatrix* mat, int n, int startnode, int destnode) {
    n++;
    int distance[max], pred[max];
    ADTMatrix* cost = new ADTMatrix(max, max);
    int visited[max], count, mindistance, nextnode, i, j;
    for (i = 1; i < n; i++)
        for (j = 1; j < n; j++)
            if (mat->element(i, j) == 0)
                cost->modify(i, j, INFINITY);
            else
                cost->modify(i, j, mat->element(i, j));
    for (i = 1; i < n; i++) {
        distance[i] = cost->element(startnode, i);
        pred[i] = startnode;
        visited[i] = 0;
    }
    distance[startnode] = 0;
    visited[startnode] = 1;
    count = 1;
    while (count < n - 1) {
        mindistance = INFINITY;
        for (i = 1; i < n; i++)
            if (distance[i] < mindistance && !visited[i]) {
                mindistance = distance[i];
                nextnode = i;
            }
        visited[nextnode] = 1;
        for (i = 1; i < n; i++)
            if (!visited[i])
                if (mindistance + cost->element(nextnode, i) < distance[i]) {
                    distance[i] = mindistance + cost->element(nextnode, i);
                    pred[i] = nextnode;
                }
        count++;
    }
    for (i = 1; i < n; i++)
        if (i == destnode) {
            std::cout << "\nDistance to city " << i << ": " << distance[i] << "km";
            std::cout << "\nPath: " << i;
            j = i;
            do {
                j = pred[j];
                std::cout << "<-" << j;
            } while (j != startnode);
        }
}



int main(){

    int nrNodes, startingNode, destinationNode;

    tests();

    ADTMatrix* mat = new ADTMatrix(max, max);


    loadData(mat, nrNodes, startingNode, destinationNode);

    dijkstra(mat, nrNodes, startingNode, destinationNode);

    return 0;
}
