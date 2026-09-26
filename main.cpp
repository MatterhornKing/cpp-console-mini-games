#include "bounce_ball.h"
#include "plane_war.h"
#include "life_game.h"
#include "consumate_snake.h"
#include "flappy_bird.h"

int a[height][width];
int start_city(){
    gotoxy(0,0);

    for(int i = 0;i<height;i++){
        a[i][0] = 1;
    }

    for(int i = 0;i<width;i++){
        a[0][i] = 1;
    }

    for(int i = 0;i<height;i++){
        a[i][width-1] = 1;
    }

    for(int i = 0;i<width;i++){
        a[height-1][i] = 1;
    }
    int flag1=1;
    for(int i = 0;i<height;i++){
        for(int j =0;j<width;j++){
            if(a[i][j]==1&&height/4!=i&&i!=height/4+2&&i!=height/4+3&&i!=height/4+4
                &&i!=height/4+5&&i!=height/4+6){
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0b);
                cout<<"*";
                }
            else if(i==height/4&&flag1==1){
                cout<<"*";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0e);
                cout<<"           Welcome to My Games!           ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0b);
                cout<<"*";
                flag1 = 0;
            }
            else if(i==height/4+2&&flag1==0){
                cout<<"*";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0f);
                cout<<"         1. Snake                               ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0b);
                cout<<"*";
                flag1 = 1;
            }
            else if(i==height/4+3&&flag1==1){
                cout<<"*";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0f);
                cout<<"         2. Plane War                             ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0b);
                cout<<"*";
                flag1 = 0;
            }
            else if(i==height/4+4&&flag1==0){
                cout<<"*";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0f);
                cout<<"         3. Brick Breaker                   ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0b);
                cout<<"*";
                flag1 = 1;
            }
            else if(i==height/4+5&&flag1==1){
                cout<<"*";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0f);
                cout<<"         4. Flappy Bird                ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0b);
                cout<<"*";
                flag1 = 0;
            }
            else if(i==height/4+6&&flag1==0){
                cout<<"*";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0f);
                cout<<"         5. Conway's Game of Life                             ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0b);
                cout<<"*";
                flag1 = 1;
            }
            else
            cout<<" ";
        }
        cout<<endl;
  }
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0f);
  cout<<"Enter a number to select a game, or press ESC to exit."<<endl;
    //SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY|BACKGROUND_RED|BACKGROUND_GREEN|BACKGROUND_BLUE);
  char choice;
  while(!kbhit()){
        choice = getch();
     if(choice==27)
        exit(0);
     else if(choice=='1')
        return 1;
     else if(choice=='2')
        return 2;
     else if(choice=='3')
        return 3;
     else if(choice=='4')
        return 4;
     else if(choice=='5')
        return 5;
  }
}
int main()
{
    HideCursor();
    int choice;
    while(1){
        choice = start_city();
        gotoxy(0,0);
        if(choice==1)
            main_snake();
        if(choice==2)
            main_plane();
        if(choice==3)
            main_ball();
        if(choice==4)
            main_bird();
        if(choice==5)
            main_life();
    }
    return 0;
}
