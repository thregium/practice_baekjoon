#include <stdio.h>

/*
���� : N���� M(N, M <= 10^6)������ ���� �ִ� 0�� ������ ����.

�ذ� ��� : ���̿� �ִ� ��� ���� ���� 0�� ������ ���� ���ָ� �ȴ�.

�ֿ� �˰��� : ���Ʈ ����, ����

��ó : IDI 2014 C��
*/

int getzeros(int x) {
    int r = 0;
    if (!x) return 1;
    while (x) {
        if (x % 10 == 0) r++;
        x /= 10;
    }
    return r;
}

int main(void) {
    int t, n, m, cnt;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d", &n, &m);
        cnt = 0;
        for (int i = n; i <= m; i++) {
            cnt += getzeros(i);
        }
        printf("%d\n", cnt);
    }
    return 0;
}