#include <stdio.h>
#include <ctype.h>

/*
���� : ī�� ǥ���, ������ũ ǥ���, �Ľ�Į ǥ��� �� �ϳ��� ǥ��� �������� ī��, ������ũ, �Ľ�Į ǥ������� ���� ��ȯ�Ѵ�.
�������� �ִ� 100���̰�, ���ĺ��� �����(������ũ ǥ����� ���)�θ� �̷���� �ִ�.

�ذ� ��� : ī�� ǥ������� �Էµ� ���, �Ľ�Į ǥ������δ� ù ���ڸ� �빮�ڷ� �ٲٸ� �ȴ�. ������ũ ǥ������δ�
�빮�ڰ� ���� �� ���� ����ٸ� �տ� �Է��ϸ� �ȴ�.
������ũ ǥ������� �Էµ� ��� ī�� ǥ������δ� ù �ڰ� �ƴϸ� �� ���ڰ� ������� ��� �빮��,
�� �ܿ��� �ҹ��ڷ� ǥ���ϸ� �ǰ�, �Ľ�Į ǥ������δ� ī�� ǥ����� ù �ڸ� �빮�ڷ� �ٲٸ� �ȴ�.
�Ľ�Į ǥ������� �Էµ� ��쿡�� ī�� ǥ������δ� ù ���ڸ� �ҹ��ڷ� �ٲٸ� �ǰ�, ������ũ ǥ������δ�
ù �ڸ� �����ϰ� �빮�ڰ� ���� �� ���� ����ٸ� �տ� �Է��ϸ� �ȴ�.

�ֿ� �˰��� : ���ڿ�, ����
*/

char s[128];

int main(void) {
    int n;
    scanf("%d %s", &n, s);
    switch (n) {
    case 1:
        printf("%s\n", s);
        for (int i = 0; s[i]; i++) {
            if (isupper(s[i])) printf("_");
            printf("%c", tolower(s[i]));
        }
        printf("\n%c%s", toupper(s[0]), s + 1);
        break;
    case 2:
        for (int i = 0; s[i]; i++) {
            if (!isalpha(s[i])) continue;
            if (i > 0 && s[i - 1] == '_') printf("%c", toupper(s[i]));
            else printf("%c", s[i]);
        }
        printf("\n%s\n", s);
        for (int i = 0; s[i]; i++) {
            if (!isalpha(s[i])) continue;
            if (i == 0 || s[i - 1] == '_') printf("%c", toupper(s[i]));
            else printf("%c", s[i]);
        }
        break;
    case 3:
        printf("%c%s\n", tolower(s[0]), s + 1);
        for (int i = 0; s[i]; i++) {
            if (isupper(s[i]) && i > 0) printf("_");
            printf("%c", tolower(s[i]));
        }
        printf("\n%s", s);
        break;
        break;
    default:
        break;
    }
    return 0;
}