#include <stdio.h>
#include <conio.h>
/*Total number of nodes in network*/
#define N 10
/*State of each node*/
#define PERMANENT 1
#define TENTATIVE 0

struct node {
    int weight;
    int prev;
    int state;
};

void main() {
    int table[N][N] =
        /* A B C D E F G H I J*/
        /*A*/ { { 0, 1, 0, 0, 0, 4, 0, 0, 0, 0 },
            /*B*/ { 1, 0, 4, 0, 0, 0, 0, 1, 0, 0 },
            /*C*/ { 0, 4, 0, 3, 2, 0, 0, 0, 3, 0 },
            /*D*/ { 0, 0, 3, 0, 1, 0, 0, 0, 0, 0 },
            /*E*/ { 0, 0, 2, 1, 0, 3, 0, 0, 0, 1 },
            /*F*/ { 4, 0, 0, 0, 3, 0, 1, 0, 0, 0 },
            /*G*/ { 0, 0, 0, 0, 0, 1, 0, 2, 0, 2 },
            /*H*/ { 0, 1, 0, 0, 0, 0, 2, 0, 1, 0 },
            /*I*/ { 0, 0, 3, 0, 0, 0, 0, 1, 0, 2 },
            /*J*/ { 0, 0, 0, 0, 1, 0, 2, 0, 2, 0 } }; /* A B C D E F G H I J*/
    /*interpret as A is connected to B at a weight of 1 as
table[A][B]=table[B][A]=1*/
    int src, dest, i, w_node;
    int min;
    struct node nodes[N];
    for (i = 0; i < N; ++i) {
        nodes[i].state = TENTATIVE;
        nodes[i].weight = 10000;
    }
    printf("\nEnter Source:");
    src = getche();

    w_node = src = toupper(src) - 'A';
    nodes[src].prev = -1;
    nodes[src].weight = 0;
    printf("\nEnter Destination:");
    dest = toupper(getche()) - 'A';
    do {
        nodes[w_node].state = PERMANENT;
        for (i = 0; i < N; ++i) {
            if (table[w_node][i] != 0 && nodes[i].state == TENTATIVE) {

                if (nodes[w_node].weight + table[w_node][i] < nodes[i].weight) {
                    nodes[i].weight = nodes[w_node].weight + table[w_node][i];
                    nodes[i].prev = w_node;
                }
            }
        }
        /*Find minimum weighted Tentative node*/
        min = 10000;
        for (i = 0; i < N; ++i) {
            if (nodes[i].state == TENTATIVE && nodes[i].weight < min) {
                min = nodes[i].weight;

                w_node = i;
            }
        }
    } while (w_node != dest);

    printf("\nShortest Path got--->\n%c", dest + 65);
    do {
        w_node = nodes[w_node].prev;
        printf("<-%c", w_node + 65);
    } while (w_node != src);
    printf("\nAt a total weight of:%d", nodes[dest].weight);
}