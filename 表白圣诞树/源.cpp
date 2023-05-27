//1.ÊµÏÖ±³¾°
//2.ÊµÏÖÆ®ÎèÑ©»¨
//3.±³¾°ÒôÀÖ
//4.×ÖÄ»

#include<graphics.h>//EasyxÍ¼ĞÎ¿â
#include<stdio.h>
#include"tools.h"
int main(void)
{
    initgraph(1600, 900);

    IMAGE imgbg, imgSnow;

    loadimage(&imgbg, "res/bj.png");
    loadimage(&imgSnow, "res/snow.png");
    int x = 700;
    int y = 100;
    while (1)
    {
        putimage(0, 0, &imgbg);
        putimagePNG(x, y, &imgSnow);
    }


    system("pause");
    return 0;
}
