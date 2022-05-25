## 思路:  
1.前序节点指向后续节点，然后删除节点 （O(N)）
2.后续节点覆盖删除节点，并指向后续节点的后续节点，删除后续节点（O(1)）

## 题目：删除链表的节点  
给定单向链表的头指针和一个要删除的节点的值，定义一个函数删除该节点。返回删除后的链表的头节点

## 代码相关
* 前提是保证删除的节点在链表中;
* 对于头尾节点的处理;
* 对于图片提到的内存泄漏 可以通过将指针指向NULL解决以及及时的delete，但是确保你的指针是否开辟空间以及指向的位置谨慎delete;

  
    
<div align=center>
 链表的理解
</div>
<div align=center>
<img src="https://raw.githubusercontent.com/xhwhht/AlgorithmProblem_Study/main/%E5%89%91%E6%8C%87offer/Image/List.jpg" width="800px" alt="链表js">
</div>
