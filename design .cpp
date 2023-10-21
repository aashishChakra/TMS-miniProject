#include"class.h"

int main(){
    int gd=DETECT , gm;
    initgraph(&gd, &gm,(char*)" ");
    initwindow (getmaxwidth(), getmaxheight(),(char*)"Travel Management System");

    char* type;
    type = "hello";
    outtextxy(50,50,(char*)type);
    
    getch();
    closegraph();
    return(0);
}