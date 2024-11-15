#include "../includes/ft_printf.h"

size_t  ft_putptr(va_list args, char c)
{
  unsigned long ptr;
  size_t        printed;

  printed = 0;
  ptr = va_arg(args, unsigned long);
  // ptr = (unsigned long)va_arg(args, void *);
  if (ptr == 0)
    printed += ft_putstr_fd("(nil)", 1);
  else
  {
    printed += ft_putstr_fd("0x", 1);
    printed += ft_puthex_fd(ptr, c, 1);
  }
  return (printed);
}
