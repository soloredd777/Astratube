#include <psp2/ctrl.h>
#include <vita2d.h>

#define WIDTH 960
#define HEIGHT 544

int main(void)
{
    vita2d_init();

    SceCtrlData pad;
    sceCtrlSetSamplingMode(SCE_CTRL_MODE_ANALOG);

    int running = 1;

    while (running)
    {
        sceCtrlPeekBufferPositive(0, &pad, 1);

        if (pad.buttons & SCE_CTRL_CIRCLE)
            running = 0;

        vita2d_start_drawing();
        vita2d_clear_screen();

        /* Fondo negro */
        vita2d_draw_rectangle(
            0, 0, WIDTH, HEIGHT,
            RGBA8(8, 8, 8, 255)
        );

        /* Barra roja superior */
        vita2d_draw_rectangle(
            0, 0, WIDTH, 8,
            RGBA8(190, 0, 25, 255)
        );

        /* Panel principal */
        vita2d_draw_rectangle(
            70, 100, 820, 90,
            RGBA8(190, 0, 25, 255)
        );

        /* Menú */
        vita2d_draw_rectangle(
            100, 230, 760, 65,
            RGBA8(35, 35, 35, 255)
        );

        vita2d_draw_rectangle(
            100, 325, 760, 65,
            RGBA8(35, 35, 35, 255)
        );

        vita2d_draw_rectangle(
            100, 420, 760, 65,
            RGBA8(35, 35, 35, 255)
        );

        vita2d_end_drawing();
        vita2d_swap_buffers();
    }

    vita2d_fini();

    return 0;
}
