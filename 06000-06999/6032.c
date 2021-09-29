#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 25000)���� �峭���� �ູ���� ������ �־��� ��, ���� ��� �ູ���� ���� ���� �峭�� 3���� ����� �Ѵ�.
�̶�, �ʿ��� ����, ��� �� �峭���� ��ȣ�� (��/�� �� ������) ����Ѵ�.

�ذ� ��� : �峭������ �ູ���� ������ �Է¹��� ����, �峭���� ��ȣ�� ���� �����ϰ� ���� / �ູ�� ������ �����Ѵ�.
�̶�, �Ǽ� ������ ���̱� ���� �� ���� ����� ����, ������ ���� ���ϴ� ���� ����.
������ �������� ���� 3���� ���� ���� ����� ����, ���� 3���� ��ȣ�� ���ʷ� ����Ѵ�.

�ֿ� �˰��� : �׸��� �˰���, ����

��ó : USACO 2010F B3��
*/

long long toys[25600][3];

int cmp1(const void* a, const void* b) {
    long long ax = *(long long*)a;
    long long bx = *(long long*)b;
    long long ay = *((long long*)a + 1);
    long long by = *((long long*)b + 1);
    if (bx * ay - ax * by < 0) return -1;
    else if (bx * ay - ax * by == 0) return 0;
    else return 1;
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld %lld", &toys[i][0], &toys[i][1]);
        if (toys[i][0] == 0 && toys[i][1] == 0) return 1;
        toys[i][2] = i + 1;
    }
    qsort(toys, n, sizeof(long long) * 3, cmp1);
    printf("%lld\n%lld\n%lld\n%lld", toys[0][1] + toys[1][1] + toys[2][1], toys[0][2], toys[1][2], toys[2][2]);
    return 0;
}