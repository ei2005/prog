#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<numeric> // __GCD()
#include<stdlib.h>
#include<time.h>
#include<set>

using namespace std;

#define ll long long

//数字当てゲーム！！！

int n=5;
int judge=0;
int rimit=15;//ターン制限
vector<char> ans(n);//答え用数字列
vector<char> x(n);//入力文字列

set<char> s;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    srand((unsigned int)time(NULL));

    cout<<"数字当てゲーム\n"<<flush;

    cout<<"コンピュータの選んだ5桁の数字を当てよう(0~9)(重複なし)\n"<<flush;
    cout<<rimit<<"ターン以内に当てれないとゲームオーバー"<<"\n"<<flush;

    cout<<"＜予想結果について＞"<<"\n"<<flush;
    cout<<"・homerun:完全にマッチ"<<"\n";
    cout<<"・hit:homerunではないが、別のところに同じ数字がある"<<"\n"<<flush;

    //答え数列生成
    for(int i=0;i<n;i++){
        do{
            ans[i]=rand()%10+'0';
        }while(s.find(ans[i])!=s.end());

        s.insert(ans[i]);
    }

    
    while(1){
        //ターン数
        judge++;

        if(judge==rimit+1){
            cout<<"ターンオーバー..."<<"\n";

            cout<<"正解\n";
            for(int i=0;i<n;i++){
                cout<<ans[i];
            }
            cout<<"\n";

            return 0;
        }

        cout<<"\n"<<"###turn"<<judge<<"###"<<"\n"<<flush;


        //解答入力
        cout<<"5桁の数字を入力して当てよう!\n"<<flush;
        for(int i=0;i<n;i++) cin>>x[i];


        //判定
        int homerun=0,hit=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(ans[i]==x[j]){
                    if(i==j) homerun++;
                    else hit++;
                    break;
                }
            }
        }


        //予想結果
        cout<<"\n";
        cout<<"homerun:"<<homerun<<"\n";
        cout<<"hit:"<<hit<<"\n"<<flush;


        //ゲーム結果
        if(homerun==n){
            break;
        }

        cout<<"\n--------------------------------------------"<<"\n";

    }


    //クリア
    cout<<"congratulation!"<<"\n";

    cout<<"正解 ";
    for(int i=0;i<n;i++){
        cout<<ans[i];
    }
    cout<<"\n";

    return 0;
}