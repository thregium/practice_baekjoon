#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

/*
���� : 80�� ������ ���� �־��� ��, �� ���� ������ �����鼭 �� �� ���� ũ���� ���� ���Ѵ�.
���ٸ� BIGGEST�� ����Ѵ�.

�ذ� ��� : next_permutation �Լ��� �̿��Ѵ�.

�ֿ� �˰��� : ����, ���շ�, ���ڿ�

��ó : GNY 2009 E��
*/

char s[128];

int main(void) {
    int t, n, l;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%s", s);
        l = strlen(s);
        if (!next_permutation(s, s + l)) printf("BIGGEST\n");
        else printf("%s\n", s);
    }
    return 0;
}