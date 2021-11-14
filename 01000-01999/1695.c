#include <stdio.h>

/*
���� : N(N <= 5000) ������ �迭�� ���� ��, �� �迭�� �Ӹ�������� ����� ���� �־�� �ϴ� ������ �ּ� ������ ���Ѵ�.

�ذ� ��� : ���̳��� ���α׷����� �̿��Ѵ�. ��ü �������� �����ؼ� ������ �� ���� Ȯ���Ѵ�.
�� ���� ���� ���ڶ�� ���� �ʿ䰡 ����, �ٸ� ���ڶ�� ���� �Ǵ� �����ʿ� �� ���ڸ� �ִ� ��� �� �� ���� ���� ���� �ȴ�.
���� ���� 1�� ���ϰ� �Ǹ� ���� 0���� ���� ��ʷ� Ȱ���Ѵ�.

�ֿ� �˰��� : DP
*/

int a[5120], mem[5120][5120];

int small(int a, int b) {
    return a < b ? a : b;
}

int dp(int s, int e) {
    if (s >= e) return mem[s][e] = 0;
    if (mem[s][e] >= 0) return mem[s][e];
    if (a[s] == a[e]) return mem[s][e] = dp(s + 1, e - 1);
    else return mem[s][e] = small(dp(s + 1, e), dp(s, e - 1)) + 1;
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        for (int j = 0; j < n; j++) mem[i][j] = -1;
    }
    printf("%d", dp(0, n - 1));
    return 0;
}