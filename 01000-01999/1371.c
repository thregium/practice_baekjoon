#include <stdio.h>
#include <ctype.h>

/*
���� : 5000�� ������ ���ĺ� �ҹ���, ����, ���ͷ� �̷���� ���ڿ��� �־��� ��,
�� ���ڿ����� ���� ���� ���� ���ĺ��� ���������� ����Ѵ�.

�ذ� ��� : ���ڿ��� �Է¹����� ���ڿ��� ���캸�ٰ� ���ĺ��� ��� �ش� ���ĺ��� ī��Ʈ�� 1 �ø���.
��� ���ڿ��� ���캸�� ���� ���� ���� ���ĺ��� ������ ã�� �ٽ� ���ĺ��� ������ �׿� ���� ���ĺ����� ���������� ����ϸ� �ȴ�.

�ֿ� �˰��� : ���ڿ�
*/

char buff[5120];
int cnt[26];

int main(void) {
    int biggest = 0;
    while (fgets(buff, 5100, stdin)) {
        for (int i = 0; buff[i]; i++) {
            if (islower(buff[i])) cnt[buff[i] - 'a']++;
        }
    }
    for (int i = 0; i < 26; i++) {
        if (cnt[i] > biggest) biggest = cnt[i];
    }
    for (int i = 0; i < 26; i++) {
        if (cnt[i] == biggest) printf("%c", i + 'a');
    }
    return 0;
}