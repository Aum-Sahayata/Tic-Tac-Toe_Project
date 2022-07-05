#include<iostream>
using namespace std;

class game{

    char value[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}},bmove='o',a[3];
    string name;
    //"go" counts the turns taken by player and "utl" hold difference of a[0] and a[1]
    int count=-1,go=0,utl=0;

    public:
    //While status is 1 game will run and stop at status 0 
    bool status=1,loopBreaker=0,loopBreaker2=0,winningCon=1,tie=1;

    game(string a){
        name=a;
    }

// This function for genereating tic tac toe box
    void boxgen(){
        if(count%2 != 0){
            cout<<endl<<name<<"'s turn"<<endl<<endl;
        }
        cout<<"     |     |     \n";
        cout<<"  "<<value[0][0]<<"  | "<<" "<<value[0][1]<<"  | "<<" "<<value[0][2]<<"   \n";
        cout<<"_____|_____|_____\n";
        cout<<"     |     |     \n";
        cout<<"  "<<value[1][0]<<"  | "<<" "<<value[1][1]<<"  | "<<" "<<value[1][2]<<"   \n";
        cout<<"_____|_____|_____\n";
        cout<<"     |     |     \n";
        cout<<"  "<<value[2][0]<<"  | "<<" "<<value[2][1]<<"  | "<<" "<<value[2][2]<<"   \n";
        cout<<"     |     |     \n";
        count++;
    }

// This function is for player's moves
    void turn(){
        string move;
            cin>>move;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (move[0]==value[i][j])
            {
                value[i][j]=move[1]; 
                a[go]=move[0];    
                go++;       
            }
        }
    }
    boxgen();
    }

// This function is for bot's moves
        void bot(){
        if(go==1){
            if(value[0][2]!='x'){
                value[0][2]=bmove;
            }
            else value[2][0]=bmove;
            boxgen();
        }
        if(go==2){
            if(a[1]>a[0]){
            utl=a[1]-a[0];
            }
            else utl=a[0]-a[1];

            if(utl==8) value[1][1]=bmove;

            else if(utl==4) value[2][2]=bmove;

            else if(utl==1){
                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        if(value[i][j]==value[i][j+1]){
                            if(j==0){
                                if(value[i][2]=='x' || value[i][2]=='o') value[1][1]=bmove;
                                else  value[i][2]=bmove;
                            }
                            else if(j==1) value[i][0]=bmove;
                        }
                    }
                    
                }
                
            }
            else if(utl==2){
                for (int i = 0; i < 3; i++){
                    if(value[i][0]==value[i][2]){
                            value[i][1]=bmove;
                    }
                }
            }
            else if(utl==3){
                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        if(value[i][j]==value[i+1][j]){
                            if(i==0) value[2][j]=bmove;
                            else if(i==1 && value[0][j]!='o'){
                                value[0][j]=bmove;
                            }
                            else if(i==1 && value[0][j]=='o') value[1][1]=bmove;
                        }
                    }
                    
                }
            }
            else if(utl==6){
                for (int j = 0; j < 3; j++){
                    if(value[0][j]==value[2][j]){
                            value[1][j]=bmove;
                    }
                }
            }
            boxgen();
        }
        if(go==3){
            for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        if('o'==value[i][j] && value[i][j]==value[i][j+1]){
                            if(j==0) {
                                if(value[i][2]!='x' && value[i][2]!='o'){
                                    value[i][2]=bmove;
                                    loopBreaker=1;
                                    winningCon=0;
                                    break;
                                }
                                else winningCon=1;
                            }
                            else if(j==1) {
                                if(value[i][0]!='x' && value[i][0]!='o'){
                                    value[i][0]=bmove;
                                    loopBreaker=1;
                                    winningCon=0;
                                    break;
                                }
                                else winningCon=1;
                            }
                        }
                        else if('o'==value[i][j] && value[i][j]==value[i+1][j]){
                            if(i==0) {
                                if(value[2][j]!='x' && value[2][j]!='o'){
                                    value[2][j]=bmove;
                                    loopBreaker=1;
                                    winningCon=0;
                                    break;
                                }
                                else winningCon=1;
                            }
                            else if(i==1) {
                                if(value[0][j]!='x' && value[0][j]!='o'){
                                    value[0][j]=bmove;
                                    loopBreaker=1;
                                    winningCon=0;
                                    break;
                                }
                                else winningCon=1;
                            }
                        }
                        else if('o'==value[i][j] && value[i][j]==value[i][j+2]){
                            if(value[i][1]!='x' && value[i][1]!='o'){
                                value[i][1]=bmove;
                                loopBreaker=1;
                                winningCon=0;
                                break;
                            }
                            else winningCon=1;
                        }
                        else if('o'==value[i][j] && value[i][j]==value[i+2][j]){
                            if(value[1][j]!='x' && value[1][j]!='o'){
                                value[1][j]=bmove;
                                loopBreaker=1;
                                winningCon=0;
                                break;
                            }
                            else winningCon=1;
                        }
                        else if('o'==value[2][0] && value[2][0]==value[0][2]){
                            if(value[1][1]!='x' && value[1][1]!='o'){
                                value[1][1]=bmove;
                                loopBreaker=1;
                                winningCon=0;
                                break;
                            }
                            else winningCon=1;
                        }
                        else if('o'==value[1][1] && value[1][1]==value[0][2]){
                            if(value[2][0]!='x' && value[2][0]!='o'){
                                value[2][0]=bmove;
                                loopBreaker=1;
                                winningCon=0;
                                break;
                            }
                            else winningCon=1;
                        }
                    }
                    if(loopBreaker) break;
                }
                if(winningCon){
                            if(value[1][1]!='x' && value[1][1]!='o'){
                            value[1][1]=bmove;
                            loopBreaker=1;
                            
                            }
                            else if(value[0][1]!='x' && value[0][1]!='o'){
                            value[0][1]=bmove;
                            loopBreaker=1;
                            
                            }
                            else if(value[0][0]!='x' && value[0][0]!='o'){
                            value[0][0]=bmove;
                            loopBreaker=1;
                            
                            }
                            else if(value[2][2]!='x' && value[2][2]!='o'){
                            value[2][2]=bmove;
                            loopBreaker=1;
                            
                            }
                        }
            boxgen();
        }
        if(go==4){
            for(int i = 0;i < 3; i++){
                for (int j = 0; j < 3; j++)
                {
                    if(value[i][j]!='x' && value[i][j]!='o'){
                        value[i][j]=bmove;
                        loopBreaker2=1;
                        break;
                    }
                }
                if(loopBreaker2) break;
            }
            boxgen();
        }
    }

//This funtions checks for any winners 
    void result(){
        for (int i = 0; i < 3; i++)
        {        
            if('x'==value[i][0] && value[i][0]==value[i][1] && value[i][1]==value[i][2]){
                status=0;
                tie=0;
                cout<<"--------------------"<<name<<" wins--------------------"<<endl;
            }
            else if('x'==value[0][i] && value[0][i]==value[1][i] && value[1][i]==value[2][i]){
                status=0;
                tie=0;
                cout<<"--------------------"<<name<<" wins--------------------"<<endl;
            }
            else if('o'==value[i][0] && value[i][0]==value[i][1] && value[i][1]==value[i][2]){
                status=0;
                tie=0;
                cout<<"--------------------AI wins--------------------"<<endl;
            }
            else if('o'==value[0][i] && value[0][i]==value[1][i] && value[1][i]==value[2][i]){
                status=0;
                tie=0;
                cout<<"--------------------AI wins--------------------"<<endl;
            }
            else status=1;
            }
            if('x'==value[0][0] && value[0][0]==value[1][1] && value[1][1]==value[2][2]){
            status=0;
            tie=0;
            cout<<"--------------------"<<name<<" wins--------------------"<<endl;
            }
            else if('o'==value[0][0] && value[0][0]==value[1][1] && value[1][1]==value[2][2]){
                status=0;
                tie=0;
                cout<<"--------------------AI wins--------------------"<<endl;
            }
            else if('x'==value[0][2] && value[0][2]==value[1][1] && value[1][1]==value[2][0]){
                status=0;
                tie=0;
                cout<<"--------------------"<<name<<" wins--------------------"<<endl;
            }
            else if('o'==value[0][2] && value[0][2]==value[1][1] && value[1][1]==value[2][0]){
                status=0;
                tie=0;
                cout<<"--------------------AI wins--------------------"<<endl;
            }
            else status=1;
    if(tie){
        if(count==9){
            status=0;
            cout<<"--------------------Gameover it's a tie--------------------"<<endl;
            }
        }
    }
};



int main() {

    string name;

    cout<<"\n--------------------------PLayer VS AI Tic Tac Toe--------------------------\n"<<endl;
    cout<<"--------------------To play follow this example: 2x or 9x--------------------\n"<<endl;

    cout<<"Enter name of player: ";
    cin>>name;

    game play(name);
    play.boxgen();

    while (play.status){
        play.turn();
        play.bot();
        play.result();
    }
    return 0;
}