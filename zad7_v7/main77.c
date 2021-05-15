#include "../usart/usart.c"
#include <stdint.h>
#include <stdlib.h>
#include <util/delay.h>



int16_t UkloniRazmak(int8_t *str)
{
	int8_t i = 0;
	int8_t j = 0;

	while (str[i] != 0)
	{
		if (str[i] != ' ')
		{
			str[j] = str[i];
			i++;
			j++;

		}
		else
		{
			i++;

		}
	}
	str[j] = 0;
	return 1;
}


int16_t UkloniDuplikate(int8_t *str)
{
	int8_t i = 0;
	int8_t j = 0;
	int8_t karakter_ponovljen;

	while (str[i] != 0)
	{
		karakter_ponovljen = 0;
		for(int8_t k = 0; k < i; k++)
		{
			if (str[k] == str[i])
			{
				karakter_ponovljen = 1;
				break;
			}
		}

		if (karakter_ponovljen != 1)
		{
			str[j] = str[i];
			i++;
			j++;

		}
		else
		{
			i++;

		}
	}
	str[j] = 0;
	return 1;
}

int16_t PonavljanjeKaraktera(int8_t *str)
{
	int8_t i = 0;
	int8_t j = 0;
	int8_t max_num = 0;
	int8_t max = str[0];
	int8_t tmp;

	while (str[i] != 0)
	{
		tmp = 0;
		j = 0;
		while (str[j] != 0)
		{
			if (str[j] == str[i])
			{
				tmp++;
			}
			j++;
		}

		if (tmp > max_num)
		{
			max_num = tmp;
			max = str[i];

		}
		i++;
	}
	str[0] = max;
	str[1] = 0;
	return 1;
}


int16_t Operation(int16_t br, int8_t *str)
{
	int16_t res;

	switch (br)
	{
	case 1:
		res = PonavljanjeKaraktera(str);
		return res;
		break;
	case 2:
		res = UkloniRazmak(str);
		return res;
		break;
	case 3:
		res = UkloniDuplikate(str);
		return res;
		break;
	default:
		usartPutString("Greska! \r\n");
		return -1;

	}

	return res;
}


int main ()
{
	int16_t number;
	int8_t str[64];
	int16_t joi;
	usartInit(9600);

	while(1)
	{
		usartPutString("Unesite string: \r\n");
		while (!usartAvailable());

		_delay_ms(100);

		usartGetString(str);

		usartPutString("Uneti string je: ");
		usartPutString(str);

		usartPutString("Izaberite opciju za modifikaciju unetog stringa:\r\n");
		usartPutString("1. Slovo koje se najvise ponavlja?\r\n");
		usartPutString("2. Ukloni sve ‘ ’ karaktere.\r\n");
		usartPutString("3. Ukloni sve duplikate karaktera.\r\n");

		number = usartParseInt();

//		sprintf(str, "%d = \0", number);
//		usartPutString("Uneli ste opciju: ");
//		usartPutString(str);

		joi = Operation(number, str);
		usartPutString(str);
		usartPutString("\r\n");




	}













	return 0;
}









