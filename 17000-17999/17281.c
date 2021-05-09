#include <stdio.h>

/*
���� : �߱����� �� �������� �̴�(N <= 50)���� ��� ����� �̸� ������ �ִٰ� �����Ѵ�.
�̶�, 4�� Ÿ�ڴ� �ݵ�� ù ��° ������ �Ѵٸ� ������ �������� Ÿ���� ������ ���� ���� ������ �� ���� ������ ���Ѵ�.
��, �� �̴׺��� �ƿ��� ����ϴ� Ÿ�ڰ� �Ѹ��� �����ϰ� ��Ÿ �̻��� ����� ���� ��� ��� ���ڴ� �����ϰ� �����Ѵٰ� �����Ѵ�.

�ذ� ��� : ���Ʈ ������ ���� ��� Ÿ���� �����غ���. �� ��쿡�� ��� ������ Ȯ���� ������
���� Ÿ�ڿ� ������ ��, �ƿ� Ƚ���� ������ �ΰ� ���� ������ ���󰡸� �ȴ�.
�ƿ� ī��Ʈ�� 3 ������ ���� ��� Ÿ�ڸ� ����� ���� �ݺ��Ѵ�. �ƿ��� ��� �ƿ� ī��Ʈ�� �ø���, ��Ÿ �̻��� ��쿡�� 
�� ���ڵ��� �����Ų ���� Ȩ�� ������ ���ڵ��� ��� ������ �����ָ� �ȴ�. ��, �� Ÿ���� ������ ������ ���� Ÿ�ڸ� ����� �͵� ���� ���ƾ� �Ѵ�.

�ֿ� �˰��� : ����, ���Ʈ ����
*/

int inning[64][16], sel[9], chk[9] = { 1, 0 };
int n, highscore = 0;

int getscore(void) {
    int score = 0, out = 0, player = 0, bases[8] = { 0, };
    for (int i = 0; i < n; i++) {
        out = 0;
        for (int j = 0; j < 8; j++) bases[j] = 0;
        while (out < 3) {
            bases[0] = 1;
            switch (inning[i][sel[player]]) {
            case 0:
                out++;
                break;
            case 1:
            case 2:
            case 3:
            case 4:
                for (int j = 3 + inning[i][sel[player]]; j >= inning[i][sel[player]]; j--) {
                    bases[j] = bases[j - inning[i][sel[player]]];
                }
                for (int j = inning[i][sel[player]] - 1; j > 0; j--) bases[j] = 0;
                break;
            }
            for (int j = 4; j < 8; j++) {
                score += bases[j];
                bases[j] = 0;
            }
            player = (player + 1) % 9;
        }
    }
    return score;
}

void track(int n, int r) {
    if (n == r) {
        int score = getscore();
        if (score > highscore) {
            highscore = score;
        }
        return;
    }

    if (r == 3) {
        sel[r] = 0;
        track(n, r + 1);
        return;
    }

    for (int i = 1; i < n; i++) {
        if (chk[i]) continue;
        chk[i] = 1;
        sel[r] = i;
        track(n, r + 1);
        chk[i] = 0;
    }
}

int main(void) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 9; j++) {
            scanf("%d", &inning[i][j]);
        }
    }
    track(9, 0);
    printf("%d", highscore);
    return 0;
}