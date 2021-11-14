#include <stdio.h>

/*
���� : �ڿ��� N(N <= 10^8)�� �־��� ��, ��� �ڿ����� ������������ �̾� ���´ٸ� N��° ���ڴ� �������� ���Ѵ�.

�ذ� ��� : N��°���� ���ڵ��� ���� Ȯ���ذ��� ã���� �ȴ�. N��°�� �Ǳ� ������ �ڸ��� �����θ�
������ ���س��� �ӵ��� �� �� ������ �� ���� �ִ�.

�ֿ� �˰��� : ���Ʈ ����, ����

��ó : ���ϴ� 2016 A��
*/

int a[16];

int digitcount(int x) {
    if (x < 10) return 1;
    else if (x < 100) return 2;
    else if (x < 1000) return 3;
    else if (x < 10000) return 4;
    else if (x < 100000) return 5;
    else if (x < 1000000) return 6;
    else if (x < 10000000) return 7;
    else if (x < 100000000) return 8;
    else if (x < 1000000000) return 9;
    else return 10;
}

int main(void) {
    int n, c = 0, r;
    scanf("%d", &n);
    for (int i = 1; n > c; i++) {
        c += digitcount(i);
        if (c >= n) {
            c -= digitcount(i);
            r = i;
            for (int j = 0; r; j++) {
                a[digitcount(i) - j] = r % 10;
                r /= 10;
            }
            printf("%d", a[n - c]);
            break;
        }
    }
    return 0;
}