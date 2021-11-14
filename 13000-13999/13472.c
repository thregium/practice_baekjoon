#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 20000)���� ����(<= 2^60, ����)�� �־��� ��, 3���� ������ �̾� ���̰� 0�� �ƴ� �ﰢ���� ���� �� �ִ��� ���Ѵ�. 

�ذ� ��� : �� ������ ���̸� ������ ����, ������ 3������ ������ ���Ǹ� �ﰢ���� ���� �� �ִ��� Ȯ���ϸ� �ȴ�.
�ﰢ���� ���� �� �ִ� ���� ª�� �� ���� ������ ���� �� ���� ���̺��� ū ����̴�. ���� ���̸� �ִ��� ���̱� ����
������ �ϰ� ������ �� ���� ���ϸ� �Ǵ� ���̴�.

�ֿ� �˰��� : �׸��� �˰���, ������, ����

��ó : BAPC 2016 L��
*/

long long tri[20480];

int cmp1(const void* a, const void* b) {
    long long ai = *(long long*)a;
    long long bi = *(long long*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &tri[i]);
    }
    qsort(tri, n, sizeof(long long), cmp1);
    for (int i = 2; i < n; i++) {
        if (tri[i - 2] + tri[i - 1] > tri[i]) r = 1;
    }
    printf("%s", r ? "possible" : "impossible");
    return 0;
}