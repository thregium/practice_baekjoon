#include <stdio.h>

/*
���� : H * W(H, W <= 500) ũ���� ���ڿ��� ���� ä�� ��, ���� ���� �Ǵ� ĭ�� ���� ���Ѵ�.
�� ������ �ؿ������� ���ʷ� �׾ƿ÷��� �����̸�, �ش� ���̿��� ���ʿ� ���� �ִ� ��쿡�� ���� ���̿� ���� ���� �ȴ�.

�ذ� ��� : �� �Ʒ��������� ���ʷ� ���ʿ� ���� �ִ��� Ȯ���� �� �ִٸ� �ش� ĭ�� ���� ä������ ���� ���� ĭ ���� ���ϸ� �ȴ�.

�ֿ� �˰��� : ���Ʈ ����

��ó : �泲�� 1ȸ D��
*/

char rain[512][512];

int main(void) {
    int h, w, x, last, r = 0;
    scanf("%d %d", &h, &w);
    for (int i = 0; i < w; i++) {
        scanf("%d", &x);
        for (int j = 0; j < x; j++) {
            rain[i][j] = 1;
        }
    }
    for (int i = 0; i < h; i++) {
        last = -1;
        for (int j = 0; j < w; j++) {
            if (!rain[j][i]) continue;
            if (last == -1) {
                last = j;
                continue;
            }
            else {
                r += j - last - 1;
                last = j;
            }
        }
    }
    printf("%d", r);
    return 0;
}