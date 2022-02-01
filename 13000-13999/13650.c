#include <stdio.h>

/*
���� : N(N <= 10000)���� ��ȭ�� �ִ�. �� ��ȭ�� ������ M(30 <= M <= 60)�� ��� �� �Ź������� ���� �־��� ��,
���� ������� ���� �� �ִ� ��ȭ�� ������ ���Ѵ�.

�ذ� ��� : �� ������� ���⸶�� �Ź��� ������ ���� ����, ���� ���� ������ ���� ���ϸ� ���� �ȴ�.

�ֿ� �˰��� : ����

��ó : Brasil 2011 B��
*/

int boot[64][2];

int small(int a, int b) {
    return a < b ? a : b;
}

int main(void) {
    int n, m, r;
    char l;
    //freopen("E:\\PS\\ICPC\\Latin America\\Brasil\\2011\\botas.in", "r", stdin);
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf("%d %c", &m, &l);
            if (l == 'D') boot[m][0]++;
            else boot[m][1]++;
        }
        r = 0;
        for (int i = 30; i <= 60; i++) {
            r += small(boot[i][0], boot[i][1]);
            boot[i][0] = 0;
            boot[i][1] = 0;
        }
        printf("%d\n", r);
    }
    return 0;
}