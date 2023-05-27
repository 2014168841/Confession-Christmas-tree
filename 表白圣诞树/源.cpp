//1.实现背景
//2.实现飘舞雪花
//3.背景音乐
//4.字幕

#include<graphics.h>//Easyx图形库
#include<stdio.h>
int main(void)
{
    initgraph(1600, 900);

    IMAGE imgbg, imgSnow;

    loadimage(&imgbg, "res/bj.png");
    loadimage(&imgSnow, "res/snow.png");

    while (1)
    {
        putimage(0, 0, &imgbg);
        putimage(700, 100, &imgSnow);
    }


    system("pause");
    return 0;
}
