#ifndef F_CPU
#define F_CPU 8000000UL
#endif

//#include <asf.h>
#include <avr/io.h>
#include <util/delay.h>


int main (void) {
	//Insert system clock initialization code here (sysclk_init()). 
	//board_init();
	//Insert application code here, after the board has been initialized. 
	
	DDRC  = 0b11111111;          // ������������� ����� C - ��������� �� ����� ������ ��� ������.
	PORTC = 0b00000000;          // ��� "0" �� ���� ������� C
	DDRD  = 0b00000000;  //����������� ��� ������� ����� D �� ����� "����"
	PORTD = 0b11111111;  //������������� ��� ������� ����� D � ���.�1� (�� ������ ����� ���������� ������ Vcc)
	int I = 123;
	
	while(1) {
		/*// LED on
		PORTC = 0b00000001;     // PC0 = 1 = Vcc
		_delay_ms(500);         // �������� 500��
		//LED off
		PORTC = 0b00000010;     // PC0 = 0 = GND
		_delay_ms(500);         // �������� 500��
		*/
		//���������: ���� ��������� PD0 ���.�0� �� ������ ������
		if ((PIND & (1 << PD0)) == 0) {
			_delay_ms(50); // ���� ���������� ������� � ��������� ������
			/*	subi	r20,k01
			sbci	r21,k00
			sbci	r22,k00
			brne	L0041
			�������� �� ����. �� ��� ����������� delay_ms */
			if ((PIND & (1 << PD0)) == 0)
				PORTC = 0b00000001;
			//PORTC |= (1 << PC0);     //��������� PC0 ������������� � ���.�1�
		} else {
			_delay_ms(50);
			if ((PIND & (1 << PD0)) == 1)
				PORTC = 0b00000010;
			//PORTC &= ~(1 << PC0);    //��������� PC0 ������������� � ���.�0�
		}
	}
	return 0;
}
