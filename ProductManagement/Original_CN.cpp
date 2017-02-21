//����:�����(06030546);����ʱ��:�����ϵ�1��,2005.9.4;����˵��:��Ʒ����ϵͳ(��������),����:link.h,goodsmanage.cpp,������ı��ĵ�

//link.h
#include <stdlib.h>
#include <iostream.h>
struct LNode
{
	ElemType  data;
	LNode   *next;
};
//1.��ʼ������
void InitList(LNode *&HL)
{
	HL = NULL;
}
//**2.ɾ�����������Ԫ��
void ClearList(LNode *&HL)
{
	LNode  *cp = HL, *np;
	while (cp != NULL)
	{
		np = cp->next;
		delete cp;
		cp = np;
	}                 //ѭ�����У�������ָ���㷨��
	HL = NULL;          //�ǵö�ͷָ������޸�
}
//3.�õ�����ĳ���
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
//**4.��������Ƿ�Ϊ��
int ListEmpty(LNode *HL)
{
	return(HL == NULL);
}
//5.�õ�����ָ����ŵ�Ԫ��
ElemType GetElem(LNode *HL, int pos)
{
	if (pos<1)
	{
		cerr << "pos is out of range!";
		exit(1);
	}              //��pos�����ж�

	LNode *p = HL;
	int i = 0;
	while (p != NULL)
	{
		i++;
		if (i == pos) break;
		p = p->next;
	}             //ѭ������

	if (p != NULL)
		return p->data;
	else
	{
		cerr << "pos is out of range!";
		exit(1);
	}             //��p�����жϣ����ز��ҽ��
}


//6.����һ������
void TraverseList(LNode *HL)
{
	LNode *p = HL;
	cout << endl;
	cout << "      ------------------------------------------------------------------" << endl;
	cout << "      ������      " << "�ҵ�����         " << "����Ʒ��     " << "����      " << "����         " << endl;
	while (p != NULL)
	{
		cout << p->data;
		p = p->next;
	}
	cout << "      ------------------------------------------------------------------" << endl << endl;
}
//7.�����������в��Ҿ��о���ֵ�ĵ�һ��Ԫ��
int  Find(LNode *HL, ElemType &item)
{
	LNode *p = HL;
	while (p != NULL)
	if (strcmp(p->data.code, item.code) == 0)
	{
		item = p->data; //�ṹ�帳ֵ
		return 1;
	}
	else
		p = p->next; //���в���
	return 0;  //?????��returnǰ��Ҫ��if �����?   //p�������0��p���е����	
}


//8.���������о��и���ֵ�ĵ�һ��Ԫ��
int Update(LNode *HL, const ElemType &item)
{
	LNode *p = HL;
	while (p != NULL)
	if (strcmp(p->data.code, item.code) == 0)
		break;
	else
		p = p->next;    //���в���

	if (p == NULL)
		return 0;
	else
	{
		p->data = item; //�ṹ����Ը�ֵ����cin��cout������  
		return 1;
	}

}
//9.�������ĩβ����һ��Ԫ��
void InsertRear(LNode *&HL, const ElemType &item)
{
	LNode *newptr;
	newptr = new LNode;  // �����ڴ�

	if (newptr == NULL)
	{
		cerr << "Memory allocation error!";
		exit(1);
	}                 //�ݴ�

	newptr->data = item;
	newptr->next = NULL;  //�����γ�һ���µĽ��

	if (HL == NULL)
	{
		HL = newptr;//????????		
	}
	else
	{
		LNode *p = HL;

		while (p->next != NULL)
			p = p->next;    //�ҵ����λ��

		p->next = newptr;

	}

}
//**10.������ı�ͷ����һ��Ԫ��
void InsertFront(LNode *&HL, const ElemType &item)
{
	LNode *newptr;
	newptr = new LNode;  // �����ڴ�

	if (newptr == NULL)
	{
		cerr << "Memory allocation error!";
		exit(1);
	}                 //�ݴ�

	newptr->data = item;
	newptr->next = HL;
	HL = newptr;        //˳���ܴ�
}
//11.������������������λ�ò���һ��Ԫ��
void Insert(LNode *&HL, const ElemType &item)
{
	LNode *newptr;
	newptr = new LNode;  // �����ڴ�

	if (newptr == NULL)
	{
		cerr << "Memory allocation error!";
		exit(1);
	}                 //�ݴ�

	newptr->data = item;
	LNode *cp = HL;
	LNode *ap = NULL;
	while (cp != NULL)
	if (item.minq<cp->data.minq)//���û�õ�����,�ҵ��պñ�cpС��λ�ò��ȥ,cp�ں�
		break;
	else
	{
		ap = cp;
		cp = cp->next; //apʼ����cp�ĺ���			
	}
	if (ap == NULL)
	{
		newptr->next = HL;
		HL = newptr;  //ͷ������
	}
	else
	{
		newptr->next = cp;
		ap->next = newptr; //����ap��cp֮�䣬���˳���ܴ�
	}
}
//**12.������������������λ�ò���һ��Ԫ��
void InsertItem(LNode *HL, const ElemType &item);
//**13.��������ɾ����1��Ԫ��
ElemType  DeleteFront(LNode *&HL, const ElemType &item)
{
	if (HL == NULL)
	{
		cerr << "deleting front error!";
		exit(1);
	}  //�п�
	LNode *p = HL;
	HL = HL->next;
	ElemType  temp = p->data;
	delete p;
	return temp; //����ɾ����ֵ
}



//14.��������ɾ��һ��Ԫ��
int Delete(LNode *HL, const ElemType &item)
{
	if (HL == NULL)
	{
		cerr << "deleting front error!";
		return 0;
	}  //�п�


	LNode *cp = HL;
	LNode *ap = NULL;
	while (cp != NULL)
	if (strcmp(cp->data.code, item.code) == 0)
		break;
	else
	{
		ap = cp;
		cp = cp->next; //apʼ����cp�ĺ���
	} //����


	if (cp == NULL)
	{
		cerr << "deleted element error!";
		return 0;
	}  //���insert���һ���ж�

	if (ap == NULL)
		HL = HL->next;
	else
		ap->next = cp->next; //ɾͷɾ�󷽷���һ��
	delete cp;
	return 1;  //��������������Ҫ��Ҫ��������		
}

//15.�������������
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
		delete p; //cp��������p����cpһֱ��ǰָ
	}
}


/*//**16.��������鲢
void Merge(LNode *HL1,LNode *HL2,LNode *HL);*/


//17.����˵��
void help()
{
	cout << endl;
	cout << "      ---------------------------------------------------------------------" << endl;
	cout << "      ������ʾ:" << endl;
	cout << "         ϵͳ��Ҫ����������,��һ�������ǲ鿴����,�κ��˿��Բ鿴��������" << endl;
	cout << "      ����־�ļ�(050902--050905),���ĳ������ļ���ʧ��,����ͨ�������ָ�," << endl;
	cout << "      ��Ҳ�����ڴ˽���鿴��ĳ�յĽ��ͳ�����,��Ի�������ɽ���ڶ�����," << endl;
	cout << "      �ڶ��������ǲ�������,ֻ�в���Ա����ͨ���������,���Զ�ĳ��ָ���Ŀ�" << endl;
	cout << "      ���ļ����н���,���,ɾ��,����,��ѯ����,������������Ա�ϵͳ����,�ļ���" << endl;
	cout << "      ���Զ�,�������,��ֱ���˻ص��鿴����鿴��,�����Բ�����ʾ��,������ʾ��" << endl;
	cout << "      ����,ϵͳ���ܻ���������,ϣ���ܸ���ָ������!" << endl;
	cout << "      ����:yhy178@sina.com  " << endl << "      qq:304962214  " << endl;
	cout << "      ---------------------���޹����һ�ӭ���ĵ���!--------------------------" << endl << endl;;
}




//18.�����ѯ
void search(LNode *HL)
{
	int i, j = 1;
	LNode *p = HL;
	ElemType q[100]; //�ṹ������
	ElemType item;
	cout << "      �Ժ��ַ�ʽ��ѯ: 1.������  2.�ҵ�����   3.����Ʒ��   4.����   5.���� " << endl;
	cout << "      ��������ѡ��:";
	cin >> i;
	while (i<1 || i>5)
	{
		cout << "      ������������ѡ��(1-5):";
		cin >> i;
	}
	cout << "      ��������Ҫ������Ϣ:";
	switch (i)
	{
	case 1:
		cin >> item.code;
		while (p != NULL)
		if (strcmp(p->data.code, item.code) == 0) //ֻҪ���������Ķ��ɼӽ��ṹ����ȥ					
		{
			q[j] = p->data;
			j++;
			p = p->next;
		}
		else
			p = p->next; //���в���
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
			p = p->next; //���в���
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
			p = p->next; //���в���
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
			p = p->next; //���в���
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
			p = p->next;  //���в���
		break;
	default:
		cout << " Selection error!";
		break;
	}
	cout << endl << "      ���ҵ�" << j - 1 << "����Ϣ����:" << endl;
	cout << "      ------------------------------------------------------------------" << endl;
	cout << "      ������      " << "�ҵ�����         " << "����Ʒ��     " << "����      " << "����         " << endl;
	for (int k = 1; k<j; k++)  //��ʾ�ṹ��
		cout << q[k];
	cout << "      ------------------------------------------------------------------" << endl << endl;
}


//19.��־�鿴
void rizhichakan()
{
	char c[10];
	ElemType r[20], s[20], t[20];
	int x = 1, y = 1, z = 1, p = 1, q = 1, v = 1;
	cout << "      ����������־�ļ���(�� r050904.dat):";
	cin >> c;
	ifstream ifstr(c, ios::in | ios::nocreate); //��Ȩ�ޣ������ͬʱ��
	if (!ifstr)
	{
		cerr << "File 'goods' not found!" << endl;
		exit(1);
	}  //�ݴ�:�跨��������������������ļ�
	char d[5];//��Ϊ�ǱȽ������ַ�������Ҫһ������
	ifstr >> d;
	while (strcmp(d, "j") == 0)
	{
		ifstr >> r[x].code >> r[x].name >> r[x].mark >> r[x].minq >> r[x].curq;
		ifstr >> d[0]; //���鸳�����������Ըĳ���Ԫ��
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
	cout << "      ע��: j--����,t--���,s--ɾ��  " << endl;
	cout << "      -------------------------------------------------------------------------" << endl;
	cout << "      ����   " << "������      " << "�ҵ�����         " << "����Ʒ��     " << "����      " << " ������  " << endl;

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

//20.��־����
void rizhibaocun(ElemType *r, ElemType *s, ElemType *t, int x, int y, int z)
{
	char a[20];
	int p = 1, q = 1, v = 1;
	cout << "      ��������־�ļ���:( �� r050904.dat ):";
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

//21.��־ͳ��
void rizhitongji()
{
	char c[10], d[5];
	ElemType r[20], s[20], t[20];
	int x = 1, y = 1, z = 1, p = 1, q = 1, v = 1;
	long int e = 0, f = 0, g = 0, m;
	cout << "      ����������־�ļ���(�� r050904.dat):";
	cin >> c;
	ifstream ifstr(c, ios::in | ios::nocreate); //��Ȩ�ޣ������ͬʱ��
	if (!ifstr)
	{
		cerr << "File 'goods' not found!" << endl;
		exit(1);
	}  //�ݴ�:�跨��������������������ļ�

	ifstr >> d;//��Ϊ�ǱȽ������ַ�������Ҫһ������
	while (strcmp(d, "j") == 0)
	{
		ifstr >> r[x].code >> r[x].name >> r[x].mark >> r[x].minq >> r[x].curq;
		ifstr >> d[0]; //���鸳�����������Ըĳ���Ԫ��
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
	cout << "      �����̳�����" << x - 1 << "�ֻ���,����" << e << "Ԫ" << endl;
	cout << "      �����̳�����" << y - 1 << "�ֻ���,����" << f << "Ԫ" << endl;
	cout << "      �����̳�ɾ��" << z - 1 << "�ֻ���,����" << g << "Ԫ" << endl;
	cout << "      �����Ƿ��ʽ����̳���Ӫ��" << m << "Ԫ" << endl;
	cout << "      ------------------------------------------------------------------" << endl;
}



//////goodsmanage.cpp

#include<iostream.h>//cin();cout();
#include<stdlib.h>//cerr()
#include<iomanip.h>//setw()
#include<string.h>
#include<fstream.h>//ifstr();ofstr();
#include"link.h"

const int MaxSize = 10;
struct goods
{
	char code[5];//������
	char name[15];//��Ʒ����
	char mark[15];//����Ʒ��
	int minq;    //����
	int  curq;    //����
};

typedef  goods  ElemType;


ostream& operator<<(ostream&  ostr, const ElemType &x) //�������������ֻ�Խṹ��
{
	ostr << "       " << x.code << setw(16) << x.name << setw(16) << x.mark << setw(10) << x.minq << setw(10) << x.curq << endl;
	return ostr;
}

void SetupGoodsList(LNode *&L, char *fname)//���ļ������ṹ���Ȼ�󽫽ṹ��һ�������������ϣ��γ�һ������
{
	ifstream ifstr(fname, ios::in | ios::nocreate); //��Ȩ�ޣ������ͬʱ��
	if (!ifstr)
	{
		cerr << "File 'goods' not found!" << endl;
		exit(1);
	}  //�ݴ�:�跨��������������������ļ�
	goods g;
	while (ifstr >> g.code)
	{
		ifstr >> g.name >> g.mark >> g.minq >> g.curq;
		InsertRear(L, g);
	}
	ifstr.close();
}

void WriteGoodsFile(char *fname, LNode *&L) //�������гɽṹ�壬Ȼ�󽫽ṹ��������ļ�
{
	ofstream ofstr(fname);
	if (!ofstr)
	{
		cerr << "File 'goods' no creat";
		exit(1);
	}
	goods g;
	int n = ListLength(L);  //�õ��ṹ�����Ŀ
	for (int i = 1; i <= n; i++)
	{
		g = GetElem(L, i);      //ѭ�������n���ṹ��
		ofstr << g.code << setw(16) << g.name << setw(12) << g.mark << setw(12) << g.minq << setw(14) << g.curq << endl;
	}
	ofstr.close();
}


void huifu()  //��֪��ʧ���յ���־��������ļ�����ǰһ��Ŀ���ļ���,�ָ��ļ�
{
	char a[20], b[20], c[20], d[5];
	ElemType r[20], s[20], t[20];
	int x = 1, y = 1, z = 1, p = 1, q = 1, v = 1, m, n;
	LNode *L2;
	InitList(L2);
	cout << "      ����������ʾ����,�ҽ������ָ���ʧ�Ŀ���ļ�!" << endl;
	cout << "      �������뵱����־�ļ���(�� r050904.dat):";
	cin >> c;
	ifstream ifstr(c, ios::in | ios::nocreate); //��Ȩ�ޣ������ͬʱ��
	if (!ifstr)
	{
		cerr << "File 'goods' not found!" << endl;
		exit(1);
	}  //�ݴ�:�跨��������������������ļ�

	ifstr >> d;//��Ϊ�ǱȽ������ַ�������Ҫ����d��һ������
	while (strcmp(d, "j") == 0)
	{
		ifstr >> r[x].code >> r[x].name >> r[x].mark >> r[x].minq >> r[x].curq;
		ifstr >> d[0]; //���鸳�����������Ըĳ���Ԫ��
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

	cout << "      ��������ǰһ��Ŀ���ļ���(��ku050904.dat):";
	cin >> a;
	SetupGoodsList(L2, a);
	for (p = 1; p<x; p++)
	{
		m = r[p].curq;
		if (Find(L2, r[p]))//�ɻ����
		{
			r[p].curq += m;
			Update(L2, r[p]);
		}
		else 	InsertRear(L2, r[p]);//�»�����
	}
	for (q = 1; q<y; q++)
	{
		n = s[q].curq;
		Find(L2, s[q]);
		s[q].curq -= n;//�ɻ�����
		Update(L2, s[q]);
	}
	for (v = 1; v<z; v++)
		Delete(L2, t[v]);//�ɻ�ɾ��

	cout << "      �����붪ʧ�Ŀ���ļ���(�� ku050904.dat):";
	cin >> b;
	WriteGoodsFile(b, L2);//���ºõĿ������浵
	cout << "      �ѻָ�,�����ڲ鿴�����в鿴��!" << endl;
}




void caozuo()
{
	ElemType r[100], s[100], t[100]; //�����������		
	int x = 1, y = 1, z = 1, m, n;
	char  a[20], b[20];
	int i;  //���ַ��Ͳ���,����45����ִ��4,5�������
	int flag = 1;
	LNode *L1;
	InitList(L1);
	goods g;
	cout << "      ��������Ҫ�����Ŀ���ļ���( �� ku050904.dat ):";
	cin >> a;
	SetupGoodsList(L1, a);	//��Ҫ�����Ŀ���ļ�ת������

	while (flag)
	{
		cout << endl;
		cout << "      * * * * * * * * * * * * * * ��Ʒ����ϵͳ* * * * * * * * * * * * * * **" << endl;
		cout << "      *               ��ӭ�����������,����������ʾ����,лл!              *" << endl;
		cout << "      *                           1.��ʾ���                               *" << endl;
		cout << "      *                           2.����                                   *" << endl;
		cout << "      *                           3.���                                   *" << endl;
		cout << "      *                           4.ɾ��                                   *" << endl;
		cout << "      *                           5.����                                   *" << endl;
		cout << "      *                           6.��ѯ                                   *" << endl;
		cout << "      *                           7.����                                   *" << endl;
		cout << "      *                           8.�Ƴ�����                               *" << endl;
		cout << "      * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * **" << endl << endl;
		cout << setw(19) << "��������ѡ��:";           //????????setw(19),�������ô������ûЧ�����������?
		cin >> i;
		while (i<1 || i>8)
		{
			cout << "      ������������ѡ��(1-8):";
			cin >> i;
		}
		switch (i)
		{
		case 1:TraverseList(L1);  break;//��ӡ
		case 2:                 //�޸�		
			cout << setw(19) << "      �������������Ʒ�����:";//????????��setw(),������ûЧ��??
			cin >> g.code;
			if (Find(L1, g))
			{
				cout << "      �������������Ʒ����:";
				cin >> m;
				g.curq += m;      //ֱ�Ӽӵ����п����		
				r[x] = g;         //���������ʱ������
				r[x].curq = m;
				x++;
				Update(L1, g);
			}
			else
			{
				cout << "      ���������½�����Ʒ�����ֶ�����:";//�Ҳ�����β��
				cin >> g.name >> g.mark >> g.minq >> g.curq;
				r[x] = g;        //���������ʱ������
				x++;
				InsertRear(L1, g);
			}
			TraverseList(L1);
			break;
		case 3:                        //����Ʒ�����
			cout << "      �������������Ʒ�����:";
			cin >> g.code;
			if (Find(L1, g))
			{
				cout << "      ���������������Ʒ��:";
				cin >> n;
				g.curq -= n;  //ֱ�������п���ϼ���
				s[y] = g;    //������������
				s[y].curq = n;
				y++;
				Update(L1, g);
				TraverseList(L1);
			}
			else
				cout << "      �Բ���,û���ҵ���Ҫ����Ʒ!" << endl << endl;//�Ҳ�����β��

			break;
		case 4:
			cout << "      ���������ɾ��Ʒ����:";
			cin >> g.code;
			Find(L1, g);  //�����¼������������,����Ҫ
			t[z] = g;
			z++;
			Delete(L1, g);
			TraverseList(L1);
			break;
		case 5:
			Sort(L1);                  //��ν�����������������
			TraverseList(L1);
			break;
		case 6:
			search(L1);         //���ղ�ͬ�ķ�ʽ��ѯ
			break;

		case 7:
			cout << "      ���������ļ���:( �� ku050904.dat ):";
			cin >> b;
			WriteGoodsFile(b, L1);//������д������ļ���ȥ
			rizhibaocun(r, s, t, x, y, z); //��־�ļ�����
			cout << "      �������,лл����ʹ��,�������ݽ�������!" << endl;
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
		cout << "      * * * * * * * * * * * * * * ��Ʒ����ϵͳ* * * * * * * * * * * * * * **" << endl;
		cout << "      *                ��ӭ����鿴����,����������ʾ����,лл!             *" << endl;
		cout << "      *                           1. ���鿴                              *" << endl;
		cout << "      *                           2. ��־�鿴                              *" << endl;
		cout << "      *                           3. ��Ʒ����                              *" << endl;
		cout << "      *                           4. �����Ķ�                              *" << endl;
		cout << "      *                           5. ϵͳ�ָ�                              *" << endl;
		cout << "      *                           6. ���ͳ��                              *" << endl;
		cout << "      *                           7. �˳��鿴                              *" << endl;
		cout << "      * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * **" << endl << endl;
		cout << setw(19) << "��������ѡ��:";           //????setw(19),�������ô������ûЧ�����������?
		cin >> i;
		while (i<1 || i>7)
		{
			cout << "      ������������ѡ��(1-7):";
			cin >> i;
		}
		switch (i)
		{
		case 1:
			cout << "      ����������Ҫ�鿴�Ŀ���ļ���(�� ku050904.dat):";
			cin >> a;
			SetupGoodsList(L3, a);
			cout << "      ��Ҫ�鿴�Ŀ���ļ�Ϊ:" << endl;
			TraverseList(L3);
			ClearList(L3);
			break;
		case 2:
			rizhichakan();    //���ļ��������
			break;
		case 3:
			char q[20];
			cout << "      ���������Ա����(1234):";
			cin >> q;
			if (strcmp(q, "1234") == 0)
				caozuo();
			else
				cout << "      �Բ���,�������,���ܽ���!" << endl;
			break;
		case 4: help();   break;
		case 5:  huifu();   break;//�ָ�
		case 6:  rizhitongji(); break;
		case 7:
			cout << "      лл�ۿ�!" << endl;
			flag = 0;
			break;
		}
	}
}