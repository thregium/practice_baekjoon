#include <stdio.h>

/*
���� : 6���� ���ﰢ���� �� ���� ���� ������ �־�����. �� �ﰢ������ �ٿ��� �������� �����,
���ʿ� �ִ� ������ ������ ������ ���� ������ �ϰ�, �ٱ��� ������ ���� ���� ũ�� ����ٸ� ���� ū ���� ���Ѵ�.
�Ұ����ϴٸ� none�� ����Ѵ�.

�ذ� ��� : �� �ﰢ������ ���� �������� ������ ���� ��� ���� ���� ���� ū ���� ���ϸ� �ȴ�.

�ֿ� �˰��� : ���Ʈ ����, ��Ʈ��ŷ

��ó : Benin 2016 G��
*/

int tri[6][3], hex[6][3], chk[6];
int best = -1;

void track(int x) {
    if (x == 6) {
        int sum = 0;
        for (int i = 0; i < 6; i++) sum += hex[i][2];
        if (hex[5][0] != hex[0][1]) return;
        if (sum > best) best = sum;
        return;
    }
    for (int i = 0; i < 6; i++) {
        if (chk[i]) continue;
        chk[i] = 1;
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) hex[x][k] = tri[i][(k + j) % 3];
            if (x == 0 || hex[x][1] == hex[x - 1][0]) track(x + 1);
        }
        chk[i] = 0;
    }
}

int main(void) {
    char c;
    while (1) {
        for (int i = 0; i < 6; i++) {
            scanf("%d %d %d", &tri[i][0], &tri[i][1], &tri[i][2]);
        }
        best = -1;
        track(0);
        if (best < 0) printf("none\n");
        else printf("%d\n", best);
        scanf(" %c", &c);
        if (c == '$') break;
    }
    return 0;
}