#include <stdio.h>
#include <string.h>

/*
���� : 1000�� ������ he...y ������(e�� ������ Ƚ����ŭ �ݺ�) ���ڿ��� �־��� ��, e�� ������ 2��� �÷� ����Ѵ�.

�ذ� ��� : e�� ������ ���ڿ��� ���̸� l�̶�� �ϸ� (l - 2) * 2ȸ�� �Ǹ� �ȴ�. h�� ����� �� e�� �ش� Ƚ�� ����ϰ� �ٽ� y�� ����ϸ� �ȴ�.

�ֿ� �˰��� : ���ڿ�, ����

��ó : BAPC 2019P G��
*/

char s[1024];

int main(void) {
    scanf("%s", s);
    int l = strlen(s);
    printf("h");
    for (int i = 0; i < (l - 2) * 2; i++) printf("e");
    printf("y");
    return 0;
}