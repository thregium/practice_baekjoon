#include <stdio.h>
#define INF 1012345678

/*
���� : 5���� 5���� �Ͽ� ���� ���̵��� �ҿ� �ð��� �־��� ��, �� ����� ���� �� ����
������ �־��� ��Ĵ�� ���� �� �� ���� ���� ���� ����� ���Ѵ�. �־����� ��� ���� 100 ������ �ڿ����̴�.

�ذ� ��� : ������ �־��� ��Ĵ�� ���ϸ� ��İ��� �ȴ�. ��İ��� ���� �� �� �ະ�� ���� ã����
�װ��� �� ����� ���� �� ���� �ȴ�. �� ���� �ּڰ��� ����� �� �� ã���� �ȴ�.

�ֿ� �˰����� : ����, ���������, ����

��ó : �߾Ӵ� 2019N G��
*/

char* name[] = { "Inseo", "Junsuk", "Jungwoo", "Jinwoo", "Youngki" };
int a[5][5], b[5][5], c[5][5], w[5];

int main(void) {
    int r = INF, rn = -1;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            scanf("%d", &b[i][j]);
        }
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
            w[i] += c[i][j];
        }
    }
    for (int i = 0; i < 5; i++) {
        if (w[i] <= r) {
            r = w[i];
            rn = i;
        }
    }
    if (rn < 0) return 1;
    printf("%s", name[rn]);
    return 0;
}