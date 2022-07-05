#include<iostream>
using namespace std;

class game{

    char value[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
    string p[2];
    int count=0,n=0;

    public:
    bool status=1,tie=1;

    game(string a,string b){
        p[0]=a;
        p[1]=b;
    }

// This function for genereating tic tac toe box
    void boxgen(){
        cout<<endl<<p[n]<<"'s turn"<<endl<<endl;
        cout<<"     |     |     \n";
        cout<<"  "<<value[0][0]<<"  |  "<<value[0][1]<<"  |  "<<value[0][2]<<"   \n";
        cout<<"_____|_____|_____\n";
        cout<<"     |     |     \n";
        cout<<"  "<<value[1][0]<<"  |  "<<value[1][1]<<"  |  "<<value[1][2]<<"   \n";
        cout<<"_____|_____|_____\n";
        cout<<"     |     |     \n";
        cout<<"  "<<value[2][0]<<"  |  "<<value[2][1]<<"  |  "<<value[2][2]<<"   \n";
        cout<<"     |     |     \n";
        
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
                if(value[i][j]=='x' || value[i][j]=='o') {
                    cout<<"No space available please enter your move again!!"<<endl;
                    cin>>move;
                    }
                else{
                    value[i][j]=move[1];
                    }
            }
        }
    if(n==0) 
        n=1;
    else 
        n=0;
    }
    count++;
    boxgen();
}

//This funtions checks for any winners 
void result(){
    for (int i = 0; i < 3; i++)
    {        
        if('x'==value[i][0] && value[i][0]==value[i][1] && value[i][1]==value[i][2]){
            status=0;
            tie=0;
            cout<<"--------------------"<<p[0]<<" wins--------------------"<<endl;
        }
        else if('x'==value[0][i] && value[0][i]==value[1][i] && value[1][i]==value[2][i]){
            status=0;
            tie=0;
            cout<<"--------------------"<<p[0]<<" wins--------------------"<<endl;
        }
        else if('o'==value[i][0] && value[i][0]==value[i][1] && value[i][1]==value[i][2]){
            status=0;
            tie=0;
            cout<<"--------------------"<<p[1]<<" wins--------------------"<<endl;
        }
        else if('o'==value[0][i] && value[0][i]==value[1][i] && value[1][i]==value[2][i]){
            status=0;
            tie=0;
            cout<<"--------------------"<<p[1]<<" wins--------------------"<<endl;
        }
        else status=1;
        }
        if('x'==value[0][0] && value[0][0]==value[1][1] && value[1][1]==value[2][2]){
        status=0;
        tie=0;
        cout<<"--------------------"<<p[0]<<" wins--------------------"<<endl;
        }
        else if('o'==value[0][0] && value[0][0]==value[1][1] && value[1][1]==value[2][2]){
            status=0;
            tie=0;
            cout<<"--------------------"<<p[1]<<" wins--------------------"<<endl;
        }
        else if('x'==value[0][2] && value[0][2]==value[1][1] && value[1][1]==value[2][0]){
            status=0;
            tie=0;
            cout<<"--------------------"<<p[0]<<" wins--------------------"<<endl;
        }
        else if('o'==value[0][2] && value[0][2]==value[1][1] && value[1][1]==value[2][0]){
            status=0;
            tie=0;
            cout<<"--------------------"<<p[1]<<" wins--------------------"<<endl;
        }
        else status=1;
    if(tie){
        if(count==9){
            status=0;
            cout<<"--------------------Gameover it's a tie--------------------"<<endl;
        }
        else status=1;
    }
    }
};


int main() {

    string p1,p2;

    cout<<"\n-----------------------------2 player Tic Tac Toe-----------------------------\n"<<endl;
    cout<<"--------------------To play follow this example: 2x or 9o--------------------\n"<<endl;

    cout<<"Enter name of player playing as x: ";
    cin>>p1;
    cout<<"\nEnter name of player playing as o: ";
    cin>>p2;
    cout<<endl;

    game play(p1,p2);
    play.boxgen();

    while (play.status){
        play.turn();
        play.result();
    }
    

    return 0;
}