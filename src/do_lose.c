/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "../include/my.h"
#include "../include/csfml.h"

static button_t *exit_b(game_info_t *game_info)
{
    int x_center_window =
    (game_info->info_window->video_mode.width / 2 - (394 * 1.25 / 2));
    int x_text_center =
    x_center_window + (394 / 2) - (my_strlen("Exit (Q)") / 2 * 20);
    button_t *button = init_button(game_info->info_window->background_texture,
    "Exit", (sfVector2f) {x_center_window, 500},
    (sfIntRect) {2048, 260, 394, 153});
    text_t info_text = {.str = "Exit (Q)", .police = "Skeina.otf", .size = 88,
    .color = sfWhite, .outline_color = sfBlack, .outline_size = 5,
    .scale = {1, 1}, .position = {x_text_center, 510}};

    button->scale = (sfVector2f) {1.25, 1};
    sfSprite_setScale(button->sprite, button->scale);
    button->text = init_text(info_text);
    return button;
}

static button_t *restart(game_info_t *game_info)
{
    int x_center_window = (game_info->info_window->video_mode.width / 2 -
    (394 * 1.25 / 2));
    int x_text_center = x_center_window + (394 / 2) -
    (my_strlen("Restart (R") / 2 * 30);
    button_t *button = init_button(game_info->info_window->background_texture,
    "Restart", (sfVector2f) {x_center_window, 300},
    (sfIntRect) {2048, 260, 394, 153});
    text_t info_text = {.str = "Restart (R)", .police = "Skeina.otf",
    .size = 88, .color = sfWhite, .outline_color = sfBlack, .outline_size = 5,
    .scale = {1, 1}, .position = {x_text_center, 310}};

    button->scale = (sfVector2f) {1.25, 1};
    sfSprite_setScale(button->sprite, button->scale);
    button->text = init_text(info_text);
    return button;
}

void fill_list_of_buttons_exit(menu_t *exit, game_info_t *game_info)
{
    button_t *button;

    for (int i = 0; i < 2; i++) {
        if (i == 0)
            button = restart(game_info);
        if (i == 1)
            button = exit_b(game_info);
        add_in_list(&exit->buttons, button);
    }
}

void init_lose(game_info_t *game_info)
{
    char const *record = "./outro.wav";

    if (game_info->play_info->do_score->score >
        game_info->play_info->do_score->old_record) {
        record = "./sigma.wav";
        game_info->play_info->do_score->old_record =
        game_info->play_info->do_score->score;
    }
    sfSprite_setTextureRect(game_info->info_window->background_sprite,
    (sfIntRect){65, 2304, 1920, 1080});
    game_info->exit = init_menu(game_info, record, "./over_button.wav");
    fill_list_of_buttons_exit(game_info->exit, game_info);
    sfText_setPosition(SCORE_TEXT, (sfVector2f){200, 50});
    sfText_setPosition(SCORE_NB, (sfVector2f){200, 100});
}

void display_lose(game_info_t *game_info)
{
    sfSound_stop(game_info->play_info->in_game);
    if (sfMusic_getStatus(game_info->exit->music) != sfPlaying
    && game_info->info_window->sound_on)
        sfMusic_play(game_info->exit->music);
    sfRenderWindow_drawSprite(game_info->info_window->my_window,
    game_info->info_window->background_sprite, NULL);
    for (nodes_t *temp = game_info->exit->buttons;
        temp != NULL; temp = temp->next) {
        sfRenderWindow_drawSprite(game_info->info_window->my_window,
        ((button_t *)temp->data)->sprite, NULL);
        sfRenderWindow_drawText(game_info->info_window->my_window,
        ((button_t *)temp->data)->text, NULL);
        analyse_events(game_info, temp->data);
    }
    sfRenderWindow_drawText(game_info->info_window->my_window,
    SCORE_TEXT, NULL);
    sfRenderWindow_drawText(game_info->info_window->my_window, SCORE_NB, NULL);
    sfRenderWindow_setMouseCursorVisible(game_info->info_window->my_window,
    sfTrue);
}
