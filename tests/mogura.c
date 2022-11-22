/* chase　ver0.0.1  coded by Tsuyoshi Kasai 　   */
/*  TurboC (PC/AT) English Version 用  */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <dos.h>

/*変数　x,y自キャラ座標　　cx,cy  dx,dy敵キャラ座標　　px,pyポイント座標  */
/* g[][]　0　何もいない　1　自キャラ　2，3　敵キャラ　　4　ポイント　  */

int x,y,px,py,cx,cy,dx,dy;
int point=0;
int end=0;
int g[40][20];

void init();　　/*初期化*/
void setp();　　/*ポイントの初期設定、配置*/　
void setc();　　/*敵キャラその１の初期設定、配置*/
void setd();    /*敵キャラその2の初期設定、配置*/
void move();　　/*自キャラの移動*/
void cmove();　 /*敵キャラ１の移動*/
void dmove();   /*敵キャラ２の移動*/
void cymove();
void dxmove();


/*  Main関数　本体プログラム　　　　　*/　

main(){
init();
x=20;y=12;g[x][y]=1;

　　/*初期画面　　GAMEの説明、枠の表示、キャラの初期配置　*/

gotoxy(1,1);printf("********CHASE ver0.01********\n");
printf("  Coded by Tsuyoshi Kasai for TurboC(for DOS/V)");
gotoxy(1,22);printf("Your character is @, and get P.  C and D are enemies.\n");
printf("If you(@) are caught by enemies(C and D), Game is over.\n");
printf("Key 2 Down   4 Left   6 Right   8 Up\n"); 
setp();
setc();
setd();

for(;;){
gotoxy(1,3);printf("POINT : %3d",point);
move();　　　　　　/*自キャラの移動*/
cmove();　　　　　/*敵キャラ１の移動*/
dmove();　　　　　/*敵キャラ２の移動*/
delay(3000);       /*ゲームスピードの調整*/
if (end == 1) break;}　　　　/*endフラグがたったら終了*/
/* 終了画面表示　　*/
gotoxy(x,y);putchar('*');
printf("----E N D----");
printf("\x1b[>5l");
}

/*初期化*/

void init(){
int i,j;
printf("\x1b[2J");printf("\x1b[>5h");
for(i=1;i<=40;i++){gotoxy(i,4);putchar('#');gotoxy(i,20);putchar('#');}
for(i=4;i<=20;i++){gotoxy(1,i);putchar('|');gotoxy(40,i);putchar('|');}
randomize();
for(i=2;i<=39;i++){
for (j=5;j<=19;j++) g[i][j]=0;}
}

/*ポイントの初期設定、配置*/　

void setp(){
st:
px=random(38)+2;py=random(15)+5;
if (g[px][py] != 0) goto st;
g[px][py]=2;gotoxy(px,py);putchar('P');
}

/*敵キャラ１の初期設定、配置*/　

void setc(){
st:
cx=random(38)+2;cy=random(15)+5;
if (g[cx][cy] != 0) goto st;
g[cx][cy]=3;
}

/*敵キャラ２の初期設定、配置*/　

void setd(){
st:
dx=random(38)+2;dy=random(15)+5;
if (g[dx][dy] != 0) goto st;
g[dx][dy]=4;
}

/*自キャラの移動*/

void move(){
int c;
for(;;){
if(!kbhit())break;　　　　/*キーが押されていたら、変数cにキー取得*/
else c=getch();
}
gotoxy(x,y);putchar(' ');g[x][y]=0;
　　　　　/*変数c（押されたキー）別に移動方向の処理*/
switch(c){　　　　　　　　
case '2':
if(y<19) y++;
else y=19;
break;
case '4':
if(x>2) x--;
else x=2;
break;
case '6':
if(x<39) x++;
else x=39;
break;
case '8':
if(y>5) y--;
else y=5;
break;
}
gotoxy(x,y);putchar('@');

/*当り判定とその処理*/
switch(g[x][y]){
case 2:               /*　ポイントと当たったら５点追加　*/
point=point+5;setp();
break;
case 3:               /* 敵と当たったら終了フラグ立てる　end=1  */
end=1;break;
case 4:               /* 敵と当たったら終了フラグ立てる　end=1  */
end=1;break;
}
g[x][y]=1;
}

/*敵キャラ１の移動*/

void cmove(){
int oldcx,oldcy,r;
r=random(3);
if (r == 0) return;  /*  ３分の２の確立で移動　*/
oldcx=cx;oldcy=cy;
gotoxy(cx,cy);putchar(' ');g[cx][cy]=0;
if(cx>x) {cx--;goto cpos;}
if(cx<x){cx++;goto cpos;}
if(cx==x) cymove();  /*x座標が同じなら、縦方向（y軸）の移動に*/
cpos:                /*当り判定とその処理*/
switch(g[cx][cy]){
case 1:               /*自キャラに当たる。ゲーム終了（end=1)*/
end=1;break;
case 2:               /*ポイントに当たる。マイナス１ポイント*/
point--;setp();break;
case 4:               /*敵２キャラと位置が重なる。この場合は移動させない*/
cx=oldcx;cy=oldcy;break;   /*元の座標(oldcx,oldcy)を代入*/
}
gotoxy(cx,cy);putchar('C');g[cx][cy]=3;
}

void cymove(){
if(cy<y) cy++;
if(cy>y) cy--;
}

/*敵キャラ２の移動*/

void dmove(){
int olddx,olddy,r;
r=random(3);
if (r == 0) return;
olddx=dx;olddy=dy;
gotoxy(dx,dy);putchar(' ');g[dx][dy]=0;
if(dy<py) {dy++;goto dpos;}
if(dy>py){dy--;goto dpos;}
if(dy == py) dxmove();
dpos:               /*当り判定とその処理*/
switch(g[dx][dy]){
case 1:
end=1;break;
case 2:
point--;setp();break;
case 3:
dx=olddx;cy=olddy;break;
}
gotoxy(dx,dy);putchar('D');g[dx][dy]=4;
}

void dxmove(){
if(dx<px) dx++;
if(dx>px) dx--;
}