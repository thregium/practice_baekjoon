#include <stdio.h>
#include <stdlib.h>
#define INF 1012345678

/*
���� : N(N <= 100000, N�� ¦��)���� �ڿ���(<= 10^6)�� �־��� ��, �� �ڿ����� ¦��� ¦�� ���� ���� ���� ¦��
���� ũ���� �Ѵٸ� �� ¦�� ���� ���Ѵ�.

�ذ� ��� : ���� ū ���� ���� ���� ��, �������� ū ���� �������� ���� �� ... �̷� ������ ��ġ�� ���� �����̴�.
����, �̸� ���� ������ �ϰ� ���ʿ������� Ȯ���� ������ ���� ���� ���� ���ϸ� �ȴ�.

�ֿ� �˰��� : �׸��� �˰���, ����

��ó : PacNW 2015 E/Q�� // SEUSA 2015D2 D��
*/

int s[103000];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, r = INF;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &s[i]);
    }
    qsort(s, n, sizeof(int), cmp1);
    for (int i = 0; i < (n >> 1); i++) {
        if (s[i] + s[n - i - 1] < r) r = s[i] + s[n - i - 1];
    }
    printf("%d", r);
    return 0;
}