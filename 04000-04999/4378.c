#include <stdio.h>
#include <string.h>

/*
���� : Ű����� ĥ �� �ִ� ���ڿ��� �־��� ��,
�� ���ڿ��� ��ĭ ���ʿ� ���� �ΰ� �ļ� ������ ���ڿ��� ���Ѵ�. ��, �����̽� �ٴ� �״�� ��µȴ�.

�ذ� ��� : Ű������ �迭�� �ϵ��ڵ��� ����, �� ���ڸ��� ���� ������ ��ĭ ������ Ű�� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����, ���ڿ�

��ó : Waterloo 20010117 C��
*/

char buff[103000];
const char* key = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

int main(void) {
    int t;
    while (fgets(buff, 101300, stdin)) {
        if (buff[strlen(buff) - 1] == '\n') buff[strlen(buff) - 1] = '\0';
        for (int i = 0; buff[i]; i++) {
            if (buff[i] == ' ') {
                printf(" ");
                continue;
            }
            t = 0;
            for (int j = 0; key[j]; j++) {
                if (key[j] == buff[i]) {
                    printf("%c", key[j - 1]);
                    t = 1;
                    break;
                }
            }
            if (!t) return 1;
        }
        printf("\n");
    }
    return 0;
}