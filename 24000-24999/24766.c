#include <stdio.h>

/*
���� : �� ���� ���� �ֻ��� 2������ ���� ���� �־����ų� �־����� ���� ��,
�־����� ���� �ֻ����� ������ ���Ƿ� �����Ͽ� ù ��° ����� �̱� Ȯ���� ���Ѵ�.
��Ģ�� ������ �־�������̴�.

�ذ� ��� : �ֻ��� 4���� ��� ��츦 �� ������ �׸� ���� �ʱ� ������
��� ����� ���� ���� ù ��° ����� �̱�� ����� ���� ���� ���� �� ���� ������ ���ϸ� �ȴ�.

�ֿ� �˰��� : ����, ���Ʈ ����

��ó : VTH 2014 B��
*/

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int score(int a, int b) {
    if (a == 2 && b == 1) return 103000;
    else if (a == b) return 100 + a;
    else return a * 10 + b;
}

int gcd(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;
    return a > b ? gcd(a % b, b) : gcd(a, b % a);
}

int main(void) {
    char a, b, c, d;
    int res, tot, g, x, y, z, w;
    while (1) {
        scanf(" %c %c %c %c", &a, &b, &c, &d);
        if (a == '0') break;
        res = 0, tot = 0;
        for (int i = 1; i <= 6; i++) {
            if (a != '*' && a - '0' != i) continue;
            for (int j = 1; j <= 6; j++) {
                if (b != '*' && b - '0' != j) continue;
                for (int k = 1; k <= 6; k++) {
                    if (c != '*' && c - '0' != k) continue;
                    for (int l = 1; l <= 6; l++) {
                        if (d != '*' && d - '0' != l) continue;
                        tot++;
                        x = i, y = j, z = k, w = l;
                        if (x < y) swap(&x, &y);
                        if (z < w) swap(&z, &w);
                        if (score(x, y) > score(z, w)) res++;
                    }
                }
            }
        }
        if (res == 0) printf("0\n");
        else if (res == tot) printf("1\n");
        else {
            g = gcd(res, tot);
            res /= g, tot /= g;
            printf("%d/%d\n", res, tot);
        }
    }
    return 0;
}