#include <stdio.h>
#include <ctype.h>

/*
���� : N(N <= 36)�� �־�����, N �̸��� �ڿ��� N * N���� 36�������� �־�����. �̶�, �� �ڿ������� ���γ� ���η� ��ġ�� �ʴ��� Ȯ���ϰ�,
��ġ�� �ʴ´ٸ�, �ٽ� �� ����/������ ���ĵ� �������� ���Ѵ�.

�ذ� ��� : �� ������ ���� ���� ���Ѵ�. ��ġ�� ���� �������� ī���� �迭�� ����ϸ� �ǰ�,
���ĵ� ���������� 2��° ������ ������� �̵��ϸ� ���� ������ ���� ������ Ȯ���ϸ� �ȴ�.

�ֿ� �˰��� : ����

��ó : PacNW 2017 O��
*/

int sqr[64][64], cnt[64];

int main(void) {
    int n, r = 1;
    char c;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf(" %c", &c);
            if (isdigit(c)) sqr[i][j] = c - '0';
            else if (isupper(c)) sqr[i][j] = c - 'A' + 10;
            else return 0;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cnt[j] = 0;
        for (int j = 0; j < n; j++) {
            cnt[sqr[i][j]]++;
            if (cnt[sqr[i][j]] > 1) r = 0;
        }
        for (int j = 0; j < n; j++) cnt[j] = 0;
        for (int j = 0; j < n; j++) {
            cnt[sqr[j][i]]++;
            if (cnt[sqr[j][i]] > 1) r = 0;
        }
    }
    if (!r) {
        printf("No");
    }
    else {
        for (int i = 1; i < n; i++) {
            if (sqr[0][i] <= sqr[0][i - 1] || sqr[i][0] <= sqr[i - 1][0]) r = 0;
        }
        if (r) printf("Reduced");
        else printf("Not Reduced");
    }
    return 0;
}