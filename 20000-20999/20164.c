#include <stdio.h>
#include <string.h>

/*
���� : �ڿ��� N(N < 10^9)�� �־��� ��, N�� �־��� ��Ģ��� �ڸ��� ��� ��� �������� �� �� �ִ� Ȧ���� ������ ������
���� ���� ���� ���� ���� ����� Ȧ���� ������ ������ ���� ���Ѵ�.
1. �� �ڸ� ���� ��� �״�� �����Ѵ�.
2. �� �ڸ� ���� ��� �� ���ڸ� ���� ���� ���ο� ������ �Ͽ� ���� �ܰ踦 �����Ѵ�.
3. �� �ڸ� �̻��� ���� ��� ������ �� �ڸ����� ���� �ڸ� ����, �ڸ� ���� ��� ���� ���� �� ������ ���� �ܰ踦 �����Ѵ�.

�ذ� ��� : ��͸� ���� �� �ܰ踦 �����ϸ� Ȯ�� ������ Ȧ���� ������ ������ ����.
�� �ڸ��� �Ǹ� ���� ������ ������ �������� �ִ�, �ּ��� ��츦 �����Ѵ�.
�� �ڸ��� ���� ������ ���� �����ϸ�, �� �ڸ��� ���� �� �ڸ� ���� ���ڿ��� �ٲ� ���� ��ġ�� ���ؼ�
���� ���س����� ����� �� �� �ִ�.

�ֿ� �˰����� : ���Ʈ ����, ���, ����

��ó : ��ȣ�� 1ȸ 1��
*/

int best = -1, worst = 99999;

void track(int n, int s) {
    char c[16] = { 0, };
    sprintf(c, "%d", n);
    int l = strlen(c), t, u, v;
    for (int m = n; m; m /= 10) {
        if (m & 1) s++;
    }
    if (n < 10) {
        if (s > best) best = s;
        if (s < worst) worst = s;
        return;
    }
    else if (n < 100) {
        track(n / 10 + n % 10, s);
    }
    else {
        t = 0;
        for (int i = 1; i < l; i++) {
            t *= 10;
            t += c[i - 1] - '0';
            u = 0;
            for (int j = i + 1; j < l; j++) {
                u *= 10;
                u += c[j - 1] - '0';
                v = 0;
                for (int k = j; k < l; k++) {
                    v *= 10;
                    v += c[k] - '0';
                }
                track(t + u + v, s);
            }
        }
    }
}

int main(void) {
    int n;
    scanf("%d", &n);
    track(n, 0);
    printf("%d %d", worst, best);
    return 0;
}