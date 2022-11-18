#include <iostream>
#include <fstream>
#include <string.h>
#include "graph.h"
using namespace std;

int main(){
    // Initializing graph in 2DArray:
    graph g("sample.txt");
    // Prims Alogrithms
    g.prims_MST();
    g.display();
    return 0;
}
