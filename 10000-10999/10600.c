#include <stdio.h>
#define INF 1012345678

/*
���� : Ư���� ���� RGB���� �־��� ��, ������ �־����� 16���� �� ��� ���� ����� ���� ã�´�.

�ذ� ��� : �� ���� ������ �ϵ��ڵ��� ��, ������ ���� ���� �Ÿ��� ���ϰ� ���� ����� ���� ���� �ȴ�.

�ֿ� �˰��� : ����, ����

��ó : Tehran 2014 B��
*/

const char* colorn[16] = { "White", "Silver", "Gray", "Black", "Red", "Maroon", "Yellow",
"Olive", "Lime", "Green", "Aqua", "Teal", "Blue", "Navy", "Fuchsia", "Purple" };

const int color[16][3] = { {255, 255, 255}, {192, 192, 192}, {128, 128, 128}, {0, 0, 0},
    {255, 0, 0}, {128, 0, 0}, {255, 255, 0}, {128, 128, 0}, {0, 255, 0}, {0, 128, 0},
    {0, 255, 255}, {0, 128, 128}, {0, 0, 255}, {0, 0, 128}, {255, 0, 255}, {128, 0, 128} };

int sqr(int a) {
    return a * a;
}

int main(void) {
    int r, g, b, best, bn;
    while (1) {
        scanf("%d %d %d", &r, &g, &b);
        if (r < 0) break;
        best = INF, bn = -1;
        for (int i = 0; i < 16; i++) {
            if (sqr(color[i][0] - r) + sqr(color[i][1] - g) + sqr(color[i][2] - b) < best) {
                best = sqr(color[i][0] - r) + sqr(color[i][1] - g) + sqr(color[i][2] - b);
                bn = i;
            }
        }
        if (bn < 0) return 1;
        printf("%s\n", colorn[bn]);
    }
    return 0;
}