 #include<iostream>
#include<memory>
#include<vector>
#include<random>
#include<algorithm>
#include<cmath>
#define DIMENSION 2 //维度
#define N 6 //种群容量
using namespace std;
//随机引擎
default_random_engine e;
uniform_int_distribution<unsigned> u(0,1);
//得到初始化种群
shared_ptr<vector<vector<int>>> init(int length)
{
        shared_ptr<vector<vector<int>>> data=make_shared<vector<vector<int>>>(N,vector<int>(DIMENSION*length));
        for(auto&i:*data)
                for_each(i.begin(),i.end(),[&e,&u](auto&j){j=u(e);});
        return data;
}
//打印种群矩阵
void print(shared_ptr<vector<vector<int>>>data)
{
        for(auto&i:*data)
        {

                for_each(i.begin(),i.end(),[](auto&j){cout<<j<<" ";});
                cout<<endl;
        }

}

//根据精度确定length 
int getLength(double min,double max,double decision)
{       
        double r=log((max-min)/decision)/log(2);
        
        return static_cast<int>(r)==r?static_cast<int>(r):static_cast<int>(r)+1;
}
int main()
{       
        /*
        ¦* 实际问题:
        ¦* x,y属于[-5.12,5.12]
        ¦* 精度0.01
        ¦* max f(x,y)=x*x+y*y
        ¦*/
        //编码长度
        length=getLength(-5.12,5.12,0.01);
        //得到初始矩阵
        auto data=init(length);
        //print(data);
        //用轮盘赌进行选择
}
