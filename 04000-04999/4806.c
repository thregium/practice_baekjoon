#include <stdio.h>

/*
���� : �־��� �Է��� �� ������ ���Ѵ�.

�ذ� ��� : fgets�� ���� �� ������ �Է¹��� �� �ִ�. EOF�� ������ ��� 0�� ��ȯ�ϹǷ� while���� ����ϸ� �ȴ�.

�ֿ� �˰��� : ���ڿ�?, �ֵ� Ȥ?

��ó : Rocky 2012 P��
*/

char s[128];

int main(void) {
    int r = 0;
    while (fgets(s, 120, stdin)) r++;
    printf("%d", r);
    return 0;
}