#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

size_t	ft_printf(const char *format, ...)
{
	va_list		args;
	const char *current_input_pos;
	ssize_t res;

	res = 0;
	current_input_pos = format;
	va_start(args, format);
	while (*current_input_pos)
	{
		if (*current_input_pos == '%' && *(current_input_pos + 1))
		{
			current_input_pos++;
			if (*current_input_pos == 'd')
			{
				
			}
			else
				break ;
		}
		else
		{
			res += write(1, current_input_pos, 1);
		}
		current_input_pos++;
	}
	va_end(args);
	return (1);
}

int main(void)
{
	ft_printf("test %x", 53);
	printf("%d", printf("%d", 1234));
}