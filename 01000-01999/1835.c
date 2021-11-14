#include <stdio.h>

/*
���� : N(N <= 1000)���� ī�带 ���ϴ� ������� ����� ���� �����ؾ� �� ������ ����Ѵ�.

�ذ� ��� : ù ��° ĭ���� �Ź� i�� ���� ī�带 i�� ����� �ȴ�. ��, �̹� ������ ī��� ���� �ʾƾ� �Ѵ�.

�ֿ� �˰��� : ����

��ó : NCPC 2006 E��
*/

int res[1024];

int main(void) {
    int t, n, pos;
    scanf("%d", &n);
    for (int i = 0; i <= n; i++) res[i] = 0;
    pos = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= i; ++j) {
            pos = (pos + 1) % n;
            while (res[pos]) {
                pos = (pos + 1) % n;
            }
        }
        res[pos] = i;
    }
    for (int i = 1; i <= n; ++i) {
        printf("%d ", res[i % n]);
    }
    printf("\n");
    return 0;
}
