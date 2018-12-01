树(Tree)：<br/>
树是n(n>=0)个结点的有限集合。n=0时称为空树。在任意一棵非空树中：<br/>
（1）有且仅有一个特定的称为根（Root）的结点；<br/>
（2）当n>1时，其余结点可分为m(m>0)个互不相交的有限集T1、T2...Tm，其中每一个集合本身又是一棵树，并且称为根的子树（SubTree）。<br/>

结点拥有的子树数称为结点的度（Degree）。度为0的结点称为叶结点（Leaf）或终端结点；度不为0的结点称为非终端结点或分支结点。除根结点之外，分支结点也称为内部结点。树的度是树内各结点的度的最大值。<br/>

如果将树中结点的各子树看成从左至右是有次序的，不能互换的，则称该树为有序树，否则称为无序树。<br/>

二叉树（Binary Tree）是n(n>=0)个结点的有限集合，该集合或者为空集（称为空二叉树），或者由一个根结点和两颗互不相交的、分别称为根结点的左子树和右子树的二叉树组成。<br/>

该demo实现了二叉树的链式存储结构(binary.c)、二叉树的前序遍历(pre.c)、中序遍历(in.c)、后序遍历(post.c)。<br/>

binary.c
```
Operation
    InitTree(*Tree)：构造空树Tree
    TreeEmpty(Tree)：若Tree为空树，返回True，否则返回False
    ClearTree(*Tree)：若树Tree存在，则将树Tree清为空树
    TreeDepth(Tree)：返回Tree的深度
    Root(Tree)：返回Tree的根结点
    InsertChild(*Tree, *p, i, c)：其中p指向树Tree的某个结点，i为所指结点p的度加上1，非空树c与Tree不相交，操作结果为插入c为树Tree中p指结点的第i棵子树
    DeleteChild(*Tree, *p, i)：其中p指向树Tree的某个结点，i为所指结点p的度加上1，非空树c与Tree不相交，操作结果为删除Tree中p指结点的第i棵子树
```