#include <stdio.h>

/*
���� : �ڿ��� P�� A(P, A <= 10^9)�� �־��� ��, �� �ڿ����� ��¥ �Ҽ����� ���Ѵ�. A^P % P = A�� ����̴�.

�ذ� ��� : ���� �־��� �ڿ����� ��¥ �Ҽ����� ���ϰ�, �׷��� ��� ��¥ �Ҽ��� �ƴϴ�.
��¥ �Ҽ��� �ƴ϶�� ���� �ŵ��������� ������ ���� Ȯ���Ѵ�. �´ٸ� ��¥ �Ҽ��̰�, �ƴ϶�� ��¥ �Ҽ��� �ƴϴ�.

�ֿ� �˰��� : ����, ������, �丣���� ������, �Ҽ� ����, ���� �ŵ�����

��ó : Waterloo 070923 C��
*/

int powe(int x, int y, int m) {
    if (y == 1) return x;
    int h = powe(x, y >> 1, m);
    h = ((long long)h * h) % m;
    if (y & 1) return ((long long)h * x) % m;
    else return h;
}

int main(void) {
    int p, a, t;
    while (1) {
        scanf("%d %d", &p, &a);
        if (a == 0) break;
        t = 1;
        for (int i = 2; i * i <= p; i++) {
            if (p % i == 0) {
                t = 0;
                break;
            }
        }
        if (t) {
            printf("no\n");
            continue;
        }
        if (powe(a, p, p) == a) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}