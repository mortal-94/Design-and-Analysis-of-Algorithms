# Design-and-Analysis-of-Algorithms
记录算法设计与分析课程的学习

- [分而治之.md](divide-and-conquer/分而治之.md)  

- [动态规划.md](dynamic-programming/动态规划.md) 

- [贪心算法.md](greedy-algorithm/贪心算法.md) 

- [图算法.md](graph-algorithm/图算法.md)  

- [回溯算法与分支界定法.md](Backtracking-and-Branch-and-Bound/回溯算法与分支界定法.md) 

- [随机算法.md](random-algorithm/随机算法.md) 

- [P与NP.md](P-and-NP/P与NP.md) 

## 五符号：$O、\Omega、\Theta、o、\omega$

$n$ 为问题规模； $T(n)$ 为求解问题算法的复杂性； $g(n)$ 为定义在正数集上的正函数。

极限 $\alpha=\lim\limits_{n \to \infty}\frac{\max T(n)}{g(n)}$ ， $\beta=\lim\limits_{n \to \infty}\frac{\min T(n)}{g(n)}$ 。非零常数 $c$ 。五符号定义如下： $T(n)=$

**$O(g(n))$ ：渐进上界； $\alpha=c$ ；复杂性不超过 $g$ 的阶； $\le$** 

$\Omega(g(n))$ ：渐进下界； $\beta=c$ ；复杂性不低于 $g$ 的阶； $\ge$

$\Theta(g(n))$ ：渐进紧确界； $\alpha=\beta=c$ ；复杂性为 $g$ 阶； $=$

$o(g(n))$ ：非紧渐进上界； $\alpha=0$ ；复杂性小于 $g$ 的阶；$<$

$\omega(g(n))$ ：非紧渐进下界； $\beta=0$ ；复杂性大于 $g$ 的阶； $>$



```
O(1)（常数）<O(log n) （对数）<O(n) （线性）<O(n log n) （对数线性）<O(nᵏ) （多项式）<O(kⁿ)（指数）<O(n!) （阶乘）
```

## 算法的性质

输入、输出、有穷性、确定性、可行性
