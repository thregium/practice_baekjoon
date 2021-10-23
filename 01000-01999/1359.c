#include <stdio.h>

/*
���� : N(N <= 8)���� �� ��� M���� �̰�, �� M���� �̾��� ��, K�� �̻��� ���� Ȯ���� ���Ѵ�.

�ذ� ��� : N�� �ſ� �۱� ������ ���Ʈ ������ ���� ��� ������ �̾ƺ� ���� ���� ��(M ������ ��, 1���� K������ ����
���ʷ� �̾Ҵٰ� �����Ѵ�.)�� ������ K�� �̻��� ���� ������ ���Ѵ�. �� ����, ��ü ������ �������� �� ���� ������
���� ���� �� �ִ�.

�ֿ� �˰��� : ����, ���շ�, ���Ʈ ����
*/

int pick[16];

int track(int n, int m, int k, int p, int l) {
    int r = 0;
    if (p == m) {
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            if (pick[i] <= m) cnt++;
        }
        if (cnt >= k) r = 1;
        return r;
    }
    for (int i = l; i <= n; i++) {
        pick[p] = i;
        r += track(n, m, k, p + 1, i + 1);
    }
    return r;
}

int main(void) {
    int n, m, k, r, fact = 1;
    scanf("%d %d %d", &n, &m, &k);
    r = track(n, m, k, 0, 1);
    for (int i = 2; i <= n; i++) fact *= i;
    for (int i = 2; i <= m; i++) fact /= i;
    for (int i = 2; i <= n - m; i++) fact /= i;
    printf("%.39lf", r / (double)fact);
    return 0;
}