#include <stdio.h>
#include <string.h>

/*
���� : 3���� �� �� �ϳ��� ���� ���� ��, �� �ŵ��� �ٲ� ������ �־����ٸ� �������� ���� �ִ� ��ġ�� ����Ѵ�.

�ذ� ��� : ���� ��ġ ��ȭ�� �ùķ��̼� �Ѵ�. �� ��� ���� ��ġ ��ȭ�� �ùķ��̼� �ϴ� ���� �� ���� ���� �ִ�.

�ֿ� �˰��� : ����, �ùķ��̼�

��ó : AIPO 2015P 4��
*/

char c[64];

int main(void) {
    int l, p = 1;
    scanf("%s", c);
    l = strlen(c);
    for (int i = 0; i < l; i++) {
        if (c[i] == 'A') {
            if (p == 1) p = 2;
            else if (p == 2) p = 1;
        }
        if (c[i] == 'B') {
            if (p == 2) p = 3;
            else if (p == 3) p = 2;
        }
        if (c[i] == 'C') {
            if (p == 1) p = 3;
            else if (p == 3) p = 1;
        }
    }
    printf("%d", p);
    return 0;
}