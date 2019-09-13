char	*ft_strcat(char *dst, const char *app)
{
	int i;
	int k;

	k = 0;
	i = 0;
	while (dst[i] != '\0')
		i++;
	while (app[k] != '\0')
	{
		dst[i] = app[k];
		i++;
		k++;
	}
	dst[i] = '\0';
	return (dst);
}
