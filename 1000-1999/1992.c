#include <stdio.h>
#include <malloc.h>

/*
���� : �׸��� ���°� �־����� �̸� ����Ʈ�� ���·� ������ ����Ѵ�.

�ذ� ��� : ����Ʈ���� ������ ���� Ʈ���� ��ȸ�ϸ� ���� ����� ��� ���ڸ� ����ϰ�, ���� ��尡 �ƴ� ��� ��ȣ �ȿ��� �ڽ� ��带 ȣ���Ѵ�.

�ֿ� �˰��� : �ڷᱸ��, ���� ����, Ʈ��
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