#include "proto.h"

size_t	sh_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s)
	{
		len++;
		s++;
	}
	return (len);
}

char	*sh_substr(char const *s, unsigned int start, size_t len)
{
	char	*s2;
	char	*temp;

	s2 = (char *)malloc(sizeof(char) * (len + 1));
	temp = s2;
	if (!s)
		return (NULL);
	if (!s2)
		return (NULL);
	if (start >= sh_strlen(s))
	{
		*temp = '\0';
		return (s2);
	}
	while (len-- != 0 && *s)
		*temp++ = *(s + start++);
	*temp = '\0';
	return (s2);
}

char	*sh_strchr(const char *s, int c)
{
	char	cc;

	cc = (char)c;
	while (*s)
	{
		if (*s == cc)
			return ((char *)s);
		s++;
	}
	if (cc == '\0' && *s == '\0')
		return ((char *)s);
	return (NULL);
}