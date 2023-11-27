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

score_t *init_best_score(game_info_t *game_info)
{
    score_t *set_score = malloc(sizeof(score_t));

    set_score->old_score = 0;
    set_score->new_score = 0;
    set_score->score = 0;
    set_score->record = 0;
    set_score->file = fopen("./score.txt", "r");
    set_score->buffer = malloc(10);
    fread(set_score->buffer, sizeof(char), 10, set_score->file);
    return set_score;
}

static void get_info(game_info_t *game_info,
    void (*display_state[])(game_info_t *), sfClock *clock)
{
    sfRenderWindow_setFramerateLimit(game_info->info_window->my_window,
    game_info->info_window->f);
    game_info->info_window->delay =
    sfClock_restart(clock).microseconds / 1000000.0;
    game_info->play_info->do_score->old_score =
        game_info->play_info->do_score->score;
    game_info->mouse_pos =
    sfMouse_getPositionRenderWindow(game_info->info_window->my_window);
    display_state[game_info->state](game_info);
    game_info->play_info->do_score->new_score =
        game_info->play_info->do_score->score;
    update_score(game_info->play_info->do_score);
    RECORD = my_getnbr(game_info->play_info->do_score->buffer);
    sfText_setString(RECORD_NB, my_str_nbr_long_long(RECORD));
}

void draw_everything(game_info_t *game_info)
{
    void(*display_state[])(game_info_t *) = {&display_menu,
        &display_play, &display_pause, &display_lose, &display_dying,
        &display_settings};
    sfClock *clock = sfClock_create();
    text_t info_text;
    int x = game_info->info_window->video_mode.width - 200;
    int y = game_info->info_window->video_mode.height - 200;

    game_info->play_info->do_score = init_best_score(game_info);
    RECORD = my_getnbr(game_info->play_info->do_score->buffer);
    info_text = (text_t) {.str = my_str_nbr_long_long(RECORD),
    .police = "Skeina.otf", .size = 50, .color = sfWhite, .outline_color =
    sfBlack, .outline_size = 5, .scale = {1, 1}, .position = {x, y + 90}};
    RECORD_NB = init_text(info_text);
    game_info->play_info->do_score->old_record = RECORD;
    while (sfRenderWindow_isOpen(game_info->info_window->my_window)) {
        get_info(game_info, display_state, clock);
        sfRenderWindow_display(game_info->info_window->my_window);
        sfRenderWindow_clear(game_info->info_window->my_window, sfBlack);
    }
}

int main(void)
{
    game_info_t game_info = init_game();

    srand(time(NULL));
    game_info.info_window->delay = 0;
    draw_everything(&game_info);
    return 0;
}
