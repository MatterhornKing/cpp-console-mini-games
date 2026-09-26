#include "consumate_snake.h"

//#define height 20
//#define width 30

//
int canvas_snake[height][width] = {0};

int moveDirection;

int food_x,food_y;

int propLife_x,propLife_y;
int propSpeed_x,propSpeed_y;
int propFast_x,propFast_y;
int coin_x,coin_y;
int poison_x,poison_y;
int score_snake;
int flag_snake = 0;
int life;
int speed = 0;
void startupAgain();


int moveSnakeByDirection(){
    int i,j;
    //
    for(i = 1;i < height-1;i++){
        for(j = 1;j<width-1;j++){
            if(canvas_snake[i][j]>0)
                canvas_snake[i][j]++;
        }
    }

    int oldTail_i,oldTail_j,oldHead_i,oldHead_j;
    int Max = 0;

    for(i = 1;i<height-1;i++){
        for(j = 1;j<width;j++){
            if(canvas_snake[i][j]>0){
                if(Max<canvas_snake[i][j]){
                    Max = canvas_snake[i][j];
                    oldTail_i = i;
                    oldTail_j = j;
                }
                if(canvas_snake[i][j]==2){
                    oldHead_i = i;
                    oldHead_j = j;
                }
            }
        }
    }

    //canvas[oldTail_i][oldTail_j]=0;

    int newHead_i,newHead_j;
    if(moveDirection == 1){
        newHead_i = oldHead_i-1;
        newHead_j = oldHead_j;
    }
    if(moveDirection == 2){
        newHead_i = oldHead_i+1;
        newHead_j = oldHead_j;
    }
    if(moveDirection ==3){
        newHead_i = oldHead_i;
        newHead_j = oldHead_j-1;
    }
    if(moveDirection==4){
        newHead_i = oldHead_i;
        newHead_j = oldHead_j+1;
    }

    //
    if(canvas_snake[newHead_i][newHead_j]==-2){
        score_snake++;
        flag_snake =1;
        canvas_snake[food_x][food_y] = 0;
        //
        do{
            food_x = rand()%(height-5) +2;
            food_y = rand()%(width-5) +2;
        }while(canvas_snake[food_x][food_y]!=0);
        canvas_snake[food_x][food_y] = -2;

        if(rand()%3==1){
            do{
                propLife_x = rand()%(height-5) +2;
                propLife_y = rand()%(width-5) +2;
            }while(canvas_snake[propLife_x][propLife_y]!=0);
            canvas_snake[propLife_x][propLife_y] = -3;
        }

        if(rand()%4==1){
            do{
                coin_x = rand()%(height-5) +2;
                coin_y = rand()%(width-5) +2;
            }while(canvas_snake[coin_x][coin_y]!=0);
            canvas_snake[coin_x][coin_y] = -5;
        }
        if(rand()%3==1){
            do{
                poison_x = rand()%(height-5) +2;
                poison_y = rand()%(width-5) +2;
            }while(canvas_snake[poison_x][poison_y]!=0);
            canvas_snake[poison_x][poison_y] = -6;
        }
        if(rand()%3==1){
            do{
                propFast_x = rand()%(height-5) +2;
                propFast_y = rand()%(width-5) +2;
            }while(canvas_snake[propFast_x][propFast_y]!=0);
            canvas_snake[propFast_x][propFast_y] = -7;
        }
    }
    else
        canvas_snake[oldTail_i][oldTail_j] = 0;

    //
    if(canvas_snake[newHead_i][newHead_j]==-3){
        life++;
        canvas_snake[newHead_i][newHead_j] = 0;
    }
    if(canvas_snake[newHead_i][newHead_j]==-4){
        speed += 5;
        canvas_snake[newHead_i][newHead_j] = 0;
    }
    if(canvas_snake[newHead_i][newHead_j]==-7){
        speed -= 5;
        canvas_snake[newHead_i][newHead_j] = 0;
    }
    if(canvas_snake[newHead_i][newHead_j]==-5){
        score_snake += 3;
        canvas_snake[newHead_i][newHead_j] = 0;
    }
    //
    if(canvas_snake[newHead_i][newHead_j]==-6){
        life--;
        canvas_snake[newHead_i][newHead_j] = 0;
    }
    if(canvas_snake[newHead_i][newHead_j]>0||canvas_snake[newHead_i][newHead_j]==-1){
        life--;
        if(life>0){
            cout<<"Please input spaces to continue another round"<<endl;
            system("pause");
            system("cls");
            startupAgain();
        }
    }
    else
        canvas_snake[newHead_i][newHead_j] = 1;

    if(life<=0){
            system("cls");
            cout<<"Game over!\n";
            cout<<"Your score is: "<<score_snake<<endl;
            cout<<"Rank: ";
            if(score_snake<5)
                cout<<"Bronze"<<endl;
            else if(score_snake<20)
                cout<<"Gold"<<endl;
            else if(score_snake>=20)
                cout<<"King"<<endl;
            Sleep(2000);
            system("pause");
            return 0;
    }
    return 1;
}
void startup_snake(){
    system("cls");
    int i,j;
    score_snake = 0;
    life = 3;
    // border
    for(i = 0;i<height;i++){
        canvas_snake[i][0] = -1;
        canvas_snake[i][width-1] = -1;
    }
    for(j = 0;j<width;j++){
        canvas_snake[0][j] = -1;
        canvas_snake[height-1][j] = -1;
    }

    //snake
    canvas_snake[height/2][width/2] = 1;
    //body of snake
    for(i = 1;i<=4;i++){
        canvas_snake[height/2][width/2-i] = i+1;
    }
    //direction
    moveDirection = 4;

    //food
    food_x = rand()%(height-5)+2;
    food_y = rand()%(width-5)+2;
    while(canvas_snake[food_x][food_y]!=0){
        food_x = rand()%(height-5)+2;
        food_y = rand()%(width-5)+2;
    }
    canvas_snake[food_x][food_y] = -2;
}

void startupAgain(){
    int i,j;
    for(i = 0;i<height;i++){
        for(j = 0;j<width;j++){
            canvas_snake[i][j] = 0;
        }
    }


    //edging
    for(i = 0;i<height;i++){
        canvas_snake[i][0] = -1;
        canvas_snake[i][width-1] = -1;
    }
    for(j = 0;j<width;j++){
        canvas_snake[0][j] = -1;
        canvas_snake[height-1][j] = -1;
    }

    //snake
    canvas_snake[height/2][width/2] = 1;
    //body of snake
    for(i = 1;i<=4;i++){
        canvas_snake[height/2][width/2-i] = i+1;
    }
    //direction
    moveDirection = 4;

    //food
    food_x = rand()%(height-5)+2;
    food_y = rand()%(width-5)+2;
    while(canvas_snake[food_x][food_y]!=0){
        food_x = rand()%(height-5)+2;
        food_y = rand()%(width-5)+2;
    }
    canvas_snake[food_x][food_y] = -2;


}

void show_snake(){
    gotoxy(0,0);
    int i,j;
    for(i = 0;i<height;i++){
        for(j = 0;j<width;j++){
            if(canvas_snake[i][j]==0)//none
                printf(" ");
            else if(canvas_snake[i][j]==-1){//edging
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0c);
                printf("#");}
            else if(canvas_snake[i][j]==1){
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0f);//head
                printf("@");}
            else if(canvas_snake[i][j]>1){
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0f);//body
                printf("*");}
            else if(canvas_snake[i][j]==-2){
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0e);//food
                printf("F");}
            else if(canvas_snake[i][j]==-3){
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0a);//life
                printf("H");}
            else if(canvas_snake[i][j]==-4){
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x09);//speed
                printf("S");}
            else if(canvas_snake[i][j]==-5){
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0d);//speed
                printf("$");}
            else if(canvas_snake[i][j]==-6){
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x06);//speed
                printf("&");}
            else if(canvas_snake[i][j]==-7){
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0c);//speed
                printf("Q");}
        }
        printf("\n");
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0f);
    printf("Score:%d \n",score_snake);
    printf("Hp:%d \n",life);
    if(speed == 0)
    Sleep(100);
    else if(speed>0){
        Sleep(300);
        speed--;
    }
    else if(speed<0){
        speed++;
    }
}

int updateWithoutInput_snake(){
    if(score_snake%2==0&&flag_snake!=0){
        do{
            propSpeed_x = rand()%(height-5) +2;
            propSpeed_y= rand()%(width-5) +2;
        }while(canvas_snake[propSpeed_x][propSpeed_y]!=0);
        canvas_snake[propSpeed_x][propSpeed_y] = -4;
        flag_snake = 0;
    }

    if(moveSnakeByDirection()==0)
        return 0;
    return 1;
}

void updateWithInput_snake(){
    char input;
    if(kbhit()){
        input = getch();
        if(input == 'a')
        {
            if(moveDirection==4)
                return;
            else
            moveDirection = 3;
            moveSnakeByDirection();
        }
        else if(input == 'd'){
                if(moveDirection==3)
                return;
            moveDirection = 4;
            moveSnakeByDirection();
        }
        else if(input == 'w'){
            if(moveDirection==2)
                return;
            moveDirection = 1;
            moveSnakeByDirection();
        }
        else if(input == 's'){
            if(moveDirection==1)
                return;
            moveDirection = 2;
            moveSnakeByDirection();
        }
    }
}

int main_snake(){

    startup_snake();
    //system("color FC");
    while(1){
        show_snake();
        if(updateWithoutInput_snake()==0)
            break;
        updateWithInput_snake();
    }
    system("cls");
    return 0;
}

