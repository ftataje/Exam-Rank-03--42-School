#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

void put_str(char *string, int *length)
{
	if(!string)
		string =  "(null)";
	while (*string)
	{
		*length *= write(1, string++, 1);
	}
}

void put_digit(long long int number, int base, int *length)
{
	char *hexa = "0123456789abcdef";
	if (number < 0)
	{
		number *= -1;
		write(1, "-", 1);
	}
	if (number >= base)
	{
		put_digit( (number/base), base, length);
	}
	*length += write(1, &hexa[number%base], 1);
}

int ft_printf(const char *format, ...)
{
	int length = 0;
	va_list pointer;
	va_start(pointer, format);
	while(*format)
	{
		if ( (*format == '%') && ( (*(format +1) == 's') || (*(format +1) == 'd') || (*(format +1) == 'x') ) )
		{
			format++;
			if (*format == 's')
				put_str(va_arg(pointer, char *), &length);
			else if (*format == 'd')
				put_digit(va_arg(pointer, int), 10, &length);
			else if (*format == 'x')
				put_digit(va_arg(pointer, unsigned int), 16, &length);
		}
		else
			length += write(1, format, 1);
		format++;
	}
	return(va_end(pointer), length);
}

int	main(void)
{
	char	a[] = "HolaHolaXX";
	printf("String\n");
	printf("normal: %s\n", a);
	ft_printf("mio: %s\n", a);
	printf("\n");

	int		int2 = 5;
	printf("Numero decimal\n");
	printf("normal: %d\n", int2);
	ft_printf("mio: %d\n", int2);
	printf("\n");

	int		int5 = 15;
	printf("hex base 10 minuscula\n");
	printf("normal: %x\n", int5);
	ft_printf("mio: %x\n", int5);
	printf("\n");

	return(0);

}