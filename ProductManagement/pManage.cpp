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
	char code[5];	//������
	char name[15];	//��Ʒ����
	char mark[15];	//����Ʒ��
	int minq;    	//����
	int  curq;    	//����
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