#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
���� : �־��� XML ������ ��Ģ�� �´��� �˻��ϴ� ���α׷��� �����.

�ذ� ��� : �� �±׵��� ���� �и��ؼ� Ű������ �±��� ����(���� ����, �Ű� ���� ��)�� ��´�.
Ű������� ������� ���ÿ� �����ϰ� ���� ���ÿ��� ���� �������� ���� �ʴ� ���� �����ų� ������ �� ���¿��� ������ �ϴ�
���� ��Ȳ�� ������ ��Ģ�� ���� ������ �� �� �ִ�. ����, ���ÿ� �ִ� ������ �ٽ� �ְų� ���α׷��� ����ǰ�
���ÿ� ���� �����ִ� ���, �ƴϸ� ���� �±װ� 2�� �̻��� ��� � ���� üũ�Ѵ�.

�ֿ� �˰��� : ����, �Ľ�, ����

��ó : GNY 2000 E��
*/

char buff[1024], temp[64], stack[1024][64];//, lastelems[1024][16][64];
int sttop = 0;

int parse(void) {
    int bracket = 0, ends = 0, tp = 0, at = 0, fin = 0;
    for (int i = 0; buff[i]; i++) {
        if (buff[i] == '<') {
            if (bracket || fin) return 0;
            bracket = 1;
        }
        else if (buff[i] == '>') {
            if (!bracket) return 0;
            if (at > 0 && at % 2 == 0) return 0;
            if (ends == 0) {
                //���ο� �±��� ���
                for (int j = 0; j < sttop; j++) {
                    if (!strcmp(temp, stack[j])) return 0; //���� ���ÿ� �̹� �����ϴ� �±׶�� ��Ģ ����
                }
                strcpy(stack[sttop], temp);
                sttop++;
            }
            else if (ends == 1) {
                //�ݴ� �±��� ���
                if (strcmp(temp, stack[sttop - 1])) return 0; //������ ������ ���� �ٸ��ٸ� ��Ģ ����
                else {
                    sttop--;
                    if (sttop < 0) {
                        sttop = 0;
                        return 0; //������ 0�ε� �ݴ� �±װ� ���� ��� ��Ģ ����
                    }
                    else if (sttop == 0) fin = 1;
                }
            }
            else {
                //������ �±��� ���
                for (int j = 0; j < sttop; j++) {
                    if (!strcmp(temp, stack[j])) return 0; //���ÿ� �����ϴ� �±׶�� ��Ģ ����
                }
            }
            ends = 0;
            at = 0;
            bracket = 0;
            tp = 0;
        }
        if (buff[i] == '/' && bracket) {
            if (tp) ends = 2; //���� /�� �ִ� ���
            else ends = 1; //���ۿ� /�� �ִ� ���
        }
        else if (bracket && (isalpha(buff[i]) || isdigit(buff[i]) || buff[i] == '-') && at == 0) {
            //Ű���� �߰�
            temp[tp++] = buff[i];
            temp[tp] = '\0';
        }
        else if (bracket && buff[i] == ' ') {
            at = 1; //���ķδ� �Ű� ����
        }
        else if (bracket && at && buff[i] == '\"') at++; //"�� ¦���� �־�� ��
    }
    return 1;
}

int main(void) {
    int r;
    //freopen("C:\\1_����\\PS\\ICPC\\North America\\Greater New York\\2000\\probleme.in", "r", stdin);
    //freopen("C:\\1_����\\PS\\ICPC\\North America\\Greater New York\\2000\\probleme_check.out", "w", stdout);
    for (int tt = 0;; tt++) {
        if (tt == 0) fgets(buff, 1000, stdin);
        if (strstr(buff, "<?end?>")) break;
        r = 1;
        sttop = 0;
        fgets(buff, 1000, stdin);
        r = parse();
        while (r && sttop) {
            //��Ģ�� �´ٸ� ������ �� �� ���� �Ľ�
            fgets(buff, 1000, stdin);
            if (strstr(buff, "<?xml version=\"1.0\"?>") || strstr(buff, "<?end?>")) break;
            r = parse();
        }

        while (!strstr(buff, "<?xml version=\"1.0\"?>") && !strstr(buff, "<?end?>")) {
            //��Ģ�� ���� �ʴ� ��� ���� �׽�Ʈ ���̽��� ���� ���������� ���ڿ��� ����
            fgets(buff, 1000, stdin);
            if (strstr(buff, "<?xml version=\"1.0\"?>") || strstr(buff, "<?end?>")) break;
            if (!strcmp(buff, "\n")) continue;
            r = 0;
        }
        if (sttop) {
            //���ÿ� ���� �����ִ� ��� ��Ģ ����
            r = 0;
            sttop = 0;
        }
        if (!r) printf("non ");
        printf("well-formed\n");
        continue;
    }
    return 0;
}