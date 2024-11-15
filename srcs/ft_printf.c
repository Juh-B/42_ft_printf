#include "../includes/ft_printf.h"

static size_t ft_specifiers(va_list args, char c)
{
  size_t  printed;

  printed = 0;
  if (c == 'c')
    printed += ft_putchar_fd(va_arg(args, int), 1);
  else if (c == 's')
    printed += ft_putstr_fd(va_arg(args, char *), 1);
  else if (c == 'd' || c == 'i')
    printed += ft_putnbr_fd(va_arg(args, int), 1);
  else if (c == 'u')
    printed += ft_putnbr_unsig_fd(va_arg(args, unsigned int), 1);
  else if (c == 'x' || c == 'X')
    printed += ft_puthex_fd(va_arg(args, unsigned int), c, 1);
  else if (c == 'p')
    printed += ft_putptr(args, c);
  else if (c == '%')
    printed += ft_putchar_fd('%', 1);
  return (printed);
}

// Funcao principal
int ft_printf(const char *fmt_str, ...)
{
  va_list args;
  int  i;
  size_t  printed;

  va_start(args, fmt_str);
  i = 0;
  printed = 0;
  while (fmt_str[i] != '\0')
  {
    if (fmt_str[i] == '%' && fmt_str[i + 1] != '\0')
    {
      i++;
      printed += ft_specifiers(args, fmt_str[i]);
      i++;
    }
    else
    {
      printed += ft_putchar_fd(fmt_str[i], 1);
      i++;
    }
  }
  va_end(args);
  return (printed);
}
