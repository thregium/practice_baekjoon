#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
���� : 100�� ������ �ҹ��ڷ� �̷���� �� ���ڿ��� �־��� ��, �� ���ڿ��� �ֳʱ׷� �������� ���Ѵ�.

�ذ� ��� : �� ���ڿ��� ������ ���� �� ���ڿ��� ���Ѵ�. �� ���ڿ��� ���ٸ� �ֳʱ׷� ������ ���̰�,
���� �ʴٸ� �ֳʱ׷� ���谡 �ƴ� ���̴�.

�ֿ� �˰��� : ����, ���ڿ�, ����

��ó : HSPC 2013 2��
*/

char word1[128], word2[128], st1[128], st2[128];

int cmp1(const void* a, const void* b) {
    char ai = *(char*)a;
    char bi = *(char*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int t;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%s %s", word1, word2);
        strcpy(st1, word1);
        strcpy(st2, word2);
        qsort(st1, strlen(st1), sizeof(char), cmp1);
        qsort(st2, strlen(st2), sizeof(char), cmp1);
        if (strcmp(st1, st2)) printf("%s & %s are NOT anagrams.\n", word1, word2);
        else printf("%s & %s are anagrams.\n", word1, word2);
    }
    return 0;
}