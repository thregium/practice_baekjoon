#include <stdio.h>
#include <stdlib.h>

/*
���� : K(K <= 100000)���� �ʺ� L(L <= 100)cm�� ���ڰ� �ִ�. �� ���ڸ� �� �ٿ� �ִ� 2���� ������ N * M(N, M <= 10000)m
ũ���� ���� ���ڸ� �ڸ��� �ʰ� ä��� ����� �ִ��� Ȯ���ϰ� �ִٸ� ���ڸ� ���� ���� ����� �� ����ϴ� ������ ���� ���Ѵ�.

�ذ� ��� : ����, ������ �ʺ� ���� �������� ������ �� ���� �ʺ�� ������ ���������� Ȯ���Ѵ�. �Ұ����ϴٸ�
���ķδ� Ȯ���� �͵� ���� ä�� �� ����. �����ϴٸ� ���ڵ��� ���� ������ ������ ��, ���̰� ���� ���̿� ���� ������ ���� ����.
�� ���ڵ�� ���� ä�� �� �ִٸ� �ݴ� ������ ���캸�� ���ٸ� �� �����͸� �̿��� ���� 2���� ���� ����ϴ� ����� ������.
�� ���� ������� ä�� �� �ִ��� Ȯ���ϰ� �ִٸ� �� ���� ������ ���� Ȯ���� �� �ݴ� ������ ���캸��, ���ٸ� ä�� �� ����.
�ݴ� ���⵵ ���������� �� ���� ä�� �� �ִ� ���� ��� �� ���� ����ϴ� ���� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����, �� ������

��ó : Brasil 2008 C��
*/

int a[103000];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, m, l, k, r1, r2, cnt, lo, hi;
    //freopen("E:\\PS\\ICPC\\Latin America\\Brasil\\2008\\C.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\Latin America\\Brasil\\2008\\C.out", "w", stdout);
    while (1) {
        scanf("%d %d", &n, &m);
        if (n == 0) break;
        scanf("%d%d", &l, &k);
        for (int i = 0; i < k; i++) {
            scanf("%d", &a[i]);
        }
        qsort(a, k, sizeof(int), cmp1);
        r1 = 0, r2 = 0;
        if ((n * 100) % l == 0) {
            cnt = 0;
            lo = 0, hi = k - 1;
            while (a[hi] > m && hi >= 0) hi--;
            while (a[hi] == m && hi >= 0 && cnt * l < (n * 100)) {
                hi--;
                cnt++, r1++;
            }
            while (lo < hi && cnt * l < (n * 100)) {
                if (a[lo] + a[hi] == m) {
                    lo++, hi--;
                    cnt++, r1 += 2;
                }
                else if (a[lo] + a[hi] < m) lo++;
                else hi--;
            }
            if (cnt < (n * 100) / l) r1 = -1;
        }
        else r1 = -1;
        if ((m * 100) % l == 0) {
            cnt = 0;
            lo = 0, hi = k - 1;
            while (a[hi] > n && hi >= 0) hi--;
            while (a[hi] == n && hi >= 0 && cnt * l < (m * 100)) {
                hi--;
                cnt++, r2++;
            }
            while (lo < hi && cnt * l < (m * 100)) {
                if (a[lo] + a[hi] == n) {
                    lo++, hi--;
                    cnt++, r2 += 2;
                }
                else if (a[lo] + a[hi] < n) lo++;
                else hi--;
            }
            if (cnt < (m * 100) / l) r2 = -1;
        }
        else r2 = -1;

        if (r1 < 0 && r2 < 0) printf("impossivel\n");
        else if (r1 < 0) printf("%d\n", r2);
        else if (r2 < 0) printf("%d\n", r1);
        else if (r1 < r2) printf("%d\n", r1);
        else printf("%d\n", r2);
    }
    return 0;
}