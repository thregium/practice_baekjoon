#include <stdio.h>

/*
���� : 20���� ī�� ��� �� ���� �̾Ҵ�. �ٸ� ����� ������ ī�� �� ī�带 �̴´ٸ� �������� �־��� �а�
�̱� Ȯ���� ���Ѵ�. �̱�� ����� ī�� ������ �� ������ �̱� ������ �����Ѵ�.

�ذ� ��� : ���� ���� ī�带 ������ ������ ī��� �� 2���� �̴� ����� Ȯ���Ѵ�. �� ��� ������ ���ؼ�
���� ���� ī�尡 �̱�� ����� ���� ���ϰ�, ��ü ����� ���� ���� ����, ���� ������ �ȴ�.

�ֿ� �˰��� : ���Ʈ ����

��ó : �泲�� 1ȸ B��
*/

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int comp(int a, int b, int c, int d) {
    //�� �и� ���Ѵ�. ���� ���� ������ �� ������ ���, ������ ������ ��ȯ�Ѵ�.
    if (a > 10) a -= 10;
    if (b > 10) b -= 10;
    if (c > 10) c -= 10;
    if (d > 10) d -= 10;
    if (a > b) swap(&a, &b);
    if (c > d) swap(&c, &d);
    if (a == b) {
        if (c == d) {
            if (a > c) return 1;
            else if (a < c) return -1;
            else return 0;
        }
        else return 1;
    }
    else if (c == d) return -1;
    else {
        if ((a + b) % 10 > (c + d) % 10) return 1;
        else if ((a + b) % 10 < (c + d) % 10) return -1;
        else return 0;
    }
}

int main(void) {
    int a, b, w = 0, al = 0;
    scanf("%d %d", &a, &b);
    if (b == a) b += 10;
    for (int i = 1; i <= 20; i++) {
        if (i == a || i == b) continue;
        for (int j = 1; j <= 20; j++) {
            if (j == i || j == a || j == b) continue;
            al++;
            if (comp(a, b, i, j) > 0) w++;
        }
    }
    printf("%.3f", (double)w / al + 0.000001);
    return 0;
}