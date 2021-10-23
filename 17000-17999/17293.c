#include <stdio.h>

/*
���� : N(N <= 99)���� ���ָ� ����Ѵ�. ������ �°� ����ؾ� �Ѵ�.

�ذ� ��� : �ݺ����� ���� 1�� �̻��� ���� ����ϰ�, ���������� ���� ����Ѵ�. 1���� ���� ���� ó���� �����Ѵ�.

�ֿ� �˰��� : ����, ���̽� ��ũ?

��ó : ���� 3ȸ�� C��
*/

char s[32];

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = n; i > 0; i--) {
        sprintf(s, "%d %s", i, i > 1 ? "bottles" : "bottle");
        printf("%s of beer on the wall, %s of beer.\n", s, s);
        if (i == 1) sprintf(s, "%s", "no more bottles");
        else sprintf(s, "%d %s", i - 1, i > 2 ? "bottles" : "bottle");
        printf("Take one down and pass it around, %s of beer on the wall.\n\n", s);
    }
    printf("No more bottles of beer on the wall, no more bottles of beer.\n");
    printf("Go to the store and buy some more, %d %s of beer on the wall.", n, n > 1 ? "bottles" : "bottle");
    return 0;
}