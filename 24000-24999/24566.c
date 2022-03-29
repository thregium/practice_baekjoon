#include <stdio.h>
#include <stdlib.h>

/*
���� : H * W(H, W <= 50) ũ���� ������ �� �Ǵ� ���� �ٸ� ������ ������� �ִ�. ���� �ִ� ĭ�� �����ϰ�
������� �밢������ Ű ������� ���Ľ�Ű�� �� ��, �Űܾ� �ϴ� ���� ������ �ּڰ��� ���Ѵ�.

�ذ� ��� : ������ 4�� ���̹Ƿ� �� �������� ���Ľ�ų �� �Űܾ� �ϴ� ���� ��� �ּڰ��� ã���� �ȴ�.
�� ���⿡�� �ּڰ��� �� ��ġ�� ���� ���� ������ ���� ����.
�̴� �� ���⿡�� �� ��ȣ�� ���� ���� ���� ������ �� �ٿ� ���ԵǴ� ��°���� ���ϰ�
�� ��°�� ���Ե��� �ʴ� ������ ���� ���ϴ� ������� ���� �����ϴ�. �̸� ���ؼ��� ������� ���̸� �̸� ��ó����
������ �迭�� �־�� �Ѵ�.

�ֿ� �˰��� : ����, ���Ʈ ����

��ó : ECNA 2021 L��
*/

int sta[64][64], asta[2560], stend[128];

void diag(int h, int w, int x) {
    for (int i = 0; i < 128; i++) stend[i] = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (sta[i][j] < 0) continue;
            if (x == 0) stend[i + j + 1]++;
            else if (x == 1) stend[i - j + w]++;
            else if (x == 2) stend[h + w - (i + j + 1)]++;
            else if (x == 3) stend[j - i + h]++;
        }
    }
    for (int i = 1; i < 128; i++) stend[i] += stend[i - 1];
}

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int h, w, n = 0, tomov, pos = -1, res = 103000;
    scanf("%d %d", &h, &w);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            scanf("%d", &sta[i][j]);
            if (sta[i][j] > 0) asta[n++] = sta[i][j];
        }
    }
    qsort(asta, n, sizeof(int), cmp1);
    asta[n] = 1012345678;
    for (int i = 0; i < 4; i++) {
        diag(h, w, i);
        tomov = 0;
        for (int x = 0; x < h; x++) {
            for (int y = 0; y < w; y++) {
                if (sta[x][y] < 0) continue;
                if (i == 0) pos = x + y + 1;
                else if (i == 1) pos = x - y + w;
                else if (i == 2) pos = h + w - (x + y + 1);
                else if (i == 3) pos = y - x + h;
                
                if (sta[x][y] < asta[stend[pos - 1]] || sta[x][y] > asta[stend[pos] - 1]) tomov++;
            }
        }
        if (tomov < res) res = tomov;
    }
    printf("%d", res);
    return 0;
}