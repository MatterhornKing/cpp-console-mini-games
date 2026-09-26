#include "bounce_ball.h"

#define h 25
#define w 50

int ball_x,ball_y;
int v_x,v_y;
int canvas_ball[h][w] = {0};//elements of canvas

int pos_x,pos_y;// paddle position
int r;
int le,ri;

int flag = 0;
int score_ball = 0;

void startup_ball(){
	//
	system("cls");
	r = 5;
	pos_x = h - 1;
	pos_y = w/2;
	le = pos_y - r;
	ri = pos_y + r;
	//
	ball_x = pos_x-1;
	ball_y = pos_y;
	v_x = -1;
	v_y = 1;
	canvas_ball[ball_x][ball_y] = 1;
	int k;
	for(k = le;k <= ri;k++)
		canvas_ball[pos_x][k] = 2;

	for(k = 0;k<w;k++)
		for(int i = 0;i<h/4;i++){
            if(rand()%3==1)
                canvas_ball[i][k]= 4;
            else
                canvas_ball[i][k]= 3;
		}

}

void startup_again(){

	ball_x = pos_x-1;
	ball_y = pos_y;
	v_x = -1;
	v_y = 1;
	canvas_ball[ball_x][ball_y] = 1;
}
void show_ball(){
	gotoxy(0,0);
	int i,j;
	for(i = 0;i<h;i++){
		for(j = 0;j<w;j++){
			if(canvas_ball[i][j]==0){
				cout<<" ";
			}
			else if(canvas_ball[i][j]==1){
				cout<<"0";
			}
			else if(canvas_ball[i][j]==2){
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0b);
				cout<<"*";
			}
			else if(canvas_ball[i][j]==4){
			    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0e);
				cout<<"$";
			}
			else if(canvas_ball[i][j]==3){
			    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0f);
				cout<<"#";
			}
		}
		cout<<"|"<<endl;
	}
	for(j=0;j<w;j++){
		cout<<"-";
	}
	cout<<endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0f);
	cout<<"Score:"<<score_ball<<endl;

}

void updateWithInput_ball(){
	char input;
	if(flag == 1){
		flag = 0;
		cin>>input;
		if(input==' '){
			startup_again();
			return;
		}

	}
	if(kbhit()){
		input = getch();
		if(input == 'a'&&le>0){
			canvas_ball[pos_x][ri] = 0;
			pos_y--;
			le = pos_y -r;
			ri = pos_y + r;
			canvas_ball[pos_x][le] = 2;
		}
		if(input == 'd'&&ri<w-1){
			canvas_ball[pos_x][le] = 0;
			pos_y++;
			le = pos_y -r;
			ri = pos_y + r;
			canvas_ball[pos_x][ri] = 2;
		}
		if(input == 's'){
            for(int i = 1;i<w-1;i++){
                if(canvas_ball[pos_x][i] == 2){
                    canvas_ball[pos_x][i]=0;
                    canvas_ball[pos_x+1][i]=2;
                }
            }
            pos_x++;

		}
		if(input == 'w'){
			for(int i = 1;i<w-1;i++){
                if(canvas_ball[pos_x][i] == 2){
                    canvas_ball[pos_x][i]=0;
                    canvas_ball[pos_x-1][i]=2;
                }
            }
            pos_x--;
		}

	}


}
int updateWithoutInput_ball(){
	//
	if(ball_x == pos_x-1){
		if((ball_y>=le)&&(ball_y<=ri)){
			cout<<"\a";
		}

	}
    else if(ball_x>h-2){
			cout<<"Game over!"<<endl;
			system("pause");
			//system("cls");
			return 0;
    }

	static int speed = 0;
	if(speed < 3)
		speed++;
	if(speed == 3){
		speed = 0;

		//
		canvas_ball[ball_x][ball_y] = 0;

		ball_x += v_x;
		ball_y += v_y;
		canvas_ball[ball_x][ball_y] = 1;

		if((ball_x==0)||((ball_x == pos_x-1)&&(ball_y>=le)&&(ball_y<=ri)))
			v_x = -v_x;
		if((ball_y==0)||(ball_y==w-1))
			v_y = -v_y;

		if(canvas_ball[ball_x-1][ball_y]==3){
			v_x = -v_x;
			canvas_ball[ball_x-1][ball_y] = 0;
			cout<<"\a";
			score_ball++;
		}
		if(canvas_ball[ball_x-1][ball_y]==4){
			v_x = -v_x;
			canvas_ball[ball_x-1][ball_y] = 0;
			cout<<"\a";
			score_ball+=3;
		}

	}

    return 1;
	//Sleep(50);
}



int main_ball(){
	HideCursor();
	startup_ball();
	while(1){
		show_ball();
		if(updateWithoutInput_ball()==0)
            break;
		updateWithInput_ball();
	}
	system("cls");
	return 0;
}

