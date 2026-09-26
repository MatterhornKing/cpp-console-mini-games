#include "life_game.h"
int cells[height][width];
int NewCells[height][width];

void startup_life(){
    system("cls");
	int i,j;
	srand((unsigned)time(NULL));
	for (i = 0;i < height;i++){
		for(j = 0;j<width;j++){
			cells[i][j] = rand()%2;
		}
	}
}

void gosper_plane(){
    system("cls");
	int i,j;
	for (i = 0;i < height;i++){
		for(j = 0;j<width;j++){
			cells[i][j] = 0;
		}
	}

	int flag = 10;
	cells[0][flag+11] = 1;
	cells[0][flag+13] = 1;
	cells[1][flag+10] = 1;
	cells[1][flag+13] = 1;
	cells[2][flag+9] = 1;
	cells[2][flag+10] = 1;
	cells[2][flag+21] = 1;
	cells[2][flag+28] = 1;

	cells[3][flag+1] = 1;
	cells[3][flag+2] = 1;
	cells[3][flag+7] = 1;
	cells[3][flag+8] = 1;
	cells[3][flag+12] = 1;
	cells[3][flag+21] = 1;
	cells[3][flag+27] = 1;
	cells[3][flag+29] = 1;

	cells[4][flag+1] = 1;
	cells[4][flag+2] = 1;
	cells[4][flag+9] = 1;
	cells[4][flag+10] = 1;
	cells[4][flag+20] = 1;
	cells[4][flag+27] = 1;
	cells[4][flag+28] = 1;
	cells[4][flag+30] = 1;

	cells[5][flag+10] = 1;
	cells[5][flag+13] = 1;
	cells[5][flag+16] = 1;
	cells[5][flag+17] = 1;
	cells[5][flag+27] = 1;
	cells[5][flag+28] = 1;
	cells[5][flag+30] = 1;
	cells[5][flag+31] = 1;
	cells[5][flag+35] = 1;
	cells[5][flag+36] = 1;

	cells[6][flag+11] = 1;
	cells[6][flag+13] = 1;
	cells[6][flag+16] = 1;
	cells[6][flag+19] = 1;
	cells[6][flag+20] = 1;
	cells[6][flag+21] = 1;
	cells[6][flag+27] = 1;
	cells[6][flag+28] = 1;
	cells[6][flag+30] = 1;
	cells[6][flag+35] = 1;
	cells[6][flag+36] = 1;

	cells[7][flag+16] = 1;
	cells[7][flag+17] = 1;
	cells[7][flag+18] = 1;
	cells[7][flag+19] = 1;
	cells[7][flag+27] = 1;
	cells[7][flag+29] = 1;

	cells[8][flag+17] = 1;
	cells[8][flag+18] = 1;
	cells[8][flag+28] = 1;

}
void show_life(){
	gotoxy(0,0);
	int i,j;
	for(i = 0;i < height;i++){
		for(j = 0; j < width;j++){
			if(cells[i][j]==1)
				cout<<"*";
			else
				cout<<" ";
		}
		cout<<endl;
	}

}

int check(int a,int i,int j){
	if (a==3)
	   return 1;
	else if(a==2)
		return cells[i][j];
	else
		return 0;
}
void sp1(){
	int a;
	for(int i = 1;i<width-1;i++){
		a = cells[0][i-1]+cells[0][i+1]+cells[1][i-1]+cells[1][i]+cells[1][i+1];
		NewCells[0][i] = check(a,0,i);
	}
	for(int i = 1;i<width-1;i++){
		a = cells[height-1][i-1]+cells[height-1][i+1]+cells[height-2][i-1]+cells[height-2][i]+cells[height-2][i+1];
		NewCells[height-1][i] = check(a,height-1,i);
	}
	for(int i = 1;i<height-1;i++){
		a = cells[i-1][0]+cells[i+1][0]+cells[i-1][1]+cells[i][1]+cells[i+1][1];
		NewCells[i][0] = check(a,i,0);
	}
	for(int i = 1;i<height-1;i++){
		a = cells[i-1][width-1]+cells[i+1][width-1]+cells[i-1][width-2]+cells[i][width-2]+cells[i+1][width-2];
		NewCells[i][width-1] = check(a,i,width-1);
	}
}
void updateWithoutInput_life(){

	int NeibourNumber;
	int i,j;
		sp1();
		NeibourNumber = cells[1][0]+cells[0][1]+cells[1][1];
		NewCells[0][0] = check(NeibourNumber,0,0);

		NeibourNumber = cells[height-2][width-1]+cells[height-2][width-2]+
		cells[height-1][width-2];
		NewCells[height-1][width-1] = check(NeibourNumber,height-1,width-1);

		NeibourNumber = cells[1][width-1]+cells[1][width-2]+cells[0][width-2];
		NewCells[0][width-1] = check(NeibourNumber,0,width-1);

		NeibourNumber = cells[height-1][1]+cells[height-2][1]+cells[height-2][0];
		NewCells[height-1][0] = check(NeibourNumber,height-1,0);

	for(i = 1;i<height-1;i++){
		for(j = 1;j<width - 1;j++){
			NeibourNumber = cells[i-1][j-1] + cells[i-1][j] + cells[i-1][j+1]
			+cells[i][j-1]+cells[i][j+1]+cells[i+1][j-1]+cells[i+1][j]+cells[i+1][j+1];
			if(NeibourNumber == 3)
				NewCells[i][j] = 1;
			else if(NeibourNumber==2)
				NewCells[i][j] = cells[i][j];
			else
				NewCells[i][j] = 0;
		}
	}
	for(i = 0;i<=height - 1;i++)
		for(j = 0;j<=width - 1;j++)
			cells[i][j] = NewCells[i][j];
}

int updateWithInput_life(){

}

int window_life(){
    system("cls");
    int i,j;
    for(i = 0;i<height/3;i++){
        for(j = 0;j<width;j++){
            printf(" ");
        }
        printf("\n");
    }
    for(i = 0;i<width/3;i++){
        printf(" ");
    }
    printf("Conway's Game of Life\n");
    printf("\n");

    for(i = 0;i<width/4;i++){
        printf(" ");
    }
    printf("1. Random Start\n");
    printf("\n");

    for(i = 0;i<width/4;i++){
        printf(" ");
    }
    printf("2. Gosper Glider Gun\n");
    printf("\n");

    while(!kbhit()){
		char choice_life = getch();
		if(choice_life =='1')
            return 1;
        else if(choice_life =='2')
            return 2;
        else if(choice_life == ' ')
            return 0;
    }
}
int main_life(){
    HideCursor();
    char input;
    int ans_life;
    system("COLOR F0");
	while(1){
        ans_life = window_life();
        if(ans_life == 1)
            startup_life();
        else if(ans_life == 2)
            gosper_plane();
        else if(ans_life == 0)
            break;

        while(1){

            show_life();
            updateWithoutInput_life();

            if(kbhit()){
                input = getch();
            if(input ==' ')
                break;
            }
        }

	}
	system("COLOR 07");
	return 0;
}
