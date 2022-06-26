#include <stdio.h>

/*
���� : N(N <= 50000)���� ������ �������� �����ִ�. ���ֻ󿡼� �� ���� ���� ������ �Ÿ��� �־��� ��,
���ֻ󿡼� �� ���� ���� �Ÿ��� ���� �� ���� ���Ѵ�.

�ذ� ��� : ���� ���� �����ϸ鼭 ���� ������ ���� ������ �ִ��� ��������� ������ ������ ��������
���۰� ������ �����Ѵ�. �� ��� ���� ��� ���� ���� ���� �ִ밡 �Ǵ� ��츦 ã���� �ȴ�.

�ֿ� �˰��� : ���� ��, �� ������
*/

int dist[51200];

int small(int a, int b) {
    return a < b ? a : b;
}

int main(void) {
    int n, sum = 0, last = 0, tsum = 0, res = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &dist[i]);
        sum += dist[i];
    }
    for (int i = 0; i < n; i++) {
        while (tsum < sum - tsum) {
            if (small(tsum, sum - tsum) > res) res = small(tsum, sum - tsum);
            tsum += dist[last];
            last = (last + 1) % n;
        }
        if (small(tsum, sum - tsum) > res) res = small(tsum, sum - tsum);
        tsum -= dist[i];
    }
    printf("%d", res);
    return 0;
}