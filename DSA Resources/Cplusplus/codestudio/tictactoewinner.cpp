#include <bits/stdc++.h>
using namespace std;

int evaluate(vector<string> &board)
{

    for (int i = 0; i < 3; ++i)
    {

        if (board[i][0] != '_' && board[i][0] == board[i][1] && board[i][1] == board[i][2])

            return (board[i][0] == 'X') ? +1 : -1;

        if (board[0][i] != '_' && board[0][i] == board[1][i] && board[1][i] == board[2][i])

            return (board[0][i] == 'X') ? +1 : -1;
    }

    if (board[0][0] != '_' && board[0][0] == board[1][1] && board[1][1] == board[2][2])

        return (board[0][0] == 'X') ? +1 : -1;

    if (board[0][2] != '_' && board[0][2] == board[1][1] && board[1][1] == board[2][0])

        return (board[0][2] == 'X') ? +1 : -1;

    return 0;
}

bool isMovesLeft(vector<string> &board)
{

    for (int i = 0; i < 3; i++)

        for (int j = 0; j < 3; j++)

            if (board[i][j] == '_')

                return true;

    return false;
}

int minimax(vector<string> &board, int depth, bool isMax)
{

    int score = evaluate(board);

    if (score == 1 || score == -1 || isMovesLeft(board) == false)

        return score;

    if (isMax)
    {

        int best = -1000;

        for (int i = 0; i < 3; i++)
        {

            for (int j = 0; j < 3; j++)
            {

                if (board[i][j] == '_')
                {

                    board[i][j] = 'X';

                    best = max(best, minimax(board, depth + 1, !isMax));

                    board[i][j] = '_';
                }
            }
        }

        return best;
    }
    else
    {

        int best = 1000;

        for (int i = 0; i < 3; i++)
        {

            for (int j = 0; j < 3; j++)
            {

                if (board[i][j] == '_')
                {

                    board[i][j] = 'O';

                    best = min(best, minimax(board, depth + 1, !isMax));

                    board[i][j] = '_';
                }
            }
        }

        return best;
    }
}
vector<int> tictactoeWinner(vector<string> &board)
{
    // Write your code here.
    int bestVal = -1000;

    pair<int, int> bestMove = {-1, -1};

    for (int i = 0; i < 3; i++)
    {

        for (int j = 0; j < 3; j++)
        {

            if (board[i][j] == '_')
            {

                board[i][j] = 'X';

                int moveVal = minimax(board, 0, false);

                board[i][j] = '_';

                if (moveVal > bestVal)
                {

                    bestMove = {i, j};

                    bestVal = moveVal;
                }
            }
        }
    }

    return {bestVal, bestMove.first + 1, bestMove.second + 1};
}