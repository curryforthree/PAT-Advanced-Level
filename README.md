# PAT-Advanced-Level刷题笔记

*准备浙大的机试 记录下过程和心得^_^*

+ a1002: cmp函数一定要保证能return，否则会导致段错误

+ a1003: 二维数组的fill，eg：G[maxn][maxn],  fill(G[0], G[0] + maxn * maxn)

dijkstra算法： 考虑当最短路径有多条时，要求哪些参数（最短路径题往往还有第二指标，即除距离最短之外还要别的要求）。本题要求最短路径条数以及最大点权和。


+ a1101: 有个别测试点不满足的时候要考虑边界情况，本题0的情况要加\n，

快排中确定主元：当元素位置与排序结果相比没有变化并且在结果序列中它左边的所有值的最⼤值都⽐它⼩的时候就可以认为它可以是主元

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

！！！后序与前序序列的的作用只是为了获取根节点，所以递归函数参数中关于先序/ 后序的参数只写其root的位置就好啦，关于中序的参数嘛，开头和结尾都还是要写的~

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

+ a1128 逻辑题

判断N皇后问题所给出的序列是否满足要求；由于保证了不在同一列；只要判断是否存在两个或多个在同一行（（v[j]== v[t]）或者是在斜对⻆线上的（abs(v[j]-v[t]) == abs(j-t) )(行和列相差的绝对值相同)

+ a1129 set + 运算符重载（overload）

C++中，结构体是无法进行==，>，<，>=，<=，!=这些操作的，这也带来了很多不方便的地方，尤其是在使用STL容器的时候。

本题对结构体重载 <,这样set中的结构体就会按照自定义的方式进行重排。

set<node> s;

查找/插入时 ： s.insert(node{实参 , 实参 ,...})

+ a1130 dfs

中序遍历。注意处理括号。如果不是根节点或者叶节点，那么遍历其左子树之前应该加上(，遍历其右子树后加上)。即二叉树的根节点和叶子结点不需要输出括号~

一开始写的分情况的中序朴素写法，有两个点过不了，是因为有可能根结点有可能是有左右儿子，也有可能只有右儿子。处理根结点的外层不能有括号。

+ a1131

+ a1132 STL

一定要判断除数是否是0

+ a1133 链表

1.所有节点用结构体｛id, data, next｝存储

2.遍历链表，找出在此链表中的节点，放入容器器v中

3.把节点分三类｛（-无穷，0）, [0,k], (k,+无穷) ｝,把他们按段，按先后顺序依次放进容器ans中，最后输出即可～

+ a1134 hash散列

记录点属于的边！

用vector v[n] 保存某结点属于的某条边的编号，比如a、b两个结点构成的这条边的编号为0，就v[a].push_back(0),v[b].push_back(0)。 表示a属于0号边，b也属于0号边。而边的编号就在输入的时候自然形成了。

在判断集合的时候，遍历集合的每一个元素，每个元素对应哪些边i，hash[i]设为1,表示这条边满足一个顶点出自集合中。

map可以直接赋值：mp1 = mp2;


+ a1135 树

descendant(后代)

判断一颗树是否是红黑树，不要被红黑树吓着，按照题目的意思进行判断即可。

+ a1136 字符串处理

本题的输入不是一个int，而是一个最高1000位的数字，用string来处理。开始读题不仔细用的int，有两个点没有通过。

本题可以写一个简化版的大整数加法。因为两个加数的位数是相同的。可以从后往前每一位相加，配合进位位来判断。

```
string add(string s1, string s2) {
    string s = s1;
    int carry = 0;
    for (int i = s1.size() - 1; i >= 0; i--) {
        s[i] = (s1[i] - '0' + s2[i] - '0' + carry) % 10 + '0';
        carry = (s1[i] - '0' + s2[i] - '0' + carry) / 10;
    }
    if (carry > 0) s = "1" + s;
    return s;
}
```
+ a1137 map映射

用map来存储姓名（string)对应在v数组中的下标。

读入三个成绩，如果第一项成绩不存在直接跳过即可。之后的两个成绩如果

+ a1138 树

不用建树，直接对前中序序列递归处理生成后序序列即可

+ a1139 水题

按照题目意思来进行存储即可，两个人的关系可以用二维数组存储（邻接矩阵），同性朋友可以用vector来存储（邻接表）

自己在写的时候，测试点1，2过不了，经过测试发现测试点1，2的输入存在0000或者-0000的情况，因为是用int来接收的，所以就无法区别0号的性别是男是女！

边的表示方法可以用两个顶点来表示，比如顶点编号最大为4位，就可以用

```
  10000 * a + b
```

来表示边

+ a1140 
t
开始以为是看每一位数字有几个，推算了一下发现不对，再看看题目是look and say sequence，就想到了边看边说，原来是从前往后数，比如1122233，就是两个1三个2两个3。所以下一个就是122332。。。。

+ a1141

自己是将读到的学校名字转化为对应的idx，放在一个map里面，避免0号与不存在冲突，所以map的下标是从1开始。但是排序的时候，尽量要避免不存在的元素一起排，这题有可能有某个学校num是1，但是总分是0，这样排序就在num为0，总分是0 的学校（即第一个位置实际不存在的学校）后面了。

也可以采用柳神的思路，先用两个map存 某学校名称对应的参赛人数和某学校对应的加权成绩。最后统一加在结构体中push_back()到ans中。另外，加权总分是对最终的结果取整，而非每一次都取整。

如果map超时，改用unordered_map即可

+ a1142

按照题目说的去验证就好，没有啥算法。。。

先判断是否是clique，即判断是否任意两边都相连；之后判断是否是maximal，即遍历所有不在集合中的剩余的点，看是否存在⼀一个点满⾜足和集合中所有的结点相连，最后如果都满⾜，那就输出Yes,表示是Maximal clique～

+ a1143

注意题中的题设要求是一颗BST，两个结点一定在他们的的LCA的两侧，或者其中一个就是另一个的祖先，可以按照BST的性质去找到他们的LCA，即左子树的根结点一定是第一个小于当前根的结点，右子树的根结点一定是第一个大于当前根的结点，如果找到一个大于等于小的，小于等于大的就找到了！

还可以直接遍历前序序列，将当前结点标记为a，如果u和v分别在a的左、右，或者u、v其中⼀一个就是当前a。

+ a1144

直接开HashTable的话有可能太大了，将每个数字出现的次数存储在map⾥面，num从1开始，如果m[num] == 0说明不存在，则输出这个num

+ a1145

⾸先根据v[0]和v[1]的⼤小比较判断可能是⼤顶还是小顶，别赋值flag为1和-1，先根据层序遍历，从0
～(n-1)/2【所有有孩⼦子的结点】判断他们的孩⼦是不是满足flag的要求，如果有⼀个结点不满足，那就
将flag=0表示这不是一个堆.


### 下面是按照《算法笔记》 中的题目分类来进行整理的

####ch3入门模拟

##### 3.1简单模拟

+ a1042

建立初始数字序列与初始扑克牌号的映射关系，自己生成的映射关系（以及题目中输入的格式大小写等）一定要检查是否正确，不能让这样的无意义的失误影响结果

+ a1046

所有结点连成一个环形，可以直接用dis[i] 记录从第1个结点到第i个结点的距离，dis[1]就是0，相当于有一个数组元素浪费了，没有用，这样最后一段距离没有得到记录，记录一个总的距离，就可以弥补。

还可以用dis[i] 表示第1个结点到第i + 1个结点的距离。这样所有的数组元素就都没有浪费。（最后一个dis[n]表示的是整个环的长度）

+ a1065

a + b 的值要放到long long变量sum后才可以与c进行比较，而不可以直接与c进行比较！！！！否则最后两组数据会出错

溢出的边界需要计算，以本题为例，输入范围[-2^63, 2^63），a + b最大值均为2^63 - 1, 故a + b最大为2 ^ 64 - 2 ,将其对2 ^ 64取模得 -2，得右边界为-2，同理，a + b最小值均为-2^63, 故a + b最小为-2 ^ 64，将其对2 ^ 64取模得0，得左边界为0。所以本题正溢出后值是负的，负溢出后值可能是0，也可能是正的。

+ a1002

用一数组c表示多项式，c[i]表示指数为i的项系数。

+ a1009

注意：因为相乘后指数可能最大为2000，所以ans数组最大要开到2001！！！！
##### 3.2 查找元素

+ a1011

以三个数一组的形式读取，读取完一组后输出最大值代表的字母，然后同时ans累乘该最大值。最后根据公式输出结果。

注意累乘的初值是1！

+ a1006

将所有时间转化为秒数，方便比较早晚。边输入边比较出最早的时间与最晚的时间。同时保存其名字。可以用string存储，cin >> name，后scanf,(因为scanf可以指定输入格式)

+ a1036

注意女生信息先输出

##### 3.3图形输出

+ a1031

用二维数组存下图形，关键是确定二维数组的大小，画几个例子找规律即可，再自己验证一下

##### 3.4日期处理

无

##### 3.5进制转换

+ a1019

十进制转k进制的时候写do while循环，这样0的情况不用单独考虑。

+ a1027

在存字符数组时，无需一个个写,如
```
char c[maxn] = {'0', '1', ....}
```
直接写字符串的形式即可
```
char c[14] = {"0123456789ABC"};
```

本题较为特殊，只有两位，所以两位是a / 13 和 a % 13

+ a1058

法一：像这样的有单位的计算，可以转化为最小单位，之后再进行取余等操作即可。

把A和B都化为Knut的形式，然后相加，最后转换为Galleon.Sickle.Knut的形式～注意：A和B相加有可能超出int范围，使⽤long long格式存储数据～

法二：简单的三位，可以直接相加，用一位carry表示进位。

##### 3.6字符串处理

+ a1061

capital English letter --大写英文字母

注意代码逻辑，如果出了错，调试一下看一下是否有逻辑上的错误，静下心来调试很容易发现问题。

一般找第一个位置的找到后要continue或是break；

+ a1001

每一位之后判断剩余的位数%3 是否为0，若是则输出, 因为第一位数字已被输出 所以无需在第一位的时候不输出,  在最后一位时不输出, 即可

+ a1005

题中的输入上限是10^1000,所以读入直接string读入即可

+ a1077

suffix--后缀

寻找公共后缀，用reverse把每个字符串倒一下，找前缀比较方便，先找前两个输入的公共前缀，之后再逐渐缩短结果，最终把结果rever后输出即可。另外，由于读入的字符串有空格，要用getline。

+ a1073

portion-- 部分

fractional portion-- 小数部分

先找到E的位置，然后分类讨论E的正负

若E是负的，说明小数点向前移，前面多出了0，具体多几个可以用例子来确定位数

若E是正的，说明小数点向后移，这时还要分，1.移很多位后面要补0，2.不用移很多位，确定小数点移位之后的位置。（case2注意，若正好小数点移位到最后一位不用输出小数点）

###ch4算法初步


##### 4.1排序

+ a1062

用结构体存储。写好cmp函数～结构体数组vector v[4]中v[0]保存第一类考生，v[1]保存第⼆类考生……以此类推～写好cmp函数很重要，cmp函数中，排序先按照总分排序，然后按照德分排序，最后按照id排序……最后输出符合条件的结果～

也可将不同类型的考生用不同的r表示，最好的r = 1， 依次类推，cmp先按照r排序即可

+ a1012

用构体存储学⽣的id、四门成绩、四⻔排名、最好的排名的对应的科⽬下标!结构体中可以用数组来存储不同科目的成绩！存储的时候按照ACME来存储可以简化代码逻辑。

算平均分时如果需要四舍五入，需要按照+0.5后取整，保证是四舍五入。本题不四舍五入也能通过。

注意，排名并列应该1、1、3、4、5，⽽不是1、1、2、3、4，否则会有⼀个测试点不过
设置第一个的rank = 1，从第二个开始遍历，若分数与前一个相同rank与前一个rank一样，否则设为i + 1。

+ a1025

simultaneously -- 同时的

+ a1028

可以写三个cmp函数，也可将c作为全局变量， 在一个cmp中用分支结构。

+ a1055

本题如果是不加处理的把所以符合年龄的放到一个vector里排序会导致测试点2超时，因为n和m的差距太大了，n有10^5，m却只有100，也就是最多一个年龄段只有100个人，最极限的情况也就是一个年龄里有100个人要输出。

所以先把所有的⼈按照财富值排序，再建⽴一个数组book标记每个年龄拥有的人的数量（book[n]表示年龄n有几个人），遍历数组并统计相应年龄的人数，当 当前年龄的人的数量不超过100的时候压入新的数组，多出来的不要压入新数组中（也就是说只取每个年龄的前100名，因为⼀个年龄段最小的就是一个年龄，即使这样也不会超过100个需要输出），再从这个新的数组⾥面取符合相应年龄的人的信息～～

+ a1075

可以用resize来初始化结构体中数组的初值(resize(长度，初值))。另外结构体中的单独的值在结构体定义的时候可以直接赋值。

由于题中注明了用户的编号是1~n，所以用一个n + 1大小的vector来存储即可对应。
如果当前题目的成绩>=已有的成绩，注意区分：如果没有任何一题有有效的提交，那么不排名，结构体中增设flag来表示是否需要排名，需要排名的当中，提交过但是未编译通过显示0，未提交的显示-；所以在读到一题分数是-1时，判断原来是否分数是-1，如果是的话更改为0；
+ a1083

每个学生成绩不同降序排列即可，遍历数组，满足条件push_back()到新的数组，再对新数组排序即可。

##### 4.2hash

hash的思想：将元素通过一个函数转化为一个整数，使得该整数可以尽量唯一的表示这样元素，这个函数就是hash函数。

常用散列函数：直接定址法（即恒等变换：直接将key作为数组下标或线性变换H（key）= a * key + b），平方取中法（很少用），除留取余法（H（key） = key % mod）。mod大于表长Tsize。Tsize是一个素数。

冲突解决办法：

1.线性探查法（Linear Probing） 

如果H（key）占用，那么去探查下一个位置（H（key） + 1）。

2.平方探查法（Quadratic Probing）

如果H（key）占用，那么去探查H（key）+ 1^2, H（key） - 1^2, H（key）+ 2 ^ 2...,如果超过了表长，那么将其对表长取模。

3.链地址法

+ a1084

注意有小写字母全部转化为大写字母

HashTable数组的大小只要能把题目给出的字符包括即可，一般可以设置ASCII码的个数128

初始HashTable[128]设为false，遍历实际打出的字符串对应的HashTable设为true，再遍历第一个，有哪些为false，就是坏键，注意用set保存已输出的字符

+ a1092

字符串a和b分别存储摊主的珠串和⼩红想做的珠串，遍历字符串a，将每一个字符出现的次数保存在book数组中，表示摊主的每个珠⼦的个数，遍历字符串b，如果book[b[i]]>0，表示小红要的珠⼦摊主有，则book[b[i]]-1，将这个珠子给小红～否则说明小红要的珠子摊主没有，则将统计缺了了多少珠子的result++，如果result不不等于0，说明缺珠子，则不可以买，输出No以及缺了了的珠子个数result，否则说明不缺珠子，可以买，输出Yes以及摊主珠⼦多余的个数a.length() – b.length()～

+ a1041

建⽴一个数组，存储每个数字出现的次数，然后遍历一遍输入的顺序看是否有出现次数为1的数字

+ a1050

⽤hash[128]数组变量量标记str2出现过的字符为true，输出str1的时候根据hash[str1[i]]是否为true,如果是true就不输出

+ a1048

用hashTable保存每个硬币币值出现的次数，将输入排序后从小到大遍历，如果v[i]与m - v[i] 都能拿出来就输出。注意两个硬币币值相等的时候，看其个数是不是>=2

##### 4.3递归

##### 4.4贪心

+ a1070

注意总库存与月饼数量用double存储，题目只说了正数，没说正正数。

+ a1033

  跳

+ a1037

把这两个序列都从⼩到大排序，将前面都是负数的数相乘求和，然后将后面都是正数的数相乘求和～

初始化多个vector大小时，注意多个变量有没有写错位置。

+ a1067

0号为哨兵， 用哨兵与其他数字交换，使其他数字回到有序的位置（最后有序时所处的位置），则排序完成

2.pos[t] = i; 表示t数字当前正在占着哪一个位置。 （如果想实时监测每个数字的位置，可以⽤用 b 数组{b[pos[i]] = i } 缓存一下数据，输出查看的）

3.依次遍历每个位置i，如果当前位置不是与之对应的数字，那么我们让这哨兵一直与本该在哨兵位置的数进行交换

4.数字如何被哨兵执⾏操作回到序的位置：

如果哨兵此时不在⾃己有序的位置上，那就，先让哨兵去让他占的那个位置上的真正应该放的数字回到此位置，即交换哨兵和此数字，我们swap(pos[0],pos[pos[0]])，直到哨兵在交换的过程中回到了了⾃己的有序位置(0位置)。此时再次检查该位置是不是应该放的数字（在哨兵执行交换操作的过程中，有可能让此位置该有的数字回到位置）。如果此位置不是当前数字，那哨兵和他交换swap(a[0],a[i])，就是让他先去哨兵的有序位置待一会，等下一轮操作，哨兵会把他交换回来的。如果此位置已经是该数字了，那就什么都不不做。检查下一个数字是否归位

+ a1038

！！～～不是按照字典序排列就可以的，必须保证两个字符串构成的数字是最小的才行，所以cmp函数写成return a + b < b + a;的形式，保证它排列按照能够组成的最小数字的形式排列。

因为字符串可能前面有0，这些要移除掉（⽤s.erase(s.begin())就可以了～嗯～string如此神奇～～）。输出拼接后的字符串即可。

注意：如果移出了了0之后发现s.length() == 0了，说明这个数是0，那么要特别地输出这个0，否则会什么都不输出～

##### 4.5 二分

开始令[left,right]为整个序列的下标区间，每次测试中间位置mid = (left + right) / 2,判断a[mid]与查找元素的大小。在每次判断后变化的都是区间的范围。

```
int binarySearch(int A[], int left, int right, int x){
  int mid;
  while(left <= right){
    mid = (left + right) / 2;
    if(A[mid] == x) return mid;
    else if(A[mid] > x) right = mid - 1;
    else left = mid + 1;
  }
  return -1;
}

```

lower_bound与upper_bound函数都在解决这样一个问题：寻找有序序列中第一个满足某条件的元素的位置。

```
//解决该类问题的固定模板。
// 所谓”某条件“在序列中一定是从左到右先不满足，之后满足的，若反之，则将条件取反即可。
// 二分区间为左闭右闭的[left, right]
int sovle(int left, int right){
  int mid;
  while(left < right) {        // 注意是 <  
    if(条件满足){
      right = mid;
    }else{
      left = mid + 1;
    }
  }  
  return left;       
}

```

+ 1085

  自己的思路是这样的，从小到大对输入序列进行排序，完美数列只要确定最大和最小，所以如果要最多的元素，必定是连续的。m的位置i从0 到 n - 1遍历，中间用二分来找到第一个不满足M <= p * m的M的位置j。此时完美序列的长度为j - i。

  要注意有可能M在最后一个位置还是满足的。所以，二分的区间是[i + 1, n]。不是到n - 1，因为如果不存在的话left == right == n。当然，可以在开始的时候判断一下v[n - 1]是否满足条件，若满足直接j = n。剩下的正常写

  也可以用uppper_bound.

  tips:lower_bound与upper_bound

  lower_bound(first, last, val)。寻找数组/容器的[left,right）左闭右开，的第一个大于等于val的元素的位置的指针或迭代器。若没有，则返回其应该在的位置。

  upper_bound(first, last, val)。返回 [left,right） 左闭右开第一个大于等于val的元素的位置的指针或迭代器，若没有，则返回其应该在的位置。

+ a1044

  简单模拟会有两个点超时，由于都是正数，可以用一个sum[i]数组记录1 - i的和，sum[0] = 0,这样a[i]到a[j]的和就是sum[j] - sum[i  - 1] ，用二分找到第一个大于tot + sum[i - 1]的位置,计算和。第一遍找到最接近s的数nearS。第二遍若和（sum[j - 1] - sum[i - 1],因为找到的j是第一个超过nearS的位置，所以看j - 1）就等于nearS，就输出。




##### 4.6 two pointers

i、j的枚举是互相牵制的，其思想充分利用了序列递增的特性。使用两个下标i、j对序列进行扫描。

归并排序，如果题目只要求给出归并排序每一趟结束时的序列，那么就可以用sort来代替merge

```
void mergesort(int a[]){
  for(int step = 2; step / 2 <= n; step *= 2){ // step 为组内元素个数，等号可以不取
    for(int i = 1; i <= n; i += step){
      sort(a + i, a + min(i + step , n + 1));
    }
    // 这里可以输出某一次归并排序结束的序列
  }
}
```



##### 4.7 其他技巧（打表，递推）

活用递推，例如就某一类涉及序列的题目来说，假如序列的每一位所需要的计算的值都可以通过该位左右两侧的结果计算得到，那么就可以考虑递推




###ch5数学

##### 5.1简单数学

+ a1069

  注意输入的时候是整数的形式输入，如果位数不足4位，要在前面补足4位！！！后面的减法也是！

  s.insert(0, 4 – s.length(), ‘0’);⽤来给不足4位的时候前面补0～

  在循环的时候，因为至少要循环一次，可以用do while循环。

+ a1104

  !!! double * int * int 与 int * int * double 可能会有区别。int * int * double时  int * int 可能溢出。

+ a1008

记录现在和之前的楼层。

+ a1049

  数学问题，可以从特殊到一般找规律。从右向左遍历一遍数字 （从个位到最高位），当前位设为now，当前位左边的数字记为left，右边的记为right。

  可以这样理解，从右向左遍历一遍数 即从个位到最高位，当前位确定是1，在不超过n的情况下有多少种情况。

  now == 0 时 eg：159 0 10，now是百位，要不超过n，左边不能超过159，只能是0 - 158， 此时 now位上取1， 后面两位任意即可，即，（0 - 158）1 xx 均满足题意。ans += 158 * 100（100表示是百位xx代表0 - 99）；
  now == 1 时 eg 159 1 10， now是百位，要不超过n，左边最大可以是159，但是在159时 右边的取值有限制。右边的取值不能超过right。此时可以的取值是（0 - 158）1 xx 以及 159 1 （0 - 10）。所以ans += 158 * 100 + right + 1；

  now > 1的时候， eg 159 5 10， now是百位，要不超过n，左边最大可以是159，即使左边在取159时 右边取值也没有限制，因为now > 1，此时可以的取值是(0~159) 1 xx, ans += 159 * 100.

###ch6 STL

##### 6.1vector

+ a1039

  自己在一开始的时候思路比较直接，由于输入的名字是字符串，就采用了map的方式将string映射到int，但是最后一组数据段错误，最后一组数据量庞大，应该采用字符串Hash的方法，由于字符串是由三个字母一个数字组成的，代码可以这样写。字符串hash的方法：字母是由26个字母组成的  可以看成26进制转化为10进制。最后一位是数字可以直接拼接上去。

  遇到输入格式固定的题目就用字符串Hash

  ```
    int getId(char name[]){
        int id = 0;
        for(int i = 0; i < 3; i++){
          id = id * 26 + (name[i] - 'A');       // 26进制转换
        }
        id = id * 10 + (name[3] - '0');          // 拼接最后一位
        return id;
    }
  ```

+ a1047

  本题可以直接用vector<string> v(n)来直接保存每一门课的人。但是，string 容易超时，当string超时的时候，用char数组。这样输入时的顺序，自动将序号和字符串关联起来

  ```
  char name[N][5];           // 存放N个名字
  scanf("%s", name[i]);      //注意没有&       
  ```

  如果排序是对字符串排序，将会导致大量的字符串，非常耗时，可以用字符串的下标来代替字符串进行移动。这样的耗时会少很多。

  ```
  bool cmp(int a, int b){
    return strcmp(name[a], name[b]) < 0;
  }
  ```

  可以开一个int的vector course[n] 存放每一门课的学生.


##### 6.2 set

+ a1063

  可以设置N个集合，set的方法和vector的一样

  ```
  set<int> s[N];
  //or
  vector<set<int> > v(n);  
  ```
  如果用第二种方法，可以用一个set全部插入之后整体赋值。

##### 6.3 string

##### 6.4 map

+ a1100

  在将10进制转化为13进制的时候，不能直接进行数字的转化（不能除基取余后把结果保存在数组中之后再将其转化为十进制，而是直接就是结果），因为13进制有字母a，b，c。从数组中一个个取出来才可以。

  所以像这样结果不超过两位数的直接a/13,a % 13即可。

  可以等每一个输入都处理好了，最后一起输出换行符。

+ a1054

  使用cin，cout会超时。20分的题目个别的点超时的时候可以改用scanf和printf

+ a1071

  string 置空是""  

  字母或者数字在cctype是 isalnum();

  ⼤小写不区分，所以统计之前要先s[i] = tolower(s[i]);

  一定要当now不为空的时候mp[now]++，因为now为空也会被统计的！！！

  另外，在字符串的最后一定要结束，不管当前位是不是字⺟数字，都得将当前这个now放到map，只要t⻓度不为0

+ a1022

  map<string, set<int> >,由于题目是给某一string来查询满足条件的id。所以可以用这一办法来实现查找一个字符串对应满足条件的int。

  把查询单独写成一个函数


###ch7 数据结构专题1

##### 7.1 栈

+ a1051

  按照题目要求模拟即可,记录栈的最大容量，在没超过的时候，用一个变量idx记录现在已经弹出的序列到那个位置了，每次压入一个元素就判断一下当前栈顶与idx号的元素是否一样，如果一样就一直循环弹出。最后判断是否idx到了最后，或者栈中还有没有元素。

  另外，在弹出的时候，一定要判断是否栈空。

##### 7.2 队列

##### 7.3 链表

  考试的时候用静态链表比较简单。

  对于比较复杂的链表题，步骤如下：

  1.定义静态链表

  ```
  struct Node{
    int address;    // 地址
    typename data;  // 数据
    int next;       //  指针域
    xxx   // 某个性质
  }node[10000];
  ```

  2.初始化静态链表
  一般来说定义中的xxx初始化的时候，一般将其定义为小于正常情况能达到的数字，比如0之类的，表示结点不在链表上。

  3.题目一般会给出一条链表的首节点的地址，遍历一遍链表，这一步对xxx进行标记，对有效结点进行计数count，

  4.静态链表一般是直接地址映射到数组的下标，这样有效结点也不是连续的，并且题目有时也会给出无效结点（即不在链表上的结点），所以为了可控的访问有效结点，一般都需要对数组进行排序。这样也可以用第三步的count来访问。排序时首先按照xxx属性来排。

+ a1074

  可以按照上面的步骤慢慢做。注意不是所有的结点都是有效结点。

  柳神的思路：把地址为temp的数的数值存入data[temp]中，把temp的下一个结点的地址存⼊next[temp]中。然后从开始的结点遍历的时候加入list[]数组,然后按照输出的规则加入ans数组

+ a1032

  ⽤结构体数组存储，node[i]表示地址为i的结点，key表示值，next为下一个结点的地址，flag表示第一条链表有没有该结点遍历第一条链表，将访问过的结点的flag都标记为true，当遍历第⼆条结点的时候，如果遇到了true的结点就输出并结束程序，没有遇到就输出-1

+ a1052

  要考虑无效结点，结构体新增一项记录是否是有效结点的属性flag，另外最后一个测试点是有效结点为0的情况，输出0 -1

+ a1097

  用一个map<int, bool> mp表示一个数的绝对值之前是否出现过。从头到尾遍历一遍链表，用两个指针来处理pre和p，如果该节点的值已经出现过，将其加入vector<Node> v中，并且利用pre和p将其在链表删除，记录最终链表的长度，输出链表之后，输出v,即可。

  柳神的思路：

  ⽤结构体数组存储这个链表，⼤小为maxn = 100000，node[i]表示地址为i的结点。在结构体中定
  义一个num变量量，将num变量量先初始化为2*maxn。通过改变num变量量的值最后sort排序来改变链表的顺序。（利用结构体中的结点属性来帮忙）

  将没有删除的结点的num标记为cnt1，cnt1为当前没有删除的结点的个数；将需要删除的结点的num标
  记为maxn + cnt2，cnt2表示当前删除了的结点的个数，因为一开始初始化为了了2 * maxn，所以我们可以通过对num排序达到：num = 0到maxn为不删除结点，num = maxn到2maxn为删除结点，num = 2maxn为无效结点


###ch8 DFS与BFS

##### 8.1 


###ch9 数据结构专题2 树

##### 9.1 

  对于完全二叉树，可以用数组从下标1开始来存储。并有以下结论：1.该数组中元素存放的顺序就是层序遍历的顺序；2.判断某个结点（编号为root）是否为叶结点的标志：其左孩子的编号root * 2 是否大于 n；3.判断某个结点是否为空的标志：该结点下标root是否大于结点总数n

##### 9.2 二叉树的遍历

二叉树的静态写法：

```
struct node{
  typename data;
  int l, r;         // -1表示不存在
}Node[maxn];   //maxn为上限    
```

层序遍历类比BFS。层序遍历的时候，队列里放的是地址

如果题目要求计算每一个结点所在的层次，这时候就需要在二叉树的结点定义中添加一个layer

+ a1020

  建树，再层序遍历比较麻烦

  与后序中序转换为前序的代码相仿（⽆须构造⼆二叉树再进⾏广度优先搜索～），只不过加⼀个变量index，表示当前根结点在二叉树中所对应的下标（从1开始），所以进⾏一次输出先序的递归的时候，把节点的index和value放进结构体⾥里里，再装进容vector⾥，这样在递归完成后，vector中按照index排序就是层序遍历的顺序～（按照完全二叉树的存储结构来放置index），左子树根结点为2 * index，右子树根结点是index + 1；

  注意，如果参数用的是root来表示根结点在前序或后序里面的下标，在递归时必须也要写root。

+ a1086

  push的顺序就是pre，pop的顺序就是inOrder

+ a1102

  反转二叉树就是存储的时候左右结点全部交换。或者先右子树，再根节点，最后左子树。

  层序遍历，可以不需要真的层序遍历，在node的性质里面加入layer和index，layer从小到大，相同的layerindex从小到大（反转的话就是从大到小）。

  另外，本题的输入形式，中间有空格，可以直接用string a, b; cin >> a >> b;来输入

##### 9.3 树的遍历
  
  普通的树的表示
  ```
  //如果题目没有涉及结点的数据域，只需要树的结构。
  vector<int> child[maxn]  // maxn为最大结点数
  //如果有点权可以用结构体
  struct node{
    typename data;
    vector child;
  }Node[maxn];

  ```

事实上，所有的DFS过程都可以化成树的形式。对这棵树的DFS过程就是对树的先根遍历。碰到一些DFS的题目可以把状态转化为树的结点，然后问题就可以直观的转化为对一颗普通的树进行先根遍历的问题了

在递归的过程中，保存路径的方法有两种，1.用path数组表示路径,path[i]表示路径上第i个结点的编号，初值为0的变量numNode作为下标，在递归进入下一层的时候numNode + 1，这样就可以随时跟踪path数组的当前结点的个数！！！，便于随时将新的结点加入路径或者将旧的结点覆盖

+ a1079

  注意题中要求，根结点是0，测试点2就只有一个结点。

+ a1090

  dfs找到最大深度的结点，cnt数组记录每一层的结点个数

+ a1004

  pedigree tree - 谱系树

  注意，最大层数可能是1，也就是输出的cnt数组只输出cnt[0],注意这种最大最小值的设定要取取不到的数字。




