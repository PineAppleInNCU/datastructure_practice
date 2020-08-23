// reference : the algorithm design manual 2nd
// adjacency list
//   basic operation, bfs, dfs

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define MAXV 1000
//#define UNDISCOVERED 0
//#define DISCOVERED 1
//#define PROCESSED 2

using namespace std;

typedef struct edgenode{
  int y;
  int weight;
  struct edgenode *next;
} edgenode;

typedef struct graph{
  edgenode *edges[MAXV+1];
  int degree[MAXV+1];
  int nvertices;
  int nedges;
  bool directed;
} graph;

void initialize_graph(graph *g, bool directed) {
  int i;
  
  g->nvertices = 0;
  g->nedges = 0;
  g->directed = directed;
  
  for (i = 1;i <= MAXV;i++) {
    g->degree[i] = 0;
    g->edges[i]  = NULL;
  }
}

void insert_edge(graph *g, int x, int y, bool directed) {
  edgenode *p;
  
  p = (edgenode *)malloc(sizeof(edgenode));
  p->weight = 0;
  p->y = y;
  p->next = g->edges[x];

  g->edges[x] = p;
  g->degree[x]++;

  if(directed) {
    g->nedges++;
  } else {
    insert_edge(g, y, x, true);
  }
}

void read_graph(graph *g, bool directed) {
  int i;
  int m;
  int x, y;

  initialize_graph(g, directed);
  
  scanf("%d %d", &(g->nvertices), &m);
  
  for(i = 1;i <= m;i++){
    scanf("%d %d", &x, &y);
    insert_edge(g, x, y, directed);
  }

}

void print_graph(graph *g) {
  int i;
  edgenode *p;

  for(i = 1;i < g->nvertices;i++) {
    printf("%d : ", i);
    p = g->edges[i];
    while(p != NULL) {
      printf(" %d", p->y);
      p = p->next;
    }
    printf("\n");
  }
}

bool processed[MAXV + 1];
bool discovered[MAXV + 1];
int parent[MAXV + 1];



int main() {
  
  graph* g = (graph *)malloc(sizeof(graph));
  read_graph(g, false);   
  print_graph(g);





  return 0;
}




