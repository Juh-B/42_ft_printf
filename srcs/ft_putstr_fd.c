#include "../includes/ft_printf.h"

size_t	ft_putstr_fd(char *s, int fd)
{
	int	i;

  if (s == NULL)
    return (ft_putstr_fd("(null)", fd));
	i = 0;
	while (s[i])
    i += ft_putchar_fd(s[i], fd);
  return (i);
}
