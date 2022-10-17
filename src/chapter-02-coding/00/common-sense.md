## 常用知识点

### 进制表示

```C {.line-numbers}
int a   = 0b100;    //二进制 4
int b   = 0100;     //八进制 64
int c   = 100;      //十进制 100
int d   = 0x100;    //十六进制 256

int a = 100;
printf("%b\n",a);   \\%b 二进制
printf("%o\n",a);   \\%o 八进制
printf("%d\n",a);   \\%d 十进制
printf("%x\n",a);   \\%x 十六进制
```

### 数组初始化

1. `int a[100] = {0};`  //可能只初始化a[0]位
2. 循环初始化
    ```C {.line-numbers}
    for(int i=0;i<sizeof(a)/sizeof(a[0]);i++)
        a[i] = 0;
    ```
    ```C {.line-numbers}
    for(int i=0;i<leng;i++)
        a[i] = value;
    ```
3. memset 初始化
    ``` C {.line-numbers}
    # include <cstring>
    ```
    - memset是按照字节进行赋值，即对每一个字节赋相同值，可以对数组进行整体赋值。
    ```C{.line-numbers}
    memset(a,0,sizeof(a));
    ```

### 最大值与最小值

#### include \<cstring\>/\<string.h>

##### int a[100]; // int类型范围：-2147483648～2147483647

```C {.line-numbers}
memset(a,127,sizeof(a)) //全部初始化为int的较大值，即2139062143(int 最大值为2147483647)；
memset(a,0,sizeof(a))   //全部初始化为0；
memset(a,-1,sizeof(a))  //全部初始化为-1；
memset(a,128,sizeof(a)) //全部初始化为一个很小的数，比int最小值略大，为-2139062144。
```
##### double a[100]; //double类似范围为：-1.7e+308～1.7e+308

```C {.line-numbers}
memset(a,127,sizeof(a))   //全部初始化为一个很大的数1.38e+306；
memset(a,0,sizeof(a))     //全部初始化为清0；
memset(a,128,sizeof(a))   //全部初始化为一个很小的数-2.93e+306。
```

#### 变量

```C {.line-numbers}
int maxx = 0x7fffffff;  //2147483647
int minn = 0x80000000;  //-2147483648
```

#### include \<climits>/<limits.h>

##### 最大值

```C {.line-numbers}
INT_MAX         //int
CHAR_MAX        //char
SHRT_MAX        //short
LONG_MAX        //long
LLONG_MAX       //long long
SCHAR_MAX       //signed char
UCHAR_MAX       //unsigned char
USHRT_MAX       //unsigned short
UINT_MAX        //unsigned int
ULONG_MAX       //unsigned long
ULLONG_MAX      //unsigned long long
```
##### 最小值

```C {.line-numbers}
CHAR_MIN        //char
SHRT_MIN        //short
INT_MIN         //int
LONG_MIN        //long
LLONG_MIN       //long long
SCHAR_MIN       //unsigned char
```

### 类型转换

#### include \<cstdlib>/\<stdlib.h>

##### int atoi(const char *str)

把参数 str 所指向的字符串转换为一个整数（类型为 int 型）

```C {.line-numbers}
char str[20];
int val = atoi(str);
```

##### char *itoa( int value, char *string,int radix)

value：欲转换的数据。
string：目标字符串的地址。
radix：转换后的进制数，可以是10进制、16进制等，范围必须在 2-36。

功能：将整数value 转换成字符串存入string 指向的内存空间 ,radix 为转换时所用基数(保存到字符串中的数据的进制基数)。

返回值：函数返回一个指向 str，无错误返回。

```C {.line-numbers}
#include <cstdlib>

int a = 123;
char str[10];
itoa(a,str,10);
```

#### 字符数组转 string  

```C {.line-numbers}
#include <string>   //不是 include <cstring> 或 include <string.h>

char */char [] p = "abcde";
string str = p;

char p[100] = "abcde";
string str = p; = "abcde"
```

#### string 转 char *

```C {.line-numbers}
string p = "abcded";
const char o[100] = p.c_str(); //必须是const
```

#### string 转 int

```C {.line-numbers}
string s = "12"
int a = atoi(s.c_str())
```

#### int 转 string

```C {.line-numbers}
include <string>

int i=12
string s = to_string(i)
```

#### int sscanf(const char *buffer, const char *format, [argument ]...) 把各种数据按格式生成字符串

把某const char* 的数据给指定 char* 变量；

```C {.line-numbers}
char buf[512] ;
sscanf("123456 ", "%s", buf);
printf("%s\n", buf);
```
结果为：123456

```C {.line-numbers}
sscanf("123456 ", "%4s", buf);
printf("%s\n", buf);
```
结果为：1234

#### int sprintf(char *buffer, const char *format, [argument] … )

用 sprintf可以把整数、浮点数转为字符串，把数据输入到指定char*

```C {.line-numbers}
sprintf(s, "%d", 123);      //把整数123打印成一个字符串保存在s中,
sprintf(s, "%8x", 4567);    //小写16进制，宽度占8个位置，右对齐
sprintf(buf, "fdsafsdf");
```
```C {.line-numbers}
char a = 'a';    
char buf[100];
sprintf(buf, "The ASCII code of a is %d.", a);
print("%s",buf);            // The ASCII code of a is a
```
```C {.line-numbers}
int n = 12345;//待转整数
char strN[50];//转换后的字符串
sprintf(strN, "%d", n);
```
```C {.line-numbers}
float n = 12345.67;//待转整数
char strN[50];//转换后的字符串
sprintf(strN, "%.2f", n);
```

### 变量的作用范围


#### main 函数外定义的全局变量与函数内部定义的变量

```C {.line-numbers}
#include <iostream>
using namespace std;

int a[100];

int main(){
    int b[100];
}
```
a和b有什么不同?
1. a 在堆中申请空间，可以很大64MB，b在栈中申请，空间比较小
2. a 全程使用，b只能在main中使用，在和main的平行函数中无法使用
3. a 自动初始化为0，b值随机

#### 作用域与作用范围

1· 区域内定义的变量只对本区域或子区域管用
2. 父子区域同名，子区域覆盖父区域

```C {.line-numbers}
int abc(int a){
    int i;
}

int main(){
    int i=100;

    for (;i<1000;i++){
        b = i * 2;
        cout << b << endl;
    }

    a = i*2;    //2000

    return 0;
}
```

### 时间

```C {.line-numbers}
#include <ctime>/<time.h>

clock_t start
clock_t finish

start = clock()
finish = clock()

double usetime = (double)(finish-start)/CLOCKS_PER_SEC
```
```C {.line-numbers}
#inlcude <iostream>
#incldue <ctime>

clock_t start;
clock_t finish;

int main(){
    int sum = 0;

    start = clock();
    for(int i=0;i<100;i++){
        a = a + i;
    }
    finish = clock();
    double usetime = (double)(finish-start)/CLOCKS_PER_SEC;

    printf("usetime is %lf second.",usetime);

    return 0;
}
```

### 随机数

```C {.line-numbers}
include <ctime>/time.h
include <cstdlib>/stdlib.h

srand((unsigned)time(NULL)); //初始化随机种子

x = (long long) rand();
int r = rand();
```

### sort

基本用法：
```C {.line-numbers}
#include <algorithm>

int a[1000]

bool cmp(int a,int b){
    return a > b;
}

int main(){
    sort(a,a+1000)
    sort(a,a+100,cmp)
    return 0;
}
```

#### sort 对任意数组排序

```C {.line-numbers}
int a[1000]
sort(a,a+1000); //升序
```

#### sort 数值降序排序

```C {.line-numbers}
#include<algorithm>  
using namespace std;

bool cmp(int a,int b) {  
    return a>b;  
} 

int main() {  
    int a[10]={2,5,3,0,1,5,6,2,8,4};  

    printf("排序前:");  
    for(int i=0;i<10;i++)  
        printf("%d ",a[i]);
    printf("\n");  

    sort(a,a+10,cmp);  
    
    printf("排序后:");  
    for(int i=0;i<10;i++)  
        printf("%d ",a[i]);  
    printf("\n");

    return 0;  
}
```

#### sort ASCII升序排序

```C {.line-numbers}
#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(char a,char b){
    return a < b;
}

int main(){
    char s[10];
    int i;
    while(cin>>s){
        for(i=0;i<3;i++)
            sort(s,s+3,cmp);
        for(i=0;i<2;i++)
            cout << s[i] << ' ';
        cout << s[2] << endl; 
    }
}
```

#### sort函数对结构体进行排序

```C {.line-numbers}
#include<algorithm>  
using namespace std;  
struct student  {  
    int grade;  
    int num_id;  
}stu[10];  

bool cmp(struct student a,struct student b)  {  
    if(a.grade!=b.grade)  
        return a.grade>b.grade;      //若成绩不相等，按成绩降序   
    else  
        return a.num_id>b.num_id;    //若成绩相等，按学号降序   
}  

int main() {  
    for(int i=0;i<10;i++)  
        scanf("%d %d",&stu[i].grade,&stu[i].num_id);  
    
    sort(stu,stu+10,cmp);  
    
    printf("成绩\t\t学号\n");  
    for(int i=0;i<10;i++)  
        printf("%d\t\t%d\n",stu[i].grade,stu[i].num_id);  
    
    return 0;  
}
```

#### sort函数对pair数组进行排序如

```C {.line-numbers}
typedef pair<int,int> P; 

bool cmp(const P &a, const P &b){   //P为pair数组  
    if (a.first < b.first)  
        return true;  
    else 
        return false;  
}
```

#### sort函数对字符数组进行排序

```C {.line-numbers}
#include<stdio.h>  
#include<string.h>  
#include<algorithm>  
using namespace std;

struct student  {  
    char stuID[10];  
    char name[10];  
    int grade;  
}stu[100005];  

bool cmp1(struct student a,struct student b) {  
    return strcmp(a.stuID,b.stuID)<0;  
}  

bool cmp2(struct student a,struct student b) {  
    if(strcmp(a.name,b.name)==0)  
        return strcmp(a.stuID,b.stuID)<0;  
    else  
        return strcmp(a.name,b.name)<0;  
}  

bool cmp3(struct student a,struct student b) {  
    if(a.grade==b.grade)  
        return strcmp(a.stuID,b.stuID)<0;  
    else  
        return a.grade<b.grade;  
}  

int main() {  
    int i,n,c,k=0;  
    while(scanf("%d %d",&n,&c),n,c)  {  
        for(i=0;i<n;i++)  
            scanf("%s %s %d",&stu[i].stuID,stu[i].name,&stu[i].grade);  
        if(c==1)  
            sort(stu,stu+n,cmp1);  
        else if(c==2)  
            sort(stu,stu+n,cmp2);  
        else if(c==3)  
            sort(stu,stu+n,cmp3);  

        printf("Case %d:\n",++k);  
        for(i=0;i<n;i++)  
            printf("%s %s %d\n",stu[i].stuID,stu[i].name,stu[i].grade);  
    }  
    return 0;  
}  

```


