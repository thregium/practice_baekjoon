#include <stdio.h>
#include <malloc.h>

/*
���� : ������ �༱�� ��ϰ� ������ ����, ���ϴ� ������� �������� ���� �� ��������� ���������� ������ ���� �� �� �ִ� �ּ����� ����� ���Ѵ�.

�ذ� ��� : ���ͽ�Ʈ�� �˰����� ���� �ִܰŸ��� Ȯ���Ѵ�. ����, ������� ����� ���õ������ �Ÿ��� Ȯ���ϰ�, ������� ���� ���� �Ÿ��� (��ǻ�) ���Ѵ�� �����Ѵ�.
���ķδ� ������� Ȯ�ε� �Ÿ��� ��� ���� ����� ���� �������� ����� ���õ������ �Ÿ��� Ȯ���ϴ� ���� �ݺ��Ѵ�.
��� ���õ��� �Ÿ��� Ȯ���ϸ� ������� ������ ������ �Ÿ��� Ȯ���ϰ� ����Ѵ�.

�ֿ� �˰��� : �׷���, ���ͽ�Ʈ��
*/

typedef struct link {
     int v;
     int w;
     struct link* l;
} link;
link* links[25600];
int best[25600];
int chk[25600];

int main(void) {
     int n, m, u, v, w, k, l, s, o;
     //n : ������ ����, m : ������ ����
     //u : �����, v : ������, w : ���
     //k : ������, l : ������
     //s : ���� Ž�� ���� ���, o : ���� s�� ã�� ���� �ӽ� ����
     scanf("%d %d", &n, &m);
     for (int i = 0; i < m; i++) {
          scanf("%d %d %d", &u, &v, &w);
          link* l;
          l = malloc(sizeof(link));
          l->v = v;
          l->w = w;
          l->l = links[u];
          links[u] = l;
     }
     for (int i = 0; i <= n; i++) best[i] = 999999999;
     scanf("%d %d", &k, &l);
     best[k] = 0;
     s = k;
     chk[k] = 1;
     for (int c = 0; c < n; c++) {
          for (link* i = links[s]; i; i = i->l) {
               if (best[s] + i->w < best[i->v]) best[i->v] = best[s] + i->w;
          }
          o = 0;
          for (int i = 1; i <= n; i++) {
               if (!chk[i] && best[i] < best[o]) {
                    o = i;
               }
          }
          //if (c == 0) break;
          chk[o] = 1;
          s = o;
     }
     printf("%d\n", best[l]);
     return 0;
}