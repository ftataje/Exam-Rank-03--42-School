#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

void	put_string(char *string, int *length)
{
	if (!string)
		string = "(null)";
	while (*string)
		*length += write(1, string++, 1);
}

void	put_digit(long long int number, int base, int *length)
{
	char	*hexadecimal = "0123456789abcdef";

	if (number < 0)
	{
		number *= -1;
		*length += write(1, "-", 1);
	}
	if (number >= base)
		put_digit((number / base), base, length);
	*length += write(1, &hexadecimal[number % base], 1);
}

int	ft_printf(const char *format, ...)
{
	int length = 0;

	va_list	pointer;
	va_start(pointer, format);

	while (*format)
	{
		if ((*format == '%') && ((*(format + 1) == 's') || (*(format + 1) == 'd') || (*(format + 1) == 'x')))
		{
			format++;
			if (*format == 's')
				put_string(va_arg(pointer, char *), &length);
			else if (*format == 'd')
				put_digit((long long int)va_arg(pointer, int), 10, &length);
			else if (*format == 'x')
				put_digit((long long int)va_arg(pointer, unsigned int), 16, &length);
		}
		else
			length += write(1, format, 1);
		format++;
	}
	return (va_end(pointer), length);
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

	/*char	caract = 'a';
	printf("Caracter\n");
	printf("normal: %c\n", caract);
	ft_printf("mio: %c\n", caract);
	printf("\n");

	int		int1 = 18;
	printf("Hexad\n");
	printf("normal: %p\n", int1);
	ft_printf("mio: %p\n", int1);
	printf("\n");

	int		int3 = 3;
	printf("Entero base 10\n");
	printf("normal: %i\n", int3);
	ft_printf("mio: %i\n", int3);
	printf("\n");

	int		int4 = -9;
	printf("Numero dec sin signo\n");
	printf("normal: %u\n", int4);
	ft_printf("mio: %u\n", int4);
	printf("\n");

	

	int		int6 = 15;
	printf("hex base 10 mayuscula\n");
	printf("normal: %X\n", int6);
	ft_printf("mio: %X\n", int6);
	printf("\n");*/

	return (0);
	
}
