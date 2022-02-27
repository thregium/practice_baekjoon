#include <stdio.h>

/*
���� : ��Ʋ�� ���� ���� 500 ������ �̵� ���(����, ����, ��ȸ��, ��ȸ��)�� �־��� ��,
��Ʋ�� ������ ������ �ѷ��ΰ� �࿡ ������ ���� ���� ���簢���� ���̸� ���Ѵ�.
������ ���� �Ǵ� ���� ��� ���� 0�̴�.

�ذ� ��� : ��Ʋ�� (0, 0)�� ���� �������� �ùķ��̼��ϸ鼭 X�� Y��ǥ�� ���� �ּڰ��� �ִ��� ���ϰ�
�� ���� �ִ� - �ּڰ��� ���� ���ϸ� �ȴ�.

�ֿ� �˰��� : ����, �ùķ��̼�

��ó : Daejeon 2011 L��
*/

char s[512];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

int main(void) {
    int t, x, y, d, xl, yl, xh, yh;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%s", s);
        x = 0, y = 0, d = 0, xl = 0, yl = 0, xh = 0, yh = 0;
        for (int i = 0; s[i]; i++) {
            if (s[i] == 'F') {
                x += dxy[d][0];
                y += dxy[d][1];
            }
            else if (s[i] == 'B') {
                x -= dxy[d][0];
                y -= dxy[d][1];
            }
            else if (s[i] == 'L') d = ((d + 1) & 3);
            else if (s[i] == 'R') d = ((d + 3) & 3);
            else return 1;

            if (x < xl) xl = x;
            if (x > xh) xh = x;
            if (y < yl) yl = y;
            if (y > yh) yh = y;
        }
        printf("%d\n", (xh - xl) * (yh - yl));
    }
    return 0;
}