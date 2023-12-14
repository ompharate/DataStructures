#include <iostream>
// #include <graphics.h>

class ScanFill {
public:
    void drawPolygon(int points[][2], int numPoints) {
        for (int i = 0; i < numPoints; i++) {
            int j = (i + 1) % numPoints;
            line(points[i][0], points[i][1], points[j][0], points[j][1]);
        }
    }

    void scanFill(int points[][2], int numPoints, int fillColor) {
        int y, x, x1, x2;
        int intersections[100]; 

        for (y = 0; y < getmaxy(); y++) {
            int count = 0; 

            for (int i = 0; i < numPoints; i++) {
                int j = (i + 1) % numPoints;

                int yi = points[i][1];
                int yj = points[j][1];

                if ((yi <= y && y < yj) || (yj <= y && y < yi)) {
                    int xi = points[i][0];
                    int xj = points[j][0];

                    int xInt = xi + (float)(y - yi) / (float)(yj - yi) * (xj - xi);
                    intersections[count++] = xInt;
                }
            }

         
            for (int i = 0; i < count - 1; i++) {
                for (int j = 0; j < count - i - 1; j++) {
                    if (intersections[j] > intersections[j + 1]) {
                        int temp = intersections[j];
                        intersections[j] = intersections[j + 1];
                        intersections[j + 1] = temp;
                    }
                }
            }

           
            for (int i = 0; i < count; i += 2) {
                x1 = intersections[i];
                x2 = intersections[i + 1];
                for (x = x1; x < x2; x++) {
                    putpixel(x, y, fillColor);
                }
            }
        }
    }
};

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    ScanFill scanFill;

    int numPoints;
    std::cout << "Enter the number of edges: ";
    std::cin >> numPoints;

    int points[numPoints][2];

    for (int i = 0; i < numPoints; i++) {
        std::cout << "Enter x-coordinate for vertex " << i + 1 << ": ";
        std::cin >> points[i][0];
        std::cout << "Enter y-coordinate for vertex " << i + 1 << ": ";
        std::cin >> points[i][1];
    }

    scanFill.drawPolygon(points, numPoints);
    scanFill.scanFill(points, numPoints, YELLOW);

    delay(5000);
    closegraph();

    return 0;
}
