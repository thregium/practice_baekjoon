#include <stdio.h>

/*
���� : ���� �ð��� �˶� �ð��� ���� �ð��� �� ������ �־��� ��, �˶��� �︮����� �� �� ���Ҵ��� ���Ѵ�.

�ذ� ��� : �� �ð��� �� ������ ����� ����, �˶� �ð��� �ð��� �� �����ٸ� 1440��(1��)�� ���Ѵ�.
�� ���� �� �ð��� ���̸� ���ϸ� �ȴ�.

�ֿ� �˰��� : ����, ��Ģ����

��ó : Brasil 2009 B��
*/

int main(void) {
    int h1, m1, h2, m2, t1, t2;
    //freopen("E:\\PS\\ICPC\\Latin America\\Brasil\\2009\\alarme.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\Latin America\\Brasil\\2009\\alarme.out", "w", stdout);
    while (1) {
        scanf("%d %d %d %d", &h1, &m1, &h2, &m2);
        if (h1 == 0 && m1 == 0 && h2 == 0 && m2 == 0) break;
        t1 = h1 * 60 + m1, t2 = h2 * 60 + m2;
        if (t1 > t2) t2 += 1440;
        printf("%d\n", (t2 - t1));
    }
    return 0;
}