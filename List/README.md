线性表(List)：<br/>
零个或多个数据元素的有限序列。线性表的数据对象集合为{a1,a2,..,an}，其中，除第一个元素a1外，每个元素有且有一个直接前驱元素，除了最后一个元素an外，每个元素有且只有一个直接后续元素。
<br/>
<br/>

该demo实现了顺序存储线性表(order.c)、单链表(single.c)、双向链表(double.c)、链栈(stack.c)、队列(queue.c)。
<br/>
<br/>

order.c、single.c、double.c
```
Operation
    InitList(*L)：初始化操作，建立一个空的线性表L
    ListEmpty(*L)：若线性表为空，返回true，否则返回false
    ClearList(*L)：将线性表清空
    GetElem(*L, i, *e)：将线性表L中的第i个位置元素值返回给e
    LocateElem(*L, e)：在线性表L中查找与给定值e相等的元素，成功则返回该元素在表中序号，失败返回0
    ListInsert(*L, i, e)：在线性表L中的第i个位置插入新元素e
    ListDelete(*L, i, *e)：删除线性表L中的第i个位置元素，并用e返回其值
```
<br/>
<br/>

stack.c
```
Operation
    InitList(*L)：初始化操作，建立一个空的栈L
    ListEmpty(*L)：若栈为空，返回true，否则返回false
    ClearList(*L)：将栈清空
    GetTop(*L, *e)：若栈存在且非空，用e返回L的栈顶元素
    Push(*L, e)：若栈L存在，插入新元素e到栈L中并成为栈顶元素
    Pop(*L, *e)：删除栈L中栈顶元素，并用e返回其值
    LinkLength(L)：返回栈L的元素个数
```
<br/>
<br/>

queue.c
```
Operation
    InitList(*L)：初始化操作，建立一个空的队列L
    ListEmpty(*L)：若队列为空，返回true，否则返回false
    ClearList(*L)：将队列清空
    GetTop(*L, *e)：若队列存在且非空，用e返回L的队头元素
    Push(*L, e)：若队列L存在，插入新元素e到队列L中并成为队尾元素
    Pop(*L, *e)：删除队列L中队头元素，并用e返回其值
    LinkLength(L)：返回栈L的元素个数
```