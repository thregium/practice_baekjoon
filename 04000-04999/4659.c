#include <stdio.h>

/*
���� : �־��� �ҹ��� 20�� ������ ���ڿ��� ���� �������� ���Ѵ�. ������ 1�� �̻� �ְ�, 'e'�� 'i'�� ������ ���� ���ڰ�
2�� �̻� �����ؼ� ���� ������, �����̳� ������ 3�������� ���� ������ ���� ������ ���̴�.

�ذ� ��� : ���ڿ��� �Է¹��� ���� ������ �ִ��� Ȯ���Ѵ�. ���ٸ� ���� �Ұ����ϴ�. �� �������δ� ���ڿ��� ���Ǹ鼭
3�������� �����̳� ������ ������ ���, ���� ���ڰ� 2����(e, i ����)���� ������ ��츦 Ȯ���Ѵ�. �׷��� ��찡 �ִٸ�
���� �Ұ����ϰ� ���ٸ� ���� �����ϴ�.

�ֿ� �˰����� : ����, ���ڿ�

��ó : MidC 2000 B��
*/

char s[32];
int chk[32];
const char* vow = "aeiou";

int main(void) {
    int r;
    while (1) {
        scanf("%s", s);
        if (s[0] == 'e' && s[1] == 'n' && s[2] == 'd' && s[3] == '\0') break;
        r = 0;
        for (int i = 0; s[i]; i++) {
            chk[i] = 0;
            for (int j = 0; j < 5; j++) {
                if (s[i] == vow[j]) {
                    r = 1;
                    chk[i] = 1;
                }
            }
        }
        for (int i = 1; s[i]; i++) {
            if (i >= 2 && (chk[i] + chk[i - 1] + chk[i - 2] == 3 || chk[i] + chk[i - 1] + chk[i - 2] == 0)) r = 0;
            if (s[i] == s[i - 1] && s[i] != 'e' && s[i] != 'o') r = 0;
        }
        printf("<%s> is %s.\n", s, r ? "acceptable" : "not acceptable");
    }
    return 0;
}