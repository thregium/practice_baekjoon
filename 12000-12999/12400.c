#include <stdio.h>
#include <ctype.h>

/*
���� : 100�� ������ �ҹ��ڿ� �������� �̷���� ���ڿ��� �־�����, �� ���ڿ��� ��ȣȭ���� ���� ���·� �ٲپ� ����Ѵ�.
��ȣ���� ���� ���ڸ� �ϴ��� �����Ͽ� ������� �ִ�. ����, ���� ���ڿ� ���� �ʴ�.

�ذ� ��� : ������ q�� z�� ������ ��� ���ڴ� ����ִ�. �׸��� q�� z�� ���� q�� z�� �ٲ� ���̱� ������
q�� z��, z�� q�� ���� �Ѵ�. �̸� �̿��� ��ȣȭ�� �����ϰ� �̸� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����, �ֵ� Ȥ

��ó : GCJ 2012Q A1��
*/

char s[128];
const char* crypt = "yhesocvxduiglbkrztnwjpfmaq";

int main(void) {
    int t;
    scanf("%d", &t);
    getchar();
    for (int tt = 1; tt <= t; tt++) {
        fgets(s, 120, stdin);
        printf("Case #%d: ", tt);
        for (int i = 0; s[i]; i++) {
            if (islower(s[i])) printf("%c", crypt[s[i] - 'a']);
            else if (s[i] == ' ' || s[i] == '\n') printf("%c", s[i]);
            else return 1;
        }
    }
    return 0;
}