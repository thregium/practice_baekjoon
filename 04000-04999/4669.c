#include <stdio.h>

/*
���� : R * C(R, C <= 10) ũ���� ���ڿ� 'N', 'E', 'S', 'W' �� �ϳ��� �� ĭ�� �����ִ�. �������� ���ʿ��� Y��° ĭ�� ������ ��,
������ �Ǵ�, �Ǵ� ���� ĭ�� �ݺ��ؼ� �̵��ϰ� �Ǵ� �̵� Ƚ���� ���Ѵ�.
�� ĭ�� ������ �� ���� ĭ�� ���� �������� �̵��Ѵ�.

�ذ� ��� : �� ĭ�� ó�� ���� ������ ǥ���ϰ�, �� ĭ�� ���� �� ���� ĭ�� ���� ������ ���� Ȯ���Ѵ�.
ĭ ������ �����ٸ� ������ ���� ���̴�. ��, �̹� ���� ĭ�� �ٽ� ���Դٸ� ��� �ݺ��ϴ� ���̴�.
�� �ܿ��� ��� �־��� ������ �̵��ϸ� �ȴ�.

�ֿ� �˰��� : ����, �ùķ��̼�

��ó : MidC 1999 F��
*/

char grid[16][16];
int step[16][16];

int main(void) {
    int r, c, x, y, time;
    while (1) {
        scanf("%d %d %d", &r, &c, &y);
        if (r == 0) break;
        y--;
        x = 0;
        for (int i = 0; i < r; i++) {
            scanf("%s", grid[i]);
            for (int j = 0; j < c; j++) step[i][j] = -1;
        }
        time = 0;
        while (x >= 0 && x < r && y >= 0 && y < c) {
            if (step[x][y] >= 0) {
                printf("%d step(s) before a loop of %d step(s)\n", step[x][y], time - step[x][y]);
                time = -1;
                break;
            }
            step[x][y] = time;
            if (grid[x][y] == 'N') x--;
            else if (grid[x][y] == 'E') y++;
            else if (grid[x][y] == 'S') x++;
            else if (grid[x][y] == 'W') y--;
            else return 1;
            time++;
        }
        if (time >= 0) printf("%d step(s) to exit\n", time);
    }
    return 0;
}