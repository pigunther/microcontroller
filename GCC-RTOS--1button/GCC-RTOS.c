#include <HAL.h>
#include <EERTOS.h>
#include <button.h>


// ��������� ����� ============================================================
void Reaction(void);

// Global Variables

//RTOS Interrupt
ISR(RTOS_ISR)
{
sei();
TimerService();						// ���������� ���� ����������
}
//..........................................................................


void Reaction(void)
{
if (bt1) { bt1=0; LED_PORT |=1<<LED0; }
if (bt2) { bt2=0; LED_PORT |=1<<LED1; }
if (bt3) { bt3=0; LED_PORT |=1<<LED2; }
if (bt4) { bt4=0; LED_PORT |=1<<LED3; }
if (bt5) { bt5=0; LED_PORT |=1<<LED4; }

if (bt_l)  { bt_l=0;  LED_PORT = 0;}
if (bt_l2) { bt_l2=0; LED_PORT = 0xFF;}

if (bt_al) { bt_al=0; LED_PORT |=1<<LED5;}

SetTimerTask(Reaction, 100);
}



//============================================================================
//������� �����
//============================================================================


//==============================================================================
int main(void)
{
InitAll();		// �������������� ���������
InitRTOS();		// �������������� ����
RunRTOS();		// ����� ����. 


bt_scan();		// ������ ��������� ������������
Reaction();		// ������ ����������� �������

while(1) 		// ������� ���� ����������
{
wdt_reset();	// ����� ��������� �������
TaskManager();	// ����� ����������
}

return 0;
}



