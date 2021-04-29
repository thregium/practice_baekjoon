#include <stdio.h>

/*
���� : N(N <= 10^6)���� 0���� �� ������ ���� K(K <= 10^6)�� ���� ������ �����Ѵ�. (Xi(Xi < N)�� ������ �������� ��� ��ȣ�� ���� 1 ������Ų��.)
������ ������ Q(Q <= 10^6)���� ������ ���� �����Ѵ�. (L�� R�� �־��� ��, L�� R ������ ��� ��ȣ�� ���� ���� ����Ѵ�.)

�ذ� ��� : N * K�� �ſ� ũ�� ������ 1���� ������ �����ϸ� �ð� �ʰ��� ���� �� ���̴�.
�׷��Ƿ� �̸� Xi�� ������ ������ ������ ������ �����ؾ� �Ѵ�. �׷��� �־��� ���(1���� N���� 1���� ������ ���)����
1 + 1/2 + 1/3 + ... + 1/N �� log(N)�� �����ϱ� ������ �ð��ʰ��� ���� �� �ִ�.
������ ������ ���� ������ ó���� ������ ���� ������Ʈ�� �����Ƿ� ���� ���� �̿��� (R������ ��) - (L - 1������ ��) = (L ~ R�� ��)�� Ǯ�� �ð� ���� Ǯ �� �ִ�.

�ֿ� �˰����� : ����, ���� ��

��ó : AIPO 2017F 7��
*/

int x[1048576];
long long seq[1048576], ss[1048576];

int main(void) {
    int n, k, xi, q, l, r;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &xi);
        x[xi]++;
    }
    for (int i = 1; i < n; i++) {
        if (x[i] == 0) continue;
        for (int j = 0; j < n; j += i) {
            seq[j] += x[i];
        }
    }
    for (int i = 1; i <= n; i++) {
        ss[i] = ss[i - 1] + seq[i - 1];
    }
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &l, &r);
        printf("%lld\n", ss[r + 1] - ss[l]);
    }
    return 0;
}