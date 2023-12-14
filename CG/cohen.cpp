#include <iostream>
#include <graphics.h>

const int INSIDE = 0; // 0000
const int LEFT = 1;   // 0001
const int RIGHT = 2;  // 0010
const int BOTTOM = 4; // 0100
const int TOP = 8;    // 1000


const int X_MIN = 100;
const int Y_MIN = 100;
const int X_MAX = 400;
const int Y_MAX = 300;

int computeCode(int x, int y) {
    int code = INSIDE; 

    if (x < X_MIN)    
        code |= LEFT;
    else if (x > X_MAX)
        code |= RIGHT;

    if (y < Y_MIN)     
        code |= BOTTOM;
    else if (y > Y_MAX) 
        code |= TOP;

    return code;
}

void cohenSutherland(int x1, int y1, int x2, int y2) {
    int code1 = computeCode(x1, y1);
    int code2 = computeCode(x2, y2);
    bool accept = false;

    while (true) {
        if (!(code1 | code2)) {
            
            accept = true;
            break;
        } else if (code1 & code2) {
            
            break;
        } else {
          
            int x, y;

      
            int codeOut = (code1 != INSIDE) ? code1 : code2;

          
            if (codeOut & TOP) {
                x = x1 + (x2 - x1) * (Y_MAX - y1) / (y2 - y1);
                y = Y_MAX;
            } else if (codeOut & BOTTOM) {
                x = x1 + (x2 - x1) * (Y_MIN - y1) / (y2 - y1);
                y = Y_MIN;
            } else if (codeOut & RIGHT) {
                y = y1 + (y2 - y1) * (X_MAX - x1) / (x2 - x1);
                x = X_MAX;
            } else if (codeOut & LEFT) {
                y = y1 + (y2 - y1) * (X_MIN - x1) / (x2 - x1);
                x = X_MIN;
            }

          
            if (codeOut == code1) {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1);
            } else {
                x2 = x;
                y2 = y;
                code2 = computeCode(x2, y2);
            }
        }
    }

    if (accept) {
       
        setcolor(RED);
        line(x1, y1, x2, y2);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int x1 = 50, y1 = 50, x2 = 300, y2 = 400;

  
    setcolor(BLUE);
    rectangle(X_MIN, Y_MIN, X_MAX, Y_MAX);

  
    setcolor(GREEN);
    line(x1, y1, x2, y2);

   
    cohenSutherland(x1, y1, x2, y2);

    getch();
    closegraph();
    return 0;
}
