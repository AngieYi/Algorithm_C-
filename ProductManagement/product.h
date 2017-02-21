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