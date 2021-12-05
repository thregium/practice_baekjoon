#include <stdio.h>

/*
���� : N(N <= 26)���� ���ڷ� �̷���� ���� S�� ���� #�� �־�����. ���� ���� S�� #�� ǥ�� ����ϰ�,
S�� �ݱ�����, �ݱ��̶�� ��ȯ��Ģ�� �����ϴ��� ���ϰ�, �ݱ��� �ƴ϶�� �������� ������ �Ǵ� ���չ�Ģ�� �������� �ʴ��� ���Ѵ�.

�ذ� ��� : ���� ���� S�� ���� #�� �Է¹��� �� ���հ� ǥ�� ����Ѵ�. �̴� ���� �����Ѵ�.
�� �� S�� ������ Ȯ���Ѵ�. �켱 �������� ���� �������� Ȯ���Ѵ�. S�� ���� ���ڰ� ����� ������ �������� ���� �����̴�.
�׸��� ���չ�Ģ�� �����ϴ��� Ȯ���Ѵ�. �̴� �̸� ����ȯ ���̺��� ���� ������ Ȯ���ϴ� ���� ����.
���չ�Ģ�� �������� ���� ���� �ִٸ� ���� �ݱ��� �ƴϴ�.
���������� ��ȯ��Ģ�� �����ϴ��� Ȯ���Ѵ�. �̶��� ���������� ��쿡 ���� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����, ����

��ó : MidC 1996 F��?
*/

char table[32][32], s[32];
int ref[32];

void printres(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (ref[table[i][j] - 'a'] < 0) {
                printf("NOT A SEMIGROUP: %c#%c = %c  WHICH IS NOT AN ELEMENT OF THE SET\n", s[i], s[j], table[i][j]);
                return;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (table[ref[table[i][j] - 'a']][k] != table[i][ref[table[j][k] - 'a']]) {
                    printf("NOT A SEMIGROUP: (%c#%c)#%c IS NOT EQUAL TO %c#(%c#%c)\n", s[i], s[j], s[k], s[i], s[j], s[k]);
                    return;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (table[i][j] != table[j][i]) {
                printf("SEMIGROUP BUT NOT COMMUTATIVE  (%c#%c IS NOT EQUAL TO %c#%c)\n", s[i], s[j], s[j], s[i]);
                return;
            }
        }
    }
    printf("COMMUTATIVE SEMIGROUP\n");
}

int main(void) {
    int n;
    //freopen("E:\\PS\\ICPC\\North America\\Mid Central\\midc96\\PROBLEM7\\SEMIGRP.IN", "r", stdin);
    //freopen("E:\\PS\\ICPC\\North America\\Mid Central\\midc96\\PROBLEM7\\SEMIGRP_T.OUT", "w", stdout);
    while (1) {
        scanf("%d", &n);
        if (n <= 0) break;
        for (int i = 0; i < 32; i++) ref[i] = -1;
        scanf("%s", s);
        for (int i = 0; i < n; i++) {
            ref[s[i] - 'a'] = i;
            scanf("%s", table[i]);
        }
        printf("S = {");
        for (int i = 0; i < n; i++) {
            if (i > 0) printf(",");
            printf("%c", s[i]);
        }
        printf("}\n #|%s\n -+", s);
        for (int i = 0; i < n; i++) printf("-");
        printf("\n");
        for (int i = 0; i < n; i++) {
            printf(" ");
            printf("%c|", s[i]);
            printf("%s\n", table[i]);
        }
        printf("\n");
        printres(n);
        printf("------------------------------\n\n");
    }
    return 0;
}