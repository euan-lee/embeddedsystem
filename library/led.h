#ifndef _LED_H_
#define _LED_H_
int ledLibInit(void);//led 시작
int ledOnOff(int ledNum,int onOff);//led 전원 
int ledStatus(void);//몇번 led가 켜져 있는지?
int ledLibExit(void);//led 전원 종료

#define LED_DRIVER_NAME "/dev/periled"
#endif _LED_H_
