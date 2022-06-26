#include <stdio.h>
#include <stdlib.h>

/*
���� : K(K <= 10^9)���� �� ä���� ���� ����(0 ~ K, �ڿ���) ��� �� �� ä���� ���� ���� ���̰�
V(V <= 1000) ���ϰ� �Ǵ� ����� ���� ���Ѵ�.

�ذ� ��� : �� V�� ���ӵ� ���󸶴� �� ��� �ϳ��� ���� �۾��� �Ͽ� �� ���� ���ϰ�,
�ٽ� V - 1�� ���ӵ� ����(�� �� ����)���� �� ��� �ϳ��� ���� �۾��� �Ͽ� �� ���� ������ ���� �ȴ�.

�ֿ� �˰��� : ����, ���շ�, ���Թ���

��ó : GCJW 2015 B3��
*/

int main(void) {
    int t, k, v;
    long long res;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d %d", &k, &v);
        res = 0;
        for (int i = v; i >= 2 * v - k - 1 && i >= v - 1; i--) {
            if ((v - i) & 1) res -= (i + 1LL) * (i + 1LL) * (i + 1LL) * (k - v - (v - i) + 1LL);
            else res += (i + 1LL) * (i + 1LL) * (i + 1LL) * (k - v - (v - i) + 1LL);
        }
        printf("Case #%d: %lld\n", tt, res);
        /*
        res = 0;
        for (int i = 0; i <= k; i++) {
            for (int j = 0; j <= k; j++) {
                for (int kk = 0; kk <= k; kk++) {
                    if (abs(i - j) <= v && abs(i - kk) <= v && abs(j - kk) <= v) res++;
                }
            }
        }
        printf("%lld\n", res);
        */
    }
    return 0;
}