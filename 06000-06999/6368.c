#include <stdio.h>
#include <string.h>

/*
���� : 4�� ������ ���̸� ���� �� ��ȣ���� �����ϴ� ���ڵ��� ���� �ִ�. ���ڿ��� �־����� �� ���ڿ��� ���ڵ��� ���� �� ��ȣ��
��ȯ�� ���� �� ��ȣ���� ���̸� ������ ���� �ٽ� �׿� �����ϴ� ���ڵ�� ��ȯ�� ���� ���Ѵ�.

�ذ� ��� : �� ���ڿ� �����ϴ� ��ȣ���� ���� �ϵ��ڵ��Ѵ�. ���ڿ��� �־����� �� ���ڿ� �����ϴ� ��� ��ȣ���� �� �� �ְ�,
��ȣ���� ���� ���� �˾Ƴ� �� �ִ�. �� ����, �� ��ȣ���� ���̸� ����� ����, �������� �ش��ϴ� ���̿� ��ȣ�� �����ϴ� ���ڵ��� �˾Ƴ��� �ȴ�.

�ֿ� �˰��� : ����, ���ڿ�

��ó : GNY 2001 B��
*/

char* morse[30] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
"-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
"..-", "...-", ".--", "-..-", "-.--", "--..", "..--", ".-.-", "---.", "----" };
char* assign = "ABCDEFGHIJKLMNOPQRSTUVWXYZ_,.?";

char buff[128], code[512], tmp[16];
int len[128];

int main(void) {
    int t, x, p;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%s", buff);
        for (int i = 0; buff[i]; i++) {
            for (int j = 0; j < 30; j++) {
                if (assign[j] == buff[i]) {
                    strcat(code, morse[j]);
                    len[i] = strlen(morse[j]);
                    break;
                }
            }
        }
        for (int i = 0, j = strlen(buff) - 1; i < j; i++, j--) {
            x = len[i];
            len[i] = len[j];
            len[j] = x;
        }
        p = 0;
        printf("%d: ", tt);
        for (int i = 0; buff[i]; i++) {
            for (int j = 0; j < len[i]; j++) {
                tmp[j] = code[p + j];
            }
            tmp[len[i]] = '\0';
            for (int j = 0; j < 30; j++) {
                if (strcmp(tmp, morse[j])) continue;
                printf("%c", assign[j]);
                break;
            }
            p += len[i];
        }
        printf("\n");
        code[0] = '\0';
    }
    return 0;
}