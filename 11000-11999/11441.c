#include <stdio.h>

/*
���� : ���� N(N <= 100000)�� ������ ���� ��, M(M <= 100000)���� [st, ed]�� ���� ���� ������ �����Ѵ�.

�ذ� ��� : ���� ���� �̸� ���� ����, ed������ ���� �տ��� st������ ���� ���� �� ���� �Ź� ����ϸ� �ȴ�.

�ֿ� �˰��� : ���� ��
*/

int a[103000], s[103000];

int main(void) {
    int n, m, st, ed;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        s[i] = s[i - 1] + a[i];
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &st, &ed);
        printf("%d\n", s[ed] - s[st - 1]);
    }
    return 0;
}