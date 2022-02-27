#include <stdio.h>

/*
���� : N(N <= 10000)���� �ֻ��� �� �鿡 ���� ������ �־�����, ��� �ֻ����� �׾Ƽ� ���� �� �ִ�
�ո��� �� �� ���� ū ���� ���Ѵ�. ��, ���Ʒ��� ������ �ֻ����� �Ʒ� �ֻ����� �����
�� �ֻ����� �Ʒ��鿡 ���� ���� ���ƾ� �Ѵ�. �� �ֻ����� 1���� 6������ ���� 1������ ���� �ִ�.

�ذ� ��� : �� �� �ֻ����� �����ϸ� ������ �ֻ����� �״� ����� ���Ʒ��� �����̹Ƿ�
�¿�� ������ 4���� ���ۿ� ����. ������ �ֻ������� �� �� �ո��� ���� ũ�� �ϴ� ������ ���,
�� �� �ֻ����� 6���� ��� �� ���� �������� Ȯ���ϸ� �ȴ�.

�ֿ� �˰��� : ����, �׸���, ���Ʈ ����

��ó : ���� 2003 ��2�� // IIPC 2005 C��
*/

int dice[10240][6];

int big(int a, int b) {
    return a > b ? a : b;
}

int getfront(int n, int x) {
    if (x == 0 || x == 5) return big(big(dice[n][1], dice[n][2]), big(dice[n][3], dice[n][4]));
    else if(x == 1 || x == 3) return big(big(dice[n][0], dice[n][2]), big(dice[n][4], dice[n][5]));
    else return big(big(dice[n][0], dice[n][1]), big(dice[n][3], dice[n][5]));
}

int gettop(int n, int x) {
    if (x == 0) return dice[n][5];
    else if (x == 1) return dice[n][3];
    else if (x == 2) return dice[n][4];
    else if (x == 3) return dice[n][1];
    else if (x == 4) return dice[n][2];
    else return dice[n][0];
}

int main(void) {
    int n, c, l, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 6; j++) {
            scanf("%d", &dice[i][j]);
        }
    }
    for (int i = 0; i < 6; i++) {
        l = dice[0][i];
        c = getfront(0, i);
        for (int j = 1; j < n; j++) {
            for (int k = 0; k < 6; k++) {
                if (dice[j][k] == l) {
                    c += getfront(j, k);
                    l = gettop(j, k);
                    break;
                }
            }
        }
        r = big(r, c);
    }
    printf("%d", r);
    return 0;
}