#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/*
���� : N(N <= 20)���� ���� ���� ������ �Ǵ� ������ ���� ���� �־�����. ���� ���� ������ �����̰�,
���߿� ������ �������̴�. �̶�, �� ������ �������� Ŀ���� ������ �����Ͽ� ����Ѵ�.
��� ���� �������� ���� �ٸ���, ��� ���� ���� �ҹ��ڷ� �̷���� 20�� ������ �ܾ��,
�������� 1000 ������ �ڿ����̴�.

�ذ� ��� : ��� �ŵ��� ���� �������� ����ü�� ��� �����Ѵ�. �� ���� �Է¹��� �� ����
�������� ���� ���θ� Ȯ���� ����, ����ü�� �� ���� ���� �������� �Ľ��Ѵ�. �׸��� �� ����ü����
������ ������������ �����Ͽ� ����ϸ� �ȴ�.

�ֿ� �˰��� : ���ڿ�, �Ľ�, ����

��ó : Rocky 2016 I��
*/

typedef struct cup {
    char color[32];
    int rad;
} cup;

char buff1[32], buff2[32];
cup c[32];

int cmp1(const void* a, const void* b) {
    int ai = ((cup*)a)->rad;
    int bi = ((cup*)b)->rad;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s %s", buff1, buff2);
        if (isdigit(buff1[0])) {
            c[i].rad = strtoll(buff1, NULL, 10) / 2;
            strcpy(c[i].color, buff2);
        }
        else {
            c[i].rad = strtoll(buff2, NULL, 10);
            strcpy(c[i].color, buff1);
        }
    }
    qsort(c, n, sizeof(cup), cmp1);
    for (int i = 0; i < n; i++) {
        printf("%s\n", c[i].color);
    }
    return 0;
}