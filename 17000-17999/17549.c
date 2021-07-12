#include <stdio.h>
#include <math.h>

/*
���� : 6 * 6 ũ���� ������ ������ ü������ �ִ�. �� ü���ǿ��� ��� ���� �������� �ʰ� �ٸ� ���� ���ٸ�
��� ��� ���� ��ġ�� �־����� �� ��� ���� ��Ȯ�� 2ȸ�� ��� ���� ���� �����̴� ����� ���� ���Ѵ�.

�ذ� ��� : ü������ �� ĭ���� ���� ������ �� �� �ִ� ĭ���� ��� ĭ�� ���� �����Ѵ�. ��ǥ��� �߾� ���� �߽�����
���ʰ� ���������� ������ ����ؾ� �Ѵ�. �� �������δ� ���� 1ȸ ������ �� �� �ִ� ��� ĭ�� Ȯ���Ѵ�.
���⼭ 1ȸ���� ��� ���� ��ġ�� ���ٸ� �� ���� �����ϰ�, ������ ��쿡 ���� �ٽ� �� ��ġ���� 1ȸ ������
��� ���� ��ġ�� �̵��� �������� Ȯ���Ѵ�. �̵��� �����ϴٸ� �ᱣ���� 1�� �߰��Ѵ�. �̸� �ݺ��� ���� �ᱣ���� ����Ѵ�.

�ֿ� �˰��� : ����, ���Ʈ ����

��ó : BAPC 2019P H��
*/

int size[12] = { 0, 6, 7, 8, 9, 10, 11, 10, 9, 8, 7, 6 };
int movable[16][16][256];

char buff1[8], buff2[8];

int main(void) {
    for (int i = 1; i <= 11; i++) {
        for (int j = 1; j <= size[i]; j++) {
            for (int k = 1; k <= size[i]; k++) {
                if (j == k) continue;
                movable[i][j][++movable[i][j][0]] = i * 100 + k;
            }
            if (i <= 6) {
                for (int k = 1; k <= 6; k++) {
                    if (k == i) continue;
                    if (size[k] >= j) movable[i][j][++movable[i][j][0]] = k * 100 + j;
                    if (j + (k - i) >= 1) movable[i][j][++movable[i][j][0]] = k * 100 + j + (k - i);
                }
                for (int k = 7; k <= 11; k++) {
                    if (k == i) continue;
                    if (size[k] >= j + (6 - i)) movable[i][j][++movable[i][j][0]] = k * 100 + (j + (6 - i));
                    if (j - (k - 6) >= 1) movable[i][j][++movable[i][j][0]] = k * 100 + (j - (k - 6));
                }
            }
            else {
                for (int k = 1; k <= 6; k++) {
                    if (k == i) continue;
                    if (size[k] >= j + (i - 6)) movable[i][j][++movable[i][j][0]] = k * 100 + (j + (i - 6));
                    if (j - (6 - k) >= 1) movable[i][j][++movable[i][j][0]] = k * 100 + (j - (6 - k));
                }
                for (int k = 7; k <= 11; k++) {
                    if (k == i) continue;
                    if (size[k] >= j) movable[i][j][++movable[i][j][0]] = k * 100 + j;
                    if (j + (i - k) >= 1) movable[i][j][++movable[i][j][0]] = k * 100 + j + (i - k);
                }
            }
        }
    }

    int x1, y1, x2, y2, x3, y3, r = 0;
    scanf("%s %s", buff1, buff2);
    x1 = buff1[0] - 'a' + 1;
    x2 = buff2[0] - 'a' + 1;
    if (buff1[2] != '\0') y1 = (buff1[1] - '0') * 10 + buff1[2] - '0';
    else y1 = buff1[1] - '0';
    if (buff2[2] != '\0') y2 = (buff2[1] - '0') * 10 + buff2[2] - '0';
    else y2 = buff2[1] - '0';
    for (int i = 1; i <= movable[x1][y1][0]; i++) {
        x3 = movable[x1][y1][i] / 100;
        y3 = movable[x1][y1][i] % 100;
        if (x3 == x2 && y3 == y2) continue;
        for (int j = 1; j <= movable[x3][y3][0]; j++) {
            if (movable[x3][y3][j] / 100 == x2 && movable[x3][y3][j] % 100 == y2) {
                r++;
            }
        }
    }
    printf("%d", r);
    return 0;
}