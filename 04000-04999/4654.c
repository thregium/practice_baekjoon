#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/*
���� : �־��� �������� ������ ����� ����Ѵ�. {} �ȿ� �ִ� ������ ����̸�, 1���� 2�� �������� ������.
$�� �ڿ� �ִ� ������ 2�� �����̰�, %�� �ִٸ� �� ���� �������� �����ؾ� �Ѵ�. &�� ������ �ٲ��̴�.
����� ������ ���������� �����ϵ�, ��ҹ��ڸ� �������� �ʴ´�. {}�� �ִ� 100���̸�, �� {}�� ���̴� �ִ� 80�̴�.

�ذ� ��� : ���� ������ ������ �� ������ ���� ����, �� �ٲ��� �������� �ٲٰ� ���� �̾��ش�.
�׸��� {} �ȿ� �ִ� ������� ���� ������ �����صд�.
�� �������δ� 1���� 2�� ������ ������ �յ��� ������ �����Ͽ� �����Ѵ�.
���� 1�� ����� ���� ���� ���ο� �ִ� �� ã�� �׷��ϴٸ� �� ���ο� ���� �������� �߰��Ѵ�.(�̹� �ִٸ� �߰����� �ʴ´�.).
�׸��� �� ���ο� 2�� ������ Ȯ���� ���� ���� �ִٸ� �ű⿡�� ���� �������� �߰��Ѵ�. ���ٸ� 2�� ������ ��ũ�� ���� ����,
���� 2�� ������ ������ �ۼ��Ѵ�. 1�� ���뵵 ���ٸ� ���������� �Ѵ�.

�̸� �ݺ��� ����, ��� ������ ������ٸ� �� ���ε��� �����Ѵ�. ���� �Լ��� ���� ���鵵�� �Ѵ�.
�׸��� ���������� ���Ŀ� �°� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����, ���ڿ�, �Ľ�, ����

��ó : MidC 2001 D��
*/

typedef struct entry {
    char term[128]; //������ ���ڿ�
    int page[16]; //�����ϴ� ������
    int subn[8]; //�ش� ������ 2�� ���� ��ȣ��
} entry;

char buff[128], str[103000], mark[128][128], ps[128], ss[128];
int mp[128];
entry primary[32], secondary[128];

int cmp1(const void* a, const void* b) {
    //1�� ����
    entry ai = *(entry*)a;
    entry bi = *(entry*)b;
    for (int i = 0; i < 128; i++) {
        if (tolower(ai.term[i]) > tolower(bi.term[i])) return 1;
        else if (tolower(ai.term[i]) < tolower(bi.term[i])) return -1;
    }
    return 0;
}

int cmp2(const void* a, const void* b) {
    //2�� ����
    entry ai = secondary[*(int*)a];
    entry bi = secondary[*(int*)b];
    for (int i = 0; i < 128; i++) {
        if (tolower(ai.term[i]) > tolower(bi.term[i])) return 1;
        else if (tolower(ai.term[i]) < tolower(bi.term[i])) return -1;
    }
    return 0;
}

void trim(char* s) {
    //���ڿ� �յ��� ������ ������
    int st = -1;
    for (int i = 0; s[i]; i++) {
        if (s[i] != ' ' && st < 0) st = i;
        if (st >= 0) s[i - st] = s[i];
        if (!s[i + 1]) s[i + 1 - st] = '\0';
    }
    for (int i = strlen(s) - 1; i >= 0; i--) {
        if (s[i] != ' ') {
            s[i + 1] = '\0';
            break;
        }
    }
}

int main(void) {
    int end = 0, pn, sn, mn, page, ex;
    char* ptr;
    //freopen("E:\\PS\\ICPC\\North America\\Mid Central\\mcpc2001\\indexgen\\indexgen.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\North America\\Mid Central\\mcpc2001\\indexgen\\indexgen_t.out", "w", stdout);
    for (int tt = 1;; tt++) {
        strcpy(str, " ");
        while (1) {
            //���� ���� �̾��ֱ�
            fgets(buff, 100, stdin);
            if (buff[strlen(buff) - 1] == '\n') buff[strlen(buff) - 1] = ' ';
            strcat(str, buff);
            if (strstr(buff, "**") == buff) {
                end = 1;
                break;
            }
            else if (strstr(buff, "*") == buff) break;
        }
        if (end) break;
        pn = 0, sn = 0, mn = 0, page = 1;
        ptr = strtok(str, "{");
        while (ptr) {
            //��ȣ, ������ Ȯ��
            for (int i = 0; ptr[i]; i++) page += (ptr[i] == '&');
            ptr = strtok(NULL, "}");
            if (!ptr) break;
            mp[mn] = page;
            strcpy(mark[mn++], ptr);
            ptr = strtok(NULL, "{");
        }

        for (int i = 0; i < mn; i++) {
            //%, $ Ȯ��
            if (strchr(mark[i], '%')) {
                ptr = strtok(mark[i], "%");
                ptr = strtok(NULL, "%");
                if (ptr == NULL) return 1;
                strcpy(mark[i], ptr);
            }
            ptr = strtok(mark[i], "$");
            strcpy(ps, ptr);
            ptr = strtok(NULL, "$");
            if (ptr) strcpy(ss, ptr);
            else ss[0] = '\0';
            trim(ps);
            if (ss[0]) trim(ss);

            //printf("%s:%s-%d\n", ps, ss, mp[i]);
            ex = 0;
            for (int j = 0; j < pn; j++) {
                if (!strcmp(ps, primary[j].term)) {
                    //1�� ���� Ȯ��
                    if (ss[0] == '\0' && primary[j].page[primary[j].page[0]] != mp[i]) {
                        primary[j].page[++primary[j].page[0]] = mp[i];
                    }
                    ex = 1;
                    if (ss[0] != '\0') {
                        //2�� ���� Ȯ��
                        for (int k = 1; k <= primary[j].subn[0]; k++) {
                            if (!strcmp(ss, secondary[primary[j].subn[k]].term)) {
                                if (secondary[primary[j].subn[k]].page[secondary[primary[j].subn[k]].page[0]] != mp[i]) {
                                    secondary[primary[j].subn[k]].page[++secondary[primary[j].subn[k]].page[0]] = mp[i];
                                }
                                ex = 2;
                                break;
                            }
                        }
                        if (ex == 1) {
                            primary[j].subn[++primary[j].subn[0]] = sn;
                            strcpy(secondary[sn].term, ss);
                            secondary[sn].page[0]++;
                            secondary[sn].page[1] = mp[i];
                            sn++;
                        }
                    }
                    break;
                }
            }
            if (!ex) {
                //1�� ������ ��ġ�ϴ� ��찡 ���� ��
                strcpy(primary[pn].term, ps);
                if (ss[0] != '\0') {
                    primary[pn].subn[++primary[pn].subn[0]] = sn;
                    strcpy(secondary[sn].term, ss);
                    secondary[sn].page[0]++;
                    secondary[sn].page[1] = mp[i];
                    sn++;
                }
                else {
                    primary[pn].page[0]++;
                    primary[pn].page[1] = mp[i];
                }
                pn++;
            }
        }
        //����
        qsort(primary, pn, sizeof(entry), cmp1);
        for (int i = 0; i < pn; i++) {
            qsort(&primary[i].subn[1], primary[i].subn[0], sizeof(int), cmp2);
        }


        //���
        printf("DOCUMENT %d\n", tt);
        for (int i = 0; i < pn; i++) {
            printf("%s", primary[i].term);
            for (int j = 1; j <= primary[i].page[0]; j++) {
                printf(", %d", primary[i].page[j]);
            }
            printf("\n");
            for (int j = 1; j <= primary[i].subn[0]; j++) {
                printf("+ %s, ", secondary[primary[i].subn[j]].term);
                for (int k = 1; k <= secondary[primary[i].subn[j]].page[0]; k++) {
                    printf("%d", secondary[primary[i].subn[j]].page[k]);
                    if (k < secondary[primary[i].subn[j]].page[0]) printf(", ");
                }
                printf("\n");
            }
        }

        //�ʱ�ȭ
        for (int i = 0; i < pn; i++) {
            primary[i].page[0] = 0;
            primary[i].subn[0] = 0;
        }
        for (int i = 0; i < sn; i++) secondary[i].page[0] = 0;
    }
    return 0;
}