#include <stdio.h>
#include <string.h>

/*
���� : �ִ� 16��, 4����� ������ ��ʸ�Ʈ�� ��� ����� �־�����. �� ��Ⱑ � ���忡 �־������� �˾Ƴ� ���� ����ǥ�� ����Ѵ�.
��, ��ʸ�Ʈ���� 2���� �Ǵ� �� ���ĺ��� ��⿡ ���� ������ ������ �� �ִ�.
����ǥ�� ������ ���� �ۼ��Ѵ�. ���� �̸��� ���� ������ �� ���庰 ���� �̸� ��� ���� �� �Ϳ��� 2ĭ�� ������ �ΰ� ������ ĭ����
_�� ����. 1������ �� ������(��� ������ 1������� �ִ� ���) 2�پ� ���� ����Ѵ�. �׸��� �� ���̸� \�� /�� ����
�밢������ �̾�� �ϰ� 2���� �̻��� ������ �� �̾��� ��ġ���� ����ϱ� �����ؾ� �Ѵ�.
���� : 
5
apple banana
banana coconut
banana
Tournament 1
_apple__
        \_banana__
_banana_/         \
                   \_banana_
                   /
         _coconut_/

�ذ� ��� : ����, �� ��Ⱑ �� ������ �� ��° ��⿴������ Ȯ���ؾ� �Ѵ�.
�̴� �� ���忡�� ���� ����� �����ϴ� ���� ����ٴ� ���� �̿��� Ȯ�� �����ϴ�. �ش� ��� ������ ����(�Ǵ� ���� ����)����
�ش� ����� ���� �� ��ġ�� ���� �ϳ��� ������ ���̱� �����̴�. �� ���� ��� ���� ���� ���� ��Ⱑ �ش� ����� ���ڰ�
������ ���� ��ȸ�� ���̹Ƿ� �� ������ ���� �������� �� �� �ִ�. ����, ��� ��ȣ ���� �̸��� ��ġ�� ���� ��ġ�� ����
�����̸� �ش� ��ȣ�� 2�� - 1, �Ʒ����̸� 2�踦 ���ָ� ������ �� �� �ִ�.(1���� ������ ��)

���� ���� �������� ���� ����ǥ�� �ۼ��Ѵ�.
�̶�, ������ �� ���庰�� ���� �� ������ ���̸� ��ó�� �صδ� ���� ����. ��ó���� ������ �� ��⺰�� ������ �ۼ��Ѵ�.
�� ������ ���ο� ���� ��ġ�� �˾Ƴ� ����, �� �ٿ� _�� ������ ������ ����Ѵ�. �� ���� \�� /�� �̿��� �� ���� �ϳ��� ������
�ؾ� �Ѵ�. ����������, ���� ���ڸ� ���� ����ϸ� �ȴ�.
���� ��ġ�� ��Ʈ ������ ���� �� ���� �� ���� ���ݰ� �ش� ������ �ִ� �� ���� ���ϸ� �˾Ƴ� �� �ְ�,
���� ��ġ�� ���� ������ ���� �� ������ ������ �տ� �밢�� ������ ��Ʈ ������ ���� �˾Ƴ��� ���ϸ� �ȴ�.

�ֿ� �˰��� : ����, �׸��� �˰���

��ó : MidC 2003 H��
*/

typedef struct bracket {
    //�� ����� ������, ����1, ����2, ����(����), ��� ��ȣ
    char team1[16];
    char team2[16];
    int level;
    int ht;
} bracket;

char winner[16], result[128][128]; //���� ���ڿ� �׷��� ����ǥ
int longest[16], ends[128]; //���庰 ���� �� ������ ���̿� �� ���� ���� ����ؾ� �ϴ� ����
int n, hlv = 0, top = 0, bottom = 0; //N, �ְ� ����, ����� ���� ��, �Ʒ��� ��
bracket compete[32];

int getlevel(int start, char* team) {
    //start ������ ��⿡�� �ش� ���� ������ ù ����� ���带 �����´�.
    for (int i = start + 1; i < n / 2; i++) {
        if (!strcmp(team, compete[i].team1) || !strcmp(team, compete[i].team2)) return compete[i].level;
    }
    if (!strcmp(team, winner)) return 0;
    else return -1;
}

int getht(int start, char* team) {
    //�ش� ����� ��� ��ȣ�� ã�Ƴ���.
    for (int i = start + 1; i < n / 2; i++) {
        if (!strcmp(team, compete[i].team1)) return compete[i].ht * 2 - 1;
        if (!strcmp(team, compete[i].team2)) return compete[i].ht * 2;
    }
    return 1;
}

int getsize(int lv) {
    //�� ������ ���� ������ �˾Ƴ���.
    return 1 << (hlv - lv);
}

int getheight(int lv, int ht) {
    //�ش� ����� �߰� ���̸� �˾Ƴ���.
    int size = getsize(lv) * 2;
    int max = (1 << (lv - 1));
    return 64 + size * (ht * 2 - 1 - max);
}

int getcolumn(int lv) {
    //�ش� ����� ���� ���� �˾Ƴ���.
    int c = 0;
    for (int i = lv + 1; i <= hlv; i++) {
        c += longest[i] + 2 + (1 << (hlv - i));
    }
    return c;
}

int main(void) {
    int lt1, lt2, x, y, sz;
    //freopen("C:\\1_����\\PS\\ICPC\\North America\\Mid Central\\mcpc2003\\tourn\\tourn.in", "r", stdin);
    //freopen("C:\\1_����\\PS\\ICPC\\North America\\Mid Central\\mcpc2003\\tourn\\tourn_check.out", "w", stdout);
    for (int tt = 1;; tt++) {
        scanf("%d", &n);
        if (n < 0) break;
        hlv = 0, top = 64, bottom = 64;
        for (int i = 0; i < n / 2; i++) {
            scanf("%s %s", compete[i].team1, compete[i].team2);
        }
        scanf("%s", winner);
        for (int i = n / 2 - 1; i >= 0; i--) {
            //�ش� ����� �� ���� ������ ���带 �˾Ƴ���.
            lt1 = getlevel(i, compete[i].team1);
            lt2 = getlevel(i, compete[i].team2);
            if (lt1 > lt2) {
                //ù ��° ���� ������ ���
                compete[i].level = lt1 + 1;
                compete[i].ht = getht(i, compete[i].team1);
            }
            else {
                //�� ��° ���� ������ ���
                compete[i].level = lt2 + 1;
                compete[i].ht = getht(i, compete[i].team2);
            }

            //���� ���� �� ����� �� ���庰 ���� �� ���� ������Ʈ
            if (compete[i].level > hlv) hlv = compete[i].level;
            if (longest[compete[i].level] < strlen(compete[i].team1)) longest[compete[i].level] = strlen(compete[i].team1);
            if (longest[compete[i].level] < strlen(compete[i].team2)) longest[compete[i].level] = strlen(compete[i].team2);
        }
        for (int i = 0; i < n / 2; i++) {
            x = getheight(compete[i].level, compete[i].ht);
            y = getcolumn(compete[i].level);
            sz = getsize(compete[i].level);
            for (int j = y; j < y + longest[compete[i].level] + 2; j++) {
                //�� ������ ����Ѵ�.
                if (j > y && compete[i].team1[j - y - 1]) result[x - sz][j] = compete[i].team1[j - y - 1];
                else result[x - sz][j] = '_';
                if (j > y && compete[i].team2[j - y - 1]) result[x + sz][j] = compete[i].team2[j - y - 1];
                else result[x + sz][j] = '_';
            }
            y += longest[compete[i].level] + 2;
            if (ends[x - sz] < y - 1) ends[x - sz] = y - 1;
            if (ends[x + sz] < y - 1) ends[x + sz] = y - 1;
            for (int j1 = x - sz + 1, j2 = x + sz; j1 < j2; j1++, j2--) {
                //�� �밢������ ����Ѵ�.
                result[j1][y] = '\\';
                result[j2][y] = '/';
                if (ends[j1] < y) ends[j1] = y;
                if (ends[j2] < y) ends[j2] = y;
                y++;
            }
            if (x - sz < top) top = x - sz;
            if (x + sz > bottom) bottom = x + sz;
        }
        for (int i = 0; i < strlen(winner) + 2; i++) {
            if (i == 0 || i == strlen(winner) + 1) result[64][i + getcolumn(0)] = '_';
            else result[64][i + getcolumn(0)] = winner[i - 1];
        }
        ends[64] = getcolumn(0) + strlen(winner) + 1;

        printf("Tournament %d\n", tt);
        for (int i = top; i <= bottom; i++) {
            for (int j = 0; j <= ends[i]; j++) {
                if (result[i][j]) printf("%c", result[i][j]); //������ ����� ��µ��� ������ ����Ѵ�.
                else printf(" ");
                result[i][j] = '\0'; //����� ������ �ʱ�ȭ�Ѵ�.
            }
            ends[i] = 0;
            printf("\n");
        }
        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < 16; j++) {
                //������ ��ĥ �� �����Ƿ� ���� �ʱ�ȭ�Ѵ�.
                compete[i].team1[j] = '\0';
                compete[i].team2[j] = '\0';
            }
        }
        for (int i = 1; i <= hlv; i++) longest[i] = 0; //�� ���庰�� ���� �� ���� �ʱ�ȭ�Ѵ�.
    }
    return 0;
}