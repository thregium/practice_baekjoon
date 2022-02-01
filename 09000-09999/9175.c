#include <stdio.h>

/*
���� : N * N(4 <= N <= 300) ũ���� ü���ǿ� N���� ����
���� ���ݹ��� �ʵ��� ��ġ�ϴ� ��� �� �ϳ��� ���Ѵ�.

�ذ� ��� : N�� 6���� ���� �������� 2�� 3�� �ƴ� ��쿡�� ���� ����(�Ǵ� + 1)�� Ȧ�� ��° ���� �ϳ���,
�Ʒ��� ���ݿ��� ¦�� ��° ���� �ϳ��� ��ġ�ϸ� �ȴ�.
�������� 2�� 3�� ��쿡�� �̸� �����Ͽ� 5���� �� �ڸ��� ���� ��ġ�ϰ� ������ ������ �о�� �������
��ġ�� �� �ִ�. ��, �� ��� 8�̳� 9������ �߸��� ��ġ�� �Ǳ� ������ �� ������ ���� ó���Ѵ�.

�ֿ� �˰��� : ������, ���̽� ��ũ

��ó : PacNW 2005 I��
*/

int res[384];
int prec[9] = { 4, 6, 8, 2, 7, 1, 3, 5, 9 };

int verify(int n) {
    for (int i = 0; i < n; i++) {
        if (res[i] < 0 || res[i] > n) return 0;
        for (int j = i + 1; j < n; j++) {
            if (res[i] == res[j] || i + res[i] == j + res[j] || i - res[i] == j - res[j]) {
                return 0;
            }
        }
    }
    return 1;
}

int main(void) {
    int t, n;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        //n = i;
        if (n % 6 != 2 && n % 6 != 3) {
            for (int j = 0; j < ((n + 1) >> 1); j++) res[j] = j * 2 + 1 + (~n & 1);
            for (int j = 0; j < (n >> 1); j++) res[j + ((n + 1) >> 1)] = j * 2 + 1 + (n & 1);
        }
        else if (n > 9) {
            res[0] = n - 1 - (n & 1);
            for (int i = 0; i < (n >> 1); i++) res[1 + i] = i * 2 + 2;
            res[1]--;
            for (int i = 0; i < (n >> 1) - 1; i++) res[1 + (n >> 1) + i] = i * 2 + 3;
            res[1 + (n >> 1)]--;
            res[n - 1 - (n & 1)] = 3;
            if (n & 1) res[n - 1] = n;
        }
        else {
            for (int j = 0; j < n; j++) res[j] = prec[j];
        }
        //printf("%d: %s\n", i, verify(n) ? "OK" : "NO!");
        printf("%d\n", n);
        for (int j = 0; j < n; j++) {
            printf(" %d", res[j] - 1);
        }
        printf("\n");
    }
    return 0;
}