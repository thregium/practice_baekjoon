#include <stdio.h>

/*
���� : N * N(N <= 100) ũ���� ���簢���� �׵θ��� @�� ����Ѵ�.

�ذ� ��� : (N + 2) * (N + 2) ũ���� ���簢���� ����ϵ� �׵θ��� @�� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����
*/

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = -1; i <= n; i++) {
        for (int j = -1; j <= n; j++) {
            printf("%c", (i < 0 || j < 0 || i == n || j == n) ? '@' : ' ');
        }
        printf("\n");
    }
    return 0;
}