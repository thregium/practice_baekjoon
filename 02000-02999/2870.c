#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
���� : 100�� ������ �ҹ��ڿ� ���ڷ� �̷���� ���ڿ� N(N <= 100)���� �־��� ��,
��� ���ڿ��� ������ ������ ������������ ������ ����� ����Ѵ�.

�ذ� ��� : ���ڿ����� ���ڰ� ������ ���� ������ �� ���ڿ��� �ش� ������ �����Ѵ�.
�̶�, 0�� �������� �ʱ� ���� ���� ������ �ξ�� �Ѵ�.
���簡 �������� ������ �Ѵ�. ����(��������)-> ������ ���� �����ϸ� �ȴ�.

�ֿ� �˰��� : ���ڿ�, �Ľ�, ����

��ó : COCI 10/11#2 2��
*/

char s[128][128], num[10240][128];

int cmp1(const void* a, const void* b) {
    int ai = strlen((char*)a);
    int bi = strlen((char*)b);
    if (ai != bi) return ai > bi ? 1 : -1;
    else return strcmp(a, b);
}

int main(void) {
    int n, p = 0, pp, ns;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; s[i][j]; j++) {
            if (isdigit(s[i][j])) {
                pp = 0, ns = 0;
                while (isdigit(s[i][j])) {
                    if (ns > 0 || s[i][j] != '0') {
                        ns = 1;
                        num[p][pp++] = s[i][j];
                    }
                    j++;
                }
                if (strlen(num[p]) == 0) strcpy(num[p], "0");
                p++;
            }
        }
    }
    qsort(num, p, sizeof(char) * 128, cmp1);
    for (int i = 0; i < p; i++) {
        printf("%s\n", num[i]);
    }
    return 0;
}