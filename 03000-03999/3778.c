#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*
���� : �� ���� ���� 45 ������ �ҹ��ڷθ� �̷���� ���ڿ��� �־��� ��, �� ���ڿ����� ���ڵ��� ������ �����Ͽ�
�ֳʱ׷� ���谡 �ǵ��� �ϴ� �ּ����� ���� Ƚ���� ���Ѵ�.

�ذ� ��� : ���� �� �������� �ִ� ���ڰ� �ٸ� �������� ���ٸ� �� ���� ���ڸ� �����ؾ� �Ѵ�.
����, �ʿ��� ���� Ƚ���� �� ������ ���� Ƚ���� �� ����, ��� ���ڿ� ���� �� ���ڿ��� ���� Ƚ���� ���̸� ���ϸ� �ȴ�.

�ֿ� �˰��� : ���ڿ�

��ó : SEERC 2005 H��
*/

char s[64];
int cnt1[26], cnt2[26];

int main(void) {
    int n, r;
    scanf("%d\n", &n);
    for (int tt = 1; tt <= n; tt++) {
        for (int i = 0; i < 26; i++) {
            cnt1[i] = 0;
            cnt2[i] = 0;
        }
        fgets(s, 60, stdin);
        for (int i = 0; s[i]; i++) {
            if (islower(s[i])) cnt1[s[i] - 'a']++;
        }
        fgets(s, 60, stdin);
        for (int i = 0; s[i]; i++) {
            if (islower(s[i])) cnt2[s[i] - 'a']++;
        }
        r = 0;
        for (int i = 0; i < 26; i++) {
            r += abs(cnt1[i] - cnt2[i]);
        }
        printf("Case #%d: %d\n", tt, r);
    }
    return 0;
}