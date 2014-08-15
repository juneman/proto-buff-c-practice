#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "player.pb-c.h"


int main(int argc, char *argv[])
{
    Coopple__Player player;

    coopple__player__init(&player);

    player.name = "coopple";
    player.type = 2;
    player.ticks = 8;

    char buff[128];
    memset(buff, 0x0, 128);

    int len = coopple__player__pack(&player, buff);

    printf("pack buff size len:%d.\n", len);

    
    Coopple__Player *raw = 
        coopple__player__unpack(NULL, len, buff);

    printf("name:%s, type:%d, tick:%d.\n",
            raw->name, raw->type, raw->ticks);
    
    return 0;
}


