#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<graphics.h>//easyxͼ�ο�ͷ�ļ�
HWND hwnd=NULL;
#define MAX 100
//��ʼ����
void initSnake();
//������
void drawSnake();
//�ߵ��ƶ�
void snakeMove();
//�ߵķ���
void keyDown();
//�ߵ�ʳ��
void foodxy();
//ʳ�����
void inifood();
//�ж����Ƿ�Ե�ʳ��
void eatfood();
//�ж����Ƿ�Թҵ�
int snakedie();
//��Ϸ�����У��� �ո� ���Զ���Ϸ������ͣ����ʼ
void again();
//�洢�ߵ�����Ľṹ��
typedef struct pointXY
{
	int x;
	int y;
}MYPOINT;
//�ߵĻ�������
struct snake
{
	int num;//�ߵ��ܽ���
	MYPOINT xy[MAX];//�洢�ߵ�����Ľṹ������
	char postion;

}snake;
//ʳ��Ļ�������
struct food
{
	MYPOINT fdxy;
	int flag = 0;
	int eatgrade = 0;
}food;
//����ö��
enum movPostion
{
	right = 72,
	left = 75,
	down = 77,
	up = 80
};

int main()
{
	hwnd=initgraph(640, 480);
	setbkcolor(WHITE);
	srand((unsigned int)time(NULL));//��������ӣ�������������ߵ�ʳ��Ҫ�õ�
	initSnake();
	while (1)
	{
		cleardevice();
		if (food.flag == 0)
		{
			foodxy();
		}
		inifood();
		drawSnake();
		if (snakedie())
		{
			break;
		}
		eatfood();   //��ʳ������
		snakeMove();
		Sleep(100);
		while (_kbhit())//�����ǰ��������Ҽ������ߵ��ƶ�
		{
			//again();
			keyDown();
		}
	}
	closegraph();
	return 0;
}
//��ʼ����
void initSnake(){

	snake.xy[2].x = 0;
	snake.xy[2].y = 0;

	snake.xy[1].x = 10;
	snake.xy[1].y = 0;

	snake.xy[0].x = 20;
	snake.xy[0].y = 0;
	
	snake.num = 3;
	snake.postion = right;
	food.flag = 0;

}
//������
void drawSnake()
{
	for (int i = 0; i < snake.num; i++)
	{
		setlinecolor(BLUE);
		setfillcolor(YELLOW);
		fillrectangle(snake.xy[i].x, snake.xy[i].y, snake.xy[i].x + 10, snake.xy[i].y + 10);
	}
}
//�ߵ��ƶ�
void snakeMove()
{
	//���˵�һ���ߣ�����ÿ�ڶ���ǰ��һ���ߵ�ǰһ������
	for (int i = snake.num - 1; i >0; i--)
	{
		snake.xy[i].x = snake.xy[i - 1].x;
		snake.xy[i].y = snake.xy[i - 1].y;
	}

	switch (snake.postion)
	{
	case right:
		snake.xy[0].x += 10;
		break;
	case left:
		snake.xy[0].x -= 10;
		break;
	case down:
		snake.xy[0].y += 10;
		break;
	case up:
		snake.xy[0].y -= 10;
		break;
	default:
		break;
	}
}
//�ߵķ������
void keyDown()
{
	char ch = 0;
	ch = _getch();
	switch (ch)
	{
	case 72:
		if (snake.postion != down)
			snake.postion = up;
		break;
	case 75:
		if (snake.postion != right)
			snake.postion = left;
		break;
	case 77:
		if (snake.postion != left)
			snake.postion = right;
		break;
	case 80:
		if (snake.postion != up)
			snake.postion = down;
		break;
	default:
		break;
	}
}
//ʳ�������ȡ
void foodxy()
{
	//������ 0 10 20 30 n*10
	//ʳ�� ��� rand() % 650 ��ô����0 1 2 3 4 �߽��Բ���ʳ�� �����غϵ�

	food.fdxy.x = rand() % 65 * 10;
	food.fdxy.y = rand() % 48 * 10;
	food.flag = 1;

	for (int i = 0; i > snake.num; i++)
	{
		if (food.fdxy.x == snake.xy[i].x && food.fdxy.y == snake.xy[i].y)
		{
			food.fdxy.x = rand() % 65 * 10;
			food.fdxy.y = rand() % 48 * 10;
		}
	}


}
//����ʳ��
void inifood()
{
	fillrectangle(food.fdxy.x, food.fdxy.y, food.fdxy.x + 10, food.fdxy.y + 10);

}
//��ʳ����ж�
void eatfood()
{

	if (snake.xy[0].x == food.fdxy.x && snake.xy[0].y == food.fdxy.y)
	{
		snake.num++;
		food.eatgrade += 10;
		food.flag = 0;

	}

}
//�ж����Ƿ�����
int  snakedie()
{
	//����
	char grade[100] = { 0 };
	sprintf(grade, "%d", food.eatgrade);
	setbkmode(0);//���ֱ���͸��
	settextcolor(LIGHTBLUE);
	outtextxy(570, 20, "������");
	outtextxy(610, 20, grade);

	if (snake.xy[0].x > 640 || snake.xy[0].x < 0 || snake.xy[0].y > 480 || snake.xy[0].y<0)
	{
		outtextxy(240, 320, "ײǽ��");
		MessageBox(hwnd, "��Ϸ������", "������ʾ��", 0);
		return 1;
	}
	for (int i = 1; i < snake.num; i++)
	{
		if (snake.xy[0].x == snake.xy[i].x &&snake.xy[0].y == snake.xy[i].y)
		{
			outtextxy(240, 320, "��ҧ�����Լ�����Ϸ������");
			MessageBox(hwnd, "��Ϸ������", "������ʾ��", 0);
			return 1;
		}
	}
	return 0;
}

void again()
{
	if (_getch() == 32)
	{
		while (_getch() != 32);
	}
}

