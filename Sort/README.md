排序：<br/>
假设含有n个记录的序列为 {r1,r2,...,rn}，其相应的关键字分别为 {k1,k2,...,kn}，需确定 1,2,...,n 的一种排列 p1,p2,...,pn，使其相应的关键字满足 kp1<=kp2<=...<=kpn（非递减或非递增）关系，即使得序列成为一个按关键字有序的序列 {rp1,rp2,...,rpn}，这样的操作就称为排序。
<br/>
<br/>

该demo实现冒泡排序(bubble.c)、简单选择排序(simple.c)、直接插入排序(insert.c)、希尔排序(shell.c)、堆排序(heap.c)、归并排序(merging.c)、快速排序(quick.c)。
<br/>
<br/>

gcc bubble.c list.c -o bubble<br/>
gcc simple.c list.c -o simple<br/>
gcc insert.c list.c -o insert<br/>
gcc shell.c list.c -o shell<br/>
gcc heap.c list.c -o heap<br/>
gcc merging.c list.c -o merging<br/>
gcc quick.c list.c -o quick<br/>