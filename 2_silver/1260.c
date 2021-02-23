#include <stdio.h>
#include <malloc.h>
#define MAXV 1024
#define MAXQ 65536

int visited[MAXV] = { 0, };

typedef struct {
     int queue[MAXQ];
     int front, rear;
} queue;

typedef struct vertex {
     int num;
     struct vertex* link;
} vertex;

typedef struct graph {
     int v;
     vertex* adj[MAXV];
} graph;

void newqueue(queue* q) {
     q->front = 0;
     q->rear = 0;
}

int qempty(queue* q) {
     return(q->front == q->rear);
}

int qfull(queue* q) {
     return ((q->rear + 1) % MAXQ == q->front);
}

void enqueue(queue* q, int e) {
     if (qfull(q)); //큐 포화 에러
     q->rear = (q->rear + 1) % MAXQ;
     q->queue[q->rear] = e;
}

int dequeue(queue* q) {
     if (qempty); //큐 공백 에러
     q->front = (q->front + 1) % MAXQ;
     return q->queue[q->front];
}

void newgraph(graph* g) {
     g->v = 0;
     for (int i = 0; i < MAXV; i++) g->adj[i] = NULL;
}

void newvertex(graph* g, int v) {
     if (g->v + 1 > MAXV) {
          //정점 갯수 초과
          return;
     }
     g->v++;
}

//u->v 삽입
void newlink(graph* g, int u, int v) {
     if (u > g->v || v > g->v) {
          //정점 번호 초과
          return;
     }
     vertex* n;
     vertex* t;
     n = (vertex*)malloc(sizeof(vertex));
     t = NULL;
     n->num = v;
     n->link = g->adj[u];
     for (vertex* i = g->adj[u]; i != NULL && n->num > i->num;) {
          t = i;
          i = i->link;
          n->link = i;
     }
     if (g->adj[u] == NULL || t == NULL) g->adj[u] = n;
     else t->link = n;
}

void DFS(graph* g, int v) {
     vertex* w;
     visited[v] = 1;
     printf("%d ", v);
     for (w = g->adj[v]; w; w = w->link) {
          if (!visited[w->num]) DFS(g, w->num);
     }
}

void BFS(graph* g, int v) {
     vertex* w;
     queue q;
     newqueue(&q);
     visited[v] = 1;
     printf("%d ", v);
     enqueue(&q, v); //큐에 저장
     while (!qempty(&q)) {
          v = dequeue(&q);
          for (w = g->adj[v]; w; w = w->link) {
               if (!visited[w->num]) {
                    visited[w->num] = 1;
                    printf("%d ", w->num);
                    enqueue(&q, w->num);
               }
          }
     }
}

int main(void) {
     int n, m, v, u1, v1;
     scanf("%d %d %d", &n, &m, &v);
     graph* g;
     g = (graph*)malloc(sizeof(graph));
     newgraph(g);
     for (int i = 1; i <= n; i++) newvertex(g, i);
     for (int i = 0; i < m; i++) {
          scanf("%d %d", &u1, &v1);
          newlink(g, u1, v1);
          newlink(g, v1, u1);
     }
     //printf("%d", v);
     DFS(g, v);
     printf("\n");
     for (int i = 0; i < MAXV; i++) visited[i] = 0;
     BFS(g, v);
     return 0;
}