# 23 普及组 2013 复赛解题过程

## 23.1 score

### step1

以 score1.ans 作为输出内容，建立最小可提交程序框架。

```cpp
#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    freopen("score.in","r",stdin);
    freopen("score.out","w",stdout);

    cout << 40 << endl;

    fclose(stdout);
    fclose(stdin);

    return 0;
}
```

### step2

编写对拍程序，通过测试点 1。

```sh
#!/bin/bash
i=1
while [ $i -le 10 ]
do
    echo score$i
    cp -f score$i.in score.in
    ./score
    if diff score$i.ans score.out ; then
        echo Ac
    fi
    i=$(($i+1))
done
```

执行对拍程序，观测测试结果。

```sh
$ cd ~/noip/2017/score/
$ sh ./score.sh 
score1
Ac
```

只有 score1 测试数据通过，可得 10 分。

### step3

综合分析试题描述对数据建模，找到基本的输入输出数据存储方式，并确定它们的数据类型。
由于需要计算成绩的只有牛牛，确定数据的读入策略为**一次性读入**。

```cpp
#include <stdio.h>
#include <iostream>
using namespace std;

int a,b,c;

int main(){
    freopen("score.in","r",stdin);
    freopen("score.out","w",stdout);
    
    cin >> a >> b >> c;
    cout << 40 << endl;

    fclose(stdout);
    fclose(stdin);

    return 0;
}
```

可以通过设置断点的方法观察读到数据的具体情况。

### step4

根据试题中给出的计算总成绩的方法，确定数据加工方法（算法）。

1. 直接输出计算结果
    ```cpp
    #include <stdio.h>
    #include <iostream>
    using namespace std;
    
    int a,b,c;
    
    int main(){
        freopen("score.in","r",stdin);
        freopen("score.out","w",stdout);
        
        cin >> a >> b >> c;
        cout << a*.2 + b*.3 + c*.5 << endl;
            
        fclose(stdout);
        fclose(stdin);

        return 0;
    }
    ```
2. 全整型计算
    ```cpp
    #include <stdio.h>
    #include <iostream>
    using namespace std;
    
    int a,b,c,score;
    
    int main(){
        freopen("score.in","r",stdin);
        freopen("score.out","w",stdout);
        
        cin >> a >> b >> c;
        score = (a*2 + b * 3 + c *5) / 10;
        cout << score << endl;

        fclose(stdout);
        fclose(stdin);
            
        return 0;
    }
    ```
3. 输出浮点计算结果
    ```cpp
    #include <stdio.h>
    #include <iostream>
    using namespace std;
    
    int a,b,c;
    double score;
    
    int main(){
        freopen("score.in","r",stdin);
        freopen("score.out","w",stdout);
    
        cin >> a >> b >> c;
        score = a*.2 + b*.3 + c*.5;
        cout << score << endl;

        fclose(stdout);
        fclose(stdin);
    
        return 0;
    }
    ```

### step5

再次执行对拍程序，确认全部 **Ac** 通过测试数据。

```sh
$ cd ~/noip/junior-rep-23-2017-C++/score/
$ sh ./score.sh
score1
Ac
score2
Ac
score3
Ac
score4
Ac
score5
Ac
score6
Ac
score7
Ac
score8
Ac
score9
Ac
score10
Ac
```

## 23.2 librarian

### step1

以 librarian1.ans 作为输出内容，建立最小可提交程序框架。

```cpp
#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    freopen("librarian.in","r",stdin);
    freopen("librarian.out","w",stdout);

    cout << 9392912 << endl;
    cout << -1 << endl;
    cout << 9392912 << endl;
    cout << -1 << endl;
    cout << 9392912 << endl;
    cout << -1 << endl;

    fclose(stdout);
    fclose(stdin);

    return 0;
}
```

### step2

编写对拍程序，通过测试点 1。

```sh
#!/bin/bash
i=1
while [ $i -le 10 ]
do
    echo librarian$i
    cp -f librarian$i.in librarian.in
    ./librarian
    if diff librarian$i.ans librarian.out ; then
        echo Ac
    fi
    i=$(($i+1))
done
```

执行对拍程序，观测测试结果。

```sh
$ cd ~/noip/2017/librarian/
$ sh ./librarian.sh 
librarian1
Ac
```

只有 librarian1 测试数据通过，可得 10 分。

### step3

综合分析试题描述对数据建模，找到基本的输入输出数据存储方式，并确定它们的数据类型。

```cpp
int n,q,book[1005],reqlen[1005],reqcode[1005];
```

其中 n 图书馆里书的数量，q 是读者的数量，对于 100%的数据， 1 ≤ n，q ≤ 1,000，book[1005] 是 n 本书的图书编号，reqlen[1005] 是 q 个需求码的长度与需求码的下标对应，reqcode[1005] 是 q 个读者的需求码，所有的图书编码和需求码均不超过 10,000,000。所以上述变量定义为** int **符合要求。

由于需要读入 n 本图书和 q 个读者的数据，所以采用**循环读入数组**的数据读取策略。

```cpp
#include <stdio.h>
#include <iostream>
using namespace std;

int n,q,book[1005],reqlen[1005],reqcode[1005];

int main(){
    freopen("librarian.in","r",stdin);
    freopen("librarian.out","w",stdout);

    cin >> n >> q;
    for(int i=0;i<n;i++)
        cin >> book[i];
    for(int i=0;i<q;i++){
        cin >> reqlen[i] >> reqcode[i] ;
    }

    cout << 9392912 << endl;
    cout << -1 << endl;
    cout << 9392912 << endl;
    cout << -1 << endl;
    cout << 9392912 << endl;
    cout << -1 << endl;

    fclose(stdout);
    fclose(stdin);
    
    return 0;
}
```

### step4

根据题意，求**每位读者（q 位）**需要的书，并判断该书是否存在。

```cpp
for(int i=0;i<q;i++){
    int min = 100000000;    //设定一个最大的，不存在的图书编码
    
    //查找图书的方法，并把找到的图书编码存入 min
    
}
```

根据每位读者需求码查找图书的过程，就是把图书编码的后几位按照需求码的长度截取下来进行比对的过程。要想截取图书编码的后几位，需要根据需求码的长度计算**模数**的大小。变量 m 用来保存模数。

```cpp
int m = 1;
for(int j=0;j<reqlen[i];j++){
    m = m * 10;
}
```

接下来对当前读者** i **就可以用他的需求码比对截取后的图书码了，如果发现新找到的图书码比前面找到的图书码小，用新的图书码替换旧的图书码。

```cpp
for(int j=0;j<n;j++){
    if(book[j]%m==reqcode[i]){
        if(book[j]<min)
            min = book[j];
    }
}
```

根据【输出格式】和【输入输出样例】确定输出策略——对每位读者判断是否找到了他所需要的那本书。

```cpp
if(min<100000000)       //min 被改变了，说明所要的图书编码找到了
    cout << min << endl;
else                    //min 没有变化，说明没有找到任何图书
    cout << -1 << endl;
```

完整的程序代码为如下，按** F7 **键编译，按** Ctrl+F5 **键执行，观察执行结果的正确性。

```cpp
#include <stdio.h>
#include <iostream>
using namespace std;

int n,q,book[1005],reqlen[1005],reqcode[1005];

int main(){
    freopen("librarian.in","r",stdin);
    freopen("librarian.out","w",stdout);

    cin >> n >> q;
    for(int i=0;i<n;i++)
        cin >> book[i];
    for(int i=0;i<q;i++){
        cin >> reqlen[i] >> reqcode[i] ;
    }

    for(int i=0;i<q;i++){
        int min = 100000000;

        int m = 1;
        for(int j=0;j<reqlen[i];j++){
            m = m * 10;
        }
        
        for(int j=0;j<n;j++){
            if(book[j]%m==reqcode[i]){
                if(book[j]<min)
                    min = book[j];
            }
        }

        if(min<100000000)
            cout << min << endl;
        else
            cout << -1 << endl;
    }

    fclose(stdout);
    fclose(stdin);
    
    return 0;
}
```

### step5

再次执行对拍程序，确认全部** Ac **通过测试数据。

```sh
$ cd ~/noip/junior-rep-23-2017-C++/librarian/
$ sh ./librarian.sh
librarian1
Ac
librarian2
Ac
librarian3
Ac
librarian4
Ac
librarian5
Ac
librarian6
Ac
librarian7
Ac
librarian8
Ac
librarian9
Ac
librarian10
Ac
```

## 23.3 chess

### step1

以 chess1.ans 作为输出内容，建立最小可提交程序框架。

```cpp
#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    freopen("chess.in","r",stdin);
    freopen("chess.out","w",stdout);

    cout << 0 << endl;

    fclose(stdout);
    fclose(stdin);

    return 0;
}
```

### step2

编写对拍程序，通过测试点 1。

```sh
#!/bin/bash
i=1
while [ $i -le 20 ]
do
    echo chess$i
    cp -f chess$i.in chess.in
    ./chess
    if diff chess$i.ans chess.out ; then
        echo Ac
    fi
    i=$(($i+1))
done
```

执行对拍程序，观测测试结果。

```sh
$ cd ~/noip/2017/chess/
$ sh ./chess.sh 
chess1
Ac
```

只有 chess1 测试数据通过，可得 5 分。

### step3

编制测试样例数据 chess.in。

```cpp
5 7
1 1 0
1 2 0
2 2 1
3 3 1
3 4 0
4 4 1
5 5 0
```

### step4

读取输入数据。

```cpp
#include <stdio.h>
#include <iostream>
using namespace std;

int m,n,chess[105][105];

int main(){
    freopen("chess.in","r",stdin);
    
    int x, y, c;
    cin >> m >> n;
    
    for(int i=1;i<=n;i++){
        cin >> x >> y >> c;
        chess[x][y]=c+1;
    }

    return 0;
}
```

查看变量观察读入数据是否正确

### step5

深度优先（DFS）走四方。

```cpp
#include <stdio.h>
#include <iostream>
#include <cstring>
using namespace std;

int m,n,chess[105][105];
int step[4][2]={ {0,-1},{0,1},{-1,0},{1,0} };

void walk(int sx,int sy,int coin,int magic){
    for(int i=0;i<4;i++){
        int tx = sx + step[i][0];
        int ty = sy + step[i][1];
        if(tx<=m && ty<=m && tx >=1 && ty >=1){
            walk(tx,ty,coin,0);
        }
    }

    return;
}

int main(){
    freopen("chess.in","r",stdin);
    
    int x, y, c;
    cin >> m >> n;
    
    for(int i=1;i<=n;i++){
        cin >> x >> y >> c;
        chess[x][y]=c+1;
    }

    walk(1,1,0,0);
    
    return 0;
}
```

### step6

增加算法逻辑——金币计算方法和递归结束方法。

```cpp
#include <stdio.h>
#include <iostream>
#include <cstring>
using namespace std;

int m,n,chess[105][105];
int step[4][2]={ {0,-1},{0,1},{-1,0},{1,0} };
int cost[105][105];

void walk(int sx,int sy,int coin,int magic){
    if (coin < cost[sx][sy])
        cost[sx][sy] = coin;
    else
        return ;
        
    for(int i=0;i<4;i++){
        int tx = sx + step[i][0];
        int ty = sy + step[i][1];
        if(tx<=m && ty<=m && tx >=1 && ty >=1){
            if(chess[tx][ty]>0){
                if(chess[sx][sy]==chess[tx][ty]){
                    walk(tx,ty,coin,0);
                }else{
                    walk(tx,ty,coin+1,0);
                }
            }else if(magic==0){
                chess[tx][ty] = chess[sx][sy];
                walk(tx,ty,coin+2,1);
                chess[tx][ty] = 0;
            }
        }
    }

    return;
}

int main(){
    freopen("chess.in","r",stdin);
    
    memset(cost,0x7f,sizeof(cost));
    
    int x, y, c;
    cin >> m >> n;
    
    for(int i=1;i<=n;i++){
        cin >> x >> y >> c;
        chess[x][y]=c+1;
    }

    walk(1,1,0,0);
    
    if(cost[m][m]==cost[0][0])
        cout << -1 << endl;
    else
        cout << cost[m][m] << endl;
    
    return 0;
}
```

### step7

增加数据输出方法，准备测试提交。

```cpp
#include <stdio.h>
#include <iostream>
#include <cstring>
using namespace std;

int m,n,chess[105][105];
int step[4][2]={ {0,-1},{0,1},{-1,0},{1,0} };
int cost[105][105];

void walk(int sx,int sy,int coin,int magic){
    if (coin < cost[sx][sy])
        cost[sx][sy] = coin;
    else
        return ;
        
    for(int i=0;i<4;i++){
        int tx = sx + step[i][0];
        int ty = sy + step[i][1];
        if(tx<=m && ty<=m && tx >=1 && ty >=1){
            if(chess[tx][ty]>0){
                if(chess[sx][sy]==chess[tx][ty]){
                    walk(tx,ty,coin,0);
                }else{
                    walk(tx,ty,coin+1,0);
                }
            }else if(magic==0){
                chess[tx][ty] = chess[sx][sy];
                walk(tx,ty,coin+2,1);
                chess[tx][ty] = 0;
            }
        }
    }

    return;
}

int main(){
    freopen("chess.in","r",stdin);
    freopen("chess.out","w",stdout);
    
    memset(cost,0x7f,sizeof(cost));
    
    int x, y, c;
    cin >> m >> n;
    
    for(int i=1;i<=n;i++){
        cin >> x >> y >> c;
        chess[x][y]=c+1;
    }

    walk(1,1,0,0);
    
    if(cost[m][m]==cost[0][0])
        cout << -1 << endl;
    else
        cout << cost[m][m] << endl;
    
    return 0;
}
```

### step8

编写对拍测试程序。

```sh
#!/bin/bash
i=1
while [ $i -le 20 ]
do
    echo chess$i
    cp -f chess$i.in chess.in
    ./chess
    if diff chess$i.ans chess.out ; then
        echo Ac
    fi
    i=$(($i+1))
done
```

### step9

执行对拍程序，查看结果，Ac 为通过的测试用例。

```sh
$ cd ~/noip/junior-rep-23-2017-C++/chess/
$ sh ./chess.sh
```

执行结果如下：

```sh
chess1
Ac
chess2
Ac
chess3
Ac
chess4
Ac
chess5
Ac
chess6
Ac
chess7
Ac
chess8
Ac
chess9
Ac
chess10
Ac
chess11
Ac
chess12
Ac
chess13
Ac
chess14
Ac
chess15
Ac
chess16
Ac
chess17
Ac
chess18
Ac
chess19
Ac
chess20
Ac
```

## 23.4 jump

### step1

以 jump1.ans 作为输出内容，建立最小可提交程序框架。

```cpp
#include <cstdio>
#include <iostream>
using namespace std;

int main(){
    freopen("jump.in","r",stdin);
    freopen("jump.out","w",stdout);
    
    cout << 87 << endl;

    fclose(stdout);
    fclose(stdin);
    
    return 0;
}
```

### step2

编写对拍程序，通过测试点 1。

```sh
#!/bin/bash
i=1
while [ $i -le 10 ]
do
    echo jump$i
    cp -f jump$i.in jump.in
    ./jump
    if diff jump$i.ans jump.out ; then
        echo Ac
    fi
    i=$(($i+1))
done
```

执行对拍程序，观测测试结果。

```sh
$ cd ~/noip/2017/jump/
$ sh ./jump.sh 
jump1
Ac
```

只有 jump1 测试数据通过，可得 10 分。

### step3

编制测试样例数据 chess.in。

```cpp
7 4 10
2 6
5 -3
10 3
11 -3
13 1
17 6
20 2
```

### step4

读取输入数据

```cpp
#include <cstdio>
#include <iostream>
using namespace std;

int n,d,k,dist[500005],value[500005];

int main(){
    freopen("jump.in","r",stdin);
    
    long long sum = 0;
    cin >> n >> d >> k;
    for (int i=1;i<=n;i++){
        cin >> dist[i] >> value[i];
        if(value[i]>0) sum = sum + value[i];
    }
    
    if(sum < k){
        cout << -1 << endl;
        return 0;
    }
    
    return 0;
}
```

查看变量，观察读入数据是否正确。

### step5 

建立二分查找程序框架。

```cpp
#include <cstdio>
#include <iostream>
using namespace std;

int n,d,k,dist[500005],value[500005];

bool check(int g){

    return 0;
}

int main(){
    freopen("jump.in","r",stdin);
    
    long long sum = 0;
    cin >> n >> d >> k;
    for (int i=1;i<=n;i++){
        cin >> dist[i] >> value[i];
        if(value[i]>0) sum = sum + value[i];
    }
    
    if(sum < k){
        cout << -1 << endl;
        return 0;
    }
    
    int lg=0,rg=1000000000;
    while(lg<rg){
        int midg = (lg+rg)>>1;
        if(check(midg)) 
            rg = midg;
        else
            lg = midg + 1;
    }
    
    cout << rg << endl;
    
    return 0;
}
```

每次执行的 midg 结果。 

```cpp
500000000
750000000
875000000
937500000
968750000
984375000
992187500
996093750
998046875
999023438
999511719
999755860
999877930
999938965
999969483
999984742
999992371
999996186
999998093
999999047
999999524
999999762
999999881
999999941
999999971
999999986
999999993
999999997
999999999
```

最终的输出结果。

```cpp
1000000000
```

### step6

暴力搜索到当前位置的最少金币数，进而找到全局最优解。

```cpp
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int n,d,k,dist[500005],value[500005];
long long coins[500005];
int lpos,rpos;

bool check(int g){
    lpos = d-g; //跳的最短距离 
    rpos = d+g; //跳的最长距离 
    if(lpos<=0) lpos = 1;
    memset(coins,-127,sizeof(coins));  //设为很小的负数
    coins[0]=0;
    for(int i=1; i<=n; i++){
        for(int j=i-1; j>=0; j--){
            if(dist[i]-dist[j]<lpos) continue;
            if(dist[i]-dist[j]>rpos) break;
            coins[i]=max(coins[i],coins[j]+value[i]);
            if(coins[i]>=k) return 1;
        }
    }
    return 0;
}

int main(){
    freopen("jump.in","r",stdin);
    freopen("jump.out","w",stdout);
    
    long long sum = 0;
    cin >> n >> d >> k;
    for (int i=1;i<=n;i++){
        cin >> dist[i] >> value[i];
        if(value[i]>0) sum = sum + value[i];
    }
    
    if(sum < k){
        cout << -1 << endl;
        return 0;
    }
    
    int lg=0,rg=1000000000;
    while(lg<rg){
        int midg = (lg+rg)>>1;
        if(check(midg)) {
            rg = midg;
        }else{
            lg = midg + 1;
        }
    }
    
    cout << rg << endl;
    
    return 0;
}
```

### step7

增加输出重定向功能，并编译通过。

```cpp
freopen("jump.out","w",stdout);
```

### step8

准备对拍程序。

```sh
#!/bin/bash
i=1
while [ $i -le 10 ]
do
    echo jump$i
    cp -f jump$i.in jump.in
    ./jump
    if diff jump$i.ans jump.out ; then
        echo Ac
    fi
    i=$(($i+1))
done
```

### step9

执行对拍程序，查看结果，Ac 为通过的测试用例。

```sh
$ cd ~/noip/junior-rep-23-2017-C++/jump/
$ sh ./jump.sh
```

执行结果如下：

```sh
jump1
Ac
jump2
Ac
jump3
Ac
jump4
Ac
jump5
Ac
jump6
Ac
jump7
Ac
jump8
Ac
jump9
Ac
jump10
Ac
```

### step10

动态规划到达当前位置花费最少金币数，进而得到全局最优解。

```cpp
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int n,d,k,dist[500005],value[500005];
long long coins[500005],inf;
int head,tail,deque[500005];  

bool check(int g){
    coins[0] = 0;
    deque[0] = 0;
    head = tail = 0;
    int pointer = 1;
    
    for(int i=1;i<=n;i++){
        while(pointer<=n && dist[pointer]<=min(dist[i]-1,dist[i]-d+g)){
            while(head<=tail && coins[deque[tail]] <=coins[pointer])  tail--;
            deque[++tail] = pointer++;
        }

        while(head<=tail && dist[deque[head]]<dist[i]-d-g)  head++;
            
        if(head<=tail && deque[head] <=dist[i]-d+g) 
            coins[i] = coins[deque[head]] + value[i];
        else
            coins[i] = -inf;
        
        if (coins[i]>k) return 1;
    }
    return 0;
}

int main(){
    freopen("jump.in","r",stdin);
    freopen("jump.out","w",stdout);
    
    inf = 1000000000;
    inf = inf * inf;
    
    long long sum = 0;
    cin >> n >> d >> k;
    for (int i=1;i<=n;i++){
        cin >> dist[i] >> value[i];
        if(value[i]>0) sum = sum + value[i];
    }
    
    if(sum < k){
        cout << -1 << endl;
        return 0;
    }
    
    int lg=0,rg=1000000000;
    while(lg<rg){
        int midg = (lg+rg)>>1;
        if(check(midg)) {
            rg = midg;
        }else{
            lg = midg + 1;
        }
    }
    
    cout << rg << endl;
    
    return 0;
}
```
