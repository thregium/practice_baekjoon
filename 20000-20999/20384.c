#include <stdio.h>

/*
���� : ��Ʈ���� ȭ�� 3���� ��Ȯ�� N���� ����� ����� ���� ���Ѵ�. ȭ�� �ϳ� �� 1 ~ 20�� ������ �ڿ����� 1, 2, 3��
�� ���� �� �ϳ� �Ǵ� 50���� ���� �� �ִ�. �ٸ� ��ġ�� ȭ���� ��Ҵ��� ���� ��ġ�� ���ٸ� ���� ����̴�.
������ ������ ��� ���Ѵ�.

�ذ� ��� : ȭ���� ���� ���� �� �ִ� �������� ���� ���� �� ��� ���� ���տ� ���� N���� �������� Ȯ���غ���
N���� ������ ��� ��츦 ���� �ȴ�.

�ֿ� �˰��� : ����, ���Ʈ ����

��ó : MidC 1993 2��
*/

int scores[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
21, 22, 24, 26, 27, 28, 30, 32, 33, 34, 36, 38, 39, 40, 42, 45, 48, 50, 51, 54, 57, 60 };

int main(void) {
    int n, c, p, example = 0;
    //freopen("E:\\PS\\ICPC\\North America\\Mid Central\\1993\\darts.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\North America\\Mid Central\\1993\\darts_t.out", "w", stdout);
    while (1) {
        scanf("%d", &n);
        if (n <= 0) {
            printf("END OF OUTPUT");
            break;
        }
        if (n == 162) example = 1;
        c = 0, p = 0;
        for (int i = 0; i < 43; i++) {
            for (int j = 0; j < 43; j++) {
                for (int k = 0; k < 43; k++) {
                    if (scores[i] + scores[j] + scores[k] == n) p++;
                }
            }
        }
        for (int i = 0; i < 43; i++) {
            for (int j = i; j < 43; j++) {
                for (int k = j; k < 43; k++) {
                    if (scores[i] + scores[j] + scores[k] == n) c++;
                }
            }
        }

        if (p == 0) printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n", n);
        else {
            printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n", n, c);
            printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n", n, p);
        }
        printf("**********************************************************************\n");
    }
    return 0;
}