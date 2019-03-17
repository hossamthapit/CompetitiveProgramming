#include<bits/stdc++.h>
using namespace std ;
typedef char datatype;

struct node{
    datatype value ;
    node *next;
};

class stackk{

    public:
        node *topptr = nullptr;
        datatype top(){
            if(!isempty()){
                return topptr->value;
            }
            else {
               cout << "No Element In The Stack" << endl;
               return -1 ;
            }

        }
        void pop(){
            if(isempty()){
               cout << "No Element In The Stack" << endl;
            }
            else {
                node *tmp = new node ;
                tmp = topptr ;
                topptr = topptr->next;
                delete tmp;
            }
        }

        void push(int x){
            try{
                node *p = new node ;
                delete p ;
            }
            catch(std::bad_alloc()){
                cout << "MEMORY IS FULL" << endl;
                exit(0);
            }
            node *tmp = new node;
            tmp->next = topptr;
            tmp->value=x;
            topptr = tmp ;
        }

        bool isempty(){
            if(topptr==nullptr)return 1 ;
            return 0 ;
        }
};


int main(){

    /// test  ((())())

    stackk stk ;
    string s = "((())())";

    for(int i = 0 ; i < s.size();i++){
        if(s[i]=='(')stk.push('(');
        else if(s[i]==')'&&!stk.isempty())stk.pop();
        else return cout << "INVALID" << endl , 0;
    }
    if(!stk.isempty())cout << "INVALID" << endl;
    else cout << "VALID" << endl;



}
