#include "ft_printf.h"
#include <locale.h>

int		main(void)
{
	setlocale(LC_ALL, "");
	printf("%S\n", L"今日は木曜日です");
	return (0);
}
