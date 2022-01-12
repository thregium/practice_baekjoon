#include <stdio.h>

/*
���� :N(N <= 100)���� ���� H, �ʺ� W(H, W <= 100)�� â���� �Ϸķ� �ִ�. �̶�, �� â���� X_i(X_i <= W)��ŭ �ű� ��
â���� ���� ������ �ʺ� ���Ѵ�. Ȧ����° â���� ����������, ¦����° â���� �������� �ű��.

�ذ� ��� : â���� �ִ� ��ġ�� �迭�� ������ ����, �迭�� ���� â���� ���� ��ġ�� ������ ���ϸ� �ȴ�.

�ֿ� �˰��� : ����

��ó : JAG 2017P A��
*/

char wind[128][10240];

int main(void) {
    int n, h, w, x, r = 0;
    scanf("%d %d %d", &n, &h, &w);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        if (i & 1) {
            for (int j = 0; j < h; j++) {
                for (int k = w * i - x; k < w * (i + 1) - x; k++) {
                    wind[j][k] = 1;
                }
            }
        }
        else {
            for (int j = 0; j < h; j++) {
                for (int k = w * i + x; k < w * (i + 1) + x; k++) {
                    wind[j][k] = 1;
                }
            }
        }
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w * n; j++) {
            r += !wind[i][j];
        }
    }
    printf("%d", r);
    return 0;
}