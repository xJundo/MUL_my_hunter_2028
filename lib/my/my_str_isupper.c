/*
** EPITECH PROJECT, 2023
** my_str_islower
** File description:
** return 1 if str is only upper cases
*/

#include "my.h"

int my_str_isupper(char const *str)
{
    int isalpha = 0;

    if (my_strlen(str) == 0)
        return 1;
    isalpha = my_str_isalpha(str);
    for (int i = 0; i < my_strlen(str); i++) {
        if (isalpha == 0)
            return 0;
        if (str[i] < 'A' || str[i] > 'Z')
            return 0;
    }
    return 1;
}
