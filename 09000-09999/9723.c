#include <stdio.h>

/*
���� : T(T <= 100000)�� �ﰢ���� �� ���� ���� A, B, C(A, B, C <= 100)�� �־��� ��, �� �ﰢ���� �����ﰢ������ ���Ѵ�.

�ذ� ��� : ��Ÿ����� ������ ���� �� ���� ������ ������ �ٸ� �� ���� ������ ������ �Ǵ� ��찡 �ִ��� Ȯ���غ��� �ȴ�.

�ֿ� �˰��� : ������, ��Ÿ���

��ó : Khwarizmi 2010 A��
*/

int main(void) {
    int t, a, b, c;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d %d %d", &a, &b, &c);
        printf("Case #%d: ", tt);
        if (a * a == b * b + c * c || b * b == a * a + c * c || c * c == a * a + b * b) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}