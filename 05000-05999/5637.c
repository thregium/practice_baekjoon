#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
���� : 10000�� ������ ���ڿ��� �־�����. ���ĺ��� '-'�� �̷���� ���� �ܾ�� �ϰ�, �� ���� ���ڰ� �ִٸ�
�ܾ�� ������ ������ ������ ��, ���� �� �ܾ� ��� ó�� ������ ���� �ҹ��ڷ� ����Ѵ�. ���ڿ��� ����
E-N-D��� �ܾ�� �־�����.

�ذ� ��� : ���ڿ��� �����ڸ� ���ĺ� ���ڿ� '-' ���� ��� ���ڷ� ���� ����, �ش� �����ڷ� ���ڿ��� �ܾ� ������ �Ľ��Ѵ�.
��������� �ܾ� ��� ���� �� �ͺ��� �� �ܾ ������ ���� �� �ܾ �����Ѵ�. �ش� �ܾ �ҹ��ڷ� �ٲٴ� �͵� ���� �ʴ´�.
E-N-D�� ������ ��������� �ܾ� ��� ���� �� ���� ����ϸ� �ȴ�.

�ֿ� �˰��� : ���ڿ�, �Ľ�

��ó : Hatyai 2012 J��
*/

char buff[10240], lng[128], delim[256];

int main(void) {
    int p = 0;
    char* t;
    for (char i = 1; i; i++) {
        if (i > 0 && (isalpha(i) || i == '-')) continue;
        delim[p++] = i;
    }
    while (1) {
        fgets(buff, 10123, stdin);
        t = strtok(buff, delim);
        if (t == NULL) continue;
        if (!strcmp(t, "E-N-D")) {
            if (lng[0] == '\0') return 1;
            printf("%s", lng);
            return 0;
        }
        if (strlen(t) > strlen(lng)) {
            strcpy(lng, t);
            for (int i = 0; lng[i]; i++) lng[i] = tolower(lng[i]);
        }
        while (t != NULL) {
            t = strtok(NULL, delim);
            if (t == NULL) break;
            if (!strcmp(t, "E-N-D")) {
                if (lng[0] == '\0') return 1;
                printf("%s", lng);
                return 0;
            }
            if (strlen(t) > strlen(lng)) {
                strcpy(lng, t);
                for (int i = 0; lng[i]; i++) lng[i] = tolower(lng[i]);
            }
        }
    }
    return 0;
}