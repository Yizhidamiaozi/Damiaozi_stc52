#include<config.h>
#include<STEENG.h>
#include<findway.h>
#include<motor.h>

void Delay(int n){
    int i,j;
    for(i=0;i<n;i++) {
        for(j=0;j<200;j++);
    }
}
void main(){
	Findway_Init();
	Com_Init();
	Motor_Init();
	while(1){
		Findway_PID();
		Findway_Deal();		
	}
}
