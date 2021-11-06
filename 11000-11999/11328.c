#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
���� : ���� 1000 ������ �� ���ڿ��� �־��� ��, ù ��° ���ڿ��� ��迭�Ͽ� �� ��° ���ڿ��� ���� �� �ִ��� Ȯ���Ѵ�.

�ذ� ��� : �� ���ڿ��� �� ���� ������ ������ ���� �� ���ڿ��� ������ ���캸�� �ȴ�.
���� �� ���ڿ��� ���ٸ� �����ϴ� ��� ������ ������ ���ٴ� �ǹ��̹Ƿ� ��迭�� �����ϰ�, �ٸ��ٸ�
������ �ٸ� ���ڰ� �����Ƿ� ��迭�� �Ұ����ϴ�.

�ֿ� �˰��� : ���ڿ�, ����

��ó : Calgary 2014 E��
*/

char s1[1024], s2[1024];

int cmp1(const void* a, const void* b) {
    char ai = *(char*)a;
    char bi = *(char*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s %s", s1, s2);
        qsort(s1, strlen(s1), sizeof(char), cmp1);
        qsort(s2, strlen(s2), sizeof(char), cmp1);
        if (strcmp(s1, s2)) printf("Impossible\n");
        else printf("Possible\n");
    }
    return 0;
}