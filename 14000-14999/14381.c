#include <stdio.h>

/*
���� : ���� �ƴ� ���� N(N <= 200)�� ����� ���ٰ� ��� �ڸ����� ������ �Ǵ� ù ���� ������ ���Ѵ�.
������ ��� �ڸ����� ������ �ʴ´ٸ� INSOMNIA�� ����Ѵ�.

�ذ� ��� : ���� Ȯ���غ��� 1���� 10^6������ ��� ���� ��� �ڸ����� �ݹ� ������ �� �� �ִ�.
�׷��Ƿ� ���� �ùķ��̼��ϸ� �ȴ�. �׷��� 0�� ���� ���������� ������ 0�̹Ƿ� INSOMNIA�� ����ؾ� �Ѵ�.

�ֿ� �˰��� : ����, �ùķ��̼�

��ó : GCJ 2016Q A1��
*/

int chk[10];

int main(void) {
    int t, n, x;
    long long r;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d", &n);
        if (n == 0) {
            printf("Case #%d: INSOMNIA\n", tt);
            continue;
        }
        for (r = n;; r += n) {
            for (long long rt = r; rt; rt /= 10) chk[rt % 10] = 1;
            x = 1;
            for (int i = 0; i < 10; i++) {
                if (!chk[i]) {
                    x = 0;
                    break;
                }
            }
            if (x) break;
        }
        for (int i = 0; i < 10; i++) chk[i] = 0;
        printf("Case #%d: %lld\n", tt, r);
    }
    return 0;
}