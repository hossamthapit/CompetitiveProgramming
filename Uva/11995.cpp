#include <bits/stdc++.h>
/*_*/
typedef long long ll;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define write  ofstream file ; file.open("HOSSAM.txt");

using namespace std;
int main()
{fast
  //  write
    int x ;
    while(cin >> x){
    int a , b , queue1=1 ,priority_queue1=1 , stack1 = 1 ;

    stack < int > stak ;
    priority_queue <int> pri_que ;
    queue <int> que ;
    int c = 0 ;
    bool h = 1 ;
    for(int i = 0 ; i < x ;i++){
        cin >> a >> b ;
            if(a==1){
            stak.push(b);
            pri_que.push(b);
            que.push(b);
            c++;
        }

        else if(c>0&&a==2){
          //  cout << stak.top() << " "<< pri_que.top() << " "<< que.front() << " "<< *st.begin() << " "<<endl;
            if(stak.top()!=b&&stack1)stack1=0;
            if(pri_que.top()!=b&&priority_queue1)priority_queue1=0;
            if(que.front()!=b&&queue1)queue1=0;
            stak.pop();
            pri_que.pop();
            que.pop();
            c--;
        }
        else if(c==0&&a==2){h = 0;}
    }

    if(stack1&&!priority_queue1&&!queue1&&h)cout << "stack" <<endl;
    else if(!stack1&&priority_queue1&&!queue1&&h)cout << "priority queue" <<endl;
    else if(!stack1&&!priority_queue1&&queue1&&h)cout << "queue" <<endl;
    else if((!stack1&&!priority_queue1&&!queue1)||!h)cout << "impossible" <<endl;
    else cout << "not sure" <<endl;
    }
}
