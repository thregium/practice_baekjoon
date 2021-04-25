#include <stdio.h>
#include <malloc.h>

/*
문제 : 그림의 형태가 주어지면 이를 쿼드트리 형태로 압축해 출력한다.

해결 방법 : 쿼드트리를 구현한 다음 트리를 순회하며 리프 노드인 경우 숫자를 출력하고, 리프 노드가 아닌 경우 괄호 안에서 자식 노드를 호출한다.

주요 알고리즘 : 자료구조, 분할 정복, 트리
*/

char v[128][128];

typedef struct qtree {
     int num;
     struct qtree* lu;
     struct qtree* ru;
     struct qtree* ld;
     struct qtree* rd;
} qtree;

void maketree(qtree* root, int size, int posx, int posy) {
     int r = 1;
     int t = v[posx][posy];
     for (int i = posx; i < posx + size; i++) {
          for (int j = posy; j < posy + size; j++) {
               if (v[i][j] != t) {
                    r = 0;
                    break;
               }
          }
          if (r == 0) break;
     }

     if (r) {
          root->num = t - 48;
          return;
     }
     else {
          root->num = -1;
          qtree* lu, *ru, *ld, *rd;
          lu = calloc(1, sizeof(qtree));
          ru = calloc(1, sizeof(qtree));
          ld = calloc(1, sizeof(qtree));
          rd = calloc(1, sizeof(qtree));
          root->lu = lu;
          root->ru = ru;
          root->ld = ld;
          root->rd = rd;
          maketree(lu, size / 2, posx, posy);
          maketree(ru, size / 2, posx, posy + size / 2);
          maketree(ld, size / 2, posx + size / 2, posy);
          maketree(rd, size / 2, posx + size / 2, posy + size / 2);
     }
}

void printtree(qtree* root) {
     if (root->num < 0) {
          printf("(");
          printtree(root->lu);
          printtree(root->ru);
          printtree(root->ld);
          printtree(root->rd);
          printf(")");
     }
     else printf("%d", root->num);
}

int main(void) {
     int n;
     qtree* root;
     root = calloc(1, sizeof(qtree));
     scanf("%d", &n);
     for (int i = 0; i < n; i++) {
          scanf("%s", v[i]);
     }
     maketree(root, n, 0, 0);
     printtree(root);
     return 0;
}