#include <stdio.h>

/*
���� : N(N <= 1000)���� ���� �̷���� �迭���� ������ ���� ��, �� ������ �ִ񰪰� �ּڰ��� ���� ����
�ִ밡 �� ���� ���� ���Ѵ�.

�ذ� ��� : 1���� DP�� �ش� ĭ���� Ȯ������ ���� �ִ��� �����ϰ� DP�� �Ѵ�. �������� ������ ��������
������ ���� ���� ���� ������ Ȯ���ϸ� �ȴ�.

�ֿ� �˰��� : DP
*/

int score[1024], mem[1024];

int big(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    int n, hi, lo;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &score[i]);
    }
    for (int i = 1; i <= n; i++) {
        hi = score[i], lo = score[i];
        for (int j = i - 1; j >= 0; j--) {
            mem[i] = big(mem[i], mem[j] + hi - lo);
            if (score[j] > hi) hi = score[j];
            if (score[j] < lo) lo = score[j];
        }
    }
    printf("%d", mem[n]);
    return 0;
}