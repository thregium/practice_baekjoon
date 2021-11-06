#include <stdio.h>
#include <ctype.h>

/*
���� : ���� 100 ������ ���ڿ��� �־��� ��, �� ���ڿ��� ��ҹ��ڸ� �������� �ʰ� ��� ���ĺ��� ����ִ��� Ȯ���Ѵ�.
���� ��� ���� ���ڵ��� �ҹ��ڷ� ���ĺ� ������� ����Ѵ�.

�ذ� ��� : ���� �� ���ڵ��� Ȯ���ϸ� �� ������ ���� ���θ� Ȯ���Ѵ�.(��ҹ��ڿ� ���� �ٸ��� ó��)
�׸��� ��� ���ڰ� ����ִ��� Ȯ���� ���� ������� ���� ���ڰ� �ִٸ� �ٽ� �̸� Ȯ���ϸ� ���ĺ� �������
���� ���ڵ��� ����ϸ� �ȴ�.

�ֿ� �˰��� : ���ڿ�, ����

��ó : NAQ 2015 F��
*/

char s[128], chk[26];

int main(void) {
    int n, r;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        fgets(s, 120, stdin);
        if (s[0] == '\n') {
            i--;
            continue;
        }
        for (int j = 0; j < 26; j++) chk[j] = 0;
        for (int j = 0; s[j]; j++) {
            if (isupper(s[j])) chk[s[j] - 'A'] = 1;
            else if (islower(s[j])) chk[s[j] - 'a'] = 1;
        }
        r = 1;
        for (int j = 0; j < 26; j++) {
            if (!chk[j]) r = 0;
        }
        if (r) printf("pangram\n");
        else {
            printf("missing ");
            for (int j = 0; j < 26; j++) {
                if (!chk[j]) printf("%c", j + 'a');
            }
            printf("\n");
        }
    }
    return 0;
}