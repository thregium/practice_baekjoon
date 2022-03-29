#include <stdio.h>
#include <string.h>

/*
���� : ���縵 ���� ���ĺ� 7��(�ҹ���)�� N(N <= 102305)���� �ܾ�(<= 24��, �ҹ���)�� �־��� ��,
������ �����ϴ� �ܾ ��� ����Ѵ�. ������ �����ϴ� �ܾ�� ���縵 ���� ù ���ĺ��� �����ϰ�,
���縵 �� �ִ� 7���� ���ĺ����θ� �̷���� 4�� �̻��� �ܾ��̴�.

�ذ� ��� : ������ ���� ������ �����ϰ� ������ �����ϴ� �� Ȯ���� ���� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����, ���ڿ�

��ó : VTH 2019 C��
*/

char bee[16], dict[32], chk[26];

int main(void) {
    int n, r;
    scanf("%s", bee);
    for (int i = 0; i < 7; i++) chk[bee[i] - 'a'] = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", dict);
        r = 0;
        for (int j = 0; dict[j]; j++) {
            if (dict[j] == bee[0]) r = 1;
        }
        for (int j = 0; dict[j]; j++) {
            if (!chk[dict[j] - 'a']) r = 0;
        }
        if (strlen(dict) < 4) r = 0;
        if (r) printf("%s\n", dict);
    }
    return 0;
}