### 题目：滑动窗口的最大值  
给定一个数组 nums 和滑动窗口的大小 k，请找出所有滑动窗口里的最大值。


### 思路:           
* 使用双向队列 单调递减的维护窗口内的最值（次大值）  
*  形成单调递减窗口+窗口滑动（维护单调递减+删除已经出窗的最大值）  
*  栈和队列+单调序列 非常适合维护当前最大最小值  
* queue和deque的区别:https://blog.csdn.net/weixin_64393298/article/details/122688810
* deque常用的 pop_front/back   push_front/back  front/back  
