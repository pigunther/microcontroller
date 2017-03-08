#define F_CPU 12000000
#include <util/delay.h>
#include <avr/io.h>


void inline SendByteHorizontal(uint8_t byte){
	uint8_t mask=0b00000001;
	while (mask){
		PORTD &= (~(1<<PIND3));  //PIND3 = 0 - ����� ������ ���������� ����� �� ��������� �������
		if (mask & byte)
			PORTD |=(1<<PIND1);       // PIND1 = 1
		else 
			PORTD &= (~(1<<PIND1));   //PIND1 = 0
		PORTD  |= (1<<PIND3);   //PIND3 = 1 - ��������
		mask<<=1;
	}
	PORTD  &= (~(1<<PIND2)); //��������� PD2 ������������� � ���.�0�
	PORTD  |= (1<<PIND2);
}

void inline SendByteVertical(uint8_t byte){
	uint8_t mask=0b10000000;
	while (mask){
		PORTD &= (~(1<<PIND3));  //PIND3 = 0 - ����� ������ ���������� ����� �� ��������� ������� 
		if (mask & byte)
			PORTD |=(1<<PIND1);       // PIND1 = 1
		else 
			PORTD &= (~(1<<PIND1));   //PIND1 = 0
		PORTD  |= (1<<PIND3);   //PIND3 = 1 - ��������
		mask>>=1;
	}
	PORTD  &= (~(1<<PIND4));
	PORTD  |= (1<<PIND4);
}

void  inline OutHoriz(){
	PORTD  &= (~(1<<PIND2)); //��������� PD2 ������������� � ���.�0�
	PORTD  |= (1<<PIND2);    //��������� PD2 ������������� � 1 -- ��������� ��, ��� �������� �� ��������� � �������� �� ������� 
}
void inline OutVert(){
	PORTD  &= (~(1<<PIND4));
	PORTD  |= (1<<PIND4);   // ��������� PD4 ������� � 0, ����� � 1
}
void inline OutOn(){
	PORTD &=(~(1<<PIND6));  // ��������� PD6 � 0
}
void inline OutOff(){
	PORTD |= (1<<PIND6);   // ��������� PD6 � 1
}

void inline TurnCertainDiod(int v, int h) {
	uint8_t vert, one;
	vert = 0b10000000;
	one = 0b111111111;
	
	while (v > 1) {
		vert >>= 1;
		v--;
	}
	SendByteVertical(one - vert);
	vert = 0b10000000;
	while (h > 1) {
		vert >>= 1;
		h--;
	}
	SendByteHorizontal(vert);
}


int main (){
	DDRD=0xff; // ������������� ����� C - ��������� �� ����� ��� ������.
	uint8_t stolb=0b01111111;
	uint8_t strok=0b11111111;
	uint8_t st[] = {
		0b01111111, 0b10111111, 0b11011111, 0b11101111, 0b11110111, 0b11111011, 0b11111101, 0b11111110
	};

	//OutOn();
	SendByteVertical(0);
	SendByteHorizontal(0);
	//_delay_ms(1000);
	int k = 1;

 	while (1) {
		 if (k > 8)
			k = 1;
		TurnCertainDiod(k, k);
		k++;
		_delay_ms(5);
	}
}

