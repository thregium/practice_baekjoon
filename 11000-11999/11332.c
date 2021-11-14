#include <stdio.h>
#include <stdlib.h>
#define SEC 100000000

/*
���� : N(N <= 10^6), �׽�Ʈ ���̽� �� T(T <= 10), �ð� ���� L(L <= 10)�� �־��� ��, 1�ʿ� 10^8ȸ ������ �����ϴٸ�
�־��� �ð� ���⵵(O(N), O(N^2), O(N^3), O(2^N), O(N!))�� ���� �ð� ���� ���� ������ �������� ���Ѵ�.
��, ����� 1�� �����Ѵ�.

�ذ� ��� : N�� ���� �ð� ���⵵�� ���� ����� �� T�� ���� ���� 10^8 * L ������ ��� �ð� ���� ���� ��� �����ϴ�.
�׷���, �״�� ���� ����ϸ� �����÷ΰ� ���� ������ �� �ð� ���⵵�� ����ϴ� �������� ������ �Ѿ�� ����
�ð� �ʰ��� ����ؾ� �Ѵ�.

O(N)�� ���� N�� 10^6�� T�� 10�̴��� �׻� 10^8 ������ ���� Ƚ���� �����Ƿ�
�ð� ���� �� ��� �����ϴ�. O(N^2)�� ���� long long ���� ���̹Ƿ� �״�� �����ϸ� �ǰ�,
O(N^3)�� ���� O(N^2)�� ������ ���� �ȴ�. O(2^N)�� ��쿡�� T���� �����ؼ� 2�� N�� ���س�����.
�߰��� L * 10^8�� ������ TLE�� ����ϰ�, ������ ���� �ʾҴٸ� ����̴�.
O(N!)�� ����� ������� T���� �����ؼ� ���丮���� ���س����� ����� ���� �ȴ�.

�ֿ� �˰��� : ����, ���̽� ��ũ

��ó : Calgary 2013 A��
*/

char s[16];

int main(void) {
    int c;
    long long n, t, l, x;
    scanf("%d", &c);
    for (int cc = 0; cc < c; cc++) {
        scanf("%s %lld %lld %lld", s, &n, &t, &l);
        if (!strcmp(s, "O(N)")) printf("May Pass.\n");
        else if (!strcmp(s, "O(N^2)")) {
            if (n * n * t <= l * SEC) printf("May Pass.\n");
            else printf("TLE!\n");
        }
        else if (!strcmp(s, "O(N^3)")) {
            if (n * n * t > l * SEC) printf("TLE!\n");
            else if (n * n * n * t > l * SEC) printf("TLE!\n");
            else printf("May Pass.\n");
        }
        else if (!strcmp(s, "O(2^N)")) {
            x = t;
            for (int i = 0; i < n; i++) {
                x <<= 1;
                if (x > l * SEC) {
                    printf("TLE!\n");
                    break;
                }
            }
            if (x <= l * SEC) printf("May Pass.\n");
        }
        else if (!strcmp(s, "O(N!)")) {
            x = t;
            for (int i = 1; i <= n; i++) {
                x *= i;
                if (x > l * SEC) {
                    printf("TLE!\n");
                    break;
                }
            }
            if (x <= l * SEC) printf("May Pass.\n");
        }
        else return 1;
    }
    return 0;
}