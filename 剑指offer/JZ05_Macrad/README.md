## 思路:  
1.确定是否在源字符串上修改，并且保证原位置后面有足够的空间  
2.双指针 复杂度O(n)

## 题目：
替换字符串中的空格为%20


##知识  
1.C++不检测数组越界问题，非常危险。你可以读取写入那些未知的位置；
但是会检测vector的越界问题，可能涉及申请连续内存的问题  ；
 
String 数组 string a[10],每一个位置既可以放字符也可放字符串，不会检查越界问题，即你可以在a[12]填入东西；
 
String a ，此时a[0]只能填字符。当初始化a={"kkkkk"},a[n]会检查下标越界问题。  
此时a.size不包括\0,但是可以通过下标访问并输出其ASCII值为0，
如果对于String输入一个数字，读入的是数字对应的ascii码以及其对应的字符。如输入64 存的为@。

2.本题使用insert可能带来的问题复杂度O(n^2)  

3.  使用这个方法找满足所有要求的空格。  
while((position=s.find(flag,position))!=string::npos)  
{  
       cout<<"position  "<<i<<" : "<<position<<endl;  
        position++;  
         i++;  
 }  
4.检测空字符串
不用空指针检测nullptr,可以用empty 或者 size==0,或者s[0]='\0'根据string的构造函数可知。  
但是数组可以用nullptr检测  
5.数组长度
char s[20] sizeof(s)/sizeof(s)=sizeof(char) 因为占一个字节  
6.注意数组下表是s[i++]=1， 先赋值再+1  
7.数组传参 都是传地址 对原数有影响 ；vector 可以传值（拷贝赋值） 引用 地址    
vec->vector<char>vec
vec->vector<char>& vec
&vec->vector<char>* vec
以下传递进行修改都会对数组有影响
s->char s[]
&s[0]->char *s (地址必须用指针接) 取第一个地址
s->char *s    同上  
8.memset
按照一个字节一个字节赋值，对于int数组初始化为0和-1  
本文char数组初始化为0就是0对应的ascii码‘\0’


