#include <stdlib.h>
#include <iostream.h>
struct LNode
{
	ElemType  data;
	LNode   *next;
};

//1.初始化链表
void InitList(LNode *&HL)
{
	HL = NULL;
}
//**2.删除链表的所有元素
void ClearList(LNode *&HL)
{
	LNode  *cp = HL, *np;
	while (cp != NULL)
	{
		np = cp->next;
		delete cp;
		cp = np;
	}                 //循环遍列，用两个指针算法好
	HL = NULL;          //记得对头指针进行修改
}
//3.得到链表的长度
int ListLength(LNode *HL)
{
	LNode *p = HL;
	int i = 0;
	while (p != NULL)
	{
		i++;
		p = p->next;
	}
	return i;
}
//**4.检查链表是否为空
int ListEmpty(LNode *HL)
{
	return(HL == NULL);
}
//5.得到链表指定序号的元素
ElemType GetElem(LNode *HL, int pos)
{
	if (pos<1)
	{
		cerr << "pos is out of range!";
		exit(1);
	}              //对pos进行判断

	LNode *p = HL;
	int i = 0;
	while (p != NULL)
	{
		i++;
		if (i == pos) break;
		p = p->next;
	}             //循环查找

	if (p != NULL)
		return p->data;
	else
	{
		cerr << "pos is out of range!";
		exit(1);
	}             //对p进行判断，返回查找结果
}


//6.遍历一个链表
void TraverseList(LNode *HL)
{
	LNode *p = HL;
	cout << endl;
	cout << "      ------------------------------------------------------------------" << endl;
	cout << "      条形码      " << "家电名称         " << "产家品牌     " << "单价      " << "数量         " << endl;
	while (p != NULL)
	{
		cout << p->data;
		p = p->next;
	}
	cout << "      ------------------------------------------------------------------" << endl << endl;
}
//7.从链表区域中查找具有决定值的第一个元素
int  Find(LNode *HL, ElemType &item)
{
	LNode *p = HL;
	while (p != NULL)
	if (strcmp(p->data.code, item.code) == 0)
	{
		item = p->data; //结构体赋值
		return 1;
	}
	else
		p = p->next; //遍列查找
	return 0;  //?????这return前不要加if 语句吗?   //p本身就是0，p遍列到最后	
}


//8.更新链表中具有给定值的第一个元素
int Update(LNode *HL, const ElemType &item)
{
	LNode *p = HL;
	while (p != NULL)
	if (strcmp(p->data.code, item.code) == 0)
		break;
	else
		p = p->next;    //遍列查找

	if (p == NULL)
		return 0;
	else
	{
		p->data = item; //结构体可以赋值，但cin，cout不可以  
		return 1;
	}

}
//9.向链表的末尾插入一个元素
void InsertRear(LNode *&HL, const ElemType &item)
{
	LNode *newptr;
	newptr = new LNode;  // 分配内存

	if (newptr == NULL)
	{
		cerr << "Memory allocation error!";
		exit(1);
	}                 //容错

	newptr->data = item;
	newptr->next = NULL;  //真正形成一个新的结点

	if (HL == NULL)
	{
		HL = newptr;//????????		
	}
	else
	{
		LNode *p = HL;

		while (p->next != NULL)
			p = p->next;    //找到最后位置

		p->next = newptr;

	}

}
//**10.向链表的表头插入一个元素
void InsertFront(LNode *&HL, const ElemType &item)
{
	LNode *newptr;
	newptr = new LNode;  // 分配内存

	if (newptr == NULL)
	{
		cerr << "Memory allocation error!";
		exit(1);
	}                 //容错

	newptr->data = item;
	newptr->next = HL;
	HL = newptr;        //顺序不能错
}
//11.向链表中满足条件的位置插入一个元素
void Insert(LNode *&HL, const ElemType &item)
{
	LNode *newptr;
	newptr = new LNode;  // 分配内存

	if (newptr == NULL)
	{
		cerr << "Memory allocation error!";
		exit(1);
	}                 //容错

	newptr->data = item;
	LNode *cp = HL;
	LNode *ap = NULL;
	while (cp != NULL)
	if (item.minq<cp->data.minq)//这儿没用到重载,找到刚好比cp小的位置插进去,cp在后
		break;
	else
	{
		ap = cp;
		cp = cp->next; //ap始终在cp的后面			
	}
	if (ap == NULL)
	{
		newptr->next = HL;
		HL = newptr;  //头插情形
	}
	else
	{
		newptr->next = cp;
		ap->next = newptr; //插在ap和cp之间，语句顺序不能错
	}
}
//**12.向链表中满足条件的位置插入一个元素
void InsertItem(LNode *HL, const ElemType &item);
//**13.从链表中删除第1个元素
ElemType  DeleteFront(LNode *&HL, const ElemType &item)
{
	if (HL == NULL)
	{
		cerr << "deleting front error!";
		exit(1);
	}  //判空
	LNode *p = HL;
	HL = HL->next;
	ElemType  temp = p->data;
	delete p;
	return temp; //返回删除的值
}



//14.从链表中删除一个元素
int Delete(LNode *HL, const ElemType &item)
{
	if (HL == NULL)
	{
		cerr << "deleting front error!";
		return 0;
	}  //判空


	LNode *cp = HL;
	LNode *ap = NULL;
	while (cp != NULL)
	if (strcmp(cp->data.code, item.code) == 0)
		break;
	else
	{
		ap = cp;
		cp = cp->next; //ap始终在cp的后面
	} //查找


	if (cp == NULL)
	{
		cerr << "deleted element error!";
		return 0;
	}  //相对insert多加一个判断

	if (ap == NULL)
		HL = HL->next;
	else
		ap->next = cp->next; //删头删后方法不一样
	delete cp;
	return 1;  //？？？后面两句要不要扩起来呢		
}

//15.对链表进行排序
void Sort(LNode *&HL)
{
	LNode *cp = HL;
	LNode *p = cp;
	HL = NULL;
	while (cp != NULL)
	{
		p = cp;
		Insert(HL, cp->data);
		cp = p->next;
		delete p; //cp参与排序，p控制cp一直向前指
	}
}


/*//**16.两个链表归并
void Merge(LNode *HL1,LNode *HL2,LNode *HL);*/


//17.帮助说明
void help()
{
	cout << endl;
	cout << "      ---------------------------------------------------------------------" << endl;
	cout << "      友情提示:" << endl;
	cout << "         系统主要有两个界面,第一个界面是查看界面,任何人可以查看到多个库存" << endl;
	cout << "      或日志文件(050902--050905),如果某个库存文件丢失了,可以通过操作恢复," << endl;
	cout << "      您也可以在此界面查看到某日的金额统计情况,需对货物操作可进入第二界面," << endl;
	cout << "      第二个界面是操作界面,只有操作员可以通过密码进入,可以对某个指定的库" << endl;
	cout << "      存文件进行进货,提货,删货,排序,查询操作,操作的情况可以被系统保存,文件名" << endl;
	cout << "      可自定,保存完后,可直接退回到查看界面查看到,您可以参照提示框,按照提示语" << endl;
	cout << "      输入,系统功能还不够完善,希望能给予指正批评!" << endl;
	cout << "      邮箱:yhy178@sina.com  " << endl << "      qq:304962214  " << endl;
	cout << "      ---------------------红艳工作室欢迎您的到来!--------------------------" << endl << endl;;
}




//18.分类查询
void search(LNode *HL)
{
	int i, j = 1;
	LNode *p = HL;
	ElemType q[100]; //结构体数组
	ElemType item;
	cout << "      以何种方式查询: 1.条形码  2.家电名称   3.产家品牌   4.单价   5.数量 " << endl;
	cout << "      请您输入选择:";
	cin >> i;
	while (i<1 || i>5)
	{
		cout << "      请您重新输入选择(1-5):";
		cin >> i;
	}
	cout << "      请输入您要给的信息:";
	switch (i)
	{
	case 1:
		cin >> item.code;
		while (p != NULL)
		if (strcmp(p->data.code, item.code) == 0) //只要符合条件的都可加进结构体中去					
		{
			q[j] = p->data;
			j++;
			p = p->next;
		}
		else
			p = p->next; //遍列查找
		break;
	case 2:
		cin >> item.name;
		while (p != NULL)
		if (strcmp(p->data.name, item.name) == 0)
		{
			q[j] = p->data;
			j++;
			p = p->next;
		}
		else
			p = p->next; //遍列查找
		break;
	case 3:
		cin >> item.mark;
		while (p != NULL)
		if (strcmp(p->data.mark, item.mark) == 0)
		{
			q[j] = p->data;
			j++;
			p = p->next;
		}
		else
			p = p->next; //遍列查找
		break;
	case 4:
		cin >> item.minq;
		while (p != NULL)
		if (p->data.minq == item.minq)
		{
			q[j] = p->data;
			j++;
			p = p->next;
		}
		else
			p = p->next; //遍列查找
		break;
	case 5:
		cin >> item.curq;
		while (p != NULL)
		if (p->data.curq == item.curq)
		{
			q[j] = p->data;
			j++;
			p = p->next;
		}
		else
			p = p->next;  //遍列查找
		break;
	default:
		cout << " Selection error!";
		break;
	}
	cout << endl << "      共找到" << j - 1 << "条信息如下:" << endl;
	cout << "      ------------------------------------------------------------------" << endl;
	cout << "      条形码      " << "家电名称         " << "产家品牌     " << "单价      " << "数量         " << endl;
	for (int k = 1; k<j; k++)  //显示结构体
		cout << q[k];
	cout << "      ------------------------------------------------------------------" << endl << endl;
}


//19.日志查看
void rizhichakan()
{
	char c[10];
	ElemType r[20], s[20], t[20];
	int x = 1, y = 1, z = 1, p = 1, q = 1, v = 1;
	cout << "      请您输入日志文件名(如 r050904.dat):";
	cin >> c;
	ifstream ifstr(c, ios::in | ios::nocreate); //打开权限，定义的同时打开
	if (!ifstr)
	{
		cerr << "File 'goods' not found!" << endl;
		exit(1);
	}  //容错:设法创建；根本不存在这个文件
	char d[5];//因为是比较两个字符串所以要一个数组
	ifstr >> d;
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
		ifstr >> t[z].code >> t[z].name >> t[z].mark >> t[z].minq >> t[z].curq;
		ifstr >> d[0];
		z++;
	}
	ifstr.close();

	cout << endl << "      -------------------------------------------------------------------------" << endl;
	cout << "      注意: j--进货,t--提货,s--删货  " << endl;
	cout << "      -------------------------------------------------------------------------" << endl;
	cout << "      操作   " << "条形码      " << "家电名称         " << "产家品牌     " << "单价      " << " 操作量  " << endl;

	for (p = 1; p<x; p++)
	{
		cout << setw(8) << "j";
		cout << setw(9) << r[p].code << setw(16) << r[p].name << setw(16) << r[p].mark << setw(10) << r[p].minq << setw(10) << r[p].curq << endl;

	}
	for (q = 1; q<y; q++)
	{
		cout << setw(8) << "t";
		cout << setw(9) << s[q].code << setw(16) << s[q].name << setw(16) << s[q].mark << setw(10) << s[q].minq << setw(10) << s[q].curq << endl;

	}
	for (v = 1; v<z; v++)
	{
		cout << setw(8) << "s";
		cout << setw(9) << t[v].code << setw(16) << t[v].name << setw(16) << t[v].mark << setw(10) << t[v].minq << setw(10) << t[v].curq << endl;
	}
	cout << "      --------------------------------------------------------------------------" << endl;

}

//20.日志保存
void rizhibaocun(ElemType *r, ElemType *s, ElemType *t, int x, int y, int z)
{
	char a[20];
	int p = 1, q = 1, v = 1;
	cout << "      请输入日志文件名:( 如 r050904.dat ):";
	cin >> a;
	ofstream ofstr(a);
	if (!ofstr)
	{
		cerr << "File 'goods' no creat";
		exit(1);
	}

	for (p = 1; p<x; p++)
	{
		ofstr << endl << "j";
		ofstr << setw(8) << r[p].code << setw(16) << r[p].name << setw(12) << r[p].mark << setw(12) << r[p].minq << setw(14) << r[p].curq;

	}

	for (q = 1; q<y; q++)
	{
		ofstr << endl << "t";
		ofstr << setw(8) << s[q].code << setw(16) << s[q].name << setw(12) << s[q].mark << setw(12) << s[q].minq << setw(14) << s[q].curq;

	}

	for (v = 1; v<z; v++)
	{
		ofstr << endl << "s";
		ofstr << setw(8) << t[v].code << setw(16) << t[v].name << setw(12) << t[v].mark << setw(12) << t[v].minq << setw(14) << t[v].curq;

	}
	ofstr << endl << "end";
	ofstr.close();
}

//21.日志统计
void rizhitongji()
{
	char c[10], d[5];
	ElemType r[20], s[20], t[20];
	int x = 1, y = 1, z = 1, p = 1, q = 1, v = 1;
	long int e = 0, f = 0, g = 0, m;
	cout << "      请您输入日志文件名(如 r050904.dat):";
	cin >> c;
	ifstream ifstr(c, ios::in | ios::nocreate); //打开权限，定义的同时打开
	if (!ifstr)
	{
		cerr << "File 'goods' not found!" << endl;
		exit(1);
	}  //容错:设法创建；根本不存在这个文件

	ifstr >> d;//因为是比较两个字符串所以要一个数组
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
		ifstr >> t[z].code >> t[z].name >> t[z].mark >> t[z].minq >> t[z].curq;
		ifstr >> d[0];
		z++;
	}
	ifstr.close();

	for (p = 1; p<x; p++)
		e += (r[p].minq)*(r[p].curq);
	for (q = 1; q<y; q++)
		f += (s[q].minq)*(s[q].curq);
	for (v = 1; v<z; v++)
		g += (t[v].minq)*(t[v].curq);
	m = f - e;
	cout << "      ------------------------------------------------------------------" << endl;
	cout << "      今天商场进了" << x - 1 << "种货物,出帐" << e << "元" << endl;
	cout << "      今天商场提了" << y - 1 << "种货物,进帐" << f << "元" << endl;
	cout << "      今天商场删掉" << z - 1 << "种货物,费帐" << g << "元" << endl;
	cout << "      不考虑费帐今天商场共营利" << m << "元" << endl;
	cout << "      ------------------------------------------------------------------" << endl;
}