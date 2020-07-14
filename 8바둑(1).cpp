#include <stdio.h> //사용할 해더파일 선언 
#include <stdlib.h>//사용할 해더파일 선언 
#include <conio.h>//사용할 해더파일 선언 
#include <windows.h>//사용할 해더파일 선언 

void move_arrow_key(char chr, int *x, int *y, int x_b, int y_b); //사용할 함수를 위에서 먼져 선언한다 
void gotoxy(int x, int y); //사용할 함수를 위에서 먼져 선언한다 
void draw_check01(int c, int r);//사용할 함수를 위에서 먼져 선언한다 
void game_control(void);//사용할 함수를 위에서 먼져 선언한다 

int main(void)//프로그램이 실행될메인되는  함수 선언 
{
	game_control();//함수사용 
	return 0;//현재 실행중인 해당함수를 정상적으로 벗어나겠다는 명령 
}

void gotoxy(int x, int y)//int 타입 x,y를 매개변수로 갖는 함수 선언 
{	//커서의 위치 바꾸는 함수 

   COORD Pos = {x - 1, y - 1}; //#include <windows.h>의 해더파일에있는 함수를 사용해 커서의 위치를 바꾼다 
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);//#include <windows.h>의 해더파일에있는 함수를 사용해 커서의 위치를 바꾼다 
}

void draw_check01(int c, int r) //바둑판을 그리는 함수 
{ 
    int i, j;
    unsigned char a=0xa6;//일반 캐릭터는 -127~127까지고 언사인캐릭터는 표현을 0~255까지할수있다 특수문자를 사용하기위해 변수를 선언한다. 
    unsigned char b[12]; //일반 캐릭터는 -127~127까지고 언사인캐릭터는 표현을 0~255까지할수있다 특수문자를 사용하기위해 변수를 선언한다. 
    for(i=1;i<12;i++)
	b[i]=0xa0+i;//12개의 서로다른 특수문자를 출력 
    printf("%c%c",a, b[3]);//(┌)문자 사용 
    for(i=0;i<c-1;i++)
	 printf("%c%c", a, b[8]);//(┬)문자 출력 
    printf("%c%c", a, b[4]);//(┐)출력 
    printf("\n");
    for(i=0;i<r-1;i++)//
    {
	printf("%c%c", a, b[7]);//(├)문자 출력 
	for(j=0;j<c-1;j++)
	   printf("%c%c", a, b[11]);//(+) 모양출력 
	printf("%c%c",a, b[9]);//(ㅓ)모양 출력 
	printf("\n");
    }
    printf("%c%c", a, b[6]);//(ㄴ)모양 출력 
    for(i=0;i<c-1;i++)
	printf("%c%c", a, b[10]);//(┴)모양 출력 
    printf("%c%c", a, b[5]);//(ㄴ이 왼쪽으로뒤집힌)모양 출력 
    printf("\n");
     printf("\n");
      printf("\n");      
} 
void game_control(void)//바둑판에 바둑돌 표시함수 바둑판크기 입력함수 
{
    int x=1, y=1;  
    char key;
    do //밑에 반복 
    {
	gotoxy(1,1);//처음 커서 위치를 0,0 으로 시작 
	draw_check01(18, 18);//바둑판의 크기 선언 
	gotoxy(x, y);//처음 커서 위치를 0,0으로 시작 
	printf("○");//바둑돌 표시를 0,0으로 
	gotoxy(1, 20);//방향키를 누르시오 텍스트를  1,20으로 
	printf("방향키를 누르시오.");//방향키를 누르시오 텍스트를  1,20으로 
	key=getch();//키보드입력을 받는다 
	if (key==27) 
		exit(0);//키보드값 27입력시 나감 
	else if (key>=72)//키보드 방향키 입력시 위쪽이 72부터 시작 
		move_arrow_key(key, &x, &y, 37, 19); //키를 입력받으면 움직이는 함수에다가 넣어준다 뒤에 37 19는 최대값 
   }while(1);
}

void move_arrow_key(char key, int *x1, int *y1, int x_b, int y_b)
{
	switch(key)
	{
	case 72:  //위쪽(상) 방향의 화살표 키 입력
		*y1=*y1-1;
		if (*y1<1)	*y1=1; //y좌표의 최소값
		break;
	case 75:  //왼쪽(좌) 방향의 화살표 키 입력
		*x1=*x1-2;             //좌측방향으로 2씩 감소
		if (*x1<1)	*x1=1; //x좌표의 최소값
		break;
	case 77:  //오른쪽(우) 방향의 화살표 키 입력
		*x1=*x1+2;               //우측방향으로 2씩 증가
		if (*x1>x_b)  *x1=x_b; //x좌표의 최대값(경계)
		break;
	case 80:  //아래쪽(하) 방향의 화살표 키 입력
		*y1=*y1+1;
		if (*y1>y_b)  *y1=y_b; //y좌표의 최대값(경계)
		break;
	default:
		return;
	}
}

