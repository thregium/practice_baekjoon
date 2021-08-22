#include <stdio.h>

/*
���� : N(N <= 123)���� ������ �÷����ִ� �ϳ��� ž�� �ִ�. �Ϲ����� �ϳ��� ž�� ��Ģ���� ���� ���� ���� ū ������
�ö� �� �ִٸ� �� ž�� ���ʿ� �ִ� ��� ���ǵ��� ���������� �ű�� ����� ���Ѵ�.
��, �־����� ó�� ���� ���� ���� ���� ���� ū ������ �ö� ������ �� �ִ�. ����, �ű�� Ƚ���� �ִ� 12345ȸ������ �����ϴ�.

�ذ� ��� : ù ��° �Ǵ� �� ��° ž�� ���� ���ǵ� ��� �� ��° ž�� �ö� ���ǵ��� �� ��° ���ǿ� �ű��,
������ ���ǵ��� �ݴ������� �ű��. �̸� �ݺ��Ͽ� ��� ���ǵ��� ����� �ȴ�. ���ƾ� N^2 / 2ȸ �ȿ� �ű� �� �ֱ� ������
12345ȸ �̳��� ����� �ű�� ���� �����ϴ�.

�ֿ� �˰��� : �׸��� �˰���, ����, ������
*/

int tower[3][128], move[16384][2];

int main(void) {
    int n, turn = 0, ntow = 0;
    scanf("%d", &n);
    tower[0][0] = n;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &tower[0][i]);
    }
    while (tower[2][0] < n) {
        for (int i = tower[ntow][0]; i > 0; i--) {
            move[turn][0] = ntow + 1;
            if (tower[ntow][i] == n - tower[2][0]) {
                move[turn++][1] = 3;
                tower[2][++tower[2][0]] = tower[ntow][i];
            }
            else {
                move[turn++][1] = (!ntow) + 1;
                tower[!ntow][++tower[!ntow][0]] = tower[ntow][i];
            }
            tower[ntow][i] = 0;
            tower[ntow][0]--;
        }
        ntow = !ntow;
    }
    if (turn > 12345) return 1;
    printf("%d\n", turn);
    for (int i = 0; i < turn; i++) {
        printf("%d %d\n", move[i][0], move[i][1]);
    }
    return 0;
}