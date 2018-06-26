#include <iostream>

using namespace std ;

bool can_be_captured(int test_row, int test_col, int board[])
{
    for (int row = 0; row < test_row; ++row)
    {
        if ((test_col == board[row]) || (abs(test_row - row) == abs(test_col - board[row])))
        {
            return true;
        }
    }
    return false;
}

void output(int board[], int size)
{
    for (int row = 0; row < size; ++row)
    {
        for (int col = 0; col < size; ++col)
        {
            cout << (col == board[row] ? "X " : ". ");
        }
        cout << endl;
    }
    cout << endl;
}

void place(int row, int board[], int size)
{
    static unsigned counter = 0;
    for (int col = 0; col < size; ++col)
    {
        if(!can_be_captured(row, col, board))
        {
            board[row] = col;
            if (row == size - 1)
            {
                cout << "Solution " << ++counter << ":" << endl;
                output(board, size);
            }
            else
            {
                place(row + 1, board, size);
            }
        }
    }
}

int main(int argc, const char **argv)
{
    cout << "Aufgabe 26: Acht-Damen-Problem\n" << endl;

    const int size {8};
    int board[size];
    place(0, board, size);
} //main
