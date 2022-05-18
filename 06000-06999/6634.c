#include <stdio.h>

/*
���� : ���� �ð��� �־��� ��, �̸� ������ ���ڷ� ����Ѵ�.

�ذ� ��� : �� �ڸ��� ��ó���� ���� �����ϰ� �׸� �̿��� ���ϴ� ������ ����ϸ� �ȴ�.

�ֿ� �˰��� : ����, ��ó��

��ó : CTU 2009 D��
*/

const char* line[6] = { "    +", "+   +", "+---+", "|    ", "    |", "|   |" };
const int digit[10][7] = { {2, 5, 5, 1, 5, 5, 2}, {0, 4, 4, 0, 4, 4, 0}, {2, 4, 4, 2, 3, 3, 2},
    {2, 4, 4, 2, 4, 4, 2}, {1, 5, 5, 2, 4, 4, 0}, {2, 3, 3, 2, 4, 4, 2}, {2, 3, 3, 2, 5, 5, 2},
    {2, 4, 4, 0, 4, 4, 0}, {2, 5, 5, 2, 5, 5, 2}, {2, 5, 5, 2, 4, 4, 2} };
char s[16], res[16][64];

void printres(int x, int p) {
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 5; j++) res[i][p + j] = line[digit[x][i]][j];
    }
}

int main(void) {
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 24; j++) res[i][j] = ' ';
    }
    res[2][14] = 'o';
    res[4][14] = 'o';
    while (1) {
        scanf("%s", s);
        if (s[0] == 'e') {
            printf("end\n");
            break;
        }
        printres(s[0] - '0', 0);
        printres(s[1] - '0', 7);
        printres(s[3] - '0', 17);
        printres(s[4] - '0', 24);
        for (int i = 0; i < 7; i++) printf("%s\n", res[i]);
        printf("\n\n");
    }
    return 0;
}