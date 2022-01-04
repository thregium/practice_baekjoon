#include <stdio.h>

/*
���� : D(D <= 10000)�� �Ÿ��� K(K <= 10000)��ŭ�� ���������� ������ �Ѵ�. �߰��� S(S <= 100)���� ������ ��ġ����
������������ �־�����. �̶�, �����Ҹ� �ּ������� �鸥�ٸ� �鷯�� �ϴ� �����ҵ��� ����Ѵ�.
�� �� ���� ��쿡�� out of petrol�� ����Ѵ�. ��߽ÿ��� ���ᰡ ���� �� �����̴�.

�ذ� ��� : ���� ����� ���� ������(�Ǵ� ������)�� �� �� ���� �� ���� �̹� �����ҿ� �鸥��. ���� �̹� �����ҿ��� �����ϴ���
���� �����ҷ� �� �� ���ٸ� out of petrol�� ����ϸ� �ȴ�.

�ֿ� �˰��� : �׸��� �˰���

��ó : Lahore 2014O 2��
*/

int fuel[128], res[128];

int main(void) {
    int t, d, k, n, f, r = 1, rn;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d %d %d", &d, &k, &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &fuel[i]);
        }
        fuel[n + 1] = d;
        f = k;
        rn = 0;
        r = 1;
        for (int i = 0; i <= n; i++) {
            if (fuel[i + 1] - fuel[i] > k) {
                r = 0;
                break;
            }
            else if (fuel[i + 1] - fuel[i] > f) {
                f = k;
                res[rn++] = fuel[i];
            }
            f -= fuel[i + 1] - fuel[i];
        }

        printf("Case #%d: ", tt);
        if (r == 0) printf("out of petrol\n");
        else {
            for (int i = 0; i < rn; i++) {
                printf("%d ", res[i]);
            }
            printf("\n");
        }
    }
    return 0;
}