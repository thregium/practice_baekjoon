#include <stdio.h>
#include <math.h>

/*
���� : ü������ ���� ������ ��� ���� �⹰�� ���� ��, ��븦 ���� �� �ִ� �⹰�� �������� ���Ѵ�.

�ذ� ��� : ��밡 �ִ� ��ġ�� �̵� ������ �⹰�̶�� ��븦 ���� �� �ִ�. ��, ��, ����� ���� ���� �ٿ� �ִ��� Ȯ���ϸ� �ǰ�,
ŷ�̳� ����Ʈ�� ���ο� ������ �Ÿ��� Ȯ���� ���� �� �ִ�.

�ֿ� �˰��� : ����, ���̽� ��ũ

��ó : ROI 2007H A��
*/

char white[8], black[8];

int big(int a, int b) {
    return a > b ? a : b;
}

int small(int a, int b) {
    return a < b ? a : b;
}

int main(void) {
    int wx, wy, bx, by, ww = 0, bw = 0;
    scanf("%s%s", white, black);
    wx = white[1] - 'a';
    wy = white[2] - '1';
    bx = black[1] - 'a';
    by = black[2] - '1';
    if (big(abs(wx - bx), abs(wy - by)) <= 1) {
        if (white[0] == 'K') ww = 1;
        if (black[0] == 'K') bw = 1;
    }
    if (wx == bx || wy == by || wx + wy == bx + by || wx - wy == bx - by) {
        if (white[0] == 'Q') ww = 1;
        if (black[0] == 'Q') bw = 1;
    }
    if (wx == bx || wy == by) {
        if (white[0] == 'R') ww = 1;
        if (black[0] == 'R') bw = 1;
    }
    if (wx + wy == bx + by || wx - wy == bx - by) {
        if (white[0] == 'B') ww = 1;
        if (black[0] == 'B') bw = 1;
    }
    if (big(abs(wx - bx), abs(wy - by)) == 2 && small(abs(wx - bx), abs(wy - by)) == 1) {
        if (white[0] == 'N') ww = 1;
        if (black[0] == 'N') bw = 1;
    }
    if (ww && bw) printf("BOTH");
    else if (ww) printf("WHITE");
    else if (bw) printf("BLACK");
    else printf("NONE");
    return 0;
}