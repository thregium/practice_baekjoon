#include <stdio.h>
#define INF 1012345678

/*
���� : N(N <= 100000)���� ���а� M(M <= 100000)���� ���� �־�����. ��� ��ǥ�� 10^9 ������ �ڿ����̴�.
�� ������ �������� ����, �־��� ������ ��� �ٸ���.
�̶�, �� ������ �߰��� ������ ����� ������ �� Ȧ�� ��°�� ������ ����ٸ�
���� ���� ������ ���� ���Ѵ�.

�ذ� ��� : �� ������ ������ ����, �� ���и��� �ش� ������ ���ԵǴ� ������ �������� ������ ���Ѵ�.
�� ���� ���� ���� ���� �ش� ������ ���� ���� ���̸� ���Ѵ�. ���� ���� Ȧ���� ¦���� ��츦
���ε��� ���صд�. �������� ���⿡ ���� ��츦 �ٸ��� ������� �Կ� �����Ѵ�.
���������� �������� ���⿡ ���� ���� ���� ���̸� ���س����� �� ���п� ���� ���� ������ ���̸�
������ ���� �� �ְ�, �̸� �ݺ��Ͽ� ���� ���� ������ ���� ���� �� �ִ�.

�ֿ� �˰��� : �̺� Ž��, ���� ��

��ó : JAG 2011D4 H��
*/

int line[103000][2], cut[103000], osum[103000], esum[103000];

int small(int a, int b) {
    return a < b ? a : b;
}

int big(int a, int b) {
    return a > b ? a : b;
}

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, m, lo, hi, mid, lt, rt;
    long long res = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &line[i][0], &line[i][1]);
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d", &cut[i]);
    }
    cut[m + 1] = INF;
    qsort(cut + 1, m, sizeof(int), cmp1);
    for (int i = 1; i <= m + 1; i++) {
        osum[i] = osum[i - 1];
        esum[i] = esum[i - 1];
        if (i & 1) osum[i] += cut[i] - cut[i - 1];
        else esum[i] += cut[i] - cut[i - 1];
    }
    osum[m + 1] = INF;
    esum[m + 1] = INF;
    for (int i = 0; i < n; i++) {
        lo = 0, hi = m + 1;
        while (lo < hi) {
            mid = (lo + hi) >> 1;
            if (cut[mid] >= small(line[i][0], line[i][1])) hi = mid;
            else lo = mid + 1;
        }
        lt = lo;
        lo = 0, hi = m + 1;
        while (lo < hi) {
            mid = (lo + hi + 1) >> 1;
            if (cut[mid] <= big(line[i][0], line[i][1])) lo = mid;
            else hi = mid - 1;
        }
        rt = hi;
        if (lt > rt) {
            res += big(line[i][0], line[i][1]) - small(line[i][0], line[i][1]);
            continue;
        }
        if (line[i][0] == line[i][1]) return 1;
        else if (line[i][0] < line[i][1]) {
            res += cut[lt] - line[i][0];
            if (lt & 1) res += osum[rt] - osum[lt];
            else res += esum[rt] - esum[lt];
            if ((rt - lt) & 1) res += line[i][1] - cut[rt];
        }
        else {
            res += line[i][0] - cut[rt];
            if (rt & 1) res += esum[rt] - esum[lt];
            else res += osum[rt] - osum[lt];
            if ((rt - lt) & 1) res += cut[lt] - line[i][1];
        }
    }
    printf("%lld\n", res);
    return 0;
}