#include <stdio.h>
#include <string.h>

/*
���� : ����� �ٸ� �������� ���� �Ҹ�(<= 10100��)�� �־�����. �̶�, �ٸ� �������� ���� �Ҹ��� ���� �־�����
������ ���� �Ҹ��� ����Ѵ�.

�ذ� ��� : ��ü ���� �Ҹ��� �ܾ� ������ �߶���� ����, �� �ܾ���� �����ص� �ٸ� �������� ���� �Ҹ��� ���Ѵ�.
���� ���� ������ �Ѿ��, ��ο� �ٸ� ���� �Ҹ����� ����ϸ� �ȴ�.

�ֿ� �˰��� : ���ڿ�, �Ľ�, ���Ʈ ����

��ó : CERC 2013 B��
*/

char saying[16384], word[128][128], buff1[128], buff2[128], ani[128][128];

int main(void) {
    int t, n, m;
    char* c;
    //freopen("E:\\PS\\ICPC\\Europe\\CERC\\2013\\b\\b-all.in", "r", stdin);
    scanf("%d", &t);
    getchar();
    for (int tt = 0; tt < t; tt++) {
        fgets(saying, 14400, stdin);
        if (saying[strlen(saying) - 1] == '\n') saying[strlen(saying) - 1] = '\0';

        n = 0;
        c = strtok(saying, " ");
        while (c) {
            strcpy(word[n++], c);
            c = strtok(NULL, " ");
        }
        m = 0;
        while (1) {
            scanf("%s %s %s", buff1, buff2, ani[m++]);
            if (buff2[0] == 'd') {
                m--;
                fgets(buff1, 120, stdin);
                break;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!strcmp(word[i], ani[j])) word[i][0] = '\0';
            }
            if (word[i][0] != '\0') printf("%s ", word[i]);
        }
        printf("\n");
    }
    return 0;
}