#include <iostream>
#include <fstream>
#include <graphics.h>
#include <conio.h>
#include <cmath>
#include <stdlib.h>
using namespace std;
ifstream f("date.in");
int a[20][20],n,d[20],t[20],viz[20],r,s,cord[20][2],v[20],nr;
void cerc(){
    int r=150,y,x;
    float a=2*M_PI/n;
    char c[2];
    y=getmaxy()/2-60;
    x=getmaxx()/2;
    for(int i=1;i<=n;i++){
        cord[i][1]=x-r*cos((i-1)*a);
        cord[i][2]=y-r*sin((i-1)*a);
        circle(cord[i][1]+8,cord[i][2]+8,20);
        itoa(i,c,10);
        outtextxy(cord[i][1],cord[i][2],c);
        }
    }
void infinit(){
    int i,j;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            if(i!=j)
                a[i][j]=100;
    }
int jum(int nod,int i){
    if(i==1){
        if(cord[nod][1]<getmaxx()/2)
            return 1;
        else
            return -1;
        }
    if(i==2){
        if(cord[nod][2]<getmaxy()/2)
            return 1;
        else
            return -1;
        }
    }
void muchii(){
    int i,j,c,x,y;
    char d[2];
    getch();
    while(f>>i>>j>>c){
        a[i][j]=c;
        setlinestyle(DASHED_LINE,0,1);
        line(cord[i][1]+8*jum(i,1),cord[i][2]+8*jum(i,2),cord[j][1]+8*jum(j,1),cord[j][2]+8*jum(j,2));
        itoa(c,d,10);
        x=(cord[i][1]+8*jum(i,1)+cord[j][1]+8*jum(j,1))/2;
        y=(cord[i][2]+8*jum(i,2)+cord[j][2]+8*jum(j,2))/2;
        outtextxy(x,y,d);
    }
}
void drum(int nod){
    if(nod!=0){
        nr++;
        v[nr]=nod;
        drum(t[nod]);
        }
    }
void afisare(){
    char c[2];
    setcolor(RED);
    setlinestyle(SOLID_LINE,0,3);
    getch();
    cout<<"Drum: ";
    for(int i=nr;i>=2;i--){
        delay(800);
        line(cord[v[i]][1]+8*jum(v[i],1),cord[v[i]][2]+8*jum(v[i],2),cord[v[i-1]][1]+8*jum(v[i-1],1),cord[v[i-1]][2]+8*jum(v[i-1],2));
        itoa(v[i],c,10);
        outtextxy(cord[v[i]][1],cord[v[i]][2],c);
        cout<<v[i]<<" ";
        }
    itoa(v[1],c,10);
    outtextxy(cord[v[1]][1],cord[v[1]][2],c);
    cout<<v[1]<<endl;
    cout<<"Cost: "<<d[v[1]]<<endl;
    }
void dijkstra(){
    int i,j,poz,min1;
    infinit();
    muchii();
    cout<<"Nod inceput= ";
    cin>>r;
    cout<<"Nod sfarsit= ";
    cin>>s;
    for(j=1;j<=n;j++)
        d[j]=a[r][j];
    viz[r]=1;
    t[r]=0;
    for(i=1;i<=n;i++)
        if(d[i]!=0 && d[i]<100)
            t[i]=r;
    for(i=1;i<=n;i++){
        min1=100;
        for(j=1;j<=n;j++){
            if(d[j]<min1 && viz[j]==0){
                min1=d[j];
                poz=j;
                }
            }
        viz[poz]=1;
        for(j=1;j<=n;j++){
            if(viz[j]==0){
                if(d[j]>d[poz]+a[poz][j]){
                    d[j]=d[poz]+a[poz][j];
                    t[j]=poz;
                    }
                }
            }
        }
    drum(s);
    if(nr==0)
        cout<<"Nu exista drum";
    else
        afisare();
    }
int main(){
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"C:\\TC\\BGI");
    settextstyle(GOTHIC_FONT,HORIZ_DIR,1);
    f>>n;
    getch();
    cerc();
    dijkstra();
    getch();
    closegraph();
    return 0;
    }
