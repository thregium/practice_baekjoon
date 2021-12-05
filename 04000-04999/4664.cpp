#include <stdio.h>
#include <map>
using namespace std;

/*
���� : 4 * 4 ũ���� �ǿ��� ƽ���並 �Ѵ�. ���� x�� ���ʶ��, �ݵ�� �̱� �� �ִ� ���� �ִ��� Ȯ���ϰ�,
�ִ� ��� �׷��� �� ��� ���������� ���� ���� ���� ����Ѵ�. ���ٸ� "#####"�� ����Ѵ�.
�� ����� ���ļ� 4�� �̻��� ���� �� ��츸 �־�����.

�ذ� ��� : ������ ��� ����� ������ �ʿ� ����ְ�, x�� �̱� �� �ִ� ��츦 1, ���� ��츦 0���� �� ä�� DP�� �����Ѵ�.
X�� ������ ��� ���� ���ʿ� ������ 1�� ������ 1, ������ 0�̴�. o�� ������ ��� 0�� ������ 0, ������ 1�̴�.
�̸� ������ ����, ���� ������ ������ ��� ��� x�� �̱� �� �ִ� ��찡 ������ �� �� ���� ���� ���� ����ϰ�,
���ٸ� #####�� ����ϸ� �ȴ�.

�ֿ� �˰��� : DP, ���� �̷�, ��

��ó : MidC 1999 A��
*/

int b3[16];
char board[8][8];
map<int, int> mem;

void dp(int x, int turn) {
    if (mem.find(x) != mem.end()) return;
    int num[16];
    int res = (!(turn - 1));
    for (int i = 0, y = x; i < 16; i++) {
        num[i] = y % 3;
        y /= 3;
    }
    for (int i = 0; i < 4; i++) {
        if (num[i * 4] == turn && num[i * 4 + 1] == turn && num[i * 4 + 2] == turn && num[i * 4 + 3] == turn) {
            mem.insert(pair<int, int>(x, turn - 1));
            return;
        }
        if (num[i] == turn && num[i + 4] == turn && num[i + 8] == turn && num[i + 12] == turn) {
            mem.insert(pair<int, int>(x, turn - 1));
            return;
        }
    }
    if (num[0] == turn && num[5] == turn && num[10] == turn && num[15] == turn) {
        mem.insert(pair<int, int>(x, turn - 1));
        return;
    }
    if (num[3] == turn && num[6] == turn && num[9] == turn && num[12] == turn) {
        mem.insert(pair<int, int>(x, turn - 1));
        return;
    }

    for (int i = 0; i < 16; i++) {
        if (num[i] == 0) {
            dp(x + b3[i] * turn, 3 - turn);
            if (turn == 1 && mem[x + b3[i] * turn] == 0) res = 0;
            else if (turn == 2 && mem[x + b3[i] * turn] == 1) res = 1;
        }
    }
    mem.insert(pair<int, int>(x, res));
}

int main(void) {
    int x, r;
    char c;
    b3[0] = 1;
    for (int i = 1; i < 16; i++) b3[i] = b3[i - 1] * 3;
    while (1) {
        scanf(" %c", &c);
        if (c == '$') break;
        x = 0;
        for (int i = 0; i < 4; i++) {
            scanf("%s", board[i]);
            for (int j = 0; j < 4; j++) {
                x *= 3;
                if (board[i][j] == 'o') x += 1;
                else if (board[i][j] == 'x') x += 2;
            }
        }
        dp(x, 2);
        r = 0;
        //printf("%d: %d\n", x, mem[x]);
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (board[i][j] == '.') {
                    //printf("%d: %d\n", x + b3[(3 - i) * 4 + (3 - j)] * 2, mem[x + b3[(3 - i) * 4 + (3 - j)] * 2]);
                    if (mem[x + b3[(3 - i) * 4 + (3 - j)] * 2]) {
                        printf("(%d,%d)\n", i, j);
                        r = 1;
                        break;
                    }
                }
            }
            if (r) break;
        }
        if (!r) printf("#####\n");
    }
    return 0;
}