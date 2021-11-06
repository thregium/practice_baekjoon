#include <stdio.h>

/*
���� : N(N <= 100)���� �������� ������ ������ �־��� ��, ������ �־��� �� ��� �� ���� ������ ���� ���� �����
���� ���� �׷��� ��ĵ��� ����Ѵ�.

�ذ� ��� : �� �������� �� ��ĵ�� ���� �� �´��� Ȯ���Ѵ�. ��� ������ Ȯ���� �� ���� ���� ���� �����
���� Ƚ���� ����ϰ� �� ��ĵ� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����

��ó : COCI 08/09#1 2��
*/

char s[128];
const char* ax = "ABC";
const char* bx = "BABC";
const char* cx = "CCAABB";

int main(void) {
    int n, a = 0, b = 0, c = 0, r;
    scanf("%d", &n);
    scanf("%s", s);
    for (int i = 0; i < n; i++) {
        if (s[i] == ax[i % 3]) a++;
        if (s[i] == bx[i & 3]) b++;
        if (s[i] == cx[i % 6]) c++;
    }
    r = a > b && a > c ? a : b > c ? b : c;
    printf("%d\n", r);
    if (a == r) printf("Adrian\n");
    if (b == r) printf("Bruno\n");
    if (c == r) printf("Goran\n");
    return 0;
}