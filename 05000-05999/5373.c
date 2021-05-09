#include <stdio.h>

//00:47:22

/*
���� : 3 * 3 * 3 ť�긦 ó�� ���¿��� �־��� ���⿡ ���� ������ ������ ������ ������ ����Ѵ�.

�ذ� ��� : �� ���⿡ ���� ���ư��� ĭ�� ��ġ���� �ϵ��ڵ��Ѵ�.

�ֿ� �˰��� : ����, �ùķ��̼�, ���̽� ��ũ

��ó : BAPC 2012P C��
*/

char cells[64] = { ' ', };
char *init = "wrbogy", *dir = "UFRBLD"; //ó�� ������ ������, ���ڰ� �þ�� ������ �� ���� ��ġ���̴�.
int outer[6][12] = { {12, 11, 10, 39, 38, 37, 30, 29, 28, 21, 20, 19}, {7, 8, 9, 19, 22, 25, 48, 47, 46, 45, 42, 39},
    {9, 6, 3, 28, 31, 34, 54, 51, 48, 18, 15, 12}, {3, 2, 1, 37, 40, 43, 52, 53, 54, 27, 24, 21},
    {1, 4, 7, 10, 13, 16, 46, 49, 52, 36, 33, 30} , {16, 17, 18, 25, 26, 27, 34, 35, 36, 43, 44, 45} };
//������ ���� �� ���� ��ġ���� ������ ���ư��� �ֺ� ĭ���̴�. (�ð���� ������ �Ǿ��ִ�,)
int inner[8] = { 1, 2, 3, 6, 9, 8, 7, 4 }; //�� ���� ������ ���ư��� �� ���� ĭ���̴�. ���� �ð���� ������ �Ǿ��ִ�.

void turn(int d, int cw) {
    //D : ������ ��, CW : ����(1 : �ð����, -1 : �ݽð����)
    char tmp[3];
    if (cw > 0) {
        //�ֺ� ĭ���� �ð�������� 3ĭ�� �δ�.
        for (int i = 0; i < 3; i++) tmp[i] = cells[outer[d][i + 9]];
        for (int i = 11; i >= 3; i--) cells[outer[d][i]] = cells[outer[d][i - 3]];
        for (int i = 0; i < 3; i++) cells[outer[d][i]] = tmp[i];
        //�ش� ĭ���� �ð�������� 2ĭ�� �δ�.
        for (int i = 0; i < 2; i++) tmp[i] = cells[inner[i + 6] + 9 * d];
        for (int i = 7; i >= 2; i--) cells[inner[i] + 9 * d] = cells[inner[i - 2] + 9 * d];
        for (int i = 0; i < 2; i++) cells[inner[i] + 9 * d] = tmp[i];
    }
    else {
        //�ֺ� ĭ���� �ݽð�������� 3ĭ�� �δ�.
        for (int i = 0; i < 3; i++) tmp[i] = cells[outer[d][i]];
        for (int i = 0; i < 9; i++) cells[outer[d][i]] = cells[outer[d][i + 3]];
        for (int i = 9; i < 12; i++) cells[outer[d][i]] = tmp[i - 9];
        //�ش� ĭ���� �ݽð�������� 2ĭ�� �δ�.
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
            cells[i] = init[(i - 1) / 9]; //ó�� ���·� ť�긦 ����д�.
        }
        for (int i = 0; i < n; i++) {
            scanf("%s", buff);
            d = -1;
            for (int j = 0; j < 6; j++) {
                if (dir[j] == buff[0]) d = j; //��� ������ �������� Ȯ���Ѵ�.
            }
            if (d < 0) return 1;
            turn(d, buff[1] == '+' ? 1 : -1);
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                printf("%c", cells[i * 3 + j + 1]); //�� �� ĭ�� ���¸� ����Ѵ�.
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
�ߡߡߡߡߡ�
*/