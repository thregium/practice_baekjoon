#include <stdio.h>

/*
���� : ���ĺ� �빮�ڷ� �̷���� 1000�� ������ ���ڿ��� �־��� ��, �ش� ���ڿ��� �������� �ʴ� �빮���� �ƽ�Ű�ڵ��� ���� ���Ѵ�.

�ذ� ��� : ���ڿ��� �� �빮���� ���� Ƚ���� �� ����, 0ȸ�� ���� �ƽ�Ű �ڵ带 ���� ���ϸ� �ȴ�.

�ֿ� �˰��� : ����, ���ڿ�
*/

char buff[1024];
int cnt[26];

int main(void) {
    int t, r = 0;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%s", &buff);
        r = 0;
        for (int i = 0; buff[i]; i++) {
            cnt[buff[i] - 'A']++;
        }
        for (int i = 0; i < 26; i++) {
            if (cnt[i] == 0) r += i + 'A';
            else cnt[i] = 0;
        }
        printf("%d\n", r);
    }
    return 0;
}