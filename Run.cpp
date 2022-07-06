// To Play you must have all the required files i.e:
// Run.cpp
// Run.exe
// 1_player_tic_tac_tao_AI.cpp
// 1_player_tic_tac_tao_AI.exe
// 2_player_tic_tac_tao.cpp
// 2_player_tic_tac_tao.exe
// Colored output only works for VScode 

#include<iostream>
#include<windows.h>

/*#define GRN "\e[0;32m"
#define RED "\e[0;31m"
#define NC "\e[0m"
#define YEL "\e[0;33m"*/

using namespace std;

void options(){
    cout<</*NC*/ "Select Gamemode: ";
    int choice;
    cin>>choice;
        switch(choice){
        case 1: {
            system("1_player_tic_tac_tao_AI.exe");
            break;
        }
        case 2: {
            system("2_player_tic_tac_tao.exe");
            break;
        }
        default: {
            cout<</*RED*/ "\nPlease select a vaild option"<<endl<<endl;
            options();
            break;
        }
    }
}

int main() {
cout<</*GRN*/ "\n-------------------------------------Welcome to Tic Tac Toe-------------------------------------\n"<<endl;
cout<</*YEL*/ "1.Single player (VS AI)"<<endl;
cout<</*YEL*/ "2.Two player"<<endl<<endl;

options();

    return 0;
}