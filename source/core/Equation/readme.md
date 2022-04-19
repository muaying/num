# 非线性方程解求根

## 二分法

![image-20220412210630025](img/image-20220412210630025.png)

```c
输入区间a,b，函数f(x)，及误差控制e

while (|a-b|>e) do
  x=(a+b)/2
  if (|f(x)|<e)  return x; // 找到根为x
  else if (f(a)*f(x)<0) b=x; // 根在区间[a,(a+b)/2]
  else if (f(b)*f(x)<0) a=x; // 根在区间[(a+b)/2,b]
end while
return (a+b)/2 // 还没有找到根，但b-a已经足够小了
```

