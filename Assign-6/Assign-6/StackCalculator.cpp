#include "StackCalculator.h"
#include <stack>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;
bool isOperator(string in);
void performOp(const string& in,stack<double>& Stack);

StackCalculator::StackCalculator(){
    string input;
    cout<<"Welcome to the Stack calculator!"<<endl;
    while(true){
        cout<<"> ";
        cin>>input;
        double num;
        if(istringstream(input)>>num){
            if (calcStack.size()>=2)
                cout<<"-->You already have two items to calculate"<<endl;
            else{
                if(num!=0)
                    calcStack.push(num);
                else
                    cout<<"--> Enter a valid entry"<<endl;
            }
        }
        else if (isOperator(input)){
            performOp(input,calcStack);
        }
        else if (input=="quit"){
            break;
        }
        else if (input=="pop"){
            if (calcStack.size()>=1){
                double a=calcStack.top();
                calcStack.pop();
                cout<<"-->Done"<<endl;
            }
            else{
                cout<<"-->Not Done"<<endl;
            }
        }
        else if (input=="show"){
            vector<double> t;
            int b=calcStack.size();
            for(int n=0;n<b;n++){
                cout<<"--> ";
                t.push_back(calcStack.top());
                calcStack.pop();
                cout<<t[n]<<endl;
           }
           for(int n=b-1;n>=0;n--){
                calcStack.push(t[n]);
           }
        }
        else
            cout<<"-->Enter a valid entry"<<endl;
    }
}

bool isOperator(string in){
    string ops[]={"-","+","*","/"};
    for(int i=0;i<4;i++){
        if(in==ops[i])
            return true;
    }
    return false;
}

void performOp(const string& in,stack<double>& Stack){
    double first, second, result;
    cout<<"--> ";
    if (Stack.size()==2){
        second=Stack.top();
        Stack.pop();

        first=Stack.top();
        Stack.pop();

        if (in=="-"){
            result = first-second;
        }
        else if (in=="+"){
            result = first+second;
        }
        else if (in=="*"){
            result = first*second;
        }
        else if (in=="/"){
            result = first/second;
        }
        cout<<result<<endl;
        Stack.push(result);
    }
    else{
        cout<<" Sorry, there are less than 2 entries on the stack.";
    }
}

StackCalculator::~StackCalculator(){
    int b=calcStack.size();
    for(int n=0;n<b;n++){
        calcStack.pop();
    }
}
