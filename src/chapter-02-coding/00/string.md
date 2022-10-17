
## 字符串

### C 语言

```C {.line-numbers}
#include <cstring>/<string.h>

char str[1000]
```
```C {.line-numbers}
strcpy(s1, s2);         //复制字符串 s2 到字符串 s1。
strcat(s1, s2);         //连接字符串 s2 到字符串 s1 的末尾。连接字符串也可以用 + 号，例如:
strlen(s1);             //返回字符串 s1 的长度。
strcmp(s1, s2);         //如果 s1 和 s2 是相同的，则返回 0；如果 s1<s2 则返回值小于 0；如果 s1>s2 则返回值大于 0。
strchr(s1, ch);         //返回一个指针，指向字符串 s1 中字符 ch 的第一次出现的位置。
strstr(s1, s2);         //返回一个指针，指向字符串 
memcpy(b,a,sizeof(a));  //数组复制
```

### C++

```C++ {.line-numbers}
#include <string>

string str1 = "runoob";
string str2 = "google";
string str3;
int  len ;

// 复制 str1 到 str3
str3 = str1;
cout << "str3 : " << str3 << endl;

// 连接 str1 和 str2
str3 = str1 + str2;
cout << "str1 + str2 : " << str3 << endl;

// 连接后，str3 的总长度
len = str3.size();
cout << "str3.size() :  " << len << endl;

// >、<、==、>=、<=、!= 比较
cout << str1 == str2
```

compare() 函数 s.compare {pos,n, s2);
若参与比较的两个串值相同，则函数返回 0；若字符串 S 按字典顺序要先于 S2，则返回负值；反之，则返回正值。
```C++ {.line-numbers}
int compare (const basic_string& s) const;
int compare (const Ch* p) const;
int compare (size_type pos, size_type n, const basic_string& s) const;
int compare (size_type pos, size_type n, const basic_string& s,size_type pos2, size_type n2) const;
int compare (size_type pos, size_type n, const Ch* p, size_type = npos) const;

cout << str1.compare(str2)
```
