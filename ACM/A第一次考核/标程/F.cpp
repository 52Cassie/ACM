#include <iostream>
#include <string>
using namespace std;
int cas,tmp,ans,tot,sum,k,x,y;
bool v[11][16];
string a[11];
char c;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
void clear(int x,int y) {
     char c = a[x][y];
     a[x][y] = '.';
     for (int k=0;k<4;k++) {
         int xx = x + dx[k];
         int yy = y + dy[k];
         if (xx>=0 && yy>=0 && xx<10 && yy<15 && a[xx][yy]==c)
            clear(xx,yy);
     }
}
void flood(int x,int y) {
     tmp++;
     v[x][y] = 1;
     for (int k=0;k<4;k++) {
         int xx = x + dx[k];
         int yy = y + dy[k];
         if (xx>=0 && yy>=0 && xx<10 && yy<15 && !v[xx][yy] && a[xx][yy]==a[x][y])
            flood(xx,yy);
     }
}
int find(int &x,int &y,char &c) {
    int ans = 0;
    memset(v,0,sizeof(v));
    for (int j=0;j<15;j++)
        for (int i=0;i<10;i++)
            if (!v[i][j] && a[i][j]!='.') {
                          tmp = 0;
                          flood(i,j);
                          if (tmp>ans) {
                                       ans = tmp;
                                       x = i;
                                       y = j;
                                       c = a[i][j];
                          }
            }
    return ans;
}
void fresh() {
     for (int j=0;j<15;j++) {
         int tmp = 0;
         for (int i=0;i<10;i++)
             if (a[i][j]=='.') tmp++;
         for (int i=0;i<10-tmp;i++)
             while (a[i][j]=='.') {
                               int k = i;
                               while (k!=9) {
                                     swap(a[k][j],a[k+1][j]);
                                     k++;
                               }
             }
     }
     int b[16],tmpx = 0;
     memset(b,0,sizeof(b));
     for (int j=0;j<15;j++) {
         int tmp = 0;
         for (int i=0;i<10;i++)
             if (a[i][j]=='.') tmp++;
         if (tmp==10) {
                      b[j] = 1;
                      tmpx++;
         }
     }
     for (int j=0;j<15-tmpx;j++)
         while (b[j]==1) {
               int k = j;
               while (k!=14) {
                     for (int i=0;i<10;i++)
                         swap(a[i][k],a[i][k+1]);
                     swap(b[k],b[k+1]);
                     k++;
               }
         }
}
int main() {
    scanf("%d",&cas);
    for (int tt=1;tt<=cas;tt++) {
        for (int i=9;i>=0;i--)
            cin >> a[i];
        printf("Game %d:\n\n",tt);
        tot = 150;
        k = 0;
        sum = 0;
        while (1) {
              ans = find(x,y,c);
              if (ans<=1) break;
              printf("Move %d at (%d,%d): removed %d balls of color %c, got %d points.\n",
                           ++k,x+1,y+1,ans,c,(ans-2)*(ans-2));
              tot -= ans;
              sum += (ans-2)*(ans-2);
              clear(x,y);
              fresh();
        }
        if (tot==0) sum += 1000;
        printf("Final score: %d, with %d balls remaining.\n\n",sum,tot);
    }
    return 0;
}

