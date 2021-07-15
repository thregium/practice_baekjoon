#include <stdio.h>

/*
���� : ������� �־����� ó�� 16�� ����� ��� ���� ����� ������ ��� �ش� ����� ����� ����� ����Ѵ�.
���� ������ �Ÿ��� RGB�� ������ ������ ���� �������� �Ͱ� ����.

�ذ� ��� : 16�� ���� ������ ���� ���� �Ÿ��� ���� ���� ���� ����� ������ ã�� �� ���� ���������� �ȴ�.

�ֿ� �˰��� : ���Ʈ ����, ��Ģ����

��ó : MidC 1994 1��
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
    //freopen("E:\\PS\\ICPC\\North America\\Mid Central\\mcpc1994\\problem1.in", "r", stdin);
    for (int i = 0; i < 16; i++) {
        scanf("%d %d %d", &target[i][0], &target[i][1], &target[i][2]);
    }
    while (scanf("%d %d %d", &color[0], &color[1], &color[2]) != EOF) {
        best = 0;
        for (int i = 1; i < 16; i++) {
            if (getdist(i) < getdist(best)) best = i;
        }
        printf("%3d %3d %3d maps to %3d %3d %3d\n", color[0], color[1], color[2], target[best][0], target[best][1], target[best][2]);
    }
    return 0;
}