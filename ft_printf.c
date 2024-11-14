// #include <stdarg.h>
// #include <stdio.h>
// #include <unistd.h>
#include "ft_printf.h"

// Tem na libft
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	char	conv_to_str;

	conv_to_str = '0';
	if (n < 0)
	{
		if (n == -2147483648)
		{
			n = -(n + 1);
			conv_to_str = '1';
		}
		else
			n = -n;
		ft_putchar_fd(45, fd);
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	ft_putchar_fd((n % 10) + conv_to_str, fd);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

// Nao tem na Libft
void	ft_putnbr_unsig_fd(unsigned int n, int fd)
{
	if (n >= 10)
	  ft_putnbr_unsig_fd(n / 10, fd);
	ft_putchar_fd((n % 10) + '0', fd);
}

static void	ft_putnbr_base_fd(unsigned long n, const char *base, int fd)
{
	if (n >= 16)
		ft_putnbr_base_fd(n / 16, base, fd);
	ft_putchar_fd(base[n % 16], fd);
}

static void	ft_puthex_fd(unsigned long n, const char base_specifier, int fd)
{
	if (base_specifier == 'X')
		ft_putnbr_base_fd(n, "0123456789ABCDEF", fd);
	else
		ft_putnbr_base_fd(n, "0123456789abcdef", fd);
}

static size_t	ft_nbrlen_base(long n, const char base_specifier)
{
	size_t	n_len;
  long    use_base;

	n_len = 0;
  if (base_specifier == 'x' || base_specifier == 'X' || base_specifier == 'p')
    use_base = 16;
  else
    use_base = 10;
  if (use_base == 10 && n < 0)
  {
    n_len++;
    n = -(unsigned long)n;
  }
	while (n >= use_base)
  {
		n_len++;
    n /= use_base;
  }
  if (n >= 0 && n < use_base)
    n_len++;
	return (n_len);
}

static void  ft_putptr(va_list args, char c)
{
  unsigned long ptr;

  ptr = va_arg(args, unsigned long);
  if (ptr == 0)
    ft_putstr_fd("(nil)", 1);
  else
  {
    ft_putstr_fd("0x", 1);
    ft_puthex_fd(ptr, c, 1);
  }
}

static size_t  ft_putptr_len(va_list args, char c)
{
  unsigned long ptr;
  size_t        printed;

  printed = 0;
  ptr = va_arg(args, unsigned long);
  if (ptr == 0)
    printed += ft_strlen("(nil)");
  else
  {
    printed += ft_strlen("0x");
    printed += ft_nbrlen_base(ptr, c);
  }
  return (printed);
}

static void ft_specifiers(va_list args, char c)
{
  if (c == 'c')
    ft_putchar_fd(va_arg(args, int), 1);
  else if (c == 's')
    ft_putstr_fd(va_arg(args, char *), 1);
  else if (c == 'd' || c == 'i')
    ft_putnbr_fd(va_arg(args, int), 1);
  else if (c == 'u')
    ft_putnbr_unsig_fd(va_arg(args, unsigned int), 1);
  else if (c == 'x' || c == 'X')
    ft_puthex_fd(va_arg(args, unsigned long), c, 1);
  else if (c == 'p')
    ft_putptr(args, c);
  else if (c == '%')
    ft_putchar_fd('%', 1);
}

static size_t ft_specifiers_len(va_list args, char c)
{
  size_t  printed;

  printed = 0;
  if (c == 'c')
  {
    printed++;
    va_arg(args, int);
  }
  else if (c == 's')
    printed += ft_strlen(va_arg(args, char *));
  else if (c == 'd' || c == 'i')
    printed += ft_nbrlen_base(va_arg(args, int), c);
  else if (c == 'u' || c == 'x' || c == 'X')
    printed += ft_nbrlen_base(va_arg(args, unsigned long), c);
  else if (c == 'p')
    printed += ft_putptr_len(args, c);
  else if (c == '%')
    printed++;
  return (printed);
}

// Funcao principal
int ft_printf(const char *fmt_str, ...)
{
  va_list args;
  va_list temp;
  int i;
  size_t  printed;

  va_start(args, fmt_str);
  va_copy(temp, args);
  i = 0;
  printed = 0;
  while (fmt_str[i] != '\0')
  {
    if (fmt_str[i] == '%' && fmt_str[i + 1] != '\0')
    {
      i++;
      ft_specifiers(args, fmt_str[i]);
      printed += ft_specifiers_len(temp, fmt_str[i]);
      i++;
    }
    write(1, &fmt_str[i], 1);
    i++;
    printed++;
  }
  va_end(temp);
  va_end(args);
  return (printed);
}

// int main(void)
// {
//   int x;
//   int y;
  // // Test caracter and string
  // printf("1. %c e %s\n", 'a', "Ola Mundo");
  // ft_printf("2. %c e %s\n", 'a', "Ola Mundo");

  // // Test int with d and i
  // printf("1. %d e %i\n", 42, -5);
  // ft_printf("2. %d e %i\n", 42, -5);

  // // Test unsigned int
  // printf("1. %u\n", -2147483647);
  // ft_printf("2. %u\n", -2147483647);

  // // Test base hex
  // printf("1. %x e %X\n", 255, 255);
  // ft_printf("2. %x e %X\n", 255, 255);

  // // Test pointer
  // char str[10] = "Ola mundo";
  // y = printf("1. %p %s\n", &str, str);
  // x = ft_printf("2. %p %s\n", &str, str);

  // Test %
  // printf("1. %c e %% test\n", 'a');
  // ft_printf("2. %c e %% test\n", 'a');

  // Testes Malucos
  // y = printf("1. Ola mund%c %s\n", 'o', "belo");
  // y = printf("1. %c %% %s %% %d %%blabla\n", 'b', "Amora", 42);
  // y = printf("1. %x e %X / %d e %u\n", 255, 255, 0, -0);
  // y = printf("   \n");

  // x = ft_printf("2. Ola mund%c %s\n", 'o', "belo");
  // x = ft_printf("2. %c %% %s %% %d %%blabla\n", 'b', "Amora", 42);
  // x = ft_printf("2. %x e %X / %d e %u\n", 255, 255, 0, -0);
  // x = ft_printf("   \n");

  // printf("1. y = %d\n", y);
  // ft_printf("2. x = %d\n", x);
  // ft_printf("Test %d %% amora\n", 42);
// }
