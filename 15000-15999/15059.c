#include <stdio.h>

/*
���� : 3���� �޴��� ���� �ʿ䷮�� �־�����. ������ �޴��� �� �� �κ����� ���Ѵ�.

�ذ� ��� : ������� �ʿ䷮�� ���� ��� �ʿ䷮�� ����� ����ŭ�� �ᱣ���� ���Ѵ�. �̸� 3�� �ϸ� �� ���� ������ ���̴�.

�ֿ� �˰��� : ����

��ó : Latin 2017 H��
*/

int main(void) {
    int ca, ba, pa, cr, br, pr, res = 0;
    scanf("%d %d %d%d %d %d", &ca, &ba, &pa, &cr, &br, &pr);
    if (cr > ca) res += cr - ca;
    if (br > ba) res += br - ba;
    if (pr > pa) res += pr - pa;
    printf("%d", res);
    return 0;
}