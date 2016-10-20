/*

☻☻☻Ä☻☻☻Ä☻☻☻Ä☻☻☻Ä☻☻☻Ä☻☻☻Ä☻☻☻Ä☻☻☻Ä☻☻☻Ä☻☻☻Ä☻☻☻Ä☻☻☻Ä☻☻☻Ä☻☻☻Ä☻☻☻Ä☻☻☻Ä☻☻☻Ä☻☻☻Ä☻☻☻Ä☻☻☻Ä☻☻☻Ä☻☻☻Ä☻☻☻Ä☻☻☻Ä☻☻☻Ä☻☻☻Ä☻☻☻Ä☻☻☻Ä☻☻☻Ä☻☻☻Ä
*    MIT License
*
*     Copyright (c) 2016 Sreyas
*
*     Permission is hereby granted, free of charge, to any person obtaining a copy
*     of this software and associated documentation files (the "Software"), to deal
*     in the Software without restriction, including without limitation the rights
*     to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
*     copies of the Software, and to permit persons to whom the Software is
*     furnished to do so, subject to the following conditions:
*
*     The above copyright notice and this permission notice shall be included in all
*     copies or substantial portions of the Software.
*
*     THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
*     IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
*     FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
*     AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
*     LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
*     OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
*     SOFTWARE.
*
//☻☻☻Ä☻☻☻Ä☻☻☻Ä☻☻☻Ä☻☻☻Ä☻☻☻Ä☻☻☻Ä☻☻☻Ä☻☻☻Ä☻☻☻Ä☻☻☻Ä☻☻☻Ä☻☻☻Ä☻☻☻Ä☻☻☻Ä☻☻☻Ä☻☻☻Ä☻☻☻Ä☻☻☻Ä☻☻☻Ä☻☻☻Ä☻☻☻Ä☻☻☻Ä☻☻☻Ä☻☻☻Ä☻☻☻Ä☻☻☻Ä☻☻☻Ä☻☻☻Ä
|||Register system for console games by Sreyas||||||||||||

*/
// global vars
int data_size, _logined = 0, _connected = 0,
               P_INDEX; // saving data size in a var is much more optimised than use tellg()
// global functions
void Register();

void Login();

void Save();

void connect();

// class for storing player data

class P_DATA
{
public:
    char name[24], password[24];
    int pscore;

    P_DATA()
    {
        pscore = 0;
    }

    void P_GET()
    {
        cout << "Input your name ";
        gets(name);
        cout << "Input password ";
        gets(password);
    }

    ~P_DATA()
    {
    }
};


////////////////////////////////////////////////////////////////////////////
