#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

/*
���� : ���� �ٸ� 3�� �̻� 7�� ������ �ҹ��ڷ� �̷���� ���ڿ��� �־��� ��,
�� ���ڿ��� ���� �� �ִ� ��� ������ ���������� ����Ѵ�.

�ذ� ��� : next_permutation() �Լ��� �̿��Ͽ� ��� ������ Ȯ���ϸ� �ȴ�.

�ֿ� �˰��� : ���Ʈ ����

��ó : IATI 2013D 3��
*/

char s[8];

int main(void) {
    int l;
    scanf("%s", s);
    l = strlen(s);
    while (next_permutation(s, s + l));
    do {
        printf("%s\n", s);
    } while (next_permutation(s, s + l));
    return 0;
}