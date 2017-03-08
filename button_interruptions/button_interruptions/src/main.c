
#include <asf.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 8000000UL  // 8 MHz �������� �������

int i=0x00;

//���������� ��� ������������� ���������� �� ������ int0
ISR(INT0_vect) {
	i++;
	if(i>0xff) {
		i=0x00;
	}
	PORTA=i;
}


int main (void) {
	 //������������ ������ �����/������
	 DDRA = 0xff;//0xff = 0b11111111  ��� ������ ����� A ���������������� ��� ������
	 DDRD = 0x00;//0x00 = 0b00000000  ��� ������ ����� D ���������������� ��� �����
	 PORTD = 0xff;//�������� ������������� ��������� �� ��� ������ ����� D
	 //������������� ����������
	 GICR |= 0x40;//0x40 = 0b01000000 ��������� ���������� �� int0
	 MCUCR |= 0x3;//0x3 = 0b00000011 ���������� �� ������ int0
	 sei();//��������� ��� ����������, cli()- ���������

	 while (1) {

	 }
}
