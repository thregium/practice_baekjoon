#include <stdio.h>
#include <stdlib.h>

/*
���� : 1���� N(N <= 1000)������ ���� ����. �̶�, �� ���� ���� mumble�� �ٲپ��ٰ� �Ѵٸ�, ����� ���� �� ������ Ȯ���Ѵ�.

�ذ� ��� : ������ ���ڿ��� �Է¹��� �� mumble�� ��� �ǳʶٰ�, ���̸� �ش� ��°�� �ƴ� ���� �ִ��� Ȯ���ϸ� �ȴ�.

�ֿ� �˰��� : ����, �Ľ�

��ó : NCPC 2018 B��
*/

char buff[64];

int main(void) {
    int n, r = 1;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%s", buff);
        if (buff[0] == 'm') continue;
        else if (strtoll(buff, NULL, 10) != i) r = 0;
    }
    if (r) printf("makes sense");
    else printf("something is fishy");
    return 0;
}