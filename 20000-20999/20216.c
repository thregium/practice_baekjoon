#include <stdio.h>
#include <string.h>

/*
���� : � ������ �־��� �� �ش� ������ � ���ڷ� ������ �� Ȯ���ϰ� ���ڿ� ���� ���� �ٸ� ����� �Ѵ�.

�ذ� ��� : strlen(���ڿ�) - 1 �Ǵ� - 2�� �ϸ� ������ ���ڸ� �� �� �ִ�. -1�� \n�� ��� -2�� �ϸ� �ȴ�.

�ֿ� �˰��� : ���ڿ�

��ó : BAPC 2020P D��
*/

char buff[10240];

int main(void) {
    char ld;
    while (1) {
        fgets(buff, 10100, stdin);
        ld = buff[strlen(buff) - 1];
        if (ld == '\n') ld = buff[strlen(buff) - 2];
        if (ld == '.') printf("*Nod*\n");
        else if (ld == '?') printf("Quack!\n");
        else if (ld == '!') return 0;
        else return 1;
        fflush(stdout);
    }
    return 0;
}