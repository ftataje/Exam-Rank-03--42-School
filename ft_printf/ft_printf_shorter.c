#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

size_t	ft_putstr(char *string, int length)
{
	while (string && string[length] && ++length);
	return (string ? write(1, string, length) : write(1, "(null)", 6));
}

void	ft_putnbr(long number, unsigned length, char *sign, int *size)
{
	if (number >= length)
		ft_putnbr(number / length, length, sign, size);
	*size += (int) write(1, &sign[number % length], 1);
}

void	ft_puthex(long number, int length, char *sign, int *size)
{
	(number < 0) ? (*size += (int) write(1, "-", 1), \
		ft_putnbr(-number, length, sign, size)) : (ft_putnbr(number, length, sign, size));
}

int	ft_printf(char *format, ...)
{
	int		size = 0;
	va_list	ap;

	va_start(ap, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1) == 's' && (format += 2))
			size += (int) ft_putstr(va_arg(ap, char *), 0);
		else if (*format == '%' && *(format + 1) == 'x' && (format += 2))
			ft_putnbr(va_arg(ap, int), 16, "0123456789abcdef", &size);
		else if (*format == '%' && *(format + 1) == 'd' && (format += 2))
			ft_puthex(va_arg(ap, int), 10, "0123456789", &size);
		else
			size += (int) write(1, format++, 1);
	}
	return (va_end(ap), size);
}

int	main(void)
{
	char	caract = 'a';
	printf("Caracter\n");
	printf("normal: %c\n", caract);
	ft_printf("mio: %c\n", caract);
	printf("\n");

	char	a[] = "HolaHolaXX";
	printf("String\n");
	printf("normal: %s\n", a);
	ft_printf("mio: %s\n", a);
	printf("\n");

	int		int1 = 18;
	printf("Hexad\n");
	printf("normal: %p\n", int1);
	ft_printf("mio: %p\n", int1);
	printf("\n");

	int		int2 = 5;
	printf("Numero decimal\n");
	printf("normal: %d\n", int2);
	ft_printf("mio: %d\n", int2);
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

	int		int5 = 15;
	printf("hex base 10 minuscula\n");
	printf("normal: %x\n", int5);
	ft_printf("mio: %x\n", int5);
	printf("\n");

	int		int6 = 15;
	printf("hex base 10 mayuscula\n");
	printf("normal: %X\n", int6);
	ft_printf("mio: %X\n", int6);
	printf("\n");

	return (0);
}
