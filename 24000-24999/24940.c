#include <stdio.h>

/*
���� : N(N <= 80)���� ������� �Ϸķ� �ִ�. ������ ������� �׷��� ���� ���� ��,
ģ�е��� �ּڰ��� ���Ѵ�. �� �׷��� ������ ������ �ٸ� ��� ������ ���� ���񰪸�ŭ ģ�е��� �پ���.

�ذ� ��� : �� ������ ������ �׻� �����Ƿ� �̸� ��ó���ϸ� ����DP�� ���°� �ȴ�.
ģ�е��� �پ�� ���� �ִ��� ���� ����, �ű⿡ -�� ���̸� �ȴ�. ���� 0�� ���� �����Ѵ�.

�ֿ� �˰��� : DP, ����DP

��ó : ���� 2022Q D��
*/

int a[96];
long long mem[96][96], alig[96][96];

long long big(long long a, long long b) {
    return a > b ? a : b;
}

long long getconflict(int as, int ae, int bs, int be) {
    if (alig[as][ae] >= 0 && alig[bs][be] >= 0) return 0;
    else if (alig[as][ae] <= 0 && alig[bs][be] <= 0) return 0;
    else return -(alig[as][ae] * alig[bs][be]);
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            for (int k = i; k <= j; k++) alig[i][j] += a[k];
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= n - i; j++) {
            for (int k = j + 1; k <= j + i; k++) {
                mem[j][j + i] = big(mem[j][j + i], mem[j][k - 1] + mem[k][j + i] +
                    getconflict(j, k - 1, k, j + i));
            }
        }
    }
    if (mem[1][n] == 0) printf("0");
    else printf("-%lld", mem[1][n]);
    return 0;
}