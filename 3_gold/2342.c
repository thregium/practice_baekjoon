#include <stdio.h>
#define INF 1234567890

/*
���� : DDR���� �� Ÿ�ϵ��� ��ƾ� �� ��ġ�� �־��� �� �ּ������� ��� �������� ���� ���Ѵ�. ���� Ÿ���� �������� ������ 1, �߾ӿ��� �ٱ� Ÿ�Ϸ� ���� �̵��ϸ� 2,
������ �ٱ� Ÿ�ϳ��� �̵��ϸ� 3, �ݴ� Ÿ�Ϸ� �̵��ϸ� 4��ŭ�� �������� �Ҹ��Ѵ�.

�ذ� ��� : ����� ��ġ���� ���� Ÿ���� ������ �ּ� �������� �����Ѵ�. ��ƾ� �� Ÿ���� ��ġ�� �־����� ���� Ÿ�ϱ��� ���� ��ġ���� ���� Ÿ�Ϸ� �ű�µ� ��� ��������
���ذ��� ���� Ÿ�ϱ��� ����� ���� �ּ� ������ ��� �ּڰ��� �����Ѵ�. ������ �Ϸ��ϸ� ������ Ÿ�ϱ��� ����� ���� ��� ���� ��ġ ��� �ּ� �������� ����Ѵ�.

�ֿ� �˰��� : ���̳��� ���α׷���
*/

int move[103000], mem[5][5][103000];

int small(int a, int b) {
    return a < b ? a : b;
}

int nrg(int a, int b) {
    if (a == b) return 1;
    if (a == 0 || b == 0) return 2;
    if (a - b == 2 || b - a == 2) return 4;
    return 3;
}

int main(void) {
    int n = 1, res = INF;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 102400; k++) mem[i][j][k] = INF;
        }
    }
    mem[0][0][0] = 0;
    while (1) {
        scanf("%d", &move[n]);

        if (move[n] == 0) {
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    res = small(res, mem[i][j][n - 1]);
                }
            }
            break;
        }

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                mem[i][move[n]][n] = small(mem[i][move[n]][n], mem[i][j][n - 1] + nrg(j, move[n]));
                mem[move[n]][j][n] = small(mem[move[n]][j][n], mem[i][j][n - 1] + nrg(i, move[n]));
            }
        }
        n++;
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            res = small(res, mem[i][j][n - 1]);
        }
    }
    printf("%d", res);
    return 0;
}