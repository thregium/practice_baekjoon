#include <stdio.h>

/*
���� : N(N <= 100)���� �ٱ��Ͽ� �ٱ��� ��ȣ�� ���� ��ȣ�� ���� ����ִ�. M(M <= 100)ȸ�� ���� ������ ������ �� �� �ٱ��Ͽ� ����ִ� ���� ��ȣ�� ���Ѵ�.
a�� �ٱ��Ͽ� b�� �ٱ����� ���� ������ a�� �ٱ��Ͽ� �ִ� ���� b����, b�� �ٱ��Ͽ� �ִ� ���� a���� �ִ´�.

�ذ� ��� : ������ ���δ�� �����Ѵ�.

�ֿ� �˰��� : ����, �ùķ��̼�
*/

int balls[128];

int main(void) {
    int n, m, a, b, t;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        balls[i] = i;
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        t = balls[a];
        balls[a] = balls[b];
        balls[b] = t;
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", balls[i]);
    }
    return 0;
}