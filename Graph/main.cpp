#include <iostream>
#include <fstream>
#include <string.h>
#include "graph.h"
using namespace std;

int main(){
    // Initializing graph in 2DArray:
    graph g("sample.txt");
    g.display();

    // Prims Alogrithms
    return 0;
}
