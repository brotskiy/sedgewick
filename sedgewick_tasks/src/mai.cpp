#include <iostream>

#include "1.3 Union-find algorithms/union_find.h"

int main(int argc, char* argv[])
{
    union_find_algorithms::DisjointSet set;

    set.add(5, 6);
    set.add(5, 4);
    set.add(6, 7);
    set.add(4, 7);

    return 0;
}