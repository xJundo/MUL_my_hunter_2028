/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "../include/my.h"
#include "../include/csfml.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdbool.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

void free_bird(game_info_t *game_info)
{
    return;
}

void free_menu(game_info_t *game_info)
{
    nodes_t *temp = game_info->menu->buttons;
    nodes_t *previous;

    sfMusic_destroy(game_info->menu->music);
    sfSound_destroy(game_info->menu->sound_button);
    free(game_info->menu);
}

void free_window(game_info_t *game_info)
{
    sfTexture_destroy(game_info->info_window->background_texture);
    sfSprite_destroy(game_info->info_window->background_sprite);
}
