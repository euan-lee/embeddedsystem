
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <ctype.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#define LED_DRIVER_NAME "/dev/periled"
#include "led.h"

int main(int argc , char **argv)
{
unsigned int data = 0;
int fd;

data = strtol(argv[1],NULL,16); //String을 16진수로 가정하고 integer형으로 변환
printf("wrate data :0x%X\n", data);
printf("test");
// open driver
ledLibInit();
write(fd,&data,4);
ledLibExit();
/*close(fd);*/
return 0;
}
