#include <graphics.h>
main()
{
    int gd = 5, gm;
    initgraph(&gd, &gm, "");
    setcolor(13);
    circle(200, 100, 50);
    setcolor(7);
    rectangle(40, 90, 80, 150);
    setcolor(11);
    ellipse(250, 240, 0, 360, 50, 70);
    getch();
    closegraph();
}
