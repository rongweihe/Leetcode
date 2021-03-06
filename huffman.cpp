Sample - Greediness
贪心典型题（1）- 哈夫曼编码
题目描述
“霍夫曼编码（Huffman Coding）是一种编码方式，是一种用于无损数据压缩的熵编码（权编码）算法。也称“哈夫曼编码”，。
1952年，David A. Huffman在麻省理工攻读博士时所发明的，并发表于《一种构建极小多余编码的方法》（A Method for the Construction of Minimum-Redundancy Codes）一文。
在计算机数据处理中，霍夫曼编码使用变长编码表对源符号（如文件中的一个字母）进行编码，其中变长编码表是通过一种评估来源符号出现机率的方法得到的，
出现机率高的字母使用较短的编码，反之出现机率低的则使用较长的编码，这便使编码之后的字符串的平均长度、期望值降低，从而达到无损压缩数据的目的。
例如，在英文中，e的出现机率最高，而z的出现概率则最低。当利用霍夫曼编码对一篇英文进行压缩时，e极有可能用一个比特来表示，而z则可能花去25个比特（不是26）。
用普通的表示方法时，每个英文字母均占用一个字节（byte），即8个比特。二者相比，e使用了一般编码的1/8的长度，z则使用了3倍多。
倘若我们能实现对于英文中各个字母出现概率的较准确的估算，就可以大幅度提高无损压缩的比例。
霍夫曼树又称最优二叉树，是一种带权路径长度最短的二叉树。所谓树的带权路径长度，就是树中所有的叶结点的权值乘上其到根结点的路径长度（若根结点为0层，
叶结点到根结点的路径长度为叶结点的层数）。树的路径长度是从树根到每一结点的路径长度之和，记为WPL=（W1*L1+W2*L2+W3*L3+...+Wn*Ln），
N个权值Wi（i=1,2,...n）构成一棵有N个叶结点的二叉树，相应的叶结点的路径长度为Li（i=1,2,...n）。可以证明霍夫曼树的WPL是最小的。” – 以上摘自维基百科
现在问题来了：给出编码中每个字符出现的频率，求其WPL最小是多少。
输入格式
多组样例，以EOF结尾，对于每组样例：
第一行: 一个正整数N(<=50000)代表编码数量。
第二行: N个正整数(<=20000)，代表每个编码的权重。
输出格式
对于每组样例，输出其最小的WPL，每个样例一行。
样例输入

                    3
                    8 5 8

样例输出

                    34
Hint
这颗树是这样的：根连接1号节点和权重8的编码。1号节点连接权重5的编码和另一个权重8的编码。
下载资料:
输入文件
输出文件
参考答案
/***************************************************************************
版权申明：本程序为北京交通大学《算法设计与分析》课程以及教材《算法设计与问题
求解-编程实践》的教辅材料，著作权为北京交通大学计算机与信息技术学院视觉智能
实验室李清勇教授所有，禁止用于任何盈利性质的商业行为。未经著作权所有人允许，
禁止进行传播和出版。
*************************************************************************/

/**************************************************************************
解题思路：频率低的字符分配长的编码，否则分配短的编码。

**************************************************************************/
/*code*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+233;
int n,a[N];
long long ret;
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        priority_queue<int,vector<int>,greater<int> >que;
        for(int i=1; i<=n; ++i)
        {
            cin>>a[i];
            que.push(a[i]);
        }
        ret=0;
        while(1)
        {
           int first_val=que.top();que.pop();  //cout<<"first_val= "<<first_val<<endl;
           if(que.empty())break;
           int second_val=que.top();que.pop(); //cout<<"second_val= "<<second_val<<endl;
           int sum_val=first_val+second_val;   //cout<<"sum_val= "<<sum_val<<endl;
           ret+=sum_val;
           que.push(sum_val);
        }
        cout<<ret<<endl;
    }
    return 0;
}



/* ***********************************************
Author        :herongwei
Created Time  :Fri 07 Jul 2017 05:37:18 PM CST
File Name     :readme.txt
************************************************ */

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
typedef long long LL;
const int maxn  = 1e5+233;
const int MOD   = 1e9+7;
const double eps= 1e-6;
const double pi = acos(-1.0);

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    return 0;

}