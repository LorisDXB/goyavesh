/*
** EPITECH PROJECT, 2023
** my_count_digit
** File description:
** emacs
*/

int count_digit(int nb)
{
    int count = 0;

    if (nb == 0)
        return 1;
    if (nb < 0) {
        nb = nb * -1;
        count++;
    }
    while (nb > 0) {
        count ++;
        nb = nb / 10;
    }
    return count;
}
