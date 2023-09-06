//#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
using namespace std;
struct us
{
	char azg[10];
	int gn;
	int bac;
	int nk;
};

struct node
{
	node* firstPtr;
	us value;
	node* secondPtr;
};

class A
{
private:
	node* h;
	int size;

public:
	A()
	{
		size = 0;
	}
	A(A& obj)
	{
		this->h = new node;
		this->h = obj.h;

		this->size = obj.size;
	}
	~A()
	{
		for (int i = 0; i < size - 1; i++)
		{
			h = h->secondPtr;
			delete h->firstPtr;
			h->firstPtr = 0;
		}
		delete h;
		h = 0;
	}

	void Tpel()
	{


		int k = 0;
		node* h1 = h;
		while (k < size)
		{
			cout << "Azganun: " << h1->value.azg << "\t";
			cout << "Gnahatakan: " << h1->value.gn << "\t";
			cout << "Bacakayutyun: " << h1->value.bac << "\t";
			cout << "Nkatoghutyun: " << h1->value.nk << endl;
			//cout << h1->firstPtr << " " << h1->value.azg << " " << h1->value.gn << " " << h1->value.bac << " " << h1->value.nk << " " << h1->secondPtr << endl;
			h1 = h1->secondPtr;
			k++;
		}
		cout << endl;
	}

	void CreateFirst(us v)
	{
		h = new node;
		h->value = v;
		h->firstPtr = h;
		h->secondPtr = h;

		size += 1;
	}

	void AddFtBeginning(us v)
	{
		node* t = new node;
		t->value = v;
		t->secondPtr = h;

		t->firstPtr = h->firstPtr;
		t->firstPtr->secondPtr = t;
		h->firstPtr = t;
		h = t;
		size++;
	}

	void AddFtEnd(us v)
	{
		int k = 0;
		node* t = new node;
		t->value = v;
		t->secondPtr = h;

		node* h1 = h;
		while (k < size - 1)
		{
			h1 = h1->secondPtr;
			k++;
		}

		h1->secondPtr = t;
		t->firstPtr = h1;
		h->firstPtr = t;

		size++;
	}

	void AddCurrent(us v, int a)
	{
		node* t = new node;
		t->value = v;

		node* h1 = h;

		for (int i = 1; i < a; i++)
		{
			h1 = h1->secondPtr;
		}

		t->secondPtr = h1;
		h1->firstPtr->secondPtr = t;
		t->firstPtr = h1->firstPtr;
		h1->firstPtr = t;
		size++;
	}

	void DeleteFtBeginning()
	{
		node* h1 = h;

		h1->firstPtr->secondPtr = h1->secondPtr;
		h1->secondPtr->firstPtr = h1->firstPtr;
		h = h1->secondPtr;

		size--;
		if (size == 0)
		{
			delete h;
			h = 0;
		}
	}

	void DeleteFtEnd()
	{
		node* h1 = h;

		h1->firstPtr = h1->firstPtr->firstPtr;
		h1->firstPtr->secondPtr = h1;

		size--;
		if (size == 0)
		{
			delete h;
			h = 0;
		}
	}

	void DeleteCurrent(int a)
	{
		node* h1 = h;

		for (int i = 1; i < a; i++)
		{
			h1 = h1->secondPtr;
		}
		h1->firstPtr->secondPtr = h1->secondPtr;
		h1->secondPtr->firstPtr = h1->firstPtr;

		if (a == 1)
		{
			h = h->secondPtr;
		}

		size--;
		if (size == 0)
		{
			delete h;
			h = 0;
		}
	}

	int ListLength()
	{
		return size;
	}

	int MinimalBac()
	{
		node* h1 = h;
		int min = h1->value.bac;
		h1 = h1->secondPtr;
		for (int i = 1; i < size; i++)
		{
			if (h1->value.bac < min)
				min = h1->value.bac;
			h1 = h1->secondPtr;
		}
		return min;
	}

	void MinBacUsanox(A& obj2, int minBac)
	{
		node* h1 = h;
		int k = 0;

		obj2.size = 0;

		for (int i = 0; i < size; i++)
		{
			if (h1->value.bac == minBac)
			{
				if (obj2.size == 0)
				{
					obj2.CreateFirst(h1->value);
				}
				else
				{
					obj2.AddFtEnd(h1->value);
				}
				k++;
			}
			h1 = h1->secondPtr;
		}
		if (k == 0)
		{
			cout << "Minimal bacakayutyun unecox hanguyc chi gtnvel" << endl;
		}
		else
		{
			obj2.Tpel();
		}
	}

	void MasterSwap(int n1, int n2)
	{
		if (size == 2)
		{
			h = h->secondPtr;
		}
		else if (((n1 - n2) * (n1 - n2) == 1) || (n1 == 1 && n2 == size) || (n2 == 1 && n1 == size))
		{
			NearSwap(n1, n2);
		}
		else
		{
			DistantSwap(n1, n2);
		}
	}

	void DistantSwap(int firstNode, int secondNode)
	{
		node* h1 = h;
		node* h2 = h;

		for (int i = 1; i < firstNode; i++)
		{
			h1 = h1->secondPtr;
		}
		node* prevH1 = h1->firstPtr;
		node* nextH1 = h1->secondPtr;

		for (int i = 1; i < secondNode; i++)
		{
			h2 = h2->secondPtr;
		}
		node* prevH2 = h2->firstPtr;
		node* nextH2 = h2->secondPtr;

		h1->secondPtr = nextH2;
		h1->firstPtr = prevH2;
		prevH2->secondPtr = h1;
		nextH2->firstPtr = h1;

		h2->firstPtr = prevH1;
		h2->secondPtr = nextH1;
		prevH1->secondPtr = h2;
		nextH1->firstPtr = h2;

		if (firstNode == 1)
		{
			h = h2;
		}
		else if (secondNode == 1)
		{
			h = h1;
		}

	}

	void NearSwap(int n1, int n2)
	{
		node* h1 = h;
		node* h2 = h;

		for (int i = 1; i < n1; i++)
		{
			h1 = h1->secondPtr;
		}
		node* prevH1 = h1->firstPtr;
		node* nextH1 = h1->secondPtr;

		for (int i = 1; i < n2; i++)
		{
			h2 = h2->secondPtr;
		}
		node* prevH2 = h2->firstPtr;
		node* nextH2 = h2->secondPtr;


		//stex 6 hat gorcoxutyuna vorovhetev irar kogh en!
		if (n2 - n1 == 1 || (n1 == size && n2 == 1))
		{
			h1->secondPtr = h2->secondPtr;
			h2->firstPtr = h1->firstPtr;
			nextH2->firstPtr = h1;
			prevH1->secondPtr = h2;
			h1->firstPtr = h2;
			h2->secondPtr = h1;
		}
		//stex miqich djvara, sax et irar kogh lineluca, te ova dzaxic ova ajic
		else if (n1 - n2 == 1 || (n2 == size && n1 == 1))
		{
			h2->secondPtr = h1->secondPtr;
			h1->firstPtr = h2->firstPtr;
			nextH1->firstPtr = h2;
			prevH2->secondPtr = h1;
			h2->firstPtr = h1;
			h1->secondPtr = h2;
		}

		if (n1 == 1)
		{
			h = h2;
		}
		else if (n2 == 1)
		{
			h = h1;
		}

	}
};

void Menu()
{
	cout << "1. Tpel cucaky" << endl;
	cout << "2. Stexcel arajin hanguycy" << endl;
	cout << "3. Avelacnel hanguyc skzbic" << endl;
	cout << "4. Avelacnel hanguyc verjic" << endl;
	cout << "5. Avelacnel hanguyc nshvac vayrum" << endl;
	cout << "6. Heracnel hanguyc skzbic" << endl;
	cout << "7. Heracnel hanguyc verjic" << endl;
	cout << "8. Heracnel hanguyc nshvac vayric" << endl;
	cout << "9. Hashvel minimal bacakayutyuny" << endl;
	cout << "10. Stanal ev tpel nor cucak minimal bacakayutyun unecoxneric" << endl;
	cout << "11. Texerov poxel erku kamayakan hanguyc" << endl;
	cout << "12. Poxel cucaky" << endl;
	cout << "13. Elq" << endl;
}

us Input()
{
	us val;

	cout << "Nermuceq` \n\t Azganun: ";
	cin >> val.azg;
	cout << "\t Gnahatakan: ";
	cin >> val.gn;
	cout << "\t Bacakayutyun: ";
	cin >> val.bac;
	cout << "\t Nkatoghutyun: ";
	cin >> val.nk;
	cout << endl;

	return val;
}

void Cases(A& obj, int _case)
{
	switch (_case)
	{
	case 1:
		if (obj.ListLength() > 0)
		{
			obj.Tpel();
		}
		else
		{
			cout << "Cucaky tpelu hamar petq e stexcel arnvazn 1 hanguyc" << endl;
		}

		break;

	case 2:
		if (obj.ListLength())
		{
			cout << "Arajin hanguycy arden stexcvac e" << endl;
		}
		else
		{
			obj.CreateFirst(Input());
		}

		break;

	case 3:

		if (obj.ListLength() > 0)
		{
			obj.AddFtBeginning(Input());
		}
		else
		{
			cout << "Petq e stexcel arajin hanguycy" << endl;
		}

		break;

	case 4:
		if (obj.ListLength() > 0)
		{
			obj.AddFtEnd(Input());
		}
		else
		{
			cout << "Petq e stexcel arajin hanguycy" << endl;
		}

		break;

	case 5:
		if (obj.ListLength() > 0)
		{
			int position;
			cout << "Nermuceq hanguyci gtnvelu vayry: ";
			cin >> position;

			if (position == 0)
			{
				cout << "Hashvarky sksvum e 1-ic" << endl;
			}
			else if (position == 1)
			{
				obj.AddFtBeginning(Input());
			}
			else if (position <= obj.ListLength())
			{
				obj.AddCurrent(Input(), position);
			}
			else if (position == obj.ListLength() + 1)
			{
				obj.AddFtEnd(Input());
			}
			else
			{
				cout << "Cucakum aydqan hanguyc chka" << endl;
			}
		}
		else
		{
			cout << "Petq e stexcel arajin hanguycy" << endl;
		}

		break;

	case 6:
		if (obj.ListLength() > 0)
		{
			if (obj.ListLength() > 0)
			{
				obj.DeleteFtBeginning();

				if (obj.ListLength() == 0)
				{
					cout << "Cucaky aylevs goyutyun chuni" << endl;
				}
			}
			else
			{
				cout << "Cucakum hanguyc chka" << endl;
			}
		}
		else
		{
			cout << "Petq e stexcel arajin hanguycy" << endl;
		}

		break;

	case 7:
		if (obj.ListLength() > 0)
		{
			if (obj.ListLength() > 0)
			{
				obj.DeleteFtEnd();

				if (obj.ListLength() == 0)
				{
					cout << "Cucaky aylevs goyutyun chuni" << endl;
				}
			}
			else
			{
				cout << "Cucakum hanguyc chka" << endl;
			}

		}
		else
		{
			cout << "Petq e stexcel arajin hanguycy" << endl;
		}

		break;

	case 8:
		if (obj.ListLength() > 0)
		{
			int position;
			cout << "Nermuceq hanguyci gtnvelu vayry: ";
			cin >> position;
			if (position <= 0)
			{
				cout << "Hashvarky sksvum e 1 - ic" << endl;
			}
			else
			{
				if (position <= obj.ListLength())
				{
					obj.DeleteCurrent(position);

					if (obj.ListLength() == 0)
					{
						cout << "Cucaky aylevs goyutyun chuni" << endl;
					}
				}
				else
				{
					cout << "Cucakum aydqan hanguyc chka" << endl;
				}
			}
		}
		else
		{
			cout << "Petq e stexcel arajin hanguycy" << endl;
		}

		break;

	case 11:
		if (obj.ListLength() > 0)
		{
			bool isInRange;
			int size = obj.ListLength();
			if (size != 1)
			{
				int n1;
				int n2;
				do
				{
					isInRange = true;

					cout << "Nermuceq arajin hanguyci hamary: ";
					cin >> n1;
					cout << endl << "Nermuceq erkrord hanguyci hamary : ";
					cin >> n2;

					if (n1 > size || n1 <= 0)
					{
						cout << "Arajin hamary cucaki chapseric durs e" << endl;
						isInRange = false;
					}
					if (n2 > size || n2 <= 0)
					{
						cout << "Erkrord hamary cucaki chapseric durs e" << endl;
						isInRange = false;
					}

				} while (!isInRange);

				if (n1 != n2)
				{
					obj.MasterSwap(n1, n2);
				}
				cout << endl << "Hanguycnery poxvecin texerov" << endl;
			}
			else
			{
				cout << "Hanguycneri texery poxelu hamar hanguycneri qanaky petq e 1-ic mec lini" << endl;
			}
		}
		else
		{
			cout << "Petq e stexcel arajin hanguycy" << endl;
		}
		break;

	default:
		cout << "Yntreq 1-13 keteric meky" << endl;
		break;
	}

}

int main()
{
	setlocale(LC_ALL, "hy_AM.UTF-8");
	system("CLS");
	int k;
	int minBac;
	bool isCreated = false;
	bool isMinBacFound = false;
	int choose = 0;
	us value;

	A obj;
	A obj2;


	do
	{
		Menu();

		cin >> k;

		switch (k)
		{
		case 9:

			if (choose)
			{
				cout << "Ays gorcoghutyuny katarelu hamar petq e yntreq 1-in cucaky" << endl;
			}
			else
			{
				if (obj.ListLength() > 0)
				{
					minBac = obj.MinimalBac();
					isMinBacFound = true;
					cout << "Minimal bacakayutyun - " << minBac << endl;
				}
				else
				{
					cout << "Petq e stexcel arajin hanguycy" << endl;
				}
			}

			break;

		case 10:

			if (choose)
			{
				cout << "Ays gorcoghutyuny katarelu hamar petq e yntreq 1-in cucaky" << endl;
			}
			else
			{
				if (obj.ListLength() > 0)
				{
					if (isMinBacFound)
					{
						obj.MinBacUsanox(obj2, minBac);
					}
					else
					{
						cout << "Nax petq e stanal minimal bacakyutyuny" << endl;
					}
				}
				else
				{
					cout << "Petq e stexcel arajin hanguycy" << endl;
				}
			}

			break;

		case 12:
			if (obj.ListLength() > 0)
			{
				if (isMinBacFound)
				{
					if (choose)
					{
						choose = 0;
						cout << "Yntrvac e 1-in cucaky" << endl;
					}
					else
					{
						choose = 1;
						cout << "Yntrvac e 2-rd cucaky" << endl;
					}
				}
				else
				{
					cout << "Cucaky poxelu hamar petq e ayn stexceq 10-rd keti ognutyamb" << endl;
				}
			}
			else
			{
				cout << "Petq e stexcel arajin hanguycy" << endl;
			}

			break;

		case 13:
			break;

		default:

			if (choose)
			{
				Cases(obj2, k);
			}
			else
			{
				Cases(obj, k);
			}

			break;

		}

		cout << endl;

	} while (k != 13);

	return 0;
}

