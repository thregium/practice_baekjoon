#include <stdio.h>

/*
���� : N(N <= 1000)���� ���� �뷮��, Ŭ�������� ũ�Ⱑ �־��� ��, ��ũ���� �����ϴ� �뷮�� ���Ѵ�.

�ذ� ��� : ���� �뷮�� Ŭ�������� ũ��� ���� ���� �ø��� ���� Ŭ�������� ũ�⸦ ���� ���� ���� ���ϸ� �ȴ�.

�ֿ� �˰��� : ����, ��Ģ����
*/

int space[1024];

int main(void) {
    int n, m;
    long long r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &space[i]);
    }
    scanf("%d", &m);
    for (int i = 0; i < n; i++) {
        r += (space[i] + (m - 1)) / m * m;
    }
    printf("%lld", r);
    return 0;
}