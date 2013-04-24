

#ifndef STR_TO_INT
#define STR_TO_INT

inline int StrToInt(const char * str)
{
   int value = 0;
   int sign = 1;
   int radix;
 
   if(*str == '-')
   {
      sign = -1;
      str++;
   }
   if(*str == '0' && (*(str+1) == 'x' || *(str+1) == 'X'))
   {
      radix = 16;
      str += 2;
   }
   else if(*str == '0')      // 八进制首字符为0
   {
      radix = 8;
      str++;
   }
   else
      radix = 10;
   while(*str)
   {
      if(radix == 16)
      {
        if(*str >= '0' && *str <= '9')
           value = value * radix + *str - '0';
        else
           value = value * radix + (*str | 0x20) - 'a' + 10;
       // value = value * radix + *str - 'a' + 10; // 也没问题啊
      }
      else
        value = value * radix + *str - '0';
      str++;
   }
   return sign*value;
}

#endif