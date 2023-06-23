#include <stdlib.h>


char **strtow(char *str, char *delims);
int is_delim(char ch, char *delims);
int get_word_length(char *str, char *delims);
int get_word_count(char *str, char *delims);
char *get_next_word(char *str, char *delims);


/**
 * strtow - Will takes a string and seperates its words
 * @str: string
 * @delims: delimitors 
 * Return: 2D array of pointers to each word
 */


char **strtow(char *str, char *delims)
{
    char **words = NULL;
    int wc, wordLen, n, t = 0;


    if (str == NULL || !*str)
        return (NULL);
    wc = get_word_count(str, delims);




    if (wc == 0)
        return (NULL);
    words = malloc((wc + 1) * sizeof(char *));
    if (words == NULL)
        return (NULL);
    while (t < wc)
    {
        wordLen = get_word_length(str, delims);
        if (is_delim(*str, delims))
        {
            str = get_next_word(str, delims);
        }
        words[t] = malloc((wordLen + 1) * sizeof(char));
        if (words[t] == NULL)
        {
            while (t >= 0)
            {
                t--;
                free(words[t]);
            }
            free(words);
            return (NULL);
        }
        n = 0;
        while (n < wordLen)
        {
            words[t][n] = *(str + n);
            n++;
        }
        words[t][n] = '\0';
        str = get_next_word(str, delims);
        t++;
    }
    words[t] = NULL; 
    return (words);
}


/**
 * is_delim - Will check if stream has delimitor char
 * @ch: character
 * @delims: Pointer
 * Return: 1 success
 */


int is_delim(char ch, char *delims)
{
    int t = 0;


    while (delims[t])
    {
        if (delims[t] == ch)
            return (1);
        t++;
    }
    return (0);
}


/**
 * get_word_length - Will get the word length 
 * @str: string
 * @delims: delimitors
 * Return: word length
 */


int get_word_length(char *str, char *delims)
{
    int wLen = 0, pending = 1, t = 0;


    while (*(str + t))
    {
        if (is_delim(str[t], delims))
            pending = 1;
        else if (pending)
        {
            wLen++;
        }
        if (wLen > 0 && is_delim(str[t], delims))
            break;
        t++;
    }
    return (wLen);
}


/**
 * get_word_count - Will get the word count
 * @str: string 
 * @delims: delim
 * Return: count
 */


int get_word_count(char *str, char *delims)
{
    int wc = 0, pending = 1, t = 0;


    while (*(str + t))
    {
        if (is_delim(str[t], delims))
            pending = 1;
        else if (pending)
        {
            pending = 0;
            wc++;
        }
        t++;
    }
    return (wc);
}


/**
 * get_next_word -Will  gets the next word
 * @str: string 
 * @delims: delimitor
 * Return: pointer 
 */


char *get_next_word(char *str, char *delims)
{
    int pending = 0;
    int t = 0;


    while (*(str + t))
    {
        if (is_delim(str[t], delims))
            pending = 1;
        else if (pending)
            break;
        t++;
    }
    return (str + t);
}

