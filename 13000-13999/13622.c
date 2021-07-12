#include <stdio.h>

/*
���� : N * P(P, N <= 1000) ũ���� ���ڿ��� 0, 1�� ���� ��, ���η� C(C <= N)�� �̻��� 1�� �����ϴ� ������ ���� ���Ѵ�.

�ذ� ��� : ���� ��� �����ٿ��� �ش��ϴ� ���� ������ ������. 1�� ������ ���Ӽ��� 1�� �ø��� 0�� ������ 0���� �ʱ�ȭ�Ѵ�.
�̶� ���Ӽ��� C�� �Ǵ� ��� �ᱣ���� 1 �ø���. �̸� �ݺ��� ��� ���ڿ��� ������ ���� ���� �� �ִ�.

�ֿ� �˰��� : ����

��ó : Brasil 2006 A��
*/

int a[1024][1024];

int main(void) {
    int p, n, c, l, r;
    //freopen("E:\\PS\\ICPC\\Latin America\\Brasil\\2006\\circuito.in", "r", stdin);
    while (1) {
        scanf("%d %d %d", &p, &n, &c);
        if (p == 0) break;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < p; j++) {
                scanf("%d", &a[i][j]);
            }
        }
        r = 0;
        for (int i = 0; i < p; i++) {
            l = 0;
            for (int j = 0; j < n; j++) {
                if (a[j][i]) {
                    l++;
                    if (l == c) r++;
                }
                else l = 0;
            }
        }
        printf("%d\n", r);
    }
    return 0;
}