#include <stdio.h>

/*
���� : ù 16���� ���� ��� �־��� ����� ���� ����� ���� ��� ��Ī��Ų ���� ���Ѵ�.

�ذ� ��� : 16���� ���� ���� ���� �Ÿ��� �纸�� ���� ����� ���� ���� �ȴ�.

�ֿ� �˰��� : ���Ʈ ����, ����

��ó : GNY 2001 A��
*/

int target[16][3], color[3];

int sqr(int a) {
    return a * a;
}

int getdist(int x) {
    return sqr(color[0] - target[x][0]) + sqr(color[1] - target[x][1]) + sqr(color[2] - target[x][2]);
}

int main(void) {
    int best;
    for (int i = 0; i < 16; i++) {
        scanf("%d %d %d", &target[i][0], &target[i][1], &target[i][2]);
    }
    while (1) {
        scanf("%d %d %d", &color[0], &color[1], &color[2]);
        if (color[0] < 0) break;
        best = 0;
        for (int i = 1; i < 16; i++) {
            if (getdist(i) < getdist(best)) best = i;
        }
        printf("(%d,%d,%d) maps to (%d,%d,%d)\n", color[0], color[1], color[2], target[best][0], target[best][1], target[best][2]);
    }
    return 0;
}