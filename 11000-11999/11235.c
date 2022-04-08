#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
���� : N(N <= 1000)���� ����� �ĺ��ڿ��� ��ǥ�ߴ�. ���� ���� ��ǥ�� ����� ����Ѵ�.
������ ��� ���������� ��� ����Ѵ�. ��ǥ�� ����� �̸��� 20�� ������ �빮�ڷ� �̷���� �ִ�.

�ذ� ��� : �� ��ǥ�� ���������� ������ ����, �� ��ǥ�� ����� ���������� �ߺ� Ƚ���� ���� �����ϰ�,
�� �� �ߺ� Ƚ���� ���� ���� ����� ���� ������� �ٽ� ���ʷ� ����ϸ� �ȴ�.

�ֿ� �˰��� : ���ڿ�, ����

��ó : SEUSA 2014D2 F��
*/

typedef struct cand {
    char name[32];
    int cnt;
} cand;

char vote[1024][32];
cand cd[1024];

int main(void) {
    int n, cp = 0, best = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", vote[i]);
    }
    qsort(vote, n, sizeof(char) * 32, strcmp);
    for (int i = 0; i < n; i++) {
        if (i == 0 || strcmp(vote[i], vote[i - 1])) {
            cd[cp].cnt = 1;
            strcpy(cd[cp++].name, vote[i]);
        }
        else cd[cp - 1].cnt++;
    }
    for (int i = 0; i < cp; i++) {
        if (cd[i].cnt > best) best = cd[i].cnt;
    }
    for (int i = 0; i < cp; i++) {
        if (cd[i].cnt == best) {
            printf("%s\n", cd[i].name);
        }
    }
    return 0;
}