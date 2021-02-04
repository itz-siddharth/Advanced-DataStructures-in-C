//11.	You have a business with several offices; you want to lease phone lines to connect them up with each other; and the phone company charges different amounts of money to connect different pairs of cities. 
//      You want a set of lines that connects all your offices with a minimum total cost. Solve the problem by suggesting appropriate data structures.  

#include<stdio.h>

#define ROW 10
#define COL 10
#define infi 9999

typedef struct prims{
	int nodes;
	int graph[ROW][COL];
	
}prims;

prims* createGraph(prims *p);
prims* primsAlgo(prims *p);


prims* createGraph(prims *p){
    int i, j;
    printf("Enter Total Offices: ");
    scanf("%d",&p->nodes);
    printf("\nEnter Adjacency Matrix: \n");
    for(i = 0; i < p->nodes; i++) {
        for(j = i; j < p->nodes; j++) {
            printf("Enter distance between %d and %d \n",i,j);
			scanf("%d",&p->graph[i][j]);
            p->graph[j][i] = p->graph[i][j];
        }
    }

    for(i = 0; i < p->nodes; i++) {
        for(j = 0; j < p->nodes; j++) {
            if (p->graph[i][j] == 0)
                p->graph[i][j] = infi;    //fill infinity where path is not present
        }
    }
}

prims* primsAlgo(prims *p) {
    int selected[ROW], i, j, ne=0;
    int zero = 0, one = 1, min = 0, x, y;
    int cost = 0;
    for(i = 0; i < p->nodes; i++)
        selected[i] = zero;

    selected[0] = one;        //starting vertex is always node-0

    while(ne < p->nodes - 1) {
        min = infi;

        for(i = 0; i < p->nodes; i++) {
            if(selected[i] == one) {
                for(j = 0; j < p->nodes; j++) {
                    if(selected[j] == zero) {
                        if(min > p->graph[i][j]) {
                            min = p->graph[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        selected[y] = one;
        printf("\n %d --> %d",x,y);
        cost += p->graph[x][y];
        ne++;
    }
    printf("\nTotal cost is: %d\n",cost);
}

int main() {
	prims *p = (prims*)malloc(sizeof(prims));

    printf("\nPrims Algorithm to connect several offices\n");
    createGraph(p);
    primsAlgo(p);
}
