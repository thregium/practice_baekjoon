#include <stdio.h>

/*
���� : �־��� ���µ��� ������ ����Ͽ� �� ������ ���� ���� �̱�ٰ� �� ��, �̱�� ���� ���Ѵ�. (���� ���� ����)

�ذ� ��� : �� ������ ���� �Է¹��� ���� ������ ����ϰ� �� ū���� ã���� �ȴ�.

�ֿ� �˰��� : ����, ��Ģ����

��ó : PacNW 2012 A��
*/

int main(void) {
    int t, a, b, c, d, e, f, g, h, s;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
        h = a + b * 2 + c * 3 + d * 3 + e * 4 + f * 10;
        scanf("%d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &g);
        s = a + b * 2 + c * 2 + d * 2 + e * 3 + f * 5 + g * 10;
        if (h > s) printf("Battle %d: Good triumphs over Evil\n", tt);
        else if (h == s) printf("Battle %d: No victor on this battle field\n", tt);
        else printf("Battle %d: Evil eradicates all trace of Good\n", tt);
    }
    return 0;
}