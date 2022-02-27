#include <stdio.h>

/*
���� : 1���� N(N <= 10^8)������ �ڿ������� ������ ���ڿ��� K(K <= 10^9)��° ���ڸ� ���Ѵ�.
�׷��� ���ڰ� ���ٸ� -1�� ����Ѵ�. (���ѽð� 2��)

�ذ� ��� : ���ѽð��� ��� ������ �� �ڿ����� ���̸� Ȯ���� �����鼭 K��°�� �� ���� ���ڸ� ã���� �ȴ�.

�ֿ� �˰��� : ����, �ùķ��̼�, ����
*/

char buff[16];

int getdigit(int x) {
    if (x >= 100000) {
        if (x < 1000000) return 6;
        else if (x < 10000000) return 7;
        else if (x < 100000000) return 8;
        else return 9;
    }
    else if (x >= 10000) return 5;
    else if (x >= 1000) return 4;
    else if (x >= 100) return 3;
    else if (x >= 10) return 2;
    else return 1;
}

int main(void) {
    int n, k, d = 0;
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
        if (d + getdigit(i) >= k) {
            sprintf(buff, "%d", i);
            printf("%d", buff[k - d - 1] - '0');
            return 0;
        }
        else d += getdigit(i);
    }
    printf("-1");
    return 0;
}