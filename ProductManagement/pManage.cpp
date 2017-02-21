// Data Structure Class Final Project 
// Hongyan.Yi 09/2005
// Product Management System
// including product.h, pManage.cpp

#include<iostream.h>	//cin();cout();
#include<stdlib.h>		//cerr()
#include<iomanip.h>		//setw()
#include<string.h>
#include<fstream.h>		//ifstr();ofstr();
#include"product.h"

const int MaxSize = 10;
struct goods
{
	char code[5];	//条形码
	char name[15];	//商品名称
	char mark[15];	//产地品牌
	int minq;    	//单价
	int  curq;    	//数量
};

typedef  goods  ElemType;


ostream& operator<<(ostream&  ostr, const ElemType &x) //重载运算符，但只对结构体
{
	ostr << "       " << x.code << setw(16) << x.name << setw(16) << x.mark << setw(10) << x.minq << setw(10) << x.curq << endl;
	return ostr;
}

void SetupGoodsList(LNode *&L, char *fname)//将文件读到结构体里，然后将结构体一个个连到链表上，形成一个链表
{
	ifstream ifstr(fname, ios::in | ios::nocreate); //打开权限，定义的同时打开
	if (!ifstr)
	{
		cerr << "File 'goods' not found!" << endl;
		exit(1);
	}  //容错:设法创建；根本不存在这个文件
	goods g;
	while (ifstr >> g.code)
	{
		ifstr >> g.name >> g.mark >> g.minq >> g.curq;
		InsertRear(L, g);
	}
	ifstr.close();
}

void WriteGoodsFile(char *fname, LNode *&L) //将链表切成结构体，然后将结构体输出到文件
{
	ofstream ofstr(fname);
	if (!ofstr)
	{
		cerr << "File 'goods' no creat";
		exit(1);
	}
	goods g;
	int n = ListLength(L);  //得到结构体的数目
	for (int i = 1; i <= n; i++)
	{
		g = GetElem(L, i);      //循环的输出n个结构体
		ofstr << g.code << setw(16) << g.name << setw(12) << g.mark << setw(12) << g.minq << setw(14) << g.curq << endl;
	}
	ofstr.close();
}


void huifu()  //已知丢失当日的日志进货提货文件名和前一天的库存文件名,恢复文件
{
	char a[20], b[20], c[20], d[5];
	ElemType r[20], s[20], t[20];
	int x = 1, y = 1, z = 1, p = 1, q = 1, v = 1, m, n;
	LNode *L2;
	InitList(L2);
	cout << "      请您根据提示输入,我将帮您恢复丢失的库存文件!" << endl;
	cout << "      请您输入当日日志文件名(如 r050904.dat):";
	cin >> c;
	ifstream ifstr(c, ios::in | ios::nocreate); //打开权限，定义的同时打开
	if (!ifstr)
	{
		cerr << "File 'goods' not found!" << endl;
		exit(1);
	}  //容错:设法创建；根本不存在这个文件

	ifstr >> d;//因为是比较两个字符串所以要定义d是一个数组
	while (strcmp(d, "j") == 0)
	{
		ifstr >> r[x].code >> r[x].name >> r[x].mark >> r[x].minq >> r[x].curq;
		ifstr >> d[0]; //数组赋不起来，所以改成了元素
		x++;
	}
	while (strcmp(d, "t") == 0)
	{
		ifstr >> s[y].code >> s[y].name >> s[y].mark >> s[y].minq >> s[y].curq;
		ifstr >> d[0];
		y++;
	}
	while (strcmp(d, "s") == 0)
	{
		ifstr >> t[z].code;
		ifstr >> d[0];
		z++;
	}
	ifstr.close();

	cout << "      请输入其前一天的库存文件名(如ku050904.dat):";
	cin >> a;
	SetupGoodsList(L2, a);
	for (p = 1; p<x; p++)
	{
		m = r[p].curq;
		if (Find(L2, r[p]))//旧货添加
		{
			r[p].curq += m;
			Update(L2, r[p]);
		}
		else 	InsertRear(L2, r[p]);//新货插入
	}
	for (q = 1; q<y; q++)
	{
		n = s[q].curq;
		Find(L2, s[q]);
		s[q].curq -= n;//旧货减少
		Update(L2, s[q]);
	}
	for (v = 1; v<z; v++)
		Delete(L2, t[v]);//旧货删除

	cout << "      请输入丢失的库存文件名(如 ku050904.dat):";
	cin >> b;
	WriteGoodsFile(b, L2);//更新好的库存链表存档
	cout << "      已恢复,您可在查看界面中查看到!" << endl;
}




void caozuo()
{
	ElemType r[100], s[100], t[100]; //存进货提货情况		
	int x = 1, y = 1, z = 1, m, n;
	char  a[20], b[20];
	int i;  //用字符型不好,输入45它就执行4,5两项操作
	int flag = 1;
	LNode *L1;
	InitList(L1);
	goods g;
	cout << "      请输入您要操作的库存文件名( 如 ku050904.dat ):";
	cin >> a;
	SetupGoodsList(L1, a);	//将要操作的库存文件转成链表

	while (flag)
	{
		cout << endl;
		cout << "      * * * * * * * * * * * * * * 商品管理系统* * * * * * * * * * * * * * **" << endl;
		cout << "      *               欢迎进入操作界面,请您根据提示输入,谢谢!              *" << endl;
		cout << "      *                           1.显示库存                               *" << endl;
		cout << "      *                           2.进货                                   *" << endl;
		cout << "      *                           3.提货                                   *" << endl;
		cout << "      *                           4.删货                                   *" << endl;
		cout << "      *                           5.排序                                   *" << endl;
		cout << "      *                           6.查询                                   *" << endl;
		cout << "      *                           7.存盘                                   *" << endl;
		cout << "      *                           8.推出操作                               *" << endl;
		cout << "      * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * **" << endl << endl;
		cout << setw(19) << "请您输入选择:";           //????????setw(19),下面的怎么看起来没效果，这可以呢?
		cin >> i;
		while (i<1 || i>8)
		{
			cout << "      请您重新输入选择(1-8):";
			cin >> i;
		}
		switch (i)
		{
		case 1:TraverseList(L1);  break;//打印
		case 2:                 //修改		
			cout << setw(19) << "      请您输入进货商品条码号:";//????????这setw(),看起来没效果??
			cin >> g.code;
			if (Find(L1, g))
			{
				cout << "      请您输入进货商品的量:";
				cin >> m;
				g.curq += m;      //直接加到现有库存上		
				r[x] = g;         //进货情况随时存起来
				r[x].curq = m;
				x++;
				Update(L1, g);
			}
			else
			{
				cout << "      请您输入新进货商品其余字段内容:";//找不到就尾插
				cin >> g.name >> g.mark >> g.minq >> g.curq;
				r[x] = g;        //进货情况随时存起来
				x++;
				InsertRear(L1, g);
			}
			TraverseList(L1);
			break;
		case 3:                        //按商品号提货
			cout << "      请您输入提货商品条码号:";
			cin >> g.code;
			if (Find(L1, g))
			{
				cout << "      请您输入提货的商品量:";
				cin >> n;
				g.curq -= n;  //直接在现有库存上减掉
				s[y] = g;    //提货情况存起来
				s[y].curq = n;
				y++;
				Update(L1, g);
				TraverseList(L1);
			}
			else
				cout << "      对不起,没有找到您要的商品!" << endl << endl;//找不到就尾插

			break;
		case 4:
			cout << "      请您输入待删商品代号:";
			cin >> g.code;
			Find(L1, g);  //方便记录才设了这三句,否则不要
			t[z] = g;
			z++;
			Delete(L1, g);
			TraverseList(L1);
			break;
		case 5:
			Sort(L1);                  //这次仅按“单价升序”排序
			TraverseList(L1);
			break;
		case 6:
			search(L1);         //按照不同的方式查询
			break;

		case 7:
			cout << "      请输入库存文件名:( 如 ku050904.dat ):";
			cin >> b;
			WriteGoodsFile(b, L1);//将链表写到库存文件里去
			rizhibaocun(r, s, t, x, y, z); //日志文件保存
			cout << "      处理结束,谢谢您的使用,您的数据将被保存!" << endl;
			break;
		case 8:  flag = 0; break;
		}
	}
}





void main()
{
	char a[20];
	int i;
	LNode *L3;
	InitList(L3);
	int flag = 1;
	while (flag)
	{
		cout << endl;
		cout << "      * * * * * * * * * * * * * * 商品管理系统* * * * * * * * * * * * * * **" << endl;
		cout << "      *                欢迎进入查看界面,请您根据提示输入,谢谢!             *" << endl;
		cout << "      *                           1. 库存查看                              *" << endl;
		cout << "      *                           2. 日志查看                              *" << endl;
		cout << "      *                           3. 商品操作                              *" << endl;
		cout << "      *                           4. 导航阅读                              *" << endl;
		cout << "      *                           5. 系统恢复                              *" << endl;
		cout << "      *                           6. 金额统计                              *" << endl;
		cout << "      *                           7. 退出查看                              *" << endl;
		cout << "      * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * **" << endl << endl;
		cout << setw(19) << "请您输入选择:";           //????setw(19),下面的怎么看起来没效果，这可以呢?
		cin >> i;
		while (i<1 || i>7)
		{
			cout << "      请您重新输入选择(1-7):";
			cin >> i;
		}
		switch (i)
		{
		case 1:
			cout << "      请您输入您要查看的库存文件名(如 ku050904.dat):";
			cin >> a;
			SetupGoodsList(L3, a);
			cout << "      您要查看的库存文件为:" << endl;
			TraverseList(L3);
			ClearList(L3);
			break;
		case 2:
			rizhichakan();    //从文件里读出来
			break;
		case 3:
			char q[20];
			cout << "      请输入操作员密码(1234):";
			cin >> q;
			if (strcmp(q, "1234") == 0)
				caozuo();
			else
				cout << "      对不起,密码错误,不能进入!" << endl;
			break;
		case 4: help();   break;
		case 5:  huifu();   break;//恢复
		case 6:  rizhitongji(); break;
		case 7:
			cout << "      谢谢观看!" << endl;
			flag = 0;
			break;
		}
	}
}