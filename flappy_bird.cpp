#include "flappy_bird.h"

int bird_x,bird_y;
int bar1_y,bar1_xDown,barl_xTop;
int bar2_y,bar2_xDown,bar2_xTop;
int score_bird;
int v_bird;

void startup_bird(){
    //height = 15;
    //width = 50;
    system("cls");
    bird_y = width/3;
    bar1_y = width/2;
    bar1_xDown = height/4;
    barl_xTop = height/2;
    bar2_y = width/2+25;
    bar2_xDown = height/2;
    bar2_xTop = 3*height/4;
    bird_x = (bar1_xDown+barl_xTop)/2;
    score_bird = 0;
    v_bird = 1;
}

void show_bird(){
    gotoxy(0,0);
    int i,j;

    for(i = 0;i<height;i++){
        for(j = 0;j<width;j++){
            if((i==bird_x)&&(j==bird_y)){
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0e);
                printf("@");
            }
            else if((j==bar1_y)&&((i<bar1_xDown)||(i>barl_xTop))){
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0b);
                printf("*");
            }
            else if((j==bar2_y)&&((i<bar2_xDown)||(i>bar2_xTop))){
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0b);
                printf("*");
            }
            else
                printf(" ");
        }
        printf("\n");
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0f);
    printf("Score:%d\n",score_bird);
}

int updateWithoutInput_bird(){
    if(bird_x>height-1){
            printf("Game over!\n");
            system("pause");
            return 0;
    }
    bird_x += v_bird;


    v_bird++;
    bar1_y--;bar2_y--;
    if(bird_y==bar1_y){
        if((bird_x>=bar1_xDown)&&(bird_x<=barl_xTop))
            score_bird++;
        else{
            printf("Game over!\n");
            return 0;
        }
    }

    if(bird_y==bar2_y){
        if((bird_x>=bar2_xDown)&&(bird_x<=bar2_xTop))
            score_bird++;
        else{
            printf("Game over!\n");
            return 0;
        }
    }

    if(bar1_y<=0){
        bar1_y = width;
        if(score_bird<5){
            int temp = rand()%int(height*0.7);
            bar1_xDown = temp - height/8;
            barl_xTop = temp+height/8;
        }
        else{
            int temp = rand()%int(height*0.8);
            bar1_xDown = temp - height/10;
            barl_xTop = temp+height/10;
        }

    }

    if(bar2_y<=0){
        bar2_y = width;
        if(score_bird<5){
            int temp = rand()%int(height*0.7);
            bar2_xDown = temp - height/8;
            bar2_xTop = temp+height/8;
        }
        else{
            int temp = rand()%int(height*0.8);
            bar2_xDown = temp - height/10;
            bar2_xTop = temp+height/10;
        }

    }

    if(score_bird<5)
        Sleep(150);
    else if(score_bird<10)
        Sleep(80);
    else
        Sleep(30);
    return 1;
}

void updateWithInput_bird(){
    char input;
    if(kbhit()){
        input = getch();
        if(input==' '){
             bird_x -= 2;
            if(bird_x<0)
                bird_x = 0;
            if(bird_x>height-1)
                bird_x = height-1;
             v_bird = 0;
        }

    }
}

int main_bird()
{
    startup_bird();
    while(1){
        show_bird();
        if(updateWithoutInput_bird()==0)
            break;
        updateWithInput_bird();
    }
    system("cls");
    if(score_bird>5){
        for(int i = 0;i<height/3;i++)
            for(int j = 0;j<width;j++)
                printf(" ");
            printf("\n");

        printf("Congratulations!\n");
        printf("Your score is : %d\n",score_bird);
        printf("Great job!");
        // printf("     tql!!!");
        printf("\n");
        printf("\n");
    }

    else{
        for(int i = 0;i<height/3;i++)
            for(int j = 0;j<width;j++)
                printf(" ");
            printf("\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0c);
        printf("  Congratulations!\n");
        printf("  Your score is : %d\n",score_bird);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0f);
        printf("Keep practicing!");
        // printf("  Wow!Vegetable dog!");
        printf("\n");
        printf("\n");
    }

    system("pause");
    system("cls");
    return 0;
}

