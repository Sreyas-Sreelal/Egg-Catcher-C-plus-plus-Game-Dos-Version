/*

	MIT License

	Copyright (c) 2016 Sreyas

	Permission is hereby granted, free of charge, to any person obtaining a copy
	of this software and associated documentation files (the "Software"), to deal
	in the Software without restriction, including without limitation the rights
	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
	copies of the Software, and to permit persons to whom the Software is
	furnished to do so, subject to the following conditions:

	The above copyright notice and this permission notice shall be included in all
	copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
	SOFTWARE.





	|-------SS---EGG---CATCHER---GAME---C++---BY---SREYAS------------------|
	|                                                                      |
	|                 Author:Sreyas                                        |
	|                 Use A and D to move                                  |
	|   		  10 Score for each egg                                |
	|                                                                      |
	|----------------------------------------------------------------------|

*/
#include <fstream.h>
#include <conio.h>
#include <stdlib.h>
#include <dos.h>
#include <stdio.h>
#include <string.h>
#include <graphics.h>

#include "register.cpp"

int gameover = 0, x, y, width, height, bx, by, score = 0;

enum DIRECTION
{
    LEFT,
    RIGHT
} dir;

P_DATA s[100], temp;

void setup()
{
    int i, j;
    clrscr();
    cout << "\t\t||||SCORE|||||: " << score << endl << "Hint:Press x to close the game" << endl;
    for (i = 0; i <= height; i++)
    {

        for (j = 0; j <= width; j++)
        {
            if (i == y && j == width - 2)
                cout << "#";

            else if (i == 0 || i == height || j == 0 || j == width)
            {

                if (i == y && j == width)
                    continue;

                else
                {
                    textcolor(RED);
                    cprintf("#");
                }
            }

            else if (i == y && j == x)
            {
                textcolor(BROWN);
                cprintf("|_|");
            }

            else if (i == by && j == bx)
            {
                textcolor(WHITE);
                cprintf("O");
            }

            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}


void createblock()
{
    bx = random(width - 1) + 5;
    by = random(5);
}

void moveblockdown()
{

    by++;

    if (by == y && (x == bx || x == bx + 1 || x == bx - 1 || x == bx - 2 || x == bx + 2))
    {
        score += 10;
        createblock();
    }

    if (x <= 0)
    {
        x = width - 3;
    }

    else if (x >= width - 2)
    {
        x = 1;
    }
}

void getkey()
{
    if (kbhit())
    {

        switch (getch())
        {
            case 'd':
                x += 2;
                break;
            case 'a':
                x -= 2;
                break;
            case 'x':
                gameover = 1;
                break;
        }
    }
}

void menu()
{
    clrscr();
    int res;

    cout << "\n\
		1.Login\n\
		2.Register\n\
		3.Highscores\n\
		4.Help\n\
		5.About\n\
		6.Exit";
    cin >> res;

    switch (res)
    {

        case 1:
            Login();

            break;

        case 2:
            Register();

            break;

        case 3:
            // need to work on

            break;

        case 4:
            clrscr();
            cout
                << "\rThe gameplay is easy you have to catch all the falling eggs as much as you can \n\
				\rEach eggs gives you +10 score.\n\
				\rYour high score will be saved after the  game is over\n\
				 \
				 \n\n\n\r\t Controls\n\
				 A - To move left\n\
				 D - To move right\n\
				 X - To close the game immediately";

            getch();
            menu();

            break;

        case 5:
            // need to work on

            break;
    }
}

void connect()
{
    int i = 0;
    ifstream fin("data.dat", ios::in);

    while (!fin.eof())
    {
        fin.read((char*)&s[i], sizeof(s[i]));
        if (fin.eof())
            break;
        i++;
    }

    data_size = i;

    fin.close();
}


void Login()
{
    temp.P_GET();
    int i, found = 0;

    for (i = 0; i < data_size; i++)
    {
        if (strcmpi(temp.name, s[i].name) == 0)
        {
            found = 1;
            if (strcmp(temp.password, s[i].password) == 0)
            {
                _logined = 1;
                P_INDEX = i;
                getch();
                break;
            }
        }
    }

    if (!found)
    {
        cout << "You are not registered please register to continue ";
        Register();
    }
    else if (!_logined)
    {
        cout << "You inputted wrong password ";
        Login();
    }
}

void Register()
{
    temp.P_GET();
    int i, found = 0;

    for (i = 0; i < data_size; i++)
    {
        if (strcmpi(temp.name, s[i].name) == 0)
        {
            found = 1;
            textcolor(RED);
            cprintf("\nThis account is registered please login \n");
            // textcolor(GREY);
            Login();
            break;
        }
    }
    if (!found)
    {
        ofstream fout("data.dat", ios::app);
        s[data_size] = temp;
        P_INDEX = data_size;
        fout.write((char*)&temp, sizeof(temp));
        data_size++;
        cout << "Your account is registered succefully ";
        fout.close();
        _logined = 1;
    }
}

void Save()
{
    ofstream fout("data.dat", ios::out);
    for (int i = 0; i < data_size; i++)
    {
        fout.write((char*)&s[i], sizeof(s[i]));
    }
    fout.close();
}

void slowprint(char text[])
{
    cout << "\n\n\n\n";

    int i;
    for (i = 0; i < strlen(text); i++)
    {
        delay(99);
        textcolor(random(15) + 1);
        cprintf("%c ", text[i]);
    }
}

void main()
{

    clrscr();
    cout << "\t\t\t";
    slowprint("\n\n\nWelcome to Egg catcher game by \n\n\n\r       Sreyas");

    getch();

    clrscr();

    connect();
    menu();

    if (_logined)
    {


        width = 45;
        height = 21;

        y = height - 2;
        x = width / 2;


        setup();

        while (!gameover)
        {
            delay(150);
            setup();
            getkey();
            createblock();

            while (by != 20 && !gameover)
            {
                delay(200);
                moveblockdown();
                setup();
                getkey();
            }
        }
    }

    if (score > s[P_INDEX].pscore)
    {
        s[P_INDEX].pscore = score;
        Save();
        clrscr();
        textbackground(YELLOW);
        textcolor(GREEN);
        window(32, 32, 32, 32);
        printf("\n\n\You got high score : %d ", score);
        getch();
    }

    else
    {
        clrscr();
        window(20, 20, 10, 10);
        // cout<<"\n\n\n\t\t\t";
        slowprint("\n\n\nGAMEOVER");
        textbackground(BLACK);
        textcolor(WHITE);
        getch();
    }
}
