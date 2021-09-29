#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
���� : 10^9 ������ �ڿ��� N�� 2������ ǥ���� ���ڿ��� 3������ ǥ���� ���ڿ����� ���� 1�ھ� �߸��� ���ڿ����� �־�����.
�̶�, N�� �����ϴٸ� ���� �� �ִ� N�� ���Ѵ�.

�ذ� ��� : �� ���ڿ����� 1�ھ� �ٸ��� ǥ���� ���ڿ����� ���� �� �ִ� N�� �ĺ����� ���� �����Ѵ�.
�� ��, �ĺ��� ��� 2�� ��Ÿ���� ���� ã���� ���� �ȴ�.

�ֿ� �˰��� : ���Ʈ ����, ����, ���ڿ�

��ó : USACO 2011N B2��
*/

char base2[64], base3[64], temp[64];
long long cand[1024];

int cmp1(const void* a, const void* b) {
    long long ai = *(long long*)a;
    long long bi = *(long long*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    long long t, p = 0;
    scanf("%s%s", base2, base3);
    strcpy(temp, base2);
    for (int i = 0; temp[i]; i++) {
        for (char j = '0'; j <= '1'; j++) {
            if (base2[i] == j || (i == 0 && j == '0')) continue;
            temp[i] = j;
            cand[p++] = strtoll(temp, NULL, 2);
        }
        temp[i] = base2[i];
    }

    strcpy(temp, base3);
    for (int i = 0; temp[i]; i++) {
        for (char j = '0'; j <= '2'; j++) {
            if (base3[i] == j || (i == 0 && j == '0')) continue;
            temp[i] = j;
            cand[p++] = strtoll(temp, NULL, 3);
        }
        temp[i] = base3[i];
    }

    qsort(cand, p, sizeof(long long), cmp1);
    for (int i = 1; i < p; i++) {
        if (cand[i] == cand[i - 1]) {
            printf("%lld", cand[i]);
            return 0;
        }
    }
    return 1;
}