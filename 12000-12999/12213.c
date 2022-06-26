#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 500)���� 2^a_i ũ���� Ÿ��(a_i <= 30)�� M * M(max(2^a_i) <= M < 2^31) ũ����
Ÿ���� �߶� ����� ���� �ʿ��� M * M ũ�� Ÿ���� ������ ���Ѵ�.

�ذ� ��� : ���� ū Ÿ�Ϻ��� ���ʷ� �߶� ������ �����Ѵ�. Ÿ���� ���� ��� �� ���� �켱
���� ���� ������ ���簢������ �ڸ���, ���� ���� �ִ� ���簢������ ū ���簢������
���� ���� �ִ� ũ��� �߶��ش�. �̸� �ݺ��ϸ� ���� ũ���� Ÿ���� ������ ���� �����
��� Ƚ���� �ּҰ� �ǵ��� �� �� �ְ�, �� Ƚ���� ���ϸ� �ȴ�.

�ֿ� �˰��� : �׸��� �˰���

��ó : GKS 2014A C2��
*/

int a[512];
long long cnt[32];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int t, n, m, r;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        qsort(a, n, sizeof(int), cmp1);
        r = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 30; j > a[i]; j--) {
                cnt[j - 1] += cnt[j] * 4;
                cnt[j] = 0;
            }
            if (cnt[a[i]] == 0) {
                for (int j = 30; j >= 0; j--) {
                    if ((m >> j) & 1) cnt[j] += ((long long)m >> j) + (m >> j) - 1;
                }
                r++;
                for (int j = 30; j > a[i]; j--) {
                    cnt[j - 1] += cnt[j] * 4;
                    cnt[j] = 0;
                }
            }
            cnt[a[i]]--;
        }
        printf("Case #%d: %d\n", tt, r);
        for (int i = 0; i < 32; i++) cnt[i] = 0;
    }
    return 0;
}