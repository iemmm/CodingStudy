## 出现的错误
```
for(int i = 1; i < vec.size(); i++){
    if(vec[i-1] >= vec[i]) return false;
        }
```
在遍历判断数组是否递增的这段代码中第一次写的是：
```
for(int i = 0; i < vec.size(); i++){
            if(vec[i] >= vec[i + 1]) return false;
        }
```

第一次写这个for循环的时候没有把握好边界，这里有两个边界出现了错误，如果是i跟i+1作比较遍历的范围就应该是[0，vec.size()-1).如果是i跟i-1作比较，遍历的范围就应该是[1,vec.size())

