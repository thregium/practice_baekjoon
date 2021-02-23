#include <stdio.h>
#include <malloc.h>

/*
���� : ���̿� 3���� ���ڰ� �����ְ�, ���̸� ��� 9��� �ؼ� ���� ���ڸ� �����ִ� ���̸� ���� �� ���� ���� ������ ������ ���Ѵ�.

�ذ� ��� : ������ ���ڰ� ���� ���� ��� Ž���� �����ϰ� ���� �ٸ� ��� 9����Ͽ� ���� ���̵� ������ Ž���Ѵ�. Ž���� ���� ����Ǹ� ������ ������ ����Ѵ�.

�ֿ� �˰��� : ���� ����
*/

char v[3072][3072];
int count[3];

void maketree(int size, int posx, int posy) {
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
          count[t + 1]++;
          return;
     }
     else {
          maketree(size / 3, posx, posy);
          maketree(size / 3, posx, posy + size / 3);
          maketree(size / 3, posx, posy + size / 3 * 2);
          maketree(size / 3, posx + size / 3, posy);
          maketree(size / 3, posx + size / 3, posy + size / 3);
          maketree(size / 3, posx + size / 3, posy + size / 3 * 2);
          maketree(size / 3, posx + size / 3 * 2, posy);
          maketree(size / 3, posx + size / 3 * 2, posy + size / 3);
          maketree(size / 3, posx + size / 3 * 2, posy + size / 3 * 2);
     }
}

int main(void) {
     int n;
     scanf("%d", &n);
     for (int i = 0; i < n; i++) {
          for (int j = 0; j < n; j++) {
               scanf("%d", &v[i][j]);
          }
     }
     maketree(n, 0, 0);
     for (int i = 0; i < 3; i++) {
          printf("%d\n", count[i]);
     }
     return 0;
}