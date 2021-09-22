#include <stdio.h>
#include <stdlib.h>

/*
���� : ��ǥ���� 10000 ������ ������ �� ���� ��ǥ�� �־�����. �̶� �� ������ ���� �� �ִ� �ﰢ���� ��� �ﰢ������ �����Ѵ�.
���ﰢ��/�����̵�ﰢ��/�����̵�ﰢ��/�а��̵�ﰢ��/�����ﰢ��/�����ﰢ��/�а��ﰢ��/�ﰢ���� �ƴ�
�� ��찡 �ִ�.

�ذ� ��� : ���� CCW �˰����� �̿��Ͽ� �� ���� �������� ��ġ���ִ��� �̸� ���Ѵ�. �������� ��� �ﰢ���� �ƴϴ�.
�ﰢ���� �´ٸ� �� ���� ������ ������ ������ �� ���� �� ���� ������ ���� ���� ���غ���.
���� �� ���� �� ũ�ٸ� �а��ﰢ���̴�. ���� �� ���� �������� ���ٸ� �����ﰢ���̰�, �� ª�ٸ� �����ﰢ���̴�.
�� �������δ� �� ���� ���̰� ������ ���캸�� �̵ ���θ� ã���� �ȴ�. ���ﰢ���� ���� ��ǥ���� ���� �� �����Ƿ�
�������� �ʾƵ� �ȴ�.(sqrt(3)�� �������̱� ������)

�ֿ� �˰��� : ������, ���̽� ��ũ
*/

int sides[3];

int sqr(int a) {
    return a * a;
}

int ccw(int ax, int ay, int bx, int by, int cx, int cy) {
    return (ax * by + bx * cy + cx * ay) - (ay * bx + by * cx + cy * ax);
}

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int x1, y1, x2, y2, x3, y3;
    scanf("%d %d%d %d%d %d", &x1, &y1, &x2, &y2, &x3, &y3);
    if (ccw(x1, y1, x2, y2, x3, y3) == 0) {
        printf("X");
        return 0;
    }
    sides[0] = sqr(x1 - x2) + sqr(y1 - y2);
    sides[1] = sqr(x2 - x3) + sqr(y2 - y3);
    sides[2] = sqr(x3 - x1) + sqr(y3 - y1);
    qsort(sides, 3, sizeof(int), cmp1);
    if (sides[2] > sides[0] + sides[1]) {
        if (sides[0] == sides[1] || sides[1] == sides[2]) printf("Dunkak2Triangle");
        else printf("DunkakTriangle");
    }
    else if (sides[2] == sides[0] + sides[1]) {
        if (sides[0] == sides[1] || sides[1] == sides[2]) printf("Jikkak2Triangle");
        else printf("JikkakTriangle");
    }
    else {
        if (sides[0] == sides[2]) printf("JungTriangle");
        else if (sides[0] == sides[1] || sides[1] == sides[2]) printf("Yeahkak2Triangle");
        else printf("YeahkakTriangle");
    }
    return 0;
}