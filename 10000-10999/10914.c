#include <stdio.h>
#include <string.h>

/*
���� : ������ �־��� ������� ��ȣȭ�� 100�� ������ 101�� ���� �ܾ�� �̷���� ���ڿ��� �־��� ��,
�̸� ��ȣȭ�� ���� ���Ѵ�.

�ذ� ��� : ���ڿ��� �޾Ƽ� �ܾ� ������ �ɰ� ���� �ܾ�� ��ȣȭ�Ͽ� ����ϸ� �ȴ�.

�ֿ� �˰��� : ���ڿ�, ����

��ó : Kriii 2ȸ V��
*/

char s[16384], word[128][128];

int main(void) {
    int n, wc = 0;
    char* c;
    scanf("%d\n", &n);
    fgets(s, 15000, stdin);
    if (s[strlen(s) - 1] == '\n') s[strlen(s) - 1] = '\0';
    c = strtok(s, " ");
    while (c) {
        strcpy(word[wc++], c);
        c = strtok(NULL, " ");
    }
    for (int i = 0; i < wc; i++) {
        for (int j = 0; word[i][j + 1]; j += 2) {
            printf("%c", (word[i][j] + word[i][j + 1] - 'a' * 2 - n + 2600) % 26 + 'a');
        }
        printf(" ");
    }
    return 0;
}