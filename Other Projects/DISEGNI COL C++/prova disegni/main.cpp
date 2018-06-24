#include<graphics.h>
#include<conio.h>
int main()
{
    int gd = DETECT;
    int gm;
    initgraph(&gd,&gm,"C:\\TC\\BGI");
    arc(200,200,0,130,50);
    getch();
    closegraph();
}
