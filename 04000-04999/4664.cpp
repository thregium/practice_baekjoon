#include <stdio.h>
#include <map>
using namespace std;

/*
문제 : 4 * 4 크기의 판에서 틱택토를 한다. 현재 x의 차례라면, 반드시 이길 수 있는 수가 있는지 확인하고,
있는 경우 그러한 수 가운데 사전순으로 가장 빠른 수를 출력한다. 없다면 "#####"을 출력한다.
두 사람이 합쳐서 4개 이상의 수를 둔 경우만 주어진다.

해결 방법 : 가능한 모든 경우의 수들을 맵에 집어넣고, x가 이길 수 있는 경우를 1, 없는 경우를 0으로 둔 채로 DP를 진행한다.
X의 차례인 경우 다음 차례에 나오는 1이 있으면 1, 없으면 0이다. o의 차례인 경우 0이 있으면 0, 없으면 1이다.
이를 시행한 다음, 다음 턴으로 가능한 경우 가운데 x가 이길 수 있는 경우가 있으면 그 중 가장 빠른 것을 출력하고,
없다면 #####을 출력하면 된다.

주요 알고리즘 : DP, 게임 이론, 맵

출처 : MidC 1999 A번
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