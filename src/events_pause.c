/*
** EPITECH PROJECT, 2023
** handle
** File description:
** stop window from crashing
*/

#include <SFML/Graphics.h>
#include "../include/my.h"
#include "../include/csfml.h"

void manage_touch_in_pause(game_info_t *game_info)
{
    if (game_info->info_window->event.key.code == sfKeyEscape)
        game_info->state = PLAY;
    for (nodes_t *temp = game_info->menu->buttons;
        temp != NULL; temp = temp->next) {
        if (ON_BUTTON_CLICK && B_PLAY)
            game_info->state = PLAY;
        if (ON_BUTTON_CLICK && B_EXIT) {
            close_window(game_info->info_window->my_window);
            free_menu(game_info);
            free_window(game_info);
            free_bird(game_info);
        }
        if (ON_BUTTON_CLICK && B_SETTINGS) {
            game_info->old_state = PAUSE;
            game_info->state = SETTINGS;
        }
    }
}

void state_pause(game_info_t *game_info, npc_t *current_bird)
{
    manage_touch_in_pause(game_info);
}
