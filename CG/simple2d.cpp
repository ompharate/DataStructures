#include <graphics.h>
#include <conio.h>

void drawSquare(int x, int y) {
    rectangle(x - 50, y - 50, x + 50, y + 50);
}

void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3) {
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    int x = getmaxx() / 2;
    int y = getmaxy() / 2;

    char ch;
    while (1) {
        cleardevice();

        // Draw square
        drawSquare(x, y);

        ch = getch();
        if (ch == 'r') {
            // Rotate 10 degrees
            cleardevice();
            rotate(x, y, 10);
            delay(200);
        } else if (ch == 's') {
            // Scale by a factor of 1.1
            cleardevice();
            scale(x, y, 1.1);
            delay(200);
        } else if (ch == 't') {
            // Translate by (10, 10)
            cleardevice();
            translate(x, y, 10, 10);
            delay(200);
        } else if (ch == 27) {
            // Exit on Esc key
            break;
        }
    }

    closegraph();
    return 0;
}

void rotate(int &x, int &y, int angle) {
    double radian = angle * (3.14159 / 180.0);
    int new_x = round(x * cos(radian) - y * sin(radian));
    int new_y = round(x * sin(radian) + y * cos(radian));
    x = new_x;
    y = new_y;
    drawSquare(x, y);
}

void scale(int &x, int &y, float factor) {
    x = round(x * factor);
    y = round(y * factor);
    drawSquare(x, y);
}

void translate(int &x, int &y, int dx, int dy) {
    x += dx;
    y += dy;
    drawSquare(x, y);
}
