/*
** EPITECH PROJECT, 2023
** handle
** File description:
** stop window from crashing
*/

#include <SFML/Graphics.h>
#include "../include/my.h"
#include "../include/csfml.h"

void manage_touch_in_lose(game_info_t *game_info)
{
    int x = game_info->info_window->video_mode.width - 200;
    int y = game_info->info_window->video_mode.height - 200;

    if (game_info->info_window->event.key.code == sfKeyR) {
        sfSprite_setTextureRect(game_info->info_window->background_sprite,
        (sfIntRect){0, 0, 1920, 1080});
        game_info->state = MENU;
        game_info->play_info->do_score->score = 0;
        game_info->play_info->level = 0;
        sfMusic_stop(game_info->exit->music);
        sfText_setPosition(SCORE_TEXT, (sfVector2f){x - 200, y});
        sfText_setPosition(SCORE_NB, (sfVector2f){x, y - 10});
        free(game_info->exit);
    }
    if (game_info->info_window->event.key.code == sfKeyQ) {
        close_window(game_info->info_window->my_window);
        free_menu(game_info);
        free_window(game_info);
        free_bird(game_info);
    }
}

void state_lose(game_info_t *game_info, npc_t *current_bird)
{
    manage_touch_in_lose(game_info);
}
