#include "common.h"

void	putchar(char ch);

void	ft_printf(const char *fmt, ...)
{
	va_list		vargs;
	const char	*s;
	unsigned	magnitude;
	unsigned	divisor;
	unsigned	nibble;

	int d_value; // d-format
	unsigned u_value; // x-format
	va_start(vargs, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			switch (*fmt)
			{
			case '\0':
				putchar('%');
				goto end;
			case '%':
				putchar('%');
				break ;
			case 's':
			{
				s = va_arg(vargs, const char *);
				while (*s)
				{
					putchar(*s);
					s++;
				}
				break ;
			}
			case 'd': // Print an integer in decimal
			{
				d_value = va_arg(vargs, int);
				magnitude = d_value;
				if (d_value < 0)
				{
					putchar('-');
					magnitude = -magnitude;
				}
				divisor = 1;
				while (magnitude / divisor > 9)
					divisor *= 10;
				while (divisor > 0)
				{
					putchar('0' + magnitude / divisor);
					magnitude %= divisor;
					divisor /= 10;
				}
				break ;
			}
			case 'x':
			{
				u_value = va_arg(vargs, unsigned);
				for (int i = 7; i >= 0; i--)
				{
					nibble = (u_value >> (i * 4)) & 0xf;
					putchar("0123456789abcdef"[nibble]);
				}
				break ;
			}
			}
		}
		else
			putchar(*fmt);
		fmt++;
	}
end:
	va_end(vargs);
}

void	*memcpy(void *dst, const void *src, size_t n)
{
	uint8_t			*d;
	const uint8_t	*s = (const uint8_t *)src;

	d = (uint8_t *)dst;
	while (n--)
		*d++ = *s++;
	return (dst);
}

void	*memset(void *buf, char c, size_t n)
{
	uint8_t	*p;

	p = (uint8_t *)buf;
	while (n--)
		*p++ = c;
	return (buf);
}

char	*ft_strcpy(char *dst, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
