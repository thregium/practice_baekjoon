#include <stdio.h>

//00:47:22

/*
문제 : 3 * 3 * 3 큐브를 처음 상태에서 주어진 방향에 따라 돌리고 마지막 상태의 윗면을 출력한다.

해결 방법 : 각 방향에 따라 돌아가는 칸의 위치들을 하드코딩한다.

주요 알고리즘 : 구현, 시뮬레이션, 케이스 워크

출처 : BAPC 2012P C번
*/

char cells[64] = { ' ', };
char *init = "wrbogy", *dir = "UFRBLD"; //처음 상태의 색깔들과, 숫자가 늘어나는 순으로 각 면의 위치들이다.
int outer[6][12] = { {12, 11, 10, 39, 38, 37, 30, 29, 28, 21, 20, 19}, {7, 8, 9, 19, 22, 25, 48, 47, 46, 45, 42, 39},
    {9, 6, 3, 28, 31, 34, 54, 51, 48, 18, 15, 12}, {3, 2, 1, 37, 40, 43, 52, 53, 54, 27, 24, 21},
    {1, 4, 7, 10, 13, 16, 46, 49, 52, 36, 33, 30} , {16, 17, 18, 25, 26, 27, 34, 35, 36, 43, 44, 45} };
//위에서 나온 각 면의 위치들을 돌리면 돌아가는 주변 칸들이다. (시계방향 순서로 되어있다,)
int inner[8] = { 1, 2, 3, 6, 9, 8, 7, 4 }; //각 면을 돌리면 돌아가는 그 면의 칸들이다. 역시 시계방향 순서로 되어있다.

void turn(int d, int cw) {
    //D : 돌리는 면, CW : 방향(1 : 시계방향, -1 : 반시계방향)
    char tmp[3];
    if (cw > 0) {
        //주변 칸들을 시계방향으로 3칸씩 민다.
        for (int i = 0; i < 3; i++) tmp[i] = cells[outer[d][i + 9]];
        for (int i = 11; i >= 3; i--) cells[outer[d][i]] = cells[outer[d][i - 3]];
        for (int i = 0; i < 3; i++) cells[outer[d][i]] = tmp[i];
        //해당 칸들을 시계방향으로 2칸씩 민다.
        for (int i = 0; i < 2; i++) tmp[i] = cells[inner[i + 6] + 9 * d];
        for (int i = 7; i >= 2; i--) cells[inner[i] + 9 * d] = cells[inner[i - 2] + 9 * d];
        for (int i = 0; i < 2; i++) cells[inner[i] + 9 * d] = tmp[i];
    }
    else {
        //주변 칸들을 반시계방향으로 3칸씩 민다.
        for (int i = 0; i < 3; i++) tmp[i] = cells[outer[d][i]];
        for (int i = 0; i < 9; i++) cells[outer[d][i]] = cells[outer[d][i + 3]];
        for (int i = 9; i < 12; i++) cells[outer[d][i]] = tmp[i - 9];
        //해당 칸들을 반시계방향으로 2칸씩 민다.
        for (int i = 0; i < 2; i++) tmp[i] = cells[inner[i] + 9 * d];
        for (int i = 0; i < 6; i++) cells[inner[i] + 9 * d] = cells[inner[i + 2] + 9 * d];
        for (int i = 6; i < 8; i++) cells[inner[i] + 9 * d] = tmp[i - 6];
    }
}

int main(void) {
    int t, n, d;
    char buff[16] = { 0, };
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        for (int i = 1; i <= 54; i++) {
            cells[i] = init[(i - 1) / 9]; //처음 상태로 큐브를 맞춰둔다.
        }
        for (int i = 0; i < n; i++) {
            scanf("%s", buff);
            d = -1;
            for (int j = 0; j < 6; j++) {
                if (dir[j] == buff[0]) d = j; //어느 방향을 돌리는지 확인한다.
            }
            if (d < 0) return 1;
            turn(d, buff[1] == '+' ? 1 : -1);
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                printf("%c", cells[i * 3 + j + 1]); //맨 윗 칸의 상태를 출력한다.
            }
            printf("\n");
        }
    }
    return 0;
}

/*
Didn't you say you must do it?
Why is it always like that?
Didn't you say you'd gotten tired of it?
Don't come to me and ask for my sympathy.

How many times are you going to make me say
"Why are you such a sissy?"
Stop looking so sloppy,
and pull yourself together.

You let out a laugh to dodge my question,
completely ignoring what I was saying.
Don't use "-chan", just call me by my name.
It makes me feel too mushy.

Stop using those heart emoticons,
and please just text normally.
I like the usual you.

I know you like me,
but don't hug me in front of people.
When we're alone,
I'll hug you as much as you like.

Our Rubik's cube can't seem to be solved
no matter how much time has passed.
We turn and turn and turn and turn and turn
and turn and turn, but can't solve it.
Our Rubik's cube remains unsolved
no matter how far we go, how much we say, or how much we come.

Why do we have such a desire to test whether or not this is love?
Please tell me.

"Let's warm each other up under the blanket until morning."
This joke gives me the shivers.
We turn and turn and turn and turn and turn
and turn and turn, but you still don't get it?

Our Rubik's cube can't seem to be solved
no matter how much time has passed.
We turn and turn and turn and turn and turn
and turn and turn, but can't solve it.
Our Rubik's cube remains unsolved
no matter how far we go, how much we say, or how much we come.

Why do we have such a desire to test whether or not this is love?

Why do I love you this much?
Please tell me the solution to the Rubik's cube of our love.
I love and love and love and love and love
and love you, so please love me back. I love you.
I don't care how much we come or reach climax,
so please solve our Rubik's cube.

We have such a desire to test whether or not this is love simply because
◆◆◆◆◆◆
*/