#include <string.h>
#include <stdio.h>

size_t    ft_strlen(const char *s)
{
    int    pos;

    pos = 0;
    while (s[pos])
        pos++;
    return (pos);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	pos;
	size_t	lendst;
	size_t	lensrc;

	lendst = ft_strlen(dst);
	lensrc = ft_strlen(src);
	pos = lendst;
	if (!dstsize)
		return (ft_strlen(src));
	while (pos < dstsize - 1)
	{
		dst[pos] = src[pos - lendst];
		pos++;
	}
	dst[pos] = 0;
	if (dstsize + lensrc < lendst + lensrc)
		return (dstsize + lensrc);
	else
		return (lendst + lensrc);
}

int main(void)
{

	char k[6];
	char l[6];
	k[0] = 'l';
	l[0] = 'l';
	k[1] = 0;
	l[1] = 0;
    int i = strlcat(k, "ko", 6);
	int j = ft_strlcat(l, "ko", 6);

    printf("%d%s\n", i, k);
	printf("%d%s", j, l);
    return (0);
}
