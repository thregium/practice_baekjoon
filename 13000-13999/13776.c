#include <stdio.h>
#include <ctype.h>

/*
���� : S * S(S <= 20) ũ���� ũ�ν����忡 ��� ���ĺ��� �ִٰ� �ϸ�, ������ ���ĺ����� ���ʷ� ����Ѵ�.

�ذ� ��� : �� ���ĺ��� ���� ���θ� ������ ��, �������� ���� ���ĺ��� ���� �� ���� ���ʴ�� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����, ���ڿ�

��ó : NZPC 2016 F��
*/

char puz[32], chk[26];

int main(void) {
    int s;
    scanf("%d\n", &s);
    for (int i = 0; i < s; i++) {
        fgets(puz, 24, stdin);
        for (int j = 0; puz[j]; j++) {
            if (isupper(puz[j])) {
                if (!chk[puz[j] - 'A']) {
                    chk[puz[j] - 'A'] = 1;
                    printf("%c", puz[j]);
                }
            }
        }
    }
    return 0;
}