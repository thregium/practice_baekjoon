#include <stdio.h>

/*
���� : 8 * 8 ũ�� ü���ǿ��� ������ ���� ��ġ�� �־��� ��, �̰��� 8-Queen ������ �� �� �ϳ����� ���Ѵ�.

�ذ� ��� : ü���ǿ��� �� ���鿡 ���� �ٽ� ü������ �� ĭ�� �縮�� �ٸ� ���� �����޴� ��ġ�� �ִ��� Ȯ���Ѵ�.
�׷��� ��찡 �ִٸ� 8-Queen ������ ���� �� �� ����. �׷��� ��찡 ���ٸ� ���� 8������ Ȯ���ϰ�,
8���� �´ٸ� 8-Queen ������ �ش��̶�� �� �� �ִ�.

�ֿ� �˰��� : ����

��ó : NAQ 2014 A / 2020 C��
*/

char qn[16][16];

int main(void) {
    int r = 1, c = 0;
    for (int i = 0; i < 8; i++) {
        scanf("%s", qn[i]);
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (qn[i][j] != '*') continue;
            c++;
            for (int k = 0; k < 8; k++) {
                for (int l = 0; l < 8; l++) {
                    if (i == k && j == l) continue;
                    if (qn[k][l] != '*') continue;
                    if (i == k || j == l || i + j == k + l || i - j == k - l) r = 0;
                }
            }
        }
    }
    if (c != 8) r = 0;
    printf("%s", r ? "valid" : "invalid");
    return 0;
}