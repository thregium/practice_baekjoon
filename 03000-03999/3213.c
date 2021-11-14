#include <stdio.h>
#include <string.h>

/*
���� : N(N <= 10000)���� 1/4 ������ �� �������� �־��� ��, ������ ��ġ�� �ʰ� �־��� ��� ���� �ϱ� ���� ��ü�� ���� ���Ѵ�.

�ذ� ��� : ū �������� ä��������. �� ���� �ʿ��� ��ü�� ���� ���ϸ� �ȴ�.

�ֿ� �˰��� : �׸��� �˰���

��ó : CHCI 2004N1S 1��
*/

char buff[8];
int cnt[4];

int main(void) {
    int n, r = 0, c;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", buff);
        if (!strcmp(buff, "1/4")) cnt[1]++;
        else if (!strcmp(buff, "1/2")) cnt[2]++;
        else if (!strcmp(buff, "3/4")) cnt[3]++;
        else return 1;
    }
    while (cnt[1] + cnt[2] + cnt[3] > 0) {
        c = 0;
        if (cnt[3]) {
            cnt[3]--;
            c += 3;
        }
        while (c <= 2 && cnt[2] > 0) {
            cnt[2]--;
            c += 2;
        }
        while (c <= 3 && cnt[1] > 0) {
            cnt[1]--;
            c++;
        }
        r++;
    }
    printf("%d", r);
    return 0;
}