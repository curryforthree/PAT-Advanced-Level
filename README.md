# PAT-Advanced-Level

*准备浙大的机试 记录下过程和心得^_^*

+ a1002: cmp函数一定要保证能return，否则会导致段错误

+ a1003: 二维数组的fill，eg：G[maxn][maxn],  fill(G[0], G[0] + maxn * maxn)

  dijkstra算法： 考虑当最短路径有多条时，要求哪些参数（最短路径题往往还有第二指标，即除距离最短之外还要别的要求）。本题要求最短路径条数以及最大点权和。


+ a1101: 有个别测试点不满足的时候要考虑边界情况，本题0的情况要加\n，

  快排中确定主元：当元素位置与排序结果相比没有变化并且在结果序列中它左边的所有值的最⼤大值都⽐ 比它⼩的
  时候就可以认为它可以是主元

+ a1102：二叉树的静态表示法：

  ```
  struct node{
    typename data;
    int l;
    int r;
          // 还可以添加其他的一些属性
  } Node[maxn]; // maxn 为最大节点数
  ```

  输入时要注意字符与数字之间的转换。

+ a1103  DFS + 剪枝

+ a1104   

   !!! double * int * int 与 int * int * double 可能会有区别。int * int * double时  int * int 可能溢出。

+ a1105

+ a1106  树的遍历

  普通的树的表示
  ```
  vector<int> child[maxn]  // maxn为最大结点数， 如果有点权可以用结构体

  ```
+ a1107 并查集


+ a1111 最短路径   

  dijkstra算法在代码实现时关键有两个：*1、用来表示顶点是否已访问的集合 可以用一个bool型的数组来实现；2.起点到任一顶点的最短距离，int型数组来实现。这两个就可以实现最短距离的求解。*

  如果需要求解最短路径还需要一个数组pre来记录前驱结点。

  求解最短路径的题目往往还有第二标尺，一种通用的解决方法是  *dijkstra+DFS*。

  *step1：先在dijkstra算法中记录下所有的最短路径（只考虑距离）。*

  为了适应多个前驱的情况，需要把pre数组定义为vector类型

  ```
  vector<int> pre[maxn];           // pre数组的定义方式
  ```
  这样对于每个结点来说，pre[v]就是一个vector，里面用来存放v的所有能产生最短路径的前驱结点。
  tips：如果题目需要查询某个顶点u是否在v的前驱中，可以用set来代替vector，此时用pre[v].count(u)来查询较为方便。

  *step2：遍历所有最短路径，找出一条使第二标尺最优的路径*
  遍历的过程会形成一颗递归树，



+ a1112 map映射+set集合

  注意题目的输出要求：in the order of ...
  一开始没有注意题目的输出的要求，调试了很久。

  如果记录需要确保不会重复输出～（用set集合，输出过了的放在set⾥⾯,输出时检查set里是否有记录）

+ a1113 排序

+ a1114 并查集
  需要用两个结构体数组，一个用来接收输入，一个处理最终的结果。（如果内存限制不严格可以将结构体数组开大一些，其id对应下标，用起来方便些）。输入同时，进行Union操作。本题要求：每个集合中id最小的那个，可以将最小的id设为根，对应的Union函数这样写:
  ```
  void Union(int a, int b) {
    int faA = find(a);
    int faB = find(b);
    if(faA > faB)
        father[faA] = faB;
    else if(faA < faB)
        father[faB] = faA;
  }
  ```
  注意在输入时有的结点有可能重复， 可以用set来处理，（set只能用迭代器来访问）。

+ a1115 BST + DFS遍历
  用一个数组countNode[maxn] 来记录每一层的结点数，作为DFS的一个参数来维护

+ a1116 简单逻辑题

+ a1117 简单逻辑题

+ a1118 并查集
  本题如果不用路径压缩，会有一个测试点超时

+ a1119 二叉树的树的遍历 由遍历序列确定树

  若已知后序与中序输出先序，无需构造二叉树再遍历！   //来源柳神blog  https://www.liuchuo.net/archives/2090

  已知后序与中序输出前序（先序）：

  后序：3, 4, 2, 6, 5, 1（左右根）

  中序：3, 2, 4, 1, 6, 5（左根右）

  分析：因为后序的最后一个总是根结点，令i在中序中找到该根结点，则i把中序分为两部分，左边是左子树，右边是右子树。因为是输出先序（根左右），所以先打印出当前根结点，然后打印左子树，再打印右子树。左子树在后序中的根结点为root – (end – i + 1)，即为当前根结点位置-右子树的个数-1。左子树在中序中的起始点start为start，末尾end点为i – 1.右子树的根结点为当前根结点的前一个结点root – 1，右子树的起始点start为i+1，末尾end点为end。

  ！！！后序与前序序列的的作用只是为了获取根节点，所以递归函数参数中关于先序/ 后序的参数只写其root的位置就好啦~，关于中序的参数嘛，开头和结尾都还是要写的~

  输出的前序应该为：1, 2, 3, 4, 5, 6（根左右）

  ```
  #include <cstdio>
  using namespace std;
  int post[] = {3, 4, 2, 6, 5, 1};
  int in[] = {3, 2, 4, 1, 6, 5};
  void pre(int root, int start, int end) {
      if(start > end) return ;
      int i = start;
      while(i < end && in[i] != post[root]) i++;
      printf("%d ", post[root]);
      pre(root - 1 - end + i, start, i - 1);
      pre(root - 1, i + 1, end);
  }

  int main() {
      pre(5, 0, 5);
      return 0;
  }
  ```

  关于本题，关键是如何判断是否唯一，当preorder的第二个和postorder的倒数第二个结点值相等时说明只有一颗子树。此时不唯一，题目要求只要输出一种形态，统一处理成右子树即可（即，无左子树，无需向左子树递归，设置flag不唯一）。
  在递归函数中，关键是确定左(右)子树在pre与post中的范围。

+ a1120 stl的应用

  string a; a[i]是char型

+ a1121

   couple数组初值 不能是0！ 因为有可能编号有0的人！

+ a1122 图   判断给定的路径是不是哈密尔顿路径

  设置flag1 判断节点是否多走、少走、或走成环

  设置flag2 判断这条路路能不能走通

  关于flag1 ，用set来记录路径上的每一个结点，最终set的长度应该是顶点数；
  若这条路径长度不等于顶点数 + 1，说明多走或少走；开头结点应该和结尾结点一样；

+ a1123 AVL树

  由于要对每个结点获取平衡因子，需要在树的结构体中加入一个变量height，表示以当前结点为根结点的子树的高度。

  ```
  struct node {
    int v, height;          // v是权值，height是当前子树高度
    node* l, r;             
  }
  ```
  此时新建一个结点，其height要设为1；

  可以通过下面的一个函数来获得结点root所在子树的当前高度
  ```
  int getHeight(node* root){
    if(root == NULL) return 0;
    return root->height;
  }
  ```

  计算平衡因子
  ```
  int getBalanceFactor(node* root){
    return getHeight(root->l) - getHeight(root->r);
  }
  ```

   在插入结点后要更新树的高度
   ```
   void updateHeight(node* root){
       root->height = max(getHeight(root->l), getHeight(root->r)) + 1;
   }
   ```
   左旋
   ```
   void L(node* &root){             // 返回值void，由于树形要改变要加&
     node* temp = root->r;    
     root->r = temp->l;
     temp->l = root;
     updateHeight(root);        // 更新两个变化的结点高度
     updateHeight(temp);        //这两句不能忘 先更新下面的结点（root）
     root = temp;
   }
   ```
   右旋同理

   关于判断是否是完全二叉树，有以下几个方法

   1.总结点数为n，从第1个结点 到第n / 2 - 1个结点都应该有左右孩子， 第 n / 2个结点应该有左孩子。（注意第n / 2个判断）

   2.每次入队count++；如果左子树或者右子树为空，则判断入队结点的总数是否是整个树的结点。

+ a1124 map

  如果用户中过奖，mapp[id] = 1

  设置一个变量s，表示下次应该去判断哪个位置是否中奖，外层循环变量i 若等于s，就看mapp[id] == 0 若满足就输出 ，s += n；若不满足则不输出 s += 1；

+ a1125  贪心

  每次长度都要减半， 最开始的肯定减半的最多， 所以开始的越短越好

+ a1126 图论

  题目的叙述是这样的

  It has been proven that connected graphs with all vertices...

  所以一定要判断图是联通图！！！DFS遍历，每遍历一个结点Count++，看最终结果是不是总的结点数。

  对于结点的度。⽤邻接表存储图，判断每个结点的度【也就是每个结点i的v[i].size()】是多少,即可得到最终结果

  ```
  vector<vector<int>> v;
  v.resize(n + 1);      //结点从1~n
  ```
