#include<bits/stdc++.h>
#include<unistd.h>
#include<ctype.h>
using namespace std;

//coutのあとにflushでなんと途中出力可能！

#define ll long long
#define rep(i,x,n) for(int i=(x);i<=(int)(n);i++)
#define rrep(i,n,x) for(int i=(n);i>=(int)(x);i--)
#define vi vector<int>
#define vll vector<ll>
#define vc vector<char>
#define vb vector<bool>
#define all(v) v.begin(),v.end()
#define fi first
#define se second
#define P pair<int,int>
#define mk(a,b) make_pair(a,b)

typedef struct{
    string s;
    int n;
    bool flag=false;

    void update(){
        n=(int)s.size();

        if(n==4){
            if(s[0]==s[1] && s[1]==s[2] && s[2]==s[3]){
                flag=true;
            }
        }
        else if(n==0){
            flag=true;
        }
    }
}boxs;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    srand((unsigned)time(NULL));

    printf("ball sort puzzle!\n");

    //ゲーム説明
    printf("数字の書かれた箱に様々なアルファベットが入っている\n");
    printf("しかし並びがバラバラなのでsortしよう\n");
    printf("ゲームでは何か中身が入っている箱の一番右を取り出し、\n");
    printf("別の箱の一番左に入れていくという作業をする\n");
    printf("しかし、ある文字の上にはその文字と同じ文字しか入れれない\n");
    printf("中身が何もない箱には何でも入れる事ができる\n");
    printf("一つ一つの箱に入れれる文字の上限 4個まで\n");
    printf("\n全ての文字を綺麗に並べ替えることができたらクリア！\n");
    printf("もし、行き詰まったり変なエラーが起こったりしたら申し訳ないけどCtrl+Cを...\n");
    printf("\n詳しくはスマホゲーム「Ball Sort Puzzle」をやってみてね！\n");
    
    sleep(5);

    printf("\nchoose level\n");
    printf("0 1 2 3 4\n");
    j1:;
    int k; cin>>k;
    if(k<0 || 4<k){
        cout<<"その数字は使えません\n"<<flush;
        goto j1;
    }

    int m;//要素数
    int x[]={7,9,11,14,14};//要素数配列

    m=x[k];
    boxs box[m];//箱のすべて

    switch(k){//データサンプル
        case 0://level 6
        box[0].s="ABBB";
        box[1].s="CADB";
        box[2].s="DCAC";
        box[3].s="EDCD";
        box[4].s="EEEA";
        break;

        case 1://level 51
        box[0].s="ABCD";
        box[1].s="BEDF";
        box[2].s="EFBF";
        box[3].s="CAGD";
        box[4].s="CGCE";
        box[5].s="GGAE";
        box[6].s="FBDA";
        break;

        case 2://level 77
        box[0].s="ABAC";
        box[1].s="BDEC";
        box[2].s="FGEE";
        box[3].s="HGDG";
        box[4].s="IFHH";
        box[5].s="AFFB";
        box[6].s="DDCA";
        box[7].s="EGII";
        box[8].s="HCIB";
        break;

        case 3://level 107
        box[0].s="ABCD";
        box[1].s="EFGH";
        box[2].s="GDIF";
        box[3].s="JHIA";
        box[4].s="GJKF";
        box[5].s="AGCF";
        box[6].s="LECB";
        box[7].s="IELH";
        box[8].s="DEKK";
        box[9].s="BIJL";
        box[10].s="BADC";
        box[11].s="KLJH";
        break;

        case 4://level 161
        box[0].s="CGJE";
        box[1].s="EDLG";
        box[2].s="HIBB";
        box[3].s="AAKL";
        box[4].s="HFJF";
        box[5].s="GHCI";
        box[6].s="DCAF";
        box[7].s="DHDJ";
        box[8].s="FALC";
        box[9].s="KGJB";
        box[10].s="IIEK";
        box[11].s="BLEK";
        break;
    }

    rep(i,0,m-1){
        box[i].update();
    }
    
    while(1){

        bool goal=true;
        rep(i,0,m-1){
            if(!box[i].flag) goal=false;
        }

        if(goal){
            cout<<"クリア！\n"<<flush;
            break;
        }

        cout<<"中身"<<"\n"<<flush;
        rep(i,0,m-1){
            cout<<"箱 ";
            if(i<10) cout<<" ";
            cout<<i<<" ";
            cout<<box[i].s<<"\n"<<flush;
        }
        cout<<"\n"<<flush;

        printf("入れ替え元と入れ替え先を入力 箱の数字を入力\n");
        
        s1:;
        cout<<"入れ替え元="<<flush;
        int from; cin>>from;
        if(iscntrl(from)){
            from=-1;
        }
        if(from<0 || m<=from){
            from=0;
            cout<<"その数字は使えません\n"<<flush;
            goto s1;
        }

        s2:;
        cout<<"入れ替え先="<<flush;
        int to; cin>>to;
        if(iscntrl(to)){
            to=-1;
        }
        if(to<0 || m<=to ||){
            to=-1;
            cout<<"その数字は使えません\n"<<flush;
            goto s2;
        }

        //例外処理
        if(to==from){
            cout<<"それはできません\n"<<flush;
            goto s1;
        }
        if(box[from].n==0 || box[to].n==4){
            cout<<"それはできません\n"<<flush;
            goto s1;
        }

        char from_ch=box[from].s[box[from].n-1];
        if(box[to].n==0){
            box[from].s.pop_back();
            box[to].s.push_back(from_ch);
        }
        else{
            char to_ch=box[to].s[box[to].n-1];
            if(from_ch!=to_ch){
                cout<<"それはできません\n"<<flush;
                goto s1;
            }
            else{
                box[from].s.pop_back();
                box[to].s.push_back(from_ch);
            }
        }

        box[from].update();
        box[to].update();
    }

    return 0;
}