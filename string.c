#include <stdlib.h>
char *get_int(int num);
unsigned int _abs(int);
int get_numbase_len(unsigned int num, unsigned int base);
void fill_numbase_buff(unsigned int num, unsigned int base,
               char *buff, int buff_size);

/**
 * get_int - Will get a character pointer to new string containing int
 * @num: number to convert to string
 *
 * Return: string
 */
char *get_int(int num)
{
    unsigned int temp;
    int len = 0;
    long num_l = 0;
    char *ret;


    temp = _abs(num);
    len = get_numbase_len(temp, 10);


    if (num < 0 || num_l < 0)
        len++; 
    ret = malloc(len + 1);
    if (!ret)
        return (NULL);


    fill_numbase_buff(temp, 10, ret, len);
    if (num < 0 || num_l < 0)
        ret[0] = '-';


    return (ret);
}


/**
 * _abs - Will get the absolute value of an integer
 * @t: int
 * Return: unsigned int
 */
unsigned int _abs(int t)
{
    if (t < 0)
        return (-(unsigned int)t);
    return ((unsigned int)t);
}


/**
 * get_numbase_len - Will get the length of buffer needed for a unsigned int
 * @num: number 
 * @base: base of number representation used by buffer
 * Return: integer containing length 
 */
int get_numbase_len(unsigned int num, unsigned int base)
{
    int len = 1; 

    while (num > base - 1)
    {
        len++;
        num /= base;
    }
    return (len);
}


/**
 * fill_numbase_buff - Will fill  buffer with correct numbers 
 * @num: number 
 * @base: the base of number used in conversion
 * @buff: buffer 
 * @buff_size: buffer in bytes
 * Return: always void
 */
void fill_numbase_buff(unsigned int num, unsigned int base,
            char *buff, int buff_size)
{
    int rem, t = buff_size - 1;


    buff[buff_size] = '\0';
    while (t >= 0)
    {
        rem = num % base;
        if (rem > 9) 
            buff[t] = rem + 87; 
        else
            buff[t] = rem + '0';
        num /= base;
        t--;
    }
}

