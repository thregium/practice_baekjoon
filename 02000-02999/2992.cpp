#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

/*
���� : 6�ڸ� ������ ���� �־��� ��, �� ���� ������ �����鼭 �� ������ ū ���� ���� ���� ���Ѵ�.
���� ��� 0�� ����Ѵ�.

�ذ� ��� : next_permutation �Լ��� �̿��Ѵ�.

�ֿ� �˰��� : ����, ���շ�?

��ó : COCI 07/08#4 2��
*/

char s[16];

int main(void) {
    scanf("%s", s);
    if (!next_permutation(s, s + strlen(s))) printf("0");
    else printf("%s", s);
    return 0;
}