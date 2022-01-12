#include <stdio.h>

/*
���� : N(N <= 13200)���� �ݾ��� 10, 50, 100, 500�� ������ �̿��Ͽ� ������ �Ѵ�.
�ݾ� �̻��� ������ ���� ������ �Ž������� �ִµ�, ������ ������ �ּ�ȭ�Ͽ� �ش�.
�̶�, N�� �� ������ ����(<= 20)�� �־����� ���� ������ ������ �ּ�ȭ�ǵ��� ������ �ִ� ����� ���Ѵ�.
��, ���� �� �� ���� ���� �־����� ������, �ǹ� ���� ��ȯ(���� �ݾ��� ������ �޴� ���)�� ����� �Ѵ�.

�ذ� ��� : ������ ���� ��� ��츦 �õ��غ��� �޴� ������ ������ Ȯ���Ѵ�.
�޴� ������ ������ ������ �¾ƶ������� ������ ū �������� �����ִ� ������ ������ �� �� �ִ�.
����, ������ ������ ���� �������� ���� ó�� ������ �ּڰ����� �ǹ̾��� ��ȯ�� ������ �ʱ� ������,
ó�� ������ �ּڰ��� ���ϸ� �װ��� ���� �ȴ�.

�ֿ� �˰��� : �׸��� �˰���, ���Ʈ ����

��ó : JAG 2005D B��
*/

int coincount(int x) {
    return x / 500 + x / 100 % 5 + x / 50 % 2 + x / 10 % 5;
}

int main(void) {
    int n, m, a, b, c, d, best, ra, rb, rc, rd;
    //freopen("E:\\PS\\Contest\\Japanese Alumni Group\\2005D\\data\\B\\input\\B4", "r", stdin);
    //freopen("E:\\PS\\Contest\\Japanese Alumni Group\\2005D\\data\\B\\output\\B4_t", "w", stdout);
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        best = 103000, ra = -1, rb = -1, rc = -1, rd = -1;
        for (int i = 0; i <= a; i++) {
            for (int j = 0; j <= b; j++) {
                for (int k = 0; k <= c; k++) {
                    for (int l = 0; l <= d; l++) {
                        m = i * 10 + j * 50 + k * 100 + l * 500;
                        if (m < n) continue;
                        if (coincount(m - n) - i - j - k - l < best) {
                            best = coincount(m - n) - i - j - k - l;
                            ra = i, rb = j, rc = k, rd = l;
                        }
                    }
                }
            }
        }
        if (ra < 0) return 1;
        if (ra) printf("10 %d\n", ra);
        if (rb) printf("50 %d\n", rb);
        if (rc) printf("100 %d\n", rc);
        if (rd) printf("500 %d\n", rd);
        printf("\n");
    }
    return 0;
}