#include <stdio.h>

/*
���� : N���� ĭ�� S�� ����, K(N, S, K <= 1000)���� �����͸� �̿��Ͽ� �������
������׷��� ����Ѵ�.

�ذ� ��� : �� ĭ�� ���� Ƚ���� �� ���� �� ĭ�� ���̸� ���߾� ����Ѵ�.

�ֿ� �˰��� : ����

��ó : BAPC 2021P H��
*/

int cnt[1024];

int main(void) {
    int n, s, k, x, h = 0;
    scanf("%d %d %d", &n, &s, &k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &x);
        cnt[(x + s - 1) / s]++;
    }
    for (int i = 1; i <= n; i++) {
        if (cnt[i] > h) h = cnt[i];
    }
    for (int i = h; i >= 1; i--) {
        for (int j = 1; j <= n; j++) {
            if (cnt[j] >= i) printf("#");
            else printf(".");
        }
        printf("\n");
    }
    for (int i = 1; i <= n; i++) printf("-");
    return 0;
}