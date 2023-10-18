#include"class.h"
int main(){
    char* type;
    type = "hello";
    int gd=DETECT , gm;
    initgraph(&gd, &gm,(char*)" ");
    initwindow (getmaxwidth(), getmaxheight(),(char*)"Travel Management System");
    outtextxy(50,50,(char*)type);
    getch();
    closegraph();
    return(0);
}