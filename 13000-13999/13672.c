#include <stdio.h>

/*
���� : B(B <= 20)���� ���࿡�� N(N <= 20)���� ä�� ���谡 �ִ�. �̶�, �� ������ �ڱ��� ������ �̵�����
��� ä�����踦 û���� �� �ִ��� ���Ѵ�.

�ذ� ��� : �� ä�� ���踦 ������ ���� �ڱ��� �̵���Ų ���� ��� ������ �ڱݷ��� Ȯ���Ѵ�.
���⼭ �ڱ��� ������ �Ǵ� ������ �ִٸ� ä�����踦 û���� �� ���� ���̴�.

�ֿ� �˰��� : ����

��ó : Brasil 2009 D��
*/

int moneys[32];

int main(void) {
    int b, n, d, c, v, r;
    //freopen("E:\\PS\\ICPC\\Latin America\\Brasil\\2009\\subprime.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\Latin America\\Brasil\\2009\\subprime.out", "w", stdout);
    while (1) {
        scanf("%d %d", &b, &n);
        if (b == 0) break;
        for (int i = 1; i <= b; i++) {
            scanf("%d", &moneys[i]);
        }
        for (int i = 0; i < n; i++) {
            scanf("%d %d %d", &d, &c, &v);
            moneys[d] -= v;
            moneys[c] += v;
        }
        r = 1;
        for (int i = 1; i <= b; i++) {
            if (moneys[i] < 0) r = 0;
        }
        printf("%c\n", r ? 'S' : 'N');
    }
    return 0;
}