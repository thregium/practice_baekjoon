#include <stdio.h>

/*
���� : R * C(R, C <= 400) ũ���� �迭�� '.', 'o', '<', '>', '^', 'v'�� ���� ���ڰ� �ִ�. �̶�, �� �迭����
���η� �����ؼ� ">o<" �Ǵ� ���η� �����ؼ� "vo^"�� �ִ� �κ��� ������ ���Ѵ�.

�ذ� ��� : �迭 ��ü�� ���Ǹ鼭 �׷��� �κ��� ������ ã���� �ȴ�. �迭 ������ �Ѿ� Ž���ϴ� ��� �ʱ�ȭ�� �����Ѵ�.

�ֿ� �˰��� : ����, ���Ʈ ����

��ó : IPSC 2012 A��
*/

char candy[512][512];

int main(void) {
    int t, r, c, res = 0;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d", &r, &c);
        res = 0;
        for (int i = 0; i < r; i++) {
            scanf("%s", candy[i]);
        }
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c - 2; j++) {
                if (candy[i][j] == '>' && candy[i][j + 1] == 'o' && candy[i][j + 2] == '<') res++;
            }
        }
        for (int i = 0; i < c; i++) {
            for (int j = 0; j < r - 2; j++) {
                if (candy[j][i] == 'v' && candy[j + 1][i] == 'o' && candy[j + 2][i] == '^') res++;
            }
        }
        printf("%d\n", res);
    }
    return 0;
}