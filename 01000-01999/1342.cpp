#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

/*
���� : ���� 10 ������ �ҹ��ڷ� �̷���� ���ڿ��� �־��� ��, �� ���ڿ��� ���ġ�Ͽ�
���� �� �ִ� (������ ���� �� ���� ���ڰ� ���� ���ڿ�)�� ������ ���Ѵ�.

�ذ� ��� : next_permutation �Լ��� �̿��� ��� ������ Ȯ���ذ��� ������ �����ϴ� ���� ������ ã���� �ȴ�.

�ֿ� �˰��� : ���ڿ�, ���Ʈ ����

��ó : SRM 428D1 1�� / D2 2��
*/

char s[16];

int main(void) {
    int l, r = 0, t;
    scanf("%s", s);
    l = strlen(s);
    while (next_permutation(s, s + l));
    while (1) {
        t = 1;
        for (int i = 1; i < l; i++) {
            if (s[i] == s[i - 1]) {
                t = 0;
                break;
            }
        }
        r += t;
        if (!next_permutation(s, s + l)) break;
    }
    printf("%d", r);
    return 0;
}