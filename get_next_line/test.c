#include <stdio.h>

int main ()
{
    int i;
    int l;
    int res;

    i = 300;
    l = 1;
    res = 256;

    res += i * (res < i);
    printf("%d", res);
}

//		*size += ft_strlen(buf) * (*size < ft_strlen(buf));
//		buffer = (char *)malloc(*size + 1);