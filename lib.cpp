/************************* c lib functions **********************/

int atoi(const char *str)
{
    assert(str != NULL);

    int ret = 0;
    int sign = 1;
    int n = strlen(str);
    int i = 0;

    while(str[i] == ' ')
        i++;
    if(str[i] == '+')
        i++;
    else if(str[i] == '-')
    {
        sign = -1;
        i++;
    }
    for(;i < n;i++)
    {
        if(str[i] < '0' || str[i] > '9')
            break;
        if(ret > INT_MAX/10 || (ret == INT_MAX/10 && (str[i]-'0') > INT_MAX%10))
            return sign == -1 ? INT_MIN : INT_MAX;
        ret = ret * 10 + str[i] - '0';
    }
    return sign * ret;
}

/****************************************************************/

void *memcpy(void *dst,const char *str,size_t n)
{
    assert(dst != NULL && src != NULL);

    char *pdst = (char*)dst;
    const char *psrc = (const char*)src;

    assert(!(pdst <= psrc && psrc < pdst+n));
    assert(!(psrc <= pdst && pdst < psrc+n));

    while(n--)
        *pdst++ = *psrc++;
    return dst;
}

/****************************************************************/

char *strcpy(char *dst,const char *src)
{
    assert(dst != NULL && src != NULL);

    if(src == dst)
        return dst;
    char *ptr = dst;
    while((*dst++ = *src++) != '\0')
        ;
    return ptr;
}

/****************************************************************/

char *strncpy(char *dst,const hcar *src,size_t n)
{
    assert(dst != NULL && src != NULL);

    char *ptr = dst;
    while(n-- && *src != '\0')
        *dst++ = *src++;
    *dst = '\0';

    return ptr;
}

/****************************************************************/

char *strstr(char *haystack,char *needle)
{
    if(needle == NULL || haystack == NULL)
        return NULL;
    int i,j;
    for(i = j = 0;haystack[i] && needle[j];)
    {
        if(haystack[i] == needle[j])
        {
            i++;
            j++;
        }
        else {
            i = i - j + 1;
            j = 0;
        }
    }
    return needle[j] ? NULL : (haystack+i-j);
}

/****************************************************************/

void *memmove(void *dst,const void *src,size_t n)
{
    assert(dst != NULL && src != NULL);

    char *pdst = (char*)dst;
    const char *psrc = (const char*)src;

    if(pdsti+n <= psrc || pdst >= psrc+n)
    {
        while(n--)
            *pdst++ = *psrc++;
    }
    else {
        pdst += n-1;
        psrc += n-1;
        while(n--)
            *pdst-- = *psrc--;
    }
    return dst;
}

/****************************************************************/

int strcmp(const char *s,const char *t)
{
    assert(s != NULL && t != NULL);

    while(*s && *t && *s == *t)
        s++,t++;
    return *s - *t;
}

/****************************************************************/

int strncmp(const char *s,const char *t)
{
    assert(s != NULL && t != NULL);

    while(*s && *t && *s == *t && n--)
        s++,t++;
    return *s - *t;
}

/****************************************************************/

size_t strlen(const char *str)
{
    assert(str != NULL);

    const char *ptr = str;
    while(*ptr != '\0')
        ptr++;
    return (ptr - str);
}

/****************************************************************/

char *strcat(char *dst,const char *src)
{
    assert(dst != NULL && src != NULL);

    char *pdst = dst;
    while(*dst != '\0')
        dst++;
    while((*dst++ = *src++) != '\0')
        ;
    return pdst;
}

/****************************************************************/

char *strncat(char *dst,const char *src,size_t n)
{
    assert(dst != NULL && src != NULL);

    char *pdst = dst;
    while(*dst != '\0')
        dst++;
    while(n-- && *src != '\0')
        *dst++ = *src++;
    *dst = '\0';

    return pdst;
}

/****************************************************************/

char *strchr(const char *str,char c)
{
    assert(str != NULL);

    for(;*str != c;str++)
        if(*str == '\0')
            return NULL;
    return (char*)str;
}

/****************************************************************/

char *strrchr(const char *str,char c)
{
    assert(str != NULL);

    const char *ptr = str;
    while(*ptr != '\0')
        ptr++;
    for(--ptr;*ptr != c;ptr--)
        if(ptr == str)
            return NULL;
    return (char*)ptr;
}

/****************************************************************/

void *memset(void *str,int c,size_t n)
{
    assert(str != NULL);

    char *s = (char*)str;
    while(n--)
        *s++ = (char)c;
    return str;
}

/****************************************************************/

