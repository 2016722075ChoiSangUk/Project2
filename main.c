﻿#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

struct stat stat1, stat2;
struct tm *time1, *time2;
struct tm temp;

void filestat1();
void filestat2();
void filetime1();
void filetime2();
void sizecmp();
void blockcmp();
void datecmp();
void timecmp();

int main(){
    filestat1();
    filestat2();
    filetime1();
    filetime2();
    sizecmp();
    blockcmp();
    datecmp();
    timecmp();
}

//파일 1의 정보를 가져오는 함수 작성
void filestat1(){
   stat("text1",&stat1);
}

//파일 2의 정보를 가져오는 함수 작성
void filestat2(){
    stat("text2",&stat2);
}

//파일 1의 시간 정보를 가져오는 함수 작성
void filetime1(){
     time1=localtime(&stat1.st_mtime);
	temp.tm_mon=time1->tm_mon;
	temp.tm_mday=time1->tm_mday;
	temp.tm_hour=time1->tm_hour;
	temp.tm_min=time1->tm_min;
	time1=&temp;
}

//파일 2의 시간 정보를 가져오는 함수 작성
void filetime2(){
   time2=localtime(&stat2.st_mtime);
}

//두 개의 파일 크기를 비교하는 함수 작성
void sizecmp(){
    printf("size compare\n");
	if(stat1.st_size>stat2.st_size)
		printf("text1 is bigger.\n\n\n");
	else if(stat1.st_size<stat2.st_size)
		printf("text2 is bigger.\n\n\n");
	else
		printf("sizes are equal.\n\n\n");
}

//두 개의 파일 블락 수를 비교하는 함수 작성
void blockcmp(){
   printf("block compare\n");
	if(stat1.st_blocks>stat2.st_blocks)
		printf("text1 is bigger.\n\n\n");
	else if(stat1.st_blocks<stat2.st_blocks)
		printf("text2 is bigger.\n\n\n");
	else
		printf("sizes are equal.\n\n\n");
}

//두 개의 파일 수정 날짜를 비교하는 함수 작성
void datecmp(){
    printf("date compare\n");
	if (time1->tm_mon+1 > time2->tm_mon+1)
		printf("text2 is early\n\n\n");
	else if (time1->tm_mon+1 == time2->tm_mon+1)
	{
		if (time1->tm_mday > time2->tm_mday)
			printf("text2 is early\n\n\n");
		else if (time1->tm_mday == time2->tm_mday)
			printf("same date\n\n\n");
		else
			printf("text1 is early\n\n\n");
	}
	else
		printf("text1 is early\n\n\n");
	return;
}

//두 개의 파일 수정 시간을 비교하는 함수 작성
void timecmp(){
    printf("time compare\n");
	if (time1->tm_hour > time2->tm_hour)
	{
		printf("text2 is early\n\n\n");
	}
	else if (time1->tm_hour == time2->tm_hour)
	{
		if (time1->tm_min > time2->tm_min)
			printf("text2 is early\n\n\n");
		else if (time1->tm_min == time2->tm_min)
			printf("same time\n\n\n");
		else
			printf("text1 is early\n\n\n");
	}
	else
		printf("text1 is early\n\n\n");
	return;
}