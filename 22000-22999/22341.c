#include <stdio.h>

/*
���� : N * N(N <= 10000) ũ���� ���簢���� �ִ�. C(C <= 10000)���� ������ �־��� ��,
�� �簢���� ��Ģ�� �°� �߶��� ���� ������ ���Ѵ�.
������ �־��� �� ���� ���� ��ǥ�� Ȯ���Ѵ�. �簢�� �ܺζ�� ���� ���� ����, ������ ���, ���ο� ���η� �߶��� ���� ���ؼ�
���� �Ǵ� ���� �簢�� �� ������ ū ������ ���� �簢���� �ڸ���. ��, ���� ������ ���� ��� ���η� �ڸ���.

�ذ� ��� : �־������ �����Ѵ�.

�ֿ� �˰����� : ����, �ùķ��̼�

��ó : ���� 2021_2 ��1��
*/

int main(void) {
    int h, w = 0, c, x, y;
    scanf("%d %d", &h, &c);
    w = h;
    for (int i = 0; i < c; i++) {
        scanf("%d %d", &x, &y);
        if (x >= h || y >= w) continue;
        if (x * w >= y * h) h = x;
        else w = y;
    }
    printf("%d", h * w);
    return 0;
}