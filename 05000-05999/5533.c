#include <stdio.h>

/*
���� : N(N <= 200)���� ������� 100 ������ �ڿ����� ���� ����. �� ����� �� ���� �ڿ����� ���� ����� ���ٸ�
���� �ڿ����� ���� ������ ��´�. �̸� 3�� �ϸ� ���� �ڿ������� �־��� ��, �� ������� ������ ���Ѵ�.

�ذ� ��� : �� ������� ���� ������ �Է¹��� ����, �� ���ӿ��� �����ڸ��� �ڽŰ� ���� �ڿ����� ���� ����� �ִ����� Ȯ���Ѵ�.
�׷��� ��찡 ���ٸ� �� ����� ������ �� �����ڰ� ���� ���� �߰��Ѵ�. �̸� 3�� �ݺ��� ����,
�� �������� ������ ����ϸ� �ȴ�.

�ֿ� �˰����� : ���Ʈ ����, ����

��ó : JOI 2013�� 2��
*/

int num[3][256], score[256];

int main(void) {
    int n, t;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &num[0][i], &num[1][i], &num[2][i]);
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            t = 1;
            for (int k = 0; k < n; k++) {
                if (j == k) continue;
                if (num[i][j] == num[i][k]) {
                    t = 0;
                    break;
                }
            }
            score[j] += t * num[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d\n", score[i]);
    }
    return 0;
}