串(String)：<br/>
串是由零个或多个字符组成的有限序列，又名叫字符串。<br/>
一般记为 s="a1a2...an"(n>=0)，其中，s 是串的名称，用引号括起来的字符序列是串的值，注意引号不属于串的内容。<br/>
ai（1<=i<=n）可以是字母、数字或其他字符，i 就是该字符在串中的位置。串中的字符数目 n 称为串的长度。零个字符的串称为空串，它的长度为零。<br/>
<br/>

ASCII码由8位二进制数表示一个字符，总共可以表示256个字符；Unicode码由16位二进制数表示一个字符，总共可表示2^16约等于6.5万个字符。Unicode的前256个字符与ASCII码完全相同。

该demo实现了串的顺序存储结构(order.c)。
<br/>

order.c
```
Operation
    InitString(*chars)：生成一个其值等于字符串常量chars的串T
    StrCopy(T, S)：串S存在，由串S复制得串T
    ClearString(S)：串S存在，将串清空
    StringEmpty(S)：若串S为空，返回true，否则返回false
    StrCompare(S, T)：若S>T，返回值>0，若S=T，返回0，若S<T，返回值<0
    Concat(T, S1, S2)：用T返回由S1和S2连接而成的新串
    SubString(Sub, S, pos, len)：串S存在，用Sub返回串S的第pos个字符起长度为len的子串
    Index(S, T, pos)：若主串S中存在和串T值相同的子串，则返回它在主串S中第pos个字符之后第一次出现的位置，否则返回-1
    Replace(S, T, V)：用V替换主串S中出现的所有与T相等的不重叠的子串
    StrInsert(S, pos, T)：在串S的第pos个字符之前插入串T
    StrDelete(S, pos, len)：从串S中删除第pos个字符起长度为len的子串
```