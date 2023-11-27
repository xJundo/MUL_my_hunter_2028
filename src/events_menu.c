/*
** EPITECH PROJECT, 2023
** handle
** File description:
** stop window from crashing
*/

#include <SFML/Graphics.h>
#include "../include/my.h"
#include "../include/csfml.h"

void change_state(game_info_t *game_info)
{
    for (nodes_t *temp = game_info->menu->buttons;
        temp != NULL; temp = temp->next) {
        if (ON_BUTTON_CLICK && B_PLAY) {
            sfMusic_stop(game_info->menu->music);
            game_info->state = PLAY;
            init_play(game_info);
        }
        if (ON_BUTTON_CLICK && B_EXIT) {
            free_window(game_info);
            close_window(game_info->info_window->my_window);
            free_menu(game_info);
        }
        if (ON_BUTTON_CLICK && B_SETTINGS && game_info->old_state != PLAY) {
            game_info->old_state = MENU;
            game_info->state = SETTINGS;
        }
    }
}

void state_menu(game_info_t *game_info, npc_t *current_bird)
{
    change_state(game_info);
}
