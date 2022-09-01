#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#define height 30
#define width 30
#define SIZE 1000
int x, y, fx, fy, score, gameover, flag, count = 0;
int tailx[SIZE], taily[SIZE];
void move();
void input();
void setup()
{

    gameover = 0;
    x = width / 2;
    y = height / 2;
l1: 
    fx = rand() % 30;
    if (fx == 0)
    {
        goto l1;
    }
l2:
    fy = rand() % 30;
    if (fy == 0)
    {
        goto l2;
    }

    score = 0;
}

void Box()
{
    int i, j;
    system("cls");
    for (i = 0; i <= width; i++)
    {
        for (j = 0; j <= height; j++)
        {
            if (i == 0 || i == height || j == 0 || j == width)
            {
                printf("*");
            }
            else
            {
                if (i == x && j == y)
                {
                    printf("O");
                }

                else if (i == fx && j == fy)
                {
                    printf("#");
                }
                else
                {
                    int c = 0;
                    for (int m = 0; m < count; m++)
                    {
                        if (i == tailx[m] && j == taily[m])
                        {
                            printf("o");
                            c = 1;
                        }
                    }
                    if (c == 0)
                        printf(" ");
                }
            }
        }

        printf("\n");
    }
}
int main()
{
    setup();
    while (!gameover)
    {
        Box();
        Sleep(100 - score);
        input();
        move();
    }

    return 0;
}
void input()
{
    if (kbhit())
    {
        switch (getch())
        {
        case 'a':
            flag = 1;
            break;
        case 's':
            flag = 2;
            break;
        case 'w':
            flag = 3;
            break;
        case 'd':
            flag = 4;
            break;
        }
    }
}

void move()
{
    int prevX = tailx[0];
    int prevY = taily[0];
    int prev2x, prev2y;
    tailx[0] = x;
    taily[0] = y;
    for (int i = 1; i < count; i++)
    {
        prev2x = tailx[i];
        prev2y = taily[i];
        tailx[i] = prevX;
        taily[i] = prevY;
        prevX = prev2x;
        prevY = prev2y;
    }

    switch (flag)
    {
    case 1:
        y--;
        break;
    case 2:
        x++;
        break;
    case 3:
        x--;
        break;
    case 4:
        y++;
        break;

    default:
        break;
    }
    if (x < 0 || x > width || y < 0 || y > height)
    {
        gameover = 1;
    }
    for (int i = 0; i < count; i++)
    {
        if (x == tailx[i] && y == taily[i])
        {
            gameover = 1;
        }
    }

    if (x == fx && y == fy)
    {
    l3:
        fx = rand() % 30;
        if (fx == 0)
        {
            goto l3;
        }
    l4:
        fy = rand() % 30;
        if (fy == 0)
        {
            goto l4;
        }
        score++;
        count++;
    }
    printf(" your score is %d", score);
}
