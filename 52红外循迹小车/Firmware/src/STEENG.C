#include <config.h>
#include<STEENG.h>
 
uchar count = 0;
uchar SEV_conut = 10;
uchar flag20ms = 0;//20ms标志

uchar Timer(){
	if(flag20ms==50)
		flag20ms=0;	 //1s内时间核对，会有一定BUG，希望后来人研究研究改进
	return 	flag20ms;
}

void right(uchar SEV){
 	SEV_conut=10;
	if(SEV>3)SEV=3;	 //本人小车最大偏角，车转角大可以调大范围
	SEV_conut=SEV_conut+SEV;
} 
void lift(uchar SEV){
 	SEV_conut=10;
	if(SEV>3)SEV=3;	 //本人小车最大偏角，车转角大可以调大范围
	SEV_conut=SEV_conut-SEV;
}
void Go(){
	SEV_conut=10;
}
	/*定时器T0初始化*/
void Com_Init(){
    TMOD &= 0x00;
    TMOD |= 0x01; //定时器T0设置成方式1
 
    TH0 = 0xff;   //定时常数 0.1ms 晶振为11.0592MHz
    TL0 = 0xa4;
 
    ET0 = 1;      
    TR0 = 1; 
	EA=1; 
	}
	
	/*T0中断初始化*/
void Time0_Init() interrupt 1{
	TR0 = 0; 
	TH0 = 0xff; //重装时间常数 0.1ms
	TL0 = 0xa4;
	
	if(count <= SEV_conut){//5==0° 10==90°
		SEV_PWM = 1; 
	}
	else{ 
		SEV_PWM = 0; 
	}
	count++;
	if(count >= 200){//T = 20ms清零 
		count = 0;
		flag20ms++; 
	}
	TR0 = 1; //开启T0
}
