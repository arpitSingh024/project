#include <bits/stdc++.h>
using namespace std;

int size = 3;
string p1, p2;
char mark = 'X';
char board[3][3] = {{'1', '2','3'},{'4','5','6'},{'7','8','9'}};
bool tie = false;

void current_board(){
  cout << "     |     |     \n";
  cout << "  " << board[0][0] << "  |  " << board[0][1] <<"  |  " << board[0][2]<<"  \n";
  cout << "     |     |     \n";
  cout << "-----------------\n";
  cout << "     |     |     \n";
  cout << "  " << board[1][0] << "  |  " << board[1][1] <<"  |  " << board[1][2]<<"  \n";
  cout << "     |     |     \n";
  cout << "-----------------\n";
  cout << "     |     |     \n";
  cout << "  " << board[2][0] << "  |  " << board[2][1] <<"  |  " << board[2][2]<<"  \n";
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

void assignValue(){
  int n;
  int r, c;
  if(mark == 'X'){
    cout << p1 << " enter cell no : ";
    cin >> n;
  }
  if(mark == 'O'){
    cout << p1 << " enter cell no : ";
    cin >> n;
  }
  
  if(n > 0 && n < 4){
    r = 0;c = n-1;
  }
  else if(n > 3 && n < 7){
    r = 1;c = n-4;
  }
  else if(n > 6 && n < 10){
    r = 2;c = n-7;
  }
  else{
    cout << "Invalid Cell";
  }

  if(board[r][c] != 'X' && board[r][c] != 'O'){
    board[r][c] = 'X' ? (mark == 'X') : 'O';
    mark = 'O' ? (mark == 'X') : 'X'; 
  }
  else{
    cout << "No empty cell" << endl;
    assignValue();
  }
  current_board();
}

bool check(){
  for(int i = 0;i < 3;i++){
    if(board[i][0] == board[i][1] && board[i][1] == board[i][2] || board[0][i] == board[1][i] && board[1][i] == board[2][i])
    return true;
  }

  if(board[1][1] == board[2][2] && board[2][2] == board[0][0] || board[0][2] == board[1][1] && board[1][1] == board[2][0])
  return true;

  for(int i = 0;i < 3;i++){
    for(int j = 0;j < 3;j++){
      if(board[i][j] != 'X' && board[i][j] != 'O')
      return false;
    }
  }

  tie = true;
  return false;

}

void playGame(){
  instructions();
  while(!check()){
    current_board();
    assignValue();
    check();
  }

}



int main() 
{
  
  cout << "Enter name of Player 1 : ";
  getline(cin, p1); cout << endl;
  cout << "Enter name of Player 2 : ";
  getline(cin, p2); cout << endl;
  cout << p1 << " will start with 'X' and " << p2 << " will proceed with 'O'" << endl;
  playGame();

  if(mark == 'X' && tie == false){
    cout << p2<<" WINS THE GAME\n";
  }
  else if(mark == 'O' && tie == false){
    cout << p1 <<" WINS THE GAME\n";
  }
  else cout << "GAME END IN DRAW\n";

  return 0;
}