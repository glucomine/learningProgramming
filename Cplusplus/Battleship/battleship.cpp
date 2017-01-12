// Battleship exercise from Code Academy Python course
// Some C++11 features are present
// TODO: optimize..OPTIMIZE!!

#include <iostream>
#include <vector>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;

auto MAX_GUESSES = 5;
auto ROW_MAX = 5;
auto COL_MAX = 5;
auto INITIAL_VALUE = "0";

void print_board(std::vector<std::vector<std::string>>& board);
int random_row(std::vector<std::vector<std::string>>& board);
int random_col(std::vector<std::vector<std::string>>& board);

int main()
{
  // initializing 2d vector for game board
  std::vector<std::vector<std::string>> board;
  board.resize(ROW_MAX, std::vector<std::string>(COL_MAX, INITIAL_VALUE));
  
  cout << "Let's play Battleship!" << endl;
  print_board(board);
  
  auto ship_row = random_row(board), ship_col = random_col(board);
  
  std::string guess_row, guess_col;
  
  while(MAX_GUESSES > 0)
  {
    cout << MAX_GUESSES << " guesses left" << endl;
    
    // get user's guess from terminal
    cout << "Guess row?";
    std::getline(cin, guess_row);
    cout << "Guess colume?";
    std::getline(cin, guess_col);
    int g_row = std::stoi(guess_row), g_col = std::stoi(guess_col);
    
    if(g_row == ship_row && g_col == ship_col)
    {
      cout << "Battleship has been destroyed!" << endl;
      break;
    }
    else
    {
      if(g_row > ROW_MAX || g_col > COL_MAX)
      {
      // user input is out of board range
      cout << "Wrong coordinates, try again." << endl;
      }
      else if(board[g_row][g_col] == "X")
      {
        cout << "You guess that one already!" << endl;
      }
      else
      {
        board[g_row][g_col].assign("X");
      }
      print_board(board);
    }
    MAX_GUESSES--;
    if(MAX_GUESSES == 0)
    {
      cout << "GAME OVER" << endl;
    }
  }
  return 0;
}

void print_board(std::vector<std::vector<std::string>>& board)
{
  for(std::vector<std::vector<int>>::size_type i = 0; i < board.size(); i++)
  {
    for(std::vector<int>::size_type j = 0; j < board[i].size(); j++)
    {
      cout << board[i][j] << ' ';
    }
    cout << endl;
  }
}

int random_row(std::vector<std::vector<std::string>>& board)
{
  srand(time(0));
  int randomNum;
  randomNum = rand()%board.size();
  return randomNum;
}

int random_col(std::vector<std::vector<std::string>>& board)
{
  srand(time(0));
  int randomNum;
  randomNum = rand()%board[0].size();
  return randomNum;
}
