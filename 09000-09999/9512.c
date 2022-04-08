#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
���� : N(N <= 100)���� ����� �̸��� �� ����� �ܾ���� �ٸ��� �־�����. �� ���� ���̴� �ִ�
256�� ���ϴ�. ���� 1000�� ������ ���� �־��� ��, �� ��� ��� �ϳ��� �� �ִ� �ܾ� �Ǵ�
�� �� ���Ե��� �ʴ� �ܾ��� �̷���� ������ �־����� � ����� ������ �� ���Ѵ�.
�ܾ�� ���� �Ǵ� �����ȣ('�� - ����)�� ������ ������, ��ҹ��ڸ� �������� �ʴ´�.

�ذ� ��� : strtok �Լ��� ���� �� ����� �̸��� �ܾ���� ������ ���� ����,
�� �ܾ���� �ҹ��ڷ� �ٲپ� �ش�.
�ٽ� ������� �Է¹��� ���� �����ȣ ������ ������ �ҹ��ڷ� �ٲ� ����, �� ����� �� �ܾ� ���
�ϳ��� ��ġ�� �� ���� ã�ƺ��鼭 ��ġ�ϴ� ������ ���ϸ� �ȴ�.

�ֿ� �˰��� : ���ڿ�, �Ľ�

��ó : PacNW 2013 L��
*/

char buff[512], word[128][128][256];
int wcnt[128];

int main(void) {
    int n, r;
    char* c;
    //freopen("E:\\PS\\ICPC\\North America\\Pacific Northwest\\2013\\_IO\\Languages.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\North America\\Pacific Northwest\\2013\\_IO\\Languages_t.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s ", word[i][0]);
        fgets(buff, 500, stdin);
        if (buff[strlen(buff) - 1] == '\n') buff[strlen(buff) - 1] = '\0';
        c = strtok(buff, " ,.!?;:()[]{}<>");
        for (int j = 1; c; j++) {
            for (int i = 0; c[i]; i++) c[i] = tolower(c[i]);
            strcpy(word[i][j], c);
            wcnt[i] = j;
            c = strtok(NULL, " ,.!?;:()[]{}<>");
        }
    }

    while (1) {
        if (!fgets(buff, 500, stdin)) break;
        if (strlen(buff) == 1) continue;
        if (buff[strlen(buff) - 1] == '\n') buff[strlen(buff) - 1] = '\0';
        c = strtok(buff, " ,.!?;:()[]{}<>");
        r = 0;
        while (c) {
            for (int i = 0; c[i]; i++) c[i] = tolower(c[i]);
            for (int i = 0; i < n; i++) {
                for (int j = 1; j <= wcnt[i]; j++) {
                    if (!strcmp(word[i][j], c)) {
                        printf("%s\n", word[i][0]);
                        r = 1;
                        break;
                    }
                }
                if (r) break;
            }
            if (r) break;
            c = strtok(NULL, " ,.!?;:()[]{}<>");
        }
        if (!r) return 1;
    }
    return 0;
}