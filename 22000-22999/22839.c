#include <stdio.h>

/*
���� : 1���� 289������ �������� �̷���� ������ �������� ���� ��, N(N <= 300)�� ����� ����� �������� ���Ѵ�.

�ذ� ��� : ���̳��� ���α׷����� ���� Ǯ�� �ȴ�.

�ֿ� �˰��� : DP, ����

��ó : Kyoto 1999 B��
*/

int mem[384];

int main(void) {
    int n;
    mem[0] = 1;
    for (int i = 1; i <= 17; i++) {
        for (int j = i * i; j <= 300; j++) {
            mem[j] += mem[j - i * i];
        }
    }
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        printf("%d\n", mem[n]);
    }
    return 0;
}