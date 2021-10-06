#include <stdio.h>
#include <stdlib.h>
#define INF 1012345678

/*
���� : N(N <= 100000)���� ���� �ο� ���� �־�����. �̶�, L(L <= 100000)���� ���� �ڱ��ο��� �� �� �ִٸ�
���� �� �ִ� H-index�� �ִ��� ���Ѵ�.

�ذ� ��� : ����, �� ���� �ο� ���� ������������ �����Ѵ�. �� ����, �� ���� H-index�� �Ű� ���� Ž���� ����
ã���� �ȴ�. ��ǥ�� �ϴ� H-index�� Ȯ���ϰ�, H���� �� ��� ��ǥġ�� ���ڶ� ���� 1ȸ�� �ڰ��ο��Ͽ�
��ǥġ�� �޼��� �� �ִ���, �����ϴٸ� Lȸ �̳��� �ο��Ͽ����� Ȯ���ϰ�, �� ���� ��쿡�� ������ ���̰�
�ƴ϶�� ������ ���簡�� ���� ã�ư��� �ȴ�.

�ֿ� �˰��� : �Ķ��Ʈ��, ����

��ó : USACO 2021O B1��
*/

int cit[103000];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

long long hdx(int n, int h) {
    long long r = 0;
    for (int i = 0; i < h; i++) {
        if (cit[i] < h - 1) return INF;
        else if (cit[i] < h) r++;
    }
    return r;
}

int main(void) {
    int n, l, lo, hi;
    scanf("%d %d", &n, &l);
    for (int i = 0; i < n; i++) {
        scanf("%d", &cit[i]);
    }
    qsort(cit, n, sizeof(int), cmp1);
    lo = 0, hi = n;
    while (lo < hi) {
        if (hdx(n, (lo + hi + 1) >> 1) <= l) lo = ((lo + hi + 1) >> 1);
        else hi = ((lo + hi + 1) >> 1) - 1;
    }
    printf("%d", lo);
    return 0;
}