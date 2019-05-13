#include<bits/stdc++.h>
using namespace std;
const int maxn = 100007;
map<char,int>Pri;
stack<int>num;
stack<char>Ope;
char str[maxn];
void init(){
    Pri['+'] = Pri['-'] = 1;
    Pri['*'] = Pri['/'] = Pri['%'] = Pri['('] = Pri[')'] = 2;
    while(!num.empty())
        num.pop();
    while(!Ope.empty())
        Ope.pop();
}
void operation_1(int &a,int &b, char c){
    if(c == '+')
        a += b;
    else if(c == '-')
        a = b-a;
    else if(c == '*')
        a *= b;
    else if(c == '/')
        a = b/a;
    else if(c == '%')
        a = b%a;
}
void operation_2(){
    char ch = Ope.top();
        while(ch != '('&&!Ope.empty()){
            Ope.pop();
            int a = num.top();
            num.pop();
            int b = num.top();
            num.pop();
            operation_1(a,b,ch);
            num.push(a);
            if(!Ope.empty())
                ch = Ope.top();
        }
        if(!Ope.empty()&&Ope.top() == '(')
            Ope.pop();
}
int main(){
    int t;
    cin>>t;getchar();
    while(t--){
        cin.getline(str,maxn);
        stringstream s(str);
        init();
        char tmp;
        while(s >> tmp){
            if(tmp >= '0' && tmp <= '9'){
                int t = 0;
                do{
                    if(Pri[tmp]){
                        break;
                    }
                    t *= 10;
                    t += tmp - '0';
                }while(s >> tmp);
                num.push(t);
            }
            if(tmp == ')'){
                operation_2();
            }
            else if(Pri[tmp]==1){
                if(!Ope.empty()&&Ope.top()!='('){
                    operation_2();
                }
                Ope.push(tmp);
            }
            else if(Pri[tmp]){
                Ope.push(tmp);
            }
        }
        int ans = num.top();
        num.pop();
        while(!num.empty()&&!Ope.empty()){
            operation_1(ans,num.top(),Ope.top());
            Ope.pop();
            num.pop();
        }
        cout << ans << endl;
    }
    return  0;
}
