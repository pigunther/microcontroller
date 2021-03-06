#include <mega8.h>
#include <ff.h>
#include <delay.h>

// Timer2 output compare interrupt service routine
interrupt [TIM2_COMP] void timer2_comp_isr(void)
{
disk_timerproc();
}

void main(void)
{
    FATFS fs;         /* ������� ������� (file system object) ��� ���������� ������ */
    FIL fp;      /* �������� ������� */
    unsigned char buffer[20];   /* ����� ��� ����������� ������ ���� */
    unsigned int br;         /* ������� ������/������ ����� */

PORTD=0x00;
DDRD=0x01;

// Timer/Counter 2 initialization
// Clock source: System Clock
// Clock value: 7,813 kHz
// Mode: CTC top=OCR2
// OC2 output: Disconnected
ASSR=0x00;
TCCR2=0x0F;
TCNT2=0x00;
OCR2=0x64;

// Timer(s)/Counter(s) Interrupt(s) initialization
TIMSK=0x80;

#asm("sei")
delay_ms(1000);

disk_initialize(0);
f_mount(0, &fs);
f_open(&fp, "0:/1.txt", FA_OPEN_EXISTING | FA_READ);
f_read(&fp, buffer, 2, &br);
f_close(&fp);

if(buffer[0]=='1') //���� � ����� ������ ������ 1 �� �������� ���������
{
PORTD.0=1;
}
else
{    
while(1)
   { 
   
   
  PORTD.0=1;
  delay_ms(200);
  PORTD.0=0;
  delay_ms(200); 
  }
}
   while(1);
   
}