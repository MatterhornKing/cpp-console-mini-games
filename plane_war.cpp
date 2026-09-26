#include "plane_war.h"

//#include <mmsystem.h>
//#pragma comment(lib,"winmm.lib")

typedef struct{
    int x;
    int y;
    int v;
    int bul_x,bul_y;
}Enemy;

typedef struct{
    int x,y;
    int v;
    int bul_x,bul_y;
    int BulletWidth;
    int a,b;
    int hp;
}Plane;

typedef struct{
    int x,y;
    int bul_x,bul_y;
    int hp;
}Boss;

//const int height = 25;
//const int width = 50;
const int EnemyNum = 5;
int score;
int boss_exist = 0;
int enemy_v = 20;
int canvas_plane[height][width] = {0};
int left_flag = 1;
Enemy enemy[EnemyNum];
Plane plane;
Boss boss;

void place_plane(int a){
    canvas_plane[plane.x][plane.y+2] = a;
	for(int i = 0;i<plane.a;i++){
        canvas_plane[plane.x+1][plane.y+i] = a;
	}
    canvas_plane[plane.x+2][plane.y+1] = a;
    canvas_plane[plane.x+2][plane.y+3] = a;
}
void startup_plane()
{
    system("cls");
	plane.x = height/2-2;
	plane.y = width/2-2;
	plane.a = 5;
	plane.b = 3;
    plane.hp = 9;
	//
	place_plane(1);

    boss.hp = 20;
    boss.x = width/2;
    boss.y = 2;
	int k;
	for(k = 0;k<width;k++){
        canvas_plane[0][k] = -1;
	}
	for(k = 0;k<height;k++){
        canvas_plane[k][0] = -1;
	}
	for(k = 0;k<width;k++){
        canvas_plane[height-1][k] = -1;
	}
	for(k = 0;k<height;k++){
        canvas_plane[k][width-1] = -1;
	}

	for(k = 0;k < EnemyNum;k++){
        enemy[k].x = rand()%2+1;
        enemy[k].y = rand()%(width-1)+1;
        enemy[k].v = 20;
        canvas_plane[enemy[k].x][enemy[k].y] = 3;
 	}
	score = 0;
	plane.BulletWidth = 0;

}

void show_plane()
{
	//system("cls");
	gotoxy(0,0);
	int i,j;
	for(i = 0; i < height;i++)
	{
		for(j = 0;j<width;j++)
		{

			if(canvas_plane[i][j] == 0)
			{
				printf(" ");
			}
			else if(canvas_plane[i][j]==-1){
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0f);
                printf("#");
			}
			else if(canvas_plane[i][j]==1)
			{
			    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0f);
				printf("*");
			}
			else if(canvas_plane[i][j]==2)
			{
			    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0f);
				printf("|");
			}
			else if(canvas_plane[i][j]==3){
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0c);
                printf("@");
			}
			else if(canvas_plane[i][j]==4){
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0b);
                printf(".");
			}
			else if(canvas_plane[i][j]==5){
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0e);
                printf("&");
			}



		}
		printf("\n");
	}
	printf("Score: %d\n",score);
	printf("HP: %d\n",plane.hp);
	printf("Boss HP: %d\n",boss.hp);
	Sleep(20);
}

int updateWithoutInput_plane()
{
	int i,j,k;

    //
    for(i = 1;i<height-1;i++){
        for(j = 1;j<width-1;j++){
            if(canvas_plane[i][j]==2){
                for(k = 0;k<EnemyNum;k++){
                    if((i<=enemy[k].x+1)&&(j==enemy[k].y)){
                        score++;
                        if(score%5==0&&enemy_v>3)
                            enemy_v--;
                        if(score%5==0&&plane.BulletWidth<8)
                            plane.BulletWidth++;
                        canvas_plane[enemy[k].x][enemy[k].y] = 0;
                        if(score<10){
                            while(1){
                                enemy[k].x = rand()%2+1;
                                enemy[k].y = rand()%(width-2)+1;
                                int count_plane = 0;
                                for(int p = 0;p<EnemyNum;p++){
                                    if(p!=k){
                                        if(enemy[k].y!=enemy[p].y)
                                            count_plane++;
                                    }
                                }
                                if(count_plane==4)
                                    break;
                            }
                            canvas_plane[enemy[k].x][enemy[k].y] = 3;
                        }
                        canvas_plane[i][j] = 0;
                        if(score>=10)
                            enemy[k].x = 0;

                    }
                }
                //

                if(i>3&&canvas_plane[i][j]==2)
                    canvas_plane[i-1][j] = 2;
                canvas_plane[i][j] = 0;
            }
        }
    }

    for(i = 1;i<height-1;i++){
        for(j = 1;j<width-1;j++){
            if(canvas_plane[i][j]==2){
                for(k = 0;k<EnemyNum;k++){
                    if((i<=enemy[k].x+1)&&(j==enemy[k].y)){
                        score++;
                        if(score%5==0&&enemy_v>3)
                            enemy_v--;
                        if(score%5==0&&plane.BulletWidth<8)
                            plane.BulletWidth++;
                        canvas_plane[enemy[k].x][enemy[k].y] = 0;
                        if(score<10){
                            while(1){
                                enemy[k].x = rand()%2+1;
                                enemy[k].y = rand()%(width-2)+1;
                                int count_plane = 0;
                                for(int p = 0;p<EnemyNum;p++){
                                    if(p!=k){
                                        if(enemy[k].y!=enemy[p].y)
                                            count_plane++;
                                    }
                                }
                                if(count_plane==4)
                                    break;
                            }
                            canvas_plane[enemy[k].x][enemy[k].y] = 3;
                        }
                        if(score>=10)
                            enemy[k].x = 0;
                        canvas_plane[i][j] = 0;
                    }
                }
                //
            }
        }
    }

    for(i = height-2;i>1;i--){
        for(j = width-2;j>1;j--){
            if(canvas_plane[i][j]==4){
                if(i!=height-2&&canvas_plane[i+1][j]!=1&&canvas_plane[i+1][j]!=2){
                    canvas_plane[i][j] = 0;
                    canvas_plane[i+1][j] = 4;
                }
                else if(canvas_plane[i+1][j]==1){
                    canvas_plane[i][j] = 0;
                    plane.hp--;
                }
                else
                    canvas_plane[i][j] = 0;
            }

        }
    }


	static int speed_plane = 0;
	if(speed_plane<enemy_v)
        speed_plane++;

    for(k = 0;k<EnemyNum;k++){
        if((plane.x<=enemy[k].x+1)&&(plane.y<=enemy[k].y)&&(plane.y+4>=enemy[k].y)){
            plane.hp--;

            canvas_plane[enemy[k].x][enemy[k].y] = 0;
            if(score<10){
                 while(1){
                                enemy[k].x = rand()%2+1;
                                enemy[k].y = rand()%(width-2)+1;
                                int count_plane = 0;
                                for(int p = 0;p<EnemyNum;p++){
                                    if(p!=k){
                                        if(enemy[k].y!=enemy[p].y)
                                            count_plane++;
                                    }
                                }
                                if(count_plane==4)
                                    break;
                            }
                 canvas_plane[enemy[k].x][enemy[k].y] = 3;
            }

        }
        if(enemy[k].x>height-2){
            if(score<10){
                canvas_plane[enemy[k].x][enemy[k].y] = 0;
                while(1){
                                enemy[k].x = rand()%2+1;
                                enemy[k].y = rand()%(width-2)+1;
                                int count_plane = 0;
                                for(int p = 0;p<EnemyNum;p++){
                                    if(p!=k){
                                        if(enemy[k].y!=enemy[p].y)
                                            count_plane++;
                                    }
                                }
                                if(count_plane==4)
                                    break;
                            }
                canvas_plane[enemy[k].x][enemy[k].y] = 3;
                score--;
            }
            else{
                canvas_plane[enemy[k].x][enemy[k].y] = 0;
            }

        }
        if(speed_plane == enemy_v)
        {
            for(k = 0;k<EnemyNum;k++){
                if(enemy[k].x!=0){
                    canvas_plane[enemy[k].x][enemy[k].y] = 0;
                    enemy[k].x++;
                    speed_plane = 0;
                    canvas_plane[enemy[k].x][enemy[k].y] = 3;
                }
            }
            for(k = 0;k<EnemyNum;k++){
                if(enemy[k].x!=0)
                canvas_plane[enemy[k].x+1][enemy[k].y] = 4;
            }
        }
        }

    if(score>=10&&boss_exist==0){
        for(i = 1;i<width-1;i++)
            for(j = 1;j<3;j++)
            canvas_plane[i][j]=0;
        for(i = boss.x-4;i<boss.x+5;i++)
            canvas_plane[1][i] = 5;
        for(i = boss.x-3;i<boss.x+4;i++)
            canvas_plane[2][i] = 5;
        boss_exist = 1;}
    if(boss_exist==1){
        if(boss.x-4>1&&left_flag==1){

            canvas_plane[1][boss.x+4]=0;
            canvas_plane[2][boss.x+3]=0;
            boss.x--;
            canvas_plane[1][boss.x-4]=5;
            canvas_plane[2][boss.x-3]=5;
        }
        if(boss.x-4==1)
            left_flag=0;
        if(boss.x+5<width-2&&left_flag==0){

            canvas_plane[1][boss.x-4]=0;
            canvas_plane[2][boss.x-3]=0;
             boss.x++;
            canvas_plane[1][boss.x+4]=5;
            canvas_plane[2][boss.x+3]=5;

        }
        if(boss.x+5==width-2)
            left_flag=1;

    }


    if(plane.hp<=0){
        system("cls");
        printf("GameOver!\n");
        printf("Your score is : %d\n",score);
        Sleep(3000);
        system("pause");
        return 0;
    }
    return 1;
}

void updateWithInput_plane()
{
	char input;
	if(kbhit())
	{
		input = getch();
		if(input == 'a'&&plane.y>1){
            place_plane(0);
            plane.y--;
            place_plane(1);
		}
		else if(input == 'd'&&plane.y<width-6){
            place_plane(0);
            plane.y++;
            place_plane(1);
		}
		else if(input == 'w'&&plane.x>1){
            place_plane(0);
            plane.x--;
            place_plane(1);
		}
		else if(input == 's'&&plane.x<height-4){
            place_plane(0);
            plane.x++;
            place_plane(1);
		}
		else if(input == ' ')
		{
			int left = plane.y + 2 - plane.BulletWidth;
			int right = plane.y + 2 + plane.BulletWidth;
			if(left<1)
                left = 1;
            if(right>width-2)
                right = width-2;
            int k;
            for(k = left;k<=right;k++){
                canvas_plane[plane.x-1][k]=2;
            }
		}
		else if(input==27)
		system("pause"); //ESC key has ASCII value 27
	}
}

int main_plane()
{
	startup_plane();
	//start_window();
	while(1)
	{
		show_plane();
		if(updateWithoutInput_plane()==0)
            break;
		updateWithInput_plane();
	}
	system("cls");
	return 0;
}

