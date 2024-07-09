#include <unistd.h>
#include <stdarg.h>

#include <stdio.h>

size_t	ft_putchar(int arg)
{
	return (write(1, &arg, 1));
}

void	ft_putstr(char *s, size_t *res) {
	while (*s) {
		*res += ft_putchar(*s);
		s++;
	}
}

void	d_handler(long long int arg, int base, size_t *res)
{
	const char bases[16] = "0123456789abcdef";

	if (arg >= base)
		d_handler(arg / base, base, res);
	*res += ft_putchar(bases[arg % base]);
}

size_t	ft_printf(const char *format, ...)
{
	size_t	res;
	va_list	args;

	res = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'd')
				d_handler(va_arg(args, int), 10, &res);
			else if (*format == 'x')
				d_handler(va_arg(args, int), 16, &res);
			else if (*format == 's')
				ft_putstr(va_arg(args, char *), &res);
			else
				break ;
		}
		else
		{
			write(1, format, 1);
			res++;
		}
		format++;
	}
	va_end(args);
	return (res);
}

int main(void)
{
	size_t res;

	res = 0;
	res = ft_printf("number is: %s\n", "azxcv");
	ft_printf("returned %d\n ", res);
}