//1.ʵ�ֱ���
//2.ʵ��Ʈ��ѩ��
//3.��������
//4.��Ļ

#include<graphics.h>//Easyxͼ�ο�
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
