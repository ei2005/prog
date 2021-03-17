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

typedef struct{//箱の原物
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


bool isnum(string s,int m){//入力が数字かどうかそして合っているか
    if(s.size()>=3) return false;
    else if(s.size()==2){
        if(s[0]<='0' || '0'+(m/10)<s[0]) return false;
        else if(s[0]=='0'+(m/10) && '0'+(m%10)<=s[1]) return false;
    }
    else{
        if(s[0]<'0' || '0'+m<=s[0]) return false;
    }

    return true;
}

int chanstr(string s){//stringを数字に変換
    if(s.size()==2) return (s[0]-'0')*10+(s[1]-'0');
    else return (s[0]-'0');
}

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


    //ーーーーーレベル入力ーーーーー
    printf("\nchoose level\n");
    printf("0 1 2 3 4\n");
    string s;

    j1:;
    cin>>s;
    int k;
    if(!isnum(s,5)){
        cout<<"その数字は使えません\n"<<flush;
        goto j1;
    }

    sleep(1);

    //ーーーーー箱(ゲーム)の生成ーーーーー
    int m;//要素数
    int x[]={7,9,11,14,14};//要素数配列 

    k=chanstr(s);
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


    //ーーーーーゲーム開始ーーーーー
    while(1){
        
        //-----状況判定-----
        bool goal=true;
        rep(i,0,m-1){
            if(!box[i].flag) goal=false;
        }

        if(goal){
            cout<<"クリア！\n"<<flush;
            sleep(1);
            break;
        }


        //-----箱の表示-----
        cout<<"\n-------------------------------------------\n";
        cout<<"中身"<<"\n";
        rep(i,0,m-1){
            cout<<"箱 ";
            if(i<10) cout<<" ";
            cout<<i<<" ";
            cout<<box[i].s<<"\n";
        }
        cout<<"\n"<<flush;


        //-----入力ステップ-----
        printf("入れ替え元と入れ替え先を入力 箱の数字を入力\n");
        printf("もし、途中でやめたい場合は\"exit\"を入力してね\n");
        
        s1:;//入れ替え元入力
        cout<<"入れ替え元="<<flush;
        cin>>s; sleep(1);
        int from;
        if(s=="exit"){
            cout<<"中断"<<"\n"<<flush;
            sleep(1);
            return 0;
        }
        if(!isnum(s,m)){
            cout<<"その数字は使えません\n"<<flush;
            sleep(1); cout<<"\n";
            goto s1;
        }
        from=chanstr(s);

        s2:;//入れ替え先入力
        cout<<"入れ替え先="<<flush;
        cin>>s; sleep(1);
        int to;
        if(s=="exit"){
            cout<<"中断"<<"\n"<<flush;
            sleep(1);
            return 0;
        }
        if(!isnum(s,m)){
            cout<<"その数字は使えません\n"<<flush;
            sleep(1); cout<<"\n";
            goto s2;
        }
        to=chanstr(s);


        //-----例外処理-----
        if(to==from){
            cout<<"それはできません\n"<<flush;
            goto s1;
        }
        if(box[from].n==0 || box[to].n==4){
            cout<<"それはできません\n"<<flush;
            goto s1;
        }


        //-----処理,実行-----
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


        //-----状況の更新-----
        box[from].update();
        box[to].update();
        
    }

    return 0;
}