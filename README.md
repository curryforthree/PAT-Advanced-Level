# PAT-Advanced-Level

*准备浙大的机试 记录下过程和心得^_^*

+ a1002: cmp函数一定要保证能return，否则会导致段错误

+ a1003: 二维数组的fill，eg：G[maxn][maxn],  fill(G[0], G[0] + maxn * maxn)

  dijkstra算法： 考虑当最短路径有多条时，要求哪些参数（最短路径题往往还有第二指标，即除距离最短之外还要别的要求）。本题要求最短路径条数以及最大点权和。
