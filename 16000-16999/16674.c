#include <stdio.h>
#include <string.h>

/*
���� : 10^9 ������ �ڿ����� �־��� ��, �� �ڿ����� 2018�� � �������� ���Ѵ�. (���� ����)

�ذ� ��� : �ڿ����� ���ڿ��� �Է¹��� ����, �ڸ����� ����, �ڸ��� ������ �̿��� ��� �������� ã���� �ȴ�.

�ֿ� �˰��� : ����, ���̽� ��ũ

��ó : ����� 2018 BB/IA��
*/

char n[16];
int cnt[10];

int main(void) {
    int l;
    scanf("%s", n);
    l = strlen(n);
    for (int i = 0; n[i]; i++) {
        cnt[n[i] - '0']++;
    }
    if (cnt[2] + cnt[0] + cnt[1] + cnt[8] != l) printf("0");
    else if (!(cnt[2] && cnt[0] && cnt[1] && cnt[8])) printf("1");
    else if (cnt[2] == cnt[0] && cnt[2] == cnt[1] && cnt[2] == cnt[8]) printf("8");
    else printf("2");
    return 0;
}