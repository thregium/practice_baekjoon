#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
���� : 5������ �ܾ �빮�ڷ� �־�����, �����ڴ� �ִ� 5ȸ�� ���� ��ȸ�� ���´�. �� ó������ �ܾ��� ù �ڸ� �˷��ְ�,
���ķδ� �����ڰ� �ִ� �ܾ ���� �����ڰ� ���� �ܾ�� ��ġ�� ��ġ�ϴ� ���ڴ� �빮�ڷ�, ���� �ܾ ������ ��ġ�� ��ġ���� �ʴ� ���ڴ� �ҹ��ڷ�,
������ ��ġ���� �ʴ� ���ڴ� .���� ��Ÿ����. ���� �����ڰ� �ܾ ����� ������ ���� ��� ������ ���� �ܾ �״�� �˷��� ���� ���� Ƚ���� 1ȸ ������Ų��.
�����ڰ� 5ȸ �̳��� ������ ��� ���� �Է��� �����Ѵ�. �ݴ��, �����ڰ� 5ȸ���� �������� ���ϰų� ���⿡ ������ ��� �ҹ��ڷ� �ܾ �˷��� ����
���� �Է��� �����Ѵ�.
��, �ҹ��� ���θ� Ȯ���� ������ �빮�ڷ� ����߰ų� �̹� �տ��� �ҹ��ڷ� ���� ��� �ش� ���ڴ� �����Ѵ�.

�ذ� ��� : ���� �ܾ �Է¹��� ����, ���ķ� �����ڰ� �ִ� �ܾ �Է¹ް� �� ���ǿ� ���� ����Ѵ�.

�ֿ� �˰��� : ���ڿ�, ���̽� ��ũ, ����

��ó : GNY 2002 C��
*/

char word[8], buff[16], review[8];

int main(void) {
    int attempt = 0, ans, t, t2;
    //freopen("C:\\1_����\\PS\\ICPC\\North America\\Greater New York\\acmgnyr.org-master\\year2002\\problemc.in", "r", stdin);
    //freopen("C:\\1_����\\PS\\ICPC\\North America\\Greater New York\\acmgnyr.org-master\\year2002\\problemc_check.out", "w", stdout);
    while (1) {
        fgets(word, 8, stdin);
        if (word[0] == '\n') {
            printf("\n");
            continue;
        }
        word[strlen(word) - 1] = '\0';
        if (!strcmp(word, "LINGO")) break;
        printf("%c....\n", word[0]);
        strcpy(review, ".....");
        review[0] = word[0];
        attempt = 0;
        ans = 0;
        while (1) {
            fgets(buff, 12, stdin);
            if (buff[0] == '\n') break;
            buff[strlen(buff) - 1] = '\0';
            if (ans || attempt >= 5) continue;
            if (strlen(buff) != 5 || !isupper(buff[0]) || !isupper(buff[1]) || !isupper(buff[2]) || !isupper(buff[3]) || !isupper(buff[4])) {
                attempt++;
                printf("%s\n", review);
                continue;
            }
            if (!strcmp(word, buff)) {
                ans = 1;
                printf("%s\n", buff);
                continue;
            }
            for (int i = 0; i < 5; i++) {
                if (word[i] == buff[i]) {
                    review[i] = buff[i];
                    printf("%c", buff[i]);
                    continue;
                }
                t = 0;
                for (int j = 0; j < 5; j++) {
                    if (word[j] == buff[i] && word[j] != buff[j]) {
                        t2 = 0;
                        for (int k = 0; k < i; k++) {
                            if (toupper(review[k]) == buff[i]) t2 = 1;
                        }
                        if (t2) continue;
                        printf("%c", tolower(buff[i]));
                        review[i] = tolower(buff[i]);
                        t = 1;
                        break;
                    }
                }
                if (!t) {
                    review[i] = '.';
                    printf(".");
                }
            }
            printf("\n");
            attempt++;
        }
        if (!ans) printf("%c%c%c%c%c\n", tolower(word[0]), tolower(word[1]), tolower(word[2]), tolower(word[3]), tolower(word[4]));
        printf("\n");
    }
    return 0;
}