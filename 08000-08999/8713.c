#include <stdio.h>

/*
���� : �� ���� A, B(|A|, |B| <= 10000)�� �־��� ��, ���̿� +, -, * �� ���� ���� Ŀ���� ���� ��� �ְ� ���� �ϼ��Ѵ�.
��, �׷��� ��찡 �� �� �̻��� ��� NIE�� ����ϰ�, ��½ÿ� �������� ��ȣ�� �ľ� �Ѵ�.

�ذ� ��� : 3���� ��츦 ���� �غ���. �߰��� ���� ���� ū ���� �����ϴٸ� �� ū ���� ���� �� ���� üũ�صд�.
üũ�� �Ǿ��ִ� ��쿡�� NIE�� ����ϰ� �� �ܿ��� �� �����ڸ� ã�� ������ �����ϸ� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����, ���̽� ��ũ

��ó : ILOCAMP 2010B 1-4��
*/

int main(void) {
    int a, b, best = -103000, bop = -1;
    scanf("%d %d", &a, &b);
    if (a + b > best) {
        best = a + b;
        bop = 0;
    }
    else if (a + b == best) bop = -1;
    if (a - b > best) {
        best = a - b;
        bop = 1;
    }
    else if (a - b == best) bop = -1;
    if (a * b > best) {
        best = a * b;
        bop = 2;
    }
    else if (a * b == best) bop = -1;
    if (best == -103000) return 1;
    if (bop < 0) printf("NIE");
    else {
        if (a < 0) printf("(%d)", a);
        else printf("%d", a);
        printf("%c", bop == 0 ? '+' : bop == 1 ? '-' : '*');
        if (b < 0) printf("(%d)=", b);
        else printf("%d=", b);
        if (best < 0) printf("(%d)", best);
        else printf("%d", best);
    }
    return 0;
}