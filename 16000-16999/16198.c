#include <stdio.h>

/*
���� : N(N <= 10)���� �ڿ���(<= 1000)�� �־��� ��, ������ �־��� ��Ĵ�� ���Ͽ� ���� �� �ִ� ���� ���� ������ ���� ���Ѵ�.
(���� ����)

�ذ� ��� : ��� ����� ���� Ȯ���ϸ� �ȴ�. ��������� ����. 

�ֿ� �˰��� : ���Ʈ ����, ���
*/

int w[16][16];
int best = 0;

int big(int a, int b) {
    return a > b ? a : b;
}

void track(int n, int l, int r) {
    if (n == 2) {
        if (r > best) best = r;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) w[l + 1][j] = w[l][j];
        for (int j = i; j < n; j++) w[l + 1][j] = w[l][j + 1];
        track(n - 1, l + 1, r + w[l][i - 1] * w[l][i + 1]);
    }
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &w[0][i]);
    }
    track(n, 0, 0);
    printf("%d", best);
    return 0;
}