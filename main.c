/*
** EPITECH PROJECT, 2024
** Project-my_hunter
** File description:
** main
*/

#include "include/struct_fb.h"

static void controller_test(void)
{
    printf("\nTo test your controller input please use the following "
        "link:\n"
        BRED"\thttps://github.com/VictorTV57/Controller_Test.git"
        "\n"COLOR_RESET);
}

static void controller_control(void)
{
    printf(BMAG"\nController Controls: (Only for Dualsense Controller)\n"
        BRED"\tLeft Stick (sfJoystickX): Move forward/backward"
        "Strafe Left/Right\n"
        BBLU"\tRight Stick (sfJoystickU): Look around \n"
        BGRN"\tR2 (Button 7): Shoot \n"
        BMAG"\t◻ (Button 3): Toggle flashlight \n"
        BBLU"\tStart (Button 9): Pause the game \n"COLOR_RESET);
}

static void keyboard_control(void)
{
    printf(BMAG"Keyboard Controls: \n"
        BRED"\tZ : Move forward \n"
        BBLU"\tS : Move backward \n"
        BGRN"\tQ : Strafe left \n"
        BCYN"\tD : Strafe right \n"
        BMAG"\tF : Toggle flashlight \n"
        BGRN"\tMouse : Look around \n"
        BBLU"\tF11 (Not working): Toggle fullscreen \n"
        BGRN"\tF4 (Not working): Quit the game \n"
        BRED"\tESC : Pause the game \n"
        BGRN"\tLeft Click : Shoot \n"COLOR_RESET);
}

static void helper(void)
{
    printf(BMAG"Usage: ./wolf3d [OPTION]\n"
        BRED"\t-h, --help\t\tDisplay this help message\n"
        BBLU"\t-c, --controls\t\tDisplay the controls of the game\n"
        BGRN"\tNo option\t\tStart the game\n\n"COLOR_RESET);
    printf(MAG "Project: \n"
        BRED"\tGame type : FPS \n"
        BLU"\tInspired Game : Wolfenstein 3D \n"
        GRN"\tCreated by Jean-Baptiste GOSSOT, Nathan CLAUDEL"
        " & Victor JOST\n"
        BLU"\tEpitech Nancy PGE 2029 NCY > ALL\n"
        BGRN"\t©JustWirelessInc. 2021-2029\n"COLOR_RESET);
}

static void unknow_arg(void)
{
    printf(BRED "Unknown argument, please use '-h' for complementary "
        "information.\n"
        "To see the controls please use '-c' or '--controls'.\n"
        "To start the game please do './wolf3d'.\n" COLOR_RESET);
}

int main(int argc, char **argv)
{
    if (argc == 1) {
        wolf3d();
        return 0;
    }
    if (!strcmp("-h", argv[1]) || !strcmp("--help", argv[1])) {
        helper();
        return 0;
    }
    if (!strcmp("-c", argv[1]) || !strcmp("--controls", argv[1])) {
        keyboard_control();
        controller_control();
        controller_test();
        return 0;
    } else {
        unknow_arg();
        return 84;
    }
    return 0;
}
