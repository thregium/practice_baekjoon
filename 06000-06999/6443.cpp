#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

/*
���� : 20�� ������ �ҹ��ڷ� �̷���� ���ڿ��� �־��� ��, �� ���ڿ��� �Ƴ��׷��� ���������� ��� ����Ѵ�.
��, �Ƴ��׷��� �ִ� 100000�� ������ ���´�.

�ذ� ��� : next_permutation �Լ��� �̿��� ù ��° �Ƴ��׷����� ���ư� ����, ���������� next_permutation() �Լ���
�Ƴ��׷����� ���� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����, ���շ�

��ó : SWERC 1995 E��
*/

char s[32];

int main(void) {
    int n, l;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        l = strlen(s);
        while (next_permutation(s, s + l));
        while (1) {
            printf("%s\n", s);
            if (!next_permutation(s, s + l)) break;
        }
    }
    return 0;
}