#include <stdio.h>
#include <stdlib.h>

/*
���� : L(L <= 1000)���� ���ڿ� K(K <= 1000)���� Ű�� �ִ�. �� Ű���� �ִ� P(P <= 1000, K * P >= L)����
���ڸ� �Ҵ��� �� ���� ��, �� ���ڸ� ����� Ƚ��(<= 10^6)�� �־����� ���ڸ� Ű�� ������ �������
�Ҵ����� �� ������ ������ Ƚ���� �ּڰ��� ���Ѵ�.

�ذ� ��� : ���� ����ϴ� ���ں��� �� Ű�� ���ʿ� �־���� �ȴ�. K * P�� L �̻��̹Ƿ�
�� ������� ��� ���ڸ� �Ҵ��� �� �ְ�, �� ����� ������ ����� �ȴ�.

�ֿ� �˰��� : �׸��� �˰���, ����

��ó : GCJ 2008C A2��
*/

int freq[1024];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int t, p, k, l;
    long long res;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d %d %d", &p, &k, &l);
        res = 0;
        for (int i = 0; i < l; i++) {
            scanf("%d", &freq[i]);
        }
        qsort(freq, l, sizeof(int), cmp1);
        for (int i = 0; i < l; i++) {
            res += (i / k + 1) * freq[i];
        }
        printf("Case #%d: %lld\n", tt, res);
    }
    return 0;
}