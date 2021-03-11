#include<stdio.h>
#include<string.h>

int main(){
    
    int n,m,i,j,p,ni,nj;
    int flag=0;
    char t[1000005],c[1000005];

    //入力
    scanf("%s %s",t,c);
    m=strlen(t);
    n=strlen(c);

    i=n-1;//今、パターンの文字列がどこにいるか
    while(i<m){
        printf("i=%d\n",i);

        ni=i;//新しいテキスト側の指標
        nj=n-1;//新しいパターン側の指標

        while(t[ni]==c[nj] && nj>=0){//比べる　(不一致まで)
            ni--;
            nj--;
        }

        if(nj<0){//全て一致したら
            flag=1;
            break;
        }else{//全て一致しなかったら
            j=nj-1;//また新しいパターン側の指標(計算用)
            while(t[ni]!=c[j] && j>=0){//飛ばす量を計算　不一致の時のテキスト側の文字がそれよりさらに後ろにあるかどうか(パターン側に)
                j--;
            }

            i+=(nj-j);
        }

    }

    if(flag) printf("p=%d\n",ni+1);
    else printf("-1\n");

    return 0;
}