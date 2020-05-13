//reference: https://www.geeksforgeeks.org/place-k-knights-such-that-they-do-not-attack-each-other/

#include <iostream>
using namespace std;

int results = 0;
int n;

/*   Create an empty board of size n*n   */
void makeBoard(char **board)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            board[i][j] = '_';
        }
    }
}

/* print the n*n board */
void displayBoard(char **board)
{
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j]=='A')
            {
                board[i][j]= '_';
            }
            cout << " " << board[i][j] << " ";
        }
        cout<<endl;
    }
}

//All possible locations that the horse can attack
void mark_attack(int x, int j, char a, char **board)
{
    /* conditions to ensure that the  block to be checked is inside the board */
    //All possible cominations of the movement of hosrse;
    if ((x + 2) < n && (j - 1) >= 0)
    {
        board[x + 2][j - 1] = a;
    }
    if ((x - 2) >= 0 && (j - 1) >= 0)
    {
        board[x - 2][j - 1] = a;
    }
    if ((x + 2) < n && (j + 1) < n)
    {
        board[x + 2][j + 1] = a;
    }
    if ((x - 2) >= 0 && (j + 1) < n)
    {
        board[x - 2][j + 1] = a;
    }
    if ((x + 1) < n && (j + 2) < n)
    {
        board[x + 1][j + 2] = a;
    }
    if ((x - 1) >= 0 && (j + 2) < n)
    {
        board[x - 1][j + 2] = a;
    }
    if ((x + 1) < n && (j - 2) >= 0)
    {
        board[x + 1][j - 2] = a;
    }
    if ((x - 1) >= 0 && (j - 2) >= 0)
    {
        board[x - 1][j - 2] = a;
    }
}

/* If the position is empty, return true, as knight can be placed */
bool check_placeKnight(int i, int j, char **board)
{
    if (board[i][j] == '_')
        return true;
    else
        return false;
}

/* place the knight at [i][j] position on board */
void placeKnight(int i, int j, char k, char a, char **board, char **temp_board)
{

    /* copy old board to new board */
    //Major step for backtracking therefore we can go back to our previous answer
    for (int y = 0; y < n; y++)
    {
        for (int z = 0; z < n; z++)
        {
            temp_board[y][z] = board[y][z];
        }
    }

    /* placing knight at position[i][j] */
    temp_board[i][j] = k;

    /* mark all attacking positions in new board, with knight placed */
    mark_attack(i, j, a, temp_board);
}

void Final_knight_board(int k, int xi, int xj, char **board)
{

    //if no more knights can be displayed display it
    if (k == 0)
    {
        
        displayBoard(board);
        results++;
        cout<<endl;
        cout<<"Result number: "<<results<<endl;
    }
    else
    {
        /* Loop for checking all the positions on n*n board */
        for (int i = xi; i < n; i++)
        {
            for (int j = xj; j < n; j++)
            {
                /* check if it is possible to place knight at [i][j] position on board */
                if (check_placeKnight(i, j, board))
                {
                    /* Create a a new board and place the new knight on it */
                    char **temp_board = new char *[n];
                    for (int x = 0; x < n; x++)
                    {
                        temp_board[x] = new char[n];
                    }
                    placeKnight(i, j, 'K', 'A', board, temp_board);

                    /* Recursively call function for (k-1) left knights */
                    Final_knight_board(k - 1, i, j, temp_board);

                    /* Delete the temp board  */
                    for (int x = 0; x < n; x++)
                    {
                        delete[] temp_board[x];
                    }
                    delete[] temp_board;
                }
            }
            xj = 0;
        }
    }
}

int main()
{
    cout << "Enter size of chess board" << endl;
    cin >> n;

    char **board = new char *[n];
    for (int i = 0; i < n; i++)
    {
        board[i] = new char[n];
    }
    makeBoard(board);                   //Intializing the board
    Final_knight_board(n, 0, 0, board); //Main function call
    cout << "Total number of solutions for " << n << " knights are: " << results;
    return 0;
}