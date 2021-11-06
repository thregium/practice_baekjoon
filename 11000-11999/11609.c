#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
���� : N(N <= 100)���� ���� �̸��� �־��� ��, �� -> �̸� ������ �����Ѵ�. ���� �̸��� �빮���� ù ���ڸ� �����ϸ�
�ҹ��ڷθ� �̷���� �ְ�, 10�� �̳��̴�.

�ذ� ��� : strcmp �Լ��� qsort �Լ��� ����Ѵ�. last name�� �켱�ӿ� �����Ѵ�.

�ֿ� �˰��� : ���ڿ�, ����

��ó : PacNW 2015 R��
*/

char name[128][2][16];

int cmp1(const void* a, const void* b) {
    if (strcmp((char*)a + 16, (char*)b + 16)) return strcmp((char*)a + 16, (char*)b + 16);
    return strcmp((char*)a, (char*)b);
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s %s", name[i][0], name[i][1]);
    }
    qsort(name, n, sizeof(char) * 2 * 16, cmp1);
    for (int i = 0; i < n; i++) {
        printf("%s %s\n", name[i][0], name[i][1]);
    }
    return 0;
}