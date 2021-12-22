#include <stdio.h>

/*
���� : N(N <= 100000)�ϰ� ����� ���� �ܰ��� �־��� ��, M�ϸ� ����� �ϱ� ���� �� ��ݽ� ����ؾ� �ϴ�
�ּ� �ݾ��� ���Ѵ�. ��, �ܾ��� ������ ���� ���� �ݾ��� ������ ����Ѵ�.

�ذ� ��� : �Ű� ���� Ž���� �̿��Ѵ�. X��ŭ ����� �� ����ؾ� �ϴ� ���� ���� ���ϰ�
�� ���� M ������ ���� ���� X�� ���ϸ� �ȴ�. ����ؾ� �ϴ� ���� ���� �׸����ϰ� ���� ���ڶ� �� ���� ����ϸ� ���� �� �ִ�.

�ֿ� �˰����� : �Ķ��Ʈ��

��ó : USACO 2007M S3��
*/

int money[103000];

int getdays(int n, int x) {
    int r = 0, m = 0;
    for (int i = 0; i < n; i++) {
        if (money[i] > m) {
            r++;
            m = x;
            if (money[i] > x) return 1012345678;
        }
        m -= money[i];
    }
    return r;
}

int main(void) {
    int n, m, l = 0, h = 1012345678;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &money[i]);
    }
    while (l < h) {
        if (getdays(n, (l + h) >> 1) <= m) h = ((l + h) >> 1);
        else l = ((l + h) >> 1) + 1;
    }
    printf("%d", l);
    return 0;
}