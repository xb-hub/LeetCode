# 1.两数之和
1. [Hash Table](https://blog.csdn.net/yyyljw/article/details/80903391)
2. > 可以使用map创建哈希表<br>
   > [map用法](https://www.jianshu.com/p/f5d14a37d005)<br>
   ```
    m.count(k);  // 返回m中键值等于k的元素的个数。
    m.find(k);  // 如果m中存在按k索引的元素，则返回指向该元素的迭代器。如果不存在，则返回结束游标end()。
    ```
方法        | 总结
| :-----:  | :----: 
两遍哈希表法 | 使用两次迭代。在第一次迭代中，我们将每个元素的值和它的索引添加到哈希表map中。然后，在第二次迭代中，我们将检查每个元素所对应的目标元素（target - nums[i]target−nums[i]）是否存在于表中。**注意，该目标元素不能是 nums[i]nums[i] 本身！**
一遍哈希表法 | 在进行迭代并将元素插入到表中的同时，我们还会回过头来检查表中是否已经存在当前元素所对应的目标元素。如果它存在，那我们已经找到了对应解，并立即将其返回。