#include <unistd.h>
#include <stdarg.h>

int	ft_putstr(char *str)
{
	int i = 0;
	if (!str)
		str = "(null)";
	while (str[i])
		write (1, &str[i++], 1);
	return i;
}
int put_digit(long long int number, int base)
{
	int len = 0;
	char *hexa = "0123456789abcdef";

	if (number < 0)
	{
		number = -number;
		len += write(1, "-", 1);
	}
	if (number >= base)
		len += put_digit((number / base), base);
	len += write (1, &hexa[number % base], 1);
	return (len);
}
int ft_printf(const char *format, ... )
{
	int i = 0;
	int len = 0;

	va_list list;
	va_start(list, format);
	while(format[i])
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			i++;
			if (format[i] == 's')
				len += ft_putstr(va_arg(list, char *));
			else if (format[i] == 'd')
				len += put_digit((long long int)va_arg(list, int), 10);
			else if (format[i] == 'x')
				len += put_digit((long long unsigned int)va_arg(list, unsigned int), 16);
		}
		else
			len += write(1, &format[i], 1);
		i++;
	}
	return (va_end(list), len);
}
