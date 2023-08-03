#include <iostream>
using namespace std;
// global variables
int space[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
string name1, name2;
int row=0, column=0;
char token = 'X';
bool tie;
void input()
{

    cout << "Enter the name of 1st player\n";
    getline(cin, name1);
    cout << "Enter the name of 2st player\n";
    getline(cin, name2);

    cout << name1 << " is the player 1 so he/she will play 1st\n";
    cout << name2 << " is the player 2 so he/she will play 2nd\n";

    cout << "      |       |      \n";
    cout << "  " << space[0][0] << "   |   " << space[0][1] << "   | " << space[0][2] << "  \n";
    cout << "______|_______|______\n";
    cout << "      |       |      \n";
    cout << "  " << space[1][0] << "   |   " << space[1][1] << "   | " << space[1][2] << "  \n";
    cout << "______|_______|______\n";
    cout << "      |       |      \n";
    cout << "  " << space[2][0] << "   |   " << space[2][1] << "   | " << space[2][2] << "  \n";
    cout << "      |       |      \n";
}
void function2()
{
    int digit;
    if (token == 'X')
    {
        cout << name1 << " please enter";
        cin >> digit;
    }
    if (token == '0')
    {
        cout << name2 << " please enter";
        cin >> digit;
    }

    if (digit == 1)
    {
        row = 0;
        column = 0;
    }
    else if (digit == 2)
    {
        row = 0;
        column = 1;
    }
    else if (digit == 3)
    {
        row = 0;
        column = 2;
    }
    else if (digit == 4)
    {
        row = 1;
        column = 0;
    }
    else if (digit == 5)
    {
        row = 1;
        column = 1;
    }
    else if (digit == 6)
    {
        row = 1;
        column = 2;
    }
    else if (digit == 7)
    {
        row = 2;
        column = 0;
    }
    else if (digit == 8)
    {
        row = 2;
        column = 1;
    }
    else if (digit == 9)
    {
        row = 2;
        column = 2;
    }
    else
    {
        cout << "invalid!!!\n";
    }

    if (token == 'X' && space[row][column] != 'X' && space[row][column] != '0')
    {
        space[row][column] = 'X';
        token = '0';
    }
    else if (token == '0' && space[row][column] != 'X' && space[row][column] != '0')
    {
        space[row][column] = '0';
        token = 'X';
    }
    else
    {
        cout<<"There is no empty space \n";
        function2();
    }
}

bool function3()
{
    for(int i=0;i<3;i++)
    {
        if(space[i][0]==space[i][1] && space[i][0]==space[i][2]  || space[0][i]==space[1][i] && space[0][i]==space[2][i])
        {
            return true;
        }
       
    }
    if(space[0][0]==space[1][1] && space[0][0]==space[2][2] || space[0][2]==space[1][1] && space[2][0]==space[1][1] )
    {
        return true;
    }

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(space[i][j]!='X' && space[i][j]!='0')
            {
                return false;
            }
        }
    }
    tie=true;
    return false;
}
int main()
{
     input();
    while(!function3())
    {
       
        function2();
        function3();
    }
    if(token=='X' && tie==false)
    {
        cout<<name2<<" wins!!!\n";
    }
    else if(token=='0' && tie==false)
    {
        cout<<name1<<" wins!!!\n";
    }
    else
    {
        cout<<"it's a draw!!\n";
    }

}