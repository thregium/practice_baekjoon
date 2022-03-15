#include <stdio.h>

/*
���� : N(N <= 10^9)�� K(K <= 100)�� �־��� ��, 1���� �ڿ������� ������� ������ ���ڿ���
N��°���� K���� ���ڸ� ���ʷ� ����Ѵ�.

�ذ� ��� : 10000 ������ �� �ڿ������� �������� ���� ���� ������ ��ó���Ѵ�.
�� ����, N�� K�� �Է¹����鼭 �� ���ڸ��� ����� ���ڸ� ã�Ƴ�����.
�켱 10000 ������ �ڿ����� ���� ã�� �� ���� 1 ������ ã���� O(KsqrtN)�� �ð��� ã�� �� �ִ�.

�ֿ� �˰��� : ����, ��ó��?

��ó : JAG 2009P C��
*/

int mem[16384];
char pnum[16];

int getdc(int x) {
    if (x >= 100000000) {
        if (x >= 1000000000) return 10;
        else return 9;
    }
    else if (x >= 10000000) return 8;
    else if (x >= 1000000) return 7;
    else if (x >= 100000) return 6;
    else if (x >= 10000) return 5;
    else if (x >= 1000) return 4;
    else if (x >= 100) return 3;
    else if (x >= 10) return 2;
    else return 1;
}

int getnthdigit(int x) {
    int r;
    for (int i = 0; i < 13000; i++) {
        if (mem[i + 1] > x) {
            r = mem[i];
            for (int j = 0; j < 10000; j++) {
                if (r + getdc(i * 10000 + j) > x) {
                    sprintf(pnum, "%d", i * 10000 + j);
                    return pnum[x - r] - '0';
                }
                else r += getdc(i * 10000 + j);
            }
        }
    }
    return -1;
}

int main(void) {
    int n, k, s = 1;
    for (int i = 1; i <= 130000000; i++) {
        if (i % 10000 == 0) {
            mem[i / 10000] = s;
        }
        s += getdc(i);
    }

    while (1) {
        scanf("%d %d", &n, &k);
        if (n == 0) break;
        for (int i = n; i < n + k; i++) {
            printf("%d", getnthdigit(i));
        }
        printf("\n");
    }
    return 0;
}