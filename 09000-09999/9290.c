#include <stdio.h>

/*
���� : ƽ���信�� �� ���� �� �θ� �̱� �� �ִ� ���� �־��� ��, �� ���� �� �� ����� ����Ѵ�.
��, ���� �����ϰ� ��������.

�ذ� ��� : 9ĭ ��� �� ĭ�� ���� ���ƺ� ���� �̱� �� �ִ� ���� ã���� �ȴ�.

�ֿ� �˰��� : ����, ���Ʈ ����

��ó : UVaH 2013 E��
*/

char ttt[4][4];
int r = 0;

void printttt(int tt) {
    printf("Case %d:\n", tt);
    for (int i = 0; i < 3; i++) {
        printf("%s\n", ttt[i]);
    }
    r++;
}

int main(void) {
    int t, n;
    char c;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        for (int i = 0; i < 3; i++) {
            scanf("%s", ttt[i]);
        }
        scanf(" %c", &c);
        r = 0;
        for (int i = 0; i < 9; i++) {
            if (ttt[i / 3][i % 3] != '-') continue;
            ttt[i / 3][i % 3] = c;
            for (int j = 0; j < 3; j++) {
                if (ttt[j][0] == c && ttt[j][1] == c && ttt[j][2] == c) printttt(tt);
                if (ttt[0][j] == c && ttt[1][j] == c && ttt[2][j] == c) printttt(tt);
            }
            if (ttt[0][0] == c && ttt[1][1] == c && ttt[2][2] == c) printttt(tt);
            if (ttt[0][2] == c && ttt[1][1] == c && ttt[2][0] == c) printttt(tt);
            ttt[i / 3][i % 3] = '-';
        }
        if (r != 1) return 1;
    }
    return 0;
}