#include <stdio.h>

/*
���� : X * Y(X, Y <= 10^6) ũ���� �׵θ� ĭ�� �ִ� ���ڸ� 1 * A(A <= 10^6) ũ�� Ÿ�Ϸ�
��ġ�� �ʰ� ���� ä��� ���� ������ �� ���Ѵ�. �̸� N(N <= 1000)�� �ݺ��Ѵ�.

�ذ� ��� : �׵θ��� ������ ��� ��ġ�� �ϳ��� ������ �� �õ��� ���鼭 �ϳ��� �����ϸ� YES��,
���� �Ұ����ϴٸ� NO�� ����Ѵ�. �� ���� �ڵ带 �����Ѵ�.

�ֿ� �˰����� : ����, ������, ���̽� ��ũ

��ó : SEERC 2014 D��
*/

int main(void) {
    int x, y, n, a;
    scanf("%d %d", &x, &y);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        if (((x - 2) % a == 0 && y % a == 0) || ((x - 1) % a == 0 && (y - 1) % a == 0) ||
            (x % a == 0 && (y - 2) % a == 0) || ((x - 2) % a == 0 && (y - 1) % a == 0 && x % a == 0) ||
            ((x - 1) % a == 0 && (y - 2) % a == 0 && y % a == 0)) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}