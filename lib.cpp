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
