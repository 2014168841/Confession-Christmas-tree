//1.实现背景
//2.实现飘舞雪花
//3.背景音乐
//4.字幕

#include<graphics.h>//Easyx图形库
#include<stdio.h>
#include"tools.h"
#include<time.h>
#include"vector2.h"

typedef struct snow
{
	vector2 strartPoinit;
	vector2 endPonit;
	vector2 p1;
	vector2 p2;
	float t;
	vector2 curPos;//当前位置
}snow;

//定义一个函数对雪花初始化
void initsnow(struct snow* snow)
{
	snow->strartPoinit = vector2(rand() % 1600, -90);
	snow->endPonit = vector2(rand() % 1600, 940);
	snow->curPos = snow->strartPoinit;
	snow->p1 = vector2(snow->strartPoinit.x - (rand() /200 + 200),rand()%200+200);
	snow->p2 = vector2(snow->endPonit.x + rand() /200 + 200,rand()%100+600);
	snow->t = 0;
}

//计算当前雪花的位置
void calSnowPos(struct snow* snow)
{
	snow->t += ((rand() % 3) + static_cast<float>(1)) / 1000;
	snow->curPos=calcBezierPoint(
		snow->t,snow->strartPoinit,snow->p1,snow->p2,snow->endPonit);
	if (snow->t >= 1)
	{
		initsnow(snow);
	}
}

int main(void)
{
	//设置随机种子;
	srand((unsigned int)time(NULL));

	initgraph(1600, 900);

	IMAGE imgbg, imgSnow;

	loadimage(&imgbg, "res/bj.png");
	loadimage(&imgSnow, "res/snow.png");

	//定义雪花
	snow snow1;
	initsnow(&snow1);

	while (true)
	{
		
		putimage(0, 0, &imgbg);
		/*putimagePNG(x, y, &imgSnow);*/
		//y += 4;//往下速度
		//x += (rand() % 9) - 4;  //-4 +4 (rand() % 9) 0-8 减4就可以得到+-4
		//y += (rand() % 3) + 2;//2-4；蠕动，不行
		//需要曲线下落;贝塞尔曲线

		/*putimagePNG2(snow1.curPos.x, snow1.curPos.y,1600, &imgSnow);*/
		/*putimage(snow1.curPos.x, snow1.curPos.y, &imgSnow);*/

		calSnowPos(&snow1);//计算雪花位置

		Sleep(20);
	}

	system("pause");
	return 0;
}
