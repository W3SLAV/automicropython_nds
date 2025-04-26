
#include "font.h"

static PrintConsole topScreen;
//static PrintConsole bottomScreen;

void buildFont()
{
    const int tile_base = 0;
    const int map_base = 20;

    videoSetMode(MODE_0_2D);
    videoSetModeSub(MODE_0_2D);
    vramSetBankA(VRAM_A_MAIN_BG);
    vramSetBankC(VRAM_C_SUB_BG);

    PrintConsole *console = consoleInit(&topScreen,0, BgType_Text4bpp, BgSize_T_256x256, map_base, tile_base, false, false);
    //PrintConsoleLower *console = consoleInit(&topScreen,0, BgType_Text4bpp, BgSize_T_256x256, map_base, tile_base, false, false);


    ConsoleFont font;

    font.gfx = (u16*)fontTiles;
    font.pal = (u16*)fontPal;
    font.numChars = 95;
    font.numColors =  fontPalLen / 2;
    font.bpp = 4;
    font.asciiOffset = 32;
    font.convertSingleColor = false;

    consoleSetFont(console, &font);
}
