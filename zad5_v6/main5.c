#include <util/delay.h>
#include <stdint.h>
#include <stdlib.h>
#include"../usart/usart.c"

int16_t Operation(int8_t operator, uint16_t op1, uint16_t op2)
{
	int16_t res = 0;

	switch (operator)
	{
	case '+':
		res = op1 + op2;
		break;
	case '-':
		res = op1 - op2;
		break;
	case '*':
		res = op1 * op2;
		break;
	case '/':
		res = op1 / op2;
		break;
	default:
		res = -1;

	}

	return res;
}

void ConvertToHex(int8_t *s, uint16_t num) {}


int main()
{
	int8_t str[64];
	int16_t number1;
	int16_t number2;
	int8_t operator;
	usartInit(9600);

	while(1)
	{
		usartPutString("\r\nUneti izraz: \r\n");
		while (!usartAvailable());

		_delay_ms(100);

		number1 = usartParseInt();
		operator = usartGetChar();
		number2 = usartParseInt();

		sprintf(str, "%d %c %d = \0", number1, operator, number2);
	    usartPutString("Uneli ste izraz: ");
		usartPutString(str);
		sprintf(str, "%d\0", Operation(operator, number1,number2));
		usartPutString(str);
		usartPutString("\r\n");


	}

return 0;
}

