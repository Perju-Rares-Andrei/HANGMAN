#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <graphics.h>
#include <winbgim.h>

using namespace std;

void patrat(int x,int y,int lat)
{
    line(x,y,x,y+lat);
    line(x,y+lat,x+lat,y+lat);
    line(x+lat,y+lat,x+lat,y);
    line(x+lat,y,x,y);
}

void caseta(char t[100],int x,int y)
{
    char z[1];
    for(int i=0; i<strlen(t); i++)
    {
        char z[1];
        sprintf(z,"%c",t[i]);
        patrat(i*25+x,y,25);
        if(z[0]!='_')
            outtextxy(i*25+x+9,y+3,z);
    }
}

void spanzuratoarea()
{
    readimagefile("inceput.jpg",500,65,800,300);
    FILE *fr;
    char line[80];
    char s[50];
    char pl, ul;

    srand (time(NULL));
    fr = fopen ("doc.txt", "rt");
    int nr_cuvinte=0;
    while(fgets(line, 50, fr) != NULL)
    {

        nr_cuvinte++;
    }
    fclose(fr);
    int numar_cuvant=rand() % nr_cuvinte + 1;
    int i;
    fr = fopen ("doc.txt", "rt");
    for (i=1; i<=numar_cuvant; i++)
        fgets(s,50,fr);
    s[strlen(s)-1]=0;

    int n=strlen(s);
    pl=s[0];
    ul=s[n-1];
    char t[50];
    strcpy(t, s);
    for(i=0; i<=n-1; i++)
        if(s[i]==pl)
            t[i]=pl;
        else if(s[i]==ul)
            t[i]=ul;
        else t[i]='_';

    outtextxy(50,50,"Acesta este cuvantul ce trebuie sa-l ghicesti:");
    caseta(t,50,80);

    int gmax=6, gasit, nrg=0, jp=0, jt=0,j=0;
    char lit,x[1];
    do
    {
        outtextxy(50,120,"Pana acum ai ghicit: ");
        caseta(t,50,150);

        lit=getch();
        outtextxy(50,200,"Litere incercate: ");
        char p1[1];
        sprintf(p1,"%c",lit);
        outtextxy(170+j,200,p1);
        j=j+30;
        gasit=0;

        for(i=0; i<=n-1; i++)
            if(lit==s[i]&&t[i]=='_')
            {
                t[i]=lit;
                gasit=1;
            }

        if(gasit==0)
        {
            nrg++;
            if(nrg==1)
                readimagefile("greseala_1.jpg",500,65,800,300);
            else if(nrg==2)
                readimagefile("greseala_2.jpg",500,65,800,300);
            else if(nrg==3)
                readimagefile("greseala_3.jpg",500,65,800,300);
            else if(nrg==4)
                readimagefile("greseala_4.jpg",500,65,800,300);
            else if(nrg==5)
                readimagefile("greseala_5.jpg",500,65,800,300);
            else if(nrg==6)
                readimagefile("greseala_6.jpg",500,65,800,300);
        }

        char p2[6];
        sprintf(p2,"%d",nrg);
        outtextxy (610,320,"Ai ");
        outtextxy(630,320,p2);
        outtextxy (640,320," greseli");

        if(nrg==gmax)
        {
            cleardevice();

            int x = getmaxx()/2;
            int y = getmaxy()/2;
            settextstyle(1,HORIZ_DIR,7);
            setcolor(RED);
            int w2=textwidth(s);
            outtextxy(getmaxx()/2-w2/2,getmaxy()/4,s);
            setcolor(RED);
            settextstyle(3,HORIZ_DIR,10);
            int w=textwidth("AI PIERDUT");
            int h=textheight("AI PIERDUT");
            outtextxy(x-w/2,y-h/2,"AI PIERDUT");
            jp=1;
        }
        if(strcmp(s,t)==0)
        {
            cleardevice();
            int x = getmaxx()/2;
            int y = getmaxy()/2;
            settextstyle(3,HORIZ_DIR,7);
            setcolor(GREEN);
            int w2=textwidth(s);
            outtextxy(getmaxx()/2-w2/2,getmaxy()/4,s);
            settextstyle(3,HORIZ_DIR,10);
            int w=textwidth("AI CASTIGAT");
            int h=textheight("AI CASTIGAT");
            outtextxy(x-w/2,y-h/2,"AI CASTIGAT");
            jt=1;
        }
    }
    while(jt==0 && jp==0);


}
int main()

{
    int window1=initwindow(500,800,"SPANZURATOAREA");



    readimagefile("spanzuratoarea.jpg",70,150,430,375);

    int i=1;
    while(!kbhit())
    {
        if(i<16)
            i++;
        else i=1;
        setcolor(i);
        delay(70);
        line(50,50,450,50);
        line(50,50,50,125);
        line(50,125,450,125);
        line(450,50,450,125);
        settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
        outtextxy(76,75,"SPANZURATOAREA");
        settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
        outtextxy(80,700,"PRESS ANNY KEY TO START");

    }
    getch();
    closegraph(window1);
    int x;

    while(x)
    {
        int window2=initwindow(900,800,"SPANZURATOAREA");

        spanzuratoarea();

        getch();
        closegraph();
    }
    return 0;

}