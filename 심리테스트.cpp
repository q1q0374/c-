#include <stdio.h>
#include <conio.h>
#include <windows.h>
void gotoxy(int x, int y);
void display_text(int count);
void display_question(void);
void display_result(void);
void intro_game(void);
char sol[10][11];  //사용자의 입력 값을 저장할 배열
int main(void)
{
	intro_game();
	display_question();
	printf("\n문제풀이가 모두 끝났습니다.\n");
	printf("\n\n풀이를 보려면 아무키나 누르시오.");
	getch();
	display_result();
	return 0;
}

void gotoxy(int x, int y)//커서 위치이동함수 
{
   COORD Pos = {x - 1, y - 1};
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
void display_text(int count)//디스플레이 출력 
{
	gotoxy(1,2);
	printf("다음 문제를 읽고 답을 입력하시오.\n\n");
	printf("(%d번 문제) \n\n", count+1);

}
void display_question(void)//문제출력 
{
	FILE *fp1;//파일함수 
	char chr1[82];//배열생성 
	int line=5, count=0;//라인과 카운트변수 생성 
	char *file1="심리테스트질문.txt";//파일열기 
	fp1=fopen(file1, "r");//파일열기 
	system("cls");
	while(!feof(fp1))//fp1파일 끝에 도달할때까지 반봅 
	{
		fgets(chr1, 80, fp1);//fp1파일에서 80자씩문자를 chr1에 입력 
		if (chr1[0]==10)//80자씩  받다가 공백을(10)을받으면  
		{
			display_text(count);
			gotoxy(1, line);
			scanf("%s", sol[count]);
			system("cls");
			line=5;
			count++;
		}
		else//게속질문 
		{
			gotoxy(1, line++);
			printf("%s", chr1);
		}
	}
	display_text(count);
	gotoxy(1, line);
	scanf("%s", sol[count]);
	fclose(fp1);//파일닫는다 

}
void display_result(void)//결과를 출력 
{
	FILE *fp2;
	char chr1[82];
	int line=5, count=0;
	char *file2="심리테스트해설.txt";
	fp2=fopen(file2, "r");
	system("cls");
	while(!feof(fp2))
	{
		fgets(chr1, 80, fp2);
		if (chr1[0]==10)
		{
			gotoxy(1, line+1);
			printf("당신의 답은 : %s\n", sol[count]);
			printf("다음문제의 해설은 아무키나 누르시오.");
			getch();
			system("cls");
			line=5;
			count++;
		}
		else
		{
			gotoxy(1, line++);
			printf("%s", chr1);
		}
	}
	gotoxy(1, line+1);
	printf("당신의 답은 : %s\n", sol[count]);
	fclose(fp2);

}
void intro_game(void)//문제 소개 
{
	system("cls");
	printf("심리테스트 게임\n\n");
	printf("제시되는 문제에 모두 답을 하고나면\n");
	printf("해설이 출력됩니다.\n\n");
	printf("아무키나 누르면 시작합니다. ");
	getch();

}
