#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <conio.h>

void time_pass(time_t start);
void display_time(long nhour, long nmin, long nsecond);
void control_watch(void);

int main(void)
{
	display_time(0, 0, 0);
	getch();
	control_watch();
	return 0;
}
void control_watch(void)//키를 입력받아서 스탑와치제어 
{
   char key; //입력받을 변수 생성 
   time_t start;//타임함수의 start변수 
   start=time(NULL);//시간비어있음 
   time_pass(start);//time_pass함수에 시작변수 넣음 
   do
   {
	key=getch();
	switch(key)
	{
	   case 10 :
		time_pass(start);//엔터 시작또는 정지 
	   case 32 : 
		start=time(NULL);//스페이스바 초기화 
		time_pass(start);//재시작 
		break;
	   case 27 : 
		exit(0);//종료 
		break;
	}
   }while(key!=27);//esc 누르면 종료 

}
void time_pass(time_t start)//시작시간과 현재시간 사이의 차이계산 
{
double hour, min, second;
long nhour, nmin, nsecond;
time_t now;
while(!kbhit())//키를 입력하면 중지 
{
	now=time(NULL);//현재시간 변수 
	second=difftime(now, start);//시간차이 계산 초로변환 
	hour= (second/3600.);//시간으로 변환 
	nhour= (long) hour;//시간 타입변환 
	min= fmod(second, 3600.)/60;//초를 3600으로 나눈나머지의 몫구하기
	nmin= (long) min;//분 타입변환 
	second= fmod(second, 60);//초를 60으로나눈 나머지 
	nsecond= (long) second;//타입 
	display_time(nhour, nmin, nsecond);//변환한값들을 출력함수에넣어줌 
 }
}
void display_time(long nhour, long nmin, long nsecond)//출력 
{
	system("cls");//화면비움 
	printf("stopwatch\n\n");
	printf("%.2ld시 %.2ld분 %.2ld초 \n\n", nhour, nmin, nsecond);
	printf("Enter:(시작/정지), SPACE:재시작, Esc:종료\n");

}
