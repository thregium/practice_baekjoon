#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
���� : ���� N(2 <= N <= 72)�� �ҹ��ڷ� �̷���� ���ڿ��� �־��� ��, �� ���ڿ��� �� �κ����� �ڸ���,
�� ���ڿ��� ���� �����ų� �״���� ���·� ������ �ٲٰų� �״�� �ٿ� ���� �� �ִ� ���ڿ��� �������� ���Ѵ�.

�ذ� ��� : ���� ������ ��� ��ġ���� ���ڿ��� �ڸ� ���� �����ų� �״�� �δ� ���� �ݺ���
���� �� �ִ� ���ڿ��� �������� ����.

�ֿ� �˰��� : ���ڿ�, ���Ʈ ����

��ó : JDC 2006 B��
*/

char train[96], sub1[96], sub2[96], conf[1024][96];

void swapc(char* a, char* b) {
    char c = *a;
    *a = *b;
    *b = c;
}

void revstr(char* s) {
    int l = strlen(s);
    for (int i = 0, j = l - 1; i < j; i++, j--) {
        swapc(&s[i], &s[j]);
    }
}

void confadd(int* c) {
    strcpy(conf[*c], sub1);
    strcat(conf[(*c)++], sub2);
    strcpy(conf[*c], sub2);
    strcat(conf[(*c)++], sub1);
}

int main(void) {
    int t, l, cnt, r;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%s", train);
        cnt = 0;
        l = strlen(train);
        for (int i = 1; i < l; i++) {
            for (int j = 0; j < i; j++) sub1[j] = train[j];
            sub1[i] = '\0';
            strcpy(sub2, train + i);
            confadd(&cnt);
            revstr(sub1);
            confadd(&cnt);
            revstr(sub2);
            confadd(&cnt);
            revstr(sub1);
            confadd(&cnt);
        }

        qsort(conf, cnt, sizeof(char) * 96, strcmp);
        r = 0;
        for (int i = 0; i < cnt; i++) {
            if (i == 0 || strcmp(conf[i], conf[i - 1])) r++;
        }
        printf("%d\n", r);
    }
    return 0;
}