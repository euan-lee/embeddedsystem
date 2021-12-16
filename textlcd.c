#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "textlcd.h"

#define TEXTLCD_DRIVER_NAME		"/dev/peritextlcd"

static int fd = 0;

stTextLCD stlcd;

int lcdtextwrite(const char str1, const char *str2, int lineFlag)
{
	stlcd.cmd = str1;
	stlcd.cmdData = lineFlag;
	strcpy(stlcd.TextData[lineFlag - 1] ,str2);
		
	fd = open(TEXTLCD_DRIVER_NAME,O_RDWR);
	if ( fd < 0 )
	{
		perror("driver (//dev//peritextlcd) open error.\n");
		return 1;
	}
	else{
		printf("textlcd file open success!!");
	}
	write(fd,&stlcd,sizeof(stTextLCD));
	
	close(fd);
	
}
