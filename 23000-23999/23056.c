#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
���� : N(N <= 10)���� �б��� �ְ� �б޴� ������ M(M <= 10)����� �ȸ�� ������ �� �ִ�. 500�� ������ ������� �ȸ��
��û�� ����� �־��� ��, �ȸ�� �����ϴ� �ο����� �־��� ��Ģ��� ����Ѵ�.
1. û��(Ȧ���� �б�)�� ����(¦���� �б�)���� ���� �;� �Ѵ�.
2. ���� �� ������ �б� ��ȣ�� �ռ� ���� ���� �´�.
3. ���� �ݿ����� �̸� ���̰� ª�� ������ �´�.
4. �̸� ���̵� ���ٸ� �̸��� ������ ���� ������ �´�.

�ذ� ��� : �ȸ�� �����ϴ� ������� ������ ����ü�� ���� �����Ѵ�. �������� ���� ���ϸ� ���� �ο��� ���� ���Կ� �����Ѵ�.
����ü�� �бް� �̸� ����, �̸��� �ְ� �־��� ��Ģ�� ���� �Լ��� �־� �����ϸ� �ȴ�.

�ֿ� �˰��� : ����, ����

��ó : �泲�� 5ȸ B��
*/

typedef struct stu {
    int cla;
    int nlen;
    char name[32];
} stu;

int cnt[16];
char buff[32];
stu st[512];

int cmp1(const void* a, const void* b) {
    stu ai = *(stu*)a;
    stu bi = *(stu*)b;
    if ((ai.cla ^ bi.cla) & 1) return (ai.cla & 1) ? -1 : 1;
    if (ai.cla - bi.cla) return ai.cla - bi.cla;
    if (ai.nlen - bi.nlen) return ai.nlen - bi.nlen;
    return strcmp(ai.name, bi.name);
}

int main(void) {
    int n, m, c, sp = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0;; i++) {
        scanf("%d %s", &c, buff);
        if (c == 0) break;
        if (cnt[c] >= m) continue;
        cnt[c]++;
        st[sp].cla = c;
        st[sp].nlen = strlen(buff);
        strcpy(st[sp].name, buff);
        sp++;
    }

    qsort(st, sp, sizeof(stu), cmp1);
    for (int i = 0; i < sp; i++) {
        printf("%d %s\n", st[i].cla, st[i].name);
    }
    return 0;
}