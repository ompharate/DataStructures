// #include<graphics>
#include <iostream>

void draw(float x1, float y1, float x2, float y2)
{

    float dx = abs(x2 - x1);
    float dy = abs(y2 - y1);

    float step;

    if (dx < dy)
    {
        step = dx;
    }
    else
    {
        step = dy;
    }

    float xin = dx / step;
    float yin = dy / step;

    for (int i = 1; i <= step; i++)
    {

        putpixel(x1, y1, RED);
        x1 = x1 + xin;
        y1 = y1 + xin;
    }
}

void drawCircle(int xc, int yc, int radius)
{

    int x, y, d;
    d = 3 - 2 * radius;
    x = 0;
    y = r;

    while (x <= y)
    {
        putpixel(xc + x, yc + y, RED);
        putpixel(xc - x, yc - y, RED);
        putpixel(xc + x, yc - y, RED);
        putpixel(xc - x, yc + y, RED);
        putpixel(xc + y, yc + x, RED);
        putpixel(xc - y, yc - x, RED);
        putpixel(xc + y, yc - x, RED);
        putpixel(xc + y, yc + x, RED);
    }

    if (d <= 0)
    {
        d = d + 4 * x + 6;
    }
    else
    {
        d = d + 4 * (x - y) + 10;
        y = y - 1;
    }
    x++;
}

int main()
{


    
}