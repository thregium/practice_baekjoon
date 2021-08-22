#include <stdio.h>

/*
���� : N(N <= 7)�ڸ� 0 �̻��� ������ ��� M(M <= N)���� �־��� ���ڵ��� ��� ���� �������� ã�´�.

�ذ� ��� : N�ڸ� ������ ��� ���� ���� �� ���ڵ��� ���� �������� �Ź� Ȯ���غ��� �ȴ�.

�ֿ� �˰��� : ���Ʈ ����, ����

��ó : ������ 12ȸM A��
*/

int nums[16], chk[16];
int b10[8] = { 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000 };

int main(void) {
    int n, m, x, r = 0, t;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        nums[x] = 1;
    }
    for (int i = 0; i < b10[n]; i++) {
        for (int j = 0; j < 10; j++) chk[j] = 0;
        t = 1;
        for (int j = i, j2 = 0; j2 < n; j /= 10, j2++) {
            chk[j % 10]++;
        }
        for (int j = 0; j < 10; j++) {
            if (nums[j] && !chk[j]) {
                t = 0;
                break;
            }
        }
        r += t;
    }
    printf("%d", r);
    return 0;
}