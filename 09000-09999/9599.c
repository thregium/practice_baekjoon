#include <stdio.h>

/*
���� : N(N <= 20)������ ���� �ٸ� �ڿ��� K(K <= 10)���� �̾Ƽ� ���� ���� S(S <= 155) ���ϰ� �Ǵ� ������ ������ ���Ѵ�.

�ذ� ��� : N�� K�� ����� �۱� ������ ��Ʈ��ŷ�� ���� ��� ��츦 ���캸�� ���� S�� ���� ������ ���� �ȴ�.

�ֿ� �˰��� : ��Ʈ��ŷ

��ó : Aizu 2013 A��
*/

int r = 0;

void track(int n, int k, int s, int l) {
    if (k == 0) {
        if (s == 0) r++;
        return;
    }
    for (int i = l + 1; i <= n; i++) {
        if (s >= i) track(n, k - 1, s - i, i);
    }
}

int main(void) {
    int n, k, s;
    while (1) {
        scanf("%d %d %d", &n, &k, &s);
        if (n == 0) break;
        r = 0;
        track(n, k, s, 0);
        printf("%d\n", r);
    }
    return 0;
}