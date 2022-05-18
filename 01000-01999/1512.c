#include <stdio.h>

/*
���� : ���� 3000 ������ DNA ���ڿ��� �־��� ��, �� ���ڿ��� �ֱ� M ������ �ֱ⹮���� �ٲٱ� ����
�ٲ�� �ϴ� ������ ������ ���Ѵ�.

�ذ� ��� : �� ������ �ֱ⹮���� ����� Ƚ���� ��� Ȯ���� ���� �� �� �ּڰ��� ���Ѵ�.
�ֱ⹮���� ����� Ƚ���� �� ��°�� ���ڸ��� ������ �� ����,
�� �� ���� ���� ���� �ƴ� ���� ������ ��� ���ϸ� �ּҰ� �ȴ�.

�ֿ� �˰��� : ���ڿ�, ���Ʈ ����, �׸��� �˰���

��ó : SRM 396D1 1�� // 396D2 2��
*/

char s[3072];
int cnt[3072][4];

int dnatoint(char c) {
    if (c == 'A') return 0;
    else if (c == 'C') return 1;
    else if (c == 'G') return 2;
    else if (c == 'T') return 3;
    else return -1;
}

int main(void) {
    int m, res = 103000, tres, hi, sum;
    scanf("%d", &m);
    scanf("%s", s);
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < i; j++) {
            for (int k = 0; k < 4; k++) cnt[j][k] = 0;
        }
        for (int j = 0; s[j]; j++) {
            cnt[j % i][dnatoint(s[j])]++;
        }
        tres = 0;
        for (int j = 0; j < i; j++) {
            hi = 0, sum = 0;
            for (int k = 0; k < 4; k++) {
                sum += cnt[j][k];
                if (cnt[j][k] > hi) hi = cnt[j][k];
            }
            tres += sum - hi;
        }
        if (tres < res) res = tres;
    }
    printf("%d", res);
    if (res == 103000) return 1;
    return 0;
}