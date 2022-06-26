#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
���� : ���� 72 ������ ���ڿ��� ���� �� �־�����. �� ���ڿ��� ������ �����Ͽ� ����� ���� ����� ��,
�ܾ� 3������ ���߲��� ���� ������ �־��� ��Ģ��� ����Ѵ�. ��, theholygrail�̶�� �κ� ������
�����ϴ� ���(��ҹ��� ����), ù ��° ������ "(A childish hand gesture)." �� �Ǿ�� �Ѵ�.

�ذ� ��� : �־��� ���ڿ��� �Ľ��� ���� ���ϴ� ������ ���ڿ��� �ٲٴ� ���ÿ� �ܾ��� ���� theholygrail�̶��
�κ� ������ ���� ���θ� Ȯ���Ѵ�. �׸��� ����� ���� ����ϰ�
�ܾ��� ��, theholygrail ���� ���ο� ���� ���� ���¿����� ������ ����Ѵ�.
���߿��� ������ �Ļ��Ǵ� ��쿡 �����Ѵ�.

�ֿ� �˰��� : ����, ���, �Ľ�

��ó : PacNW 2006 I��
*/

char knight[128], knightmod[128];
char taunt[1024];

const char* theholygrail = "theholygrail";
const int rulecnt[17] = { 4, 3, 1, 2, 2, 1, 1, 3, 5, 11, 2, 2, 1, 7, 5, 1, 1 };
int state[17] = { 0, };

const int rule[7][5][4] = {
    {{1, 1}, {2, 0, 1}, {2, 9, 15}, {1, 1}},
    {{2, 6, 2}, {2, 5, 2}, {3, 6, 12, 9}},
    {{2, 12, 3}},
    {{1, 9}, {2, 4, 9}},
    {{1, 13}, {2, 14, 13}},
    {{3, 16, 7, 10}},
    {{3, 16, 8, 11}}
};

const char* word[17][11] = {
    {""}, {""}, {""}, {""}, {""}, {""}, {""},
    {" steed", " king", " first-born"},
    {" mother", " father", " grandmother", " grandfather", " godfather"},
    {" hamster", " coconut", " duck", " herring", " newt", " peril",
    " chicken", " vole", " parrot", " mouse", " twit"},
    {" is", " masquerades as"},
    {" was", " personified"},
    {" a"},
    {" silly", " wicked", " sordid", " naughty", " repulsive", " malodorous", " ill-tempered"},
    {" conspicuously", " categorically", " positively", " cruelly", " incontrovertibly"},
    {"!"},
    {" your"}
};

void maketaunt(int rulenum) {
    int chk = 0;
    if (rulenum < 7) {
        for (int i = 1; i <= rule[rulenum][state[rulenum]][0]; i++) {
            if (rule[rulenum][state[rulenum]][i] == 0) {
                state[0]++;
                maketaunt(0);
                state[0] -= 2;
            }
            else maketaunt(rule[rulenum][state[rulenum]][i]);
        }
    }
    else strcat(taunt, word[rulenum][state[rulenum]]);
    state[rulenum]++;
    if (state[rulenum] == rulecnt[rulenum]) state[rulenum] = 0;
}

int main(void) {
    int wcnt, pwd, kpos, thg, cap;
    //freopen("E:\\PS\\ICPC\\North America\\Pacific Northwest\\2006\\input\\i.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\North America\\Pacific Northwest\\2006\\output\\i_t.out", "w", stdout);
    while (fgets(knight, 100, stdin)) {
        if (knight[strlen(knight) - 1] == '\n') knight[strlen(knight) - 1] = '\0';
        wcnt = 0, pwd = 0, kpos = 0, thg = 0;
        for (int i = 0; knight[i]; i++) {
            if (knight[i] == ' ') {
                if (kpos == 0 || knightmod[kpos - 1] == ' ') continue;
                else knightmod[kpos++] = ' ';
            }
            else {
                if (kpos == 0 || knightmod[kpos - 1] == ' ') pwd = 1;
                if (pwd && isalpha(knight[i])) {
                    wcnt++;
                    pwd = 0;
                }
                knightmod[kpos++] = knight[i];
            }

            if (thg < 12 && tolower(knight[i]) == theholygrail[thg]) thg++;
        }
        knightmod[kpos] = '\0';
        printf("Knight: %s\n", knightmod);

        if (thg == 12) thg = 1;
        else thg = 0;
        if (thg) {
            printf("Taunter: (A childish hand gesture).\n");
        }

        for (int i = thg * 3; i < wcnt; i += 3) {
            maketaunt(0);
            if (state[0] == 2) {
                state[0]++;
                i += 3;
            }
            cap = 1;
            for (int j = 0; taunt[j]; j++) {
                if (isalpha(taunt[j])) {
                    if (cap) {
                        taunt[j] = toupper(taunt[j]);
                        cap = 0;
                    }
                    else taunt[j] = tolower(taunt[j]);
                }
                else if (taunt[j] == '.' || taunt[j] == '!' || taunt[j] == '?') cap = 1;
            }

            printf("Taunter:%s.\n", taunt);
            taunt[0] = '\0';
        }
        printf("\n");
    }
    return 0;
}