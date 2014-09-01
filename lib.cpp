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
