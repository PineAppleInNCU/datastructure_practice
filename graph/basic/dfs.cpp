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

void finding_cycles_undirected() {
  // TODO !
}

void print_graph(graph *g) {
  int i;
  edgenode *p;

  for(i = 0;i < g->nvertices;i++) {
    printf("%d : ", i);
    p = g->edges[i];
    while(p != NULL) {
      printf(" %d", p->y);
      p = p->next;
    }
    printf("\n");
  }
}

enum TEST{
  FALSE,
  TRUE
};

bool processed[MAXV + 1];
bool discovered[MAXV + 1];
int entry_time[MAXV + 1];
int exit_time[MAXV + 1];
int parent[MAXV + 1];
int now_time;
int finished = FALSE;

void initialize_search(graph *g) {
  int i;

  for(i = 0;i <= g->nvertices;i++) {
    processed[i] = discovered[i] = FALSE;
    parent[i] = -1;
    entry_time[i] = -1;
    exit_time[i] = -1;
  }

  now_time = 0;

}

void process_vertex_late(int v) {
  printf("[process late] processed vertex %d\n", v);
}

void process_vertex_early(int v) {
  printf("[process early] processed vertex %d\n", v);
}

void process_edge(int x, int y) {
  printf("[process] processed edge (%d %d)\n", x, y);
}


void dfs(graph *g, int v) {
  edgenode *p;
  int y;

  if (finished) return;

  discovered[v] = TRUE;
  now_time = now_time + 1;
  entry_time[v] = now_time; 

  process_vertex_early(v);

  p = g->edges[v];
  while( p != NULL) {
    y = p->y;
    if(discovered[y] == FALSE) {
      parent[y] = v;
      process_edge(v, y);
      dfs(g, y);
    } else if((!processed[y]) || (g->directed)) {
      process_edge(v, y);
    }

    if (finished) return;
    p = p->next;
  }

  process_vertex_late(v);

  now_time = now_time + 1;
  exit_time[v] = now_time;
  
  processed[v] = TRUE;

}


void find_path(int start, int end, int parents[]) {


  if((start == end) || (end == -1)) {
    if(end == -1) {
      printf("\ncannot find start value\n");
    } else {
      printf("\n%d", start);
    }
  } else {
    find_path(start, parents[end], parents);
    printf(" %d", end);
  }
}

int main() {
  
  graph* g = (graph *)malloc(sizeof(graph));
  read_graph(g, false);   
  print_graph(g);


  printf("start to DFS\n");
  initialize_search(g);

  dfs(g, 0);

  //find_path(-1, 2, parent); 

  return 0;
}




