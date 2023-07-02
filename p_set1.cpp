#include <bits/stdc++.h>
#include <string>
using namespace std;

int size = 3;
string p1, p2;
char mark = 'X';
char board[3][3] = {{'1', '2','3'},{'4','5','6'},{'7','8','9'}};
int gt = 0;

void current_board(){
  cout << "     |     |     \n";
  cout << "  " << board[0][0] << "  |  " << board[0][1] <<"  |  " << board[0][2] <<"  \n";
  cout << "     |     |     \n";
  cout << "-----------------\n";
  cout << "     |     |     \n";
  cout << "  " << board[1][0] << "  |  " << board[1][1] <<"  |  " << board[1][2] <<"  \n";
  cout << "     |     |     \n";
  cout << "-----------------\n";
  cout << "     |     |     \n";
  cout << "  " << board[2][0] << "  |  " << board[2][1] <<"  |  " << board[2][2] <<"  \n";
  cout << "     |     |     \n";
}

void instructions(){
  cout << "The table is as shown. To fill the cell please enter the number representing the cell.\n";
  cout << "     |     |     \n";
  cout << "  1  |  2  |  3  \n";
  cout << "     |     |     \n";
  cout << "-----------------\n";
  cout << "     |     |     \n";
  cout << "  4  |  5  |  6  \n";
  cout << "     |     |     \n";
  cout << "-----------------\n";
  cout << "     |     |     \n";
  cout << "  7  |  8  |  9  \n";
  cout << "     |     |     \n";
}
int n, r, c;
void assignValue(){
  
  
  if(mark == 'X'){
    cout << p1 << " enter cell no : ";
    cin >> n;
  }
  if(mark == 'O'){
    cout << p2 << " enter cell no : ";
    cin >> n;
  }
  
  if(n >= 1 && n <= 3){
    r = 0;c = n-1;
  }
  else if(n >= 4 && n <= 6){
    r = 1;c = n-4;
  }
  else if(n >= 7 && n <= 9){
    r = 2;c = n-7;
  }
  else{
    cout << "Invalid Cell";
  }

  if(board[r][c] != 'X' && board[r][c] != 'O'){
    if(mark == 'X'){
      board[r][c] = 'X';
      mark = 'O';
      }
    else{
      board[r][c] =  'O';
      mark = 'X';
      }
  }
  else{
    cout << "No empty cell" << endl;
    assignValue();
  }
  // current_board();
}

int check(){
  for(int i = 0;i < 3;i++){
    if((board[i][0] == board[i][1] && board[i][1] == board[i][2]) || (board[0][i] == board[1][i] && board[1][i] == board[2][i]))
    return 1;
  }

  if((board[0][0] == board[1][1] && board[1][1] == board[2][2]) || (board[0][2] == board[1][1] && board[1][1] == board[2][0]))
  return 1;

  for(int i = 0;i < 3;i++){
    for(int j = 0;j < 3;j++){
      if(board[i][j] != 'X' || board[i][j] != 'O') return 0;
    }
  }

  gt = 1;
  return 1;
}

int main() 
{
  
  cout << "Enter name of Player 1 : ";
  getline(cin, p1); cout << endl;
  cout << "Enter name of Player 2 : ";
  getline(cin, p2); cout << endl;
  cout << p1 << " will start with 'X' and " << p2 << " will proceed with 'O'\n" ;
  
  instructions();
  
  while(!check()){
    assignValue();
    current_board();
    check();
  }

  if(mark == 'X' && gt == 0){
    cout << p2 <<" WINS THE GAME\n";
  }
  else if(mark == 'O' && gt == 0){
    cout << p1 <<" WINS THE GAME\n";
  }
  else cout << "GAME END IN DRAW\n";

  return 0;
}
