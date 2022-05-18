#include <stdio.h>

/*
���� : N(N <= 8)���� �ڿ���(<= 50)�� �־�����. �� ������ ���� �տ��� K(K <= 50)���� �� �����ٸ�
�ڿ����� ���� ��� ���� ���� ������ �Ǵ� ��찡 ���� ������ ������ ���Ѵ�.

�ذ� ��� : ������ ��� ��츦 �� ���鼭 �׷��� ������ ������ ���� �ȴ�.

�ֿ� �˰��� : ���Ʈ ����, ��Ʈ��ŷ
*/

int a[8], chk[8];
int r = 0;

void track(int n, int p, int x, int k) {
    if (x < 500) return;
    if (n == p) {
        r++;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (chk[i]) continue;
        else chk[i] = 1;
        track(n, p + 1, x - k + a[i], k);
        chk[i] = 0;
    }
}

int main(void) {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    track(n, 0, 500, k);
    printf("%d", r);
    return 0;
}