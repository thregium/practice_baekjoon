#include <stdio.h>

/*
���� : N(N <= 1000)���� ���� ���� 1 �̻� N ������ ���� �̷���� ������ �־�����. �̶�, ������ ���� ��� ���� ��,
������ ���� ������ ���� ���� �� ��� ���� ���� ���� ���Ѵ�.

�ذ� ��� : �� ������ ���� �� �ִ� ���� ������ �̹� �湮�� ���� ���� �� ���� �� ���� �׷��� ���� ���� ū ���� ã���� �ȴ�.

�ֿ� �˰����� : �׷��� �̷�, ���Ʈ ����

��ó : CHCI 2005RJ 2��
*/

int a[1024], vis[1024];

int main(void) {
    int n, r = 0, rn = -1, t;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
        t = 0;
        for (int j = i; !vis[j]; j = a[j]) vis[j] = 1;
        for (int j = 1; j <= n; j++) {
            t += vis[j];
            vis[j] = 0;
        }
        if (t > r) {
            r = t;
            rn = i;
        }
    }
    if (rn < 0) return 1;
    printf("%d", rn);
    return 0;
}