### 题目：反转链表  
定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节  

### 思路:       
* 使用双指针暂存进行替换  
* 递归的方法 (对内存消耗较大)  
> 1.  当结束压栈时，返回的pre即指向原链表最后一个结点，在弹出的全部过程中res一直未变为pre ;   
> 2.  结束的标致cur=null （这个是由倒数第二个结点cur(b2)->next传入,cur(b2)指向最后一个结点）此时返回pre就是指向最后一个结点；
      此时唤起倒数第二个结点。传入参数(cur(b2)指向最后一个结点,pre) cur(b2)->next=pre（指向倒数第二个结点）此时实现反向；
