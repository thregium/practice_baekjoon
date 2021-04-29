#include <stdio.h>

/*
���� : ���� ��ǻ���� ��Ʈ��ũ�� �Է¹޾��� �� 1�� ��ǻ�Ͱ� ���̷����� �ɸ��� ����� ��Ʈ��ũ�� ���� ���� ���̷����� �ɸ��� ��ǻ���� ���� ����Ѵ�.

�ذ� ��� : ��Ʈ��ũ�� ���� �Է¹��� �� 1�� ��ǻ�ͺ��� �����ؼ� ��ǻ�͵� ���̿� ��Ʈ��ũ�� �����ϴ� ��� �� ��ǻ�ͷ� �� �� ������ 1 �ø���.
�̹� �湮�� ��ǻ�ʹ� �ٽ� �湮���� �ʴ´�. �湮�� ������ ������ ����Ѵ�.

�ֿ� �˰����� : �׷���, ���� �켱 Ž��
*/

int link[128][128] = { 0, };
int visited[128] = { 0, };
int v = 0;

void virus(int n, int a) {
     if (visited[a]) return;
     visited[a] = 1;
     v++;
     for (int i = 1; i <= n; i++) {
          if (link[a][i]) virus(n, i);
     }
}

int main(void) {
     int n, l, a, b;
     scanf("%d%d", &n, &l);
     for (int i = 0; i < l; i++) {
          scanf("%d %d", &a, &b);
          link[a][b] = 1;
          link[b][a] = 1;
     }
     virus(n, 1);
     printf("%d", v - 1);
     return 0;
}