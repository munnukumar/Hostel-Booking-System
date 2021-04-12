#include <iostream>
#include <string.h>
using namespace std;
struct node
{
	int num = 1;
	int fill = 0;
	char name[3][10];
	node* next;
	node* prev;
};
class hostel
{
	node* Floor[3];
	node* cf;

public:
	hostel()
	{
		for (int i = 0; i < 3; i++)
			Floor[i] = NULL;
	}
	void create()
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				node* nn = new node;
				nn->next = NULL;
				nn->prev = NULL;
				if (Floor[i] == NULL)
				{
					Floor[i] = nn;
					nn->num = 1;
				}
				else
				{
					node* cf = Floor[i];
					while (cf->next != NULL)
					{
						cf = cf->next;
					}
					if (j == 3 || j == 5 || j == 7 || j == 8)
					{
						cf->num = 3;
					}
					if (j == 2 || j == 4 || j == 6)
					{
						cf->num = 2;
					}
					cf->next = nn;
					nn->prev = cf;
				}
			}
		}
	}
	void display()
	{
		system("color 6d");
		int j = 0, k = 0, l = 0;
		for (int i = 0; i < 120; i++)
		{
			cout << "*";
		}
		cout << "\n ";
		for (int i = 1; i < 4; i++)
		{
			cout << "| Floor number : " << i << " \t\t\t\t";
		}
		cout << "|\n";
		for (int i = 0; i < 120; i++)
		{
			cout << "*";
		}
		cf = Floor[j];
		node* sf = Floor[j + 1];
		node* tf = Floor[j + 2];
		cout << "\n ";
		while (cf != NULL)
		{
			if (cf->fill != cf->num && cf->num != 0)
			{
				j++;
				cout << "| room no : " << j;
				cout << "->Available Beds are : " << cf->num;
			}
			else
			{
				j++;
				cout << "| room no : " << j;
				cout << "->No Beds are available in this room : ";
			}
			if (sf->fill != sf->num && sf->num != 0)
			{
				k++;
				cout << "\t | room no : " << j;
				cout << "->Available Beds are : " << sf->num;
			}
			else
			{
				k++;
				cout << " \t | room no : " << j;
				cout << "->No Beds are available in this room :  ";
			}
			if (tf->fill != tf->num && tf->num != 0)
			{
				l++;
				cout << "\t | room no : " << j;
				cout << "->Available Beds are : " << tf->num << "| ";
			}
			else
			{
				l++;
				cout << "\t | room no : " << j;
				cout << "->No Beds are available in this room :  " << " | ";
			}
			cout << " \n ";
			for (int i = 0; i < 48; i++)
			{
				cout << "--";
			}
			cout << "\n ";
			cf = cf->next;
			sf = sf->next;
			tf = tf->next;
		}
	}
	void book(int people)
	{
		system("color 8b");
		int floor, room;
		cout << "\n\t\t\t\t\t\t\t\t\tEnter the floor number : ";
		cin >> floor;
		try
		{
			if (floor < 0 || floor > 4)
			{
				
				throw (floor);
			}
			cf = Floor[floor - 1];

			cout << "\n\t\t\t\t\t\t\t\t\tEnter the room number : ";
			cin >> room;
			try
			{

				if (room < 0 || room > 10)
				{
					throw (room);
				}
				else
				{
					int i = 1;
					while (i < room)
					{
						cf = cf->next;
						i++;
					}
					if (cf->num >= people)
					{
						cout << "\n\t\t\t\t\t\t\t\t\troom is vacant you can apply for room";

						int count = 0;
						while (cf->fill - 1 <= cf->num)
						{

							cout << "\n\t\t\t\t\t\t\t\t\tEnter name " << cf->fill + 1 << " : ";

							cin >> cf->name[cf->fill];
							count++;
							cf->fill++;
							if (count >= people)
							{
								break;
							}
						}
						cf->num = cf->num - people;
					}

					else
					{
						cout << "\n\t\t\t\t\t\t\t\t\troom is not vacant... SORRY !!!";
					}
				}
			}
			catch (int r)
			{
				cout << "\n\t\t\t\t\t\t\t\t\tinvalid room number : " << r;
			}
		}
		catch (int r)
		{
			cout << " \n\t\t\t\t\t\t\t\t\tinvalid floor number : " << r;
		}
	}
	void cancle(int check)
	{
		char namecheck[10];
		int flag = 0;
		int room, i = 1;
		try
		{
			if (check < 0 || check > 4)

			{
				throw (check);
			}
			else
			{
				cout << "\t\t\t\t\t\t\t\t\t Enter the room no : ";
				cin >> room;
				try
				{
					if (room < 0 || room > 10)
					{
						throw (room);
					}
					else
					{
						cout << "\t\t\t\t\t\t\t\t\t Enter the name to be delete :";

						cin >> namecheck;
						cf = Floor[check - 1];
						while (i < room)
						{
							cf = cf->next;
							i++;
						}
						i = 0;
						while (i < 3)
						{

							if (!strcmp(namecheck, cf->name[i]))

							{
								flag = 1;
								break;
								i = 0;
							}
							else
								i++;
						}
						if (flag == 1 && cf->fill != 0)
						{
							cout << "\n\t\t\t\t\t\t\t\t\trecord deleted : " << cf->name[i];

							cf->name[i][0] = 'A';
							cf->name[i][1] = '\0';
							cf->fill--;
							cf->num++;
						}
						else

							cout << "\n\t\t\t\t\t\t\t\t\trecord not present ";
					}
				}
				catch (int r)
				{
					cout << "\n\t\t\t\t\t\t\t\t\tinvalid room number : " << r;
				}
			}
		}

		catch (int r)
		{
			cout << " \n\t\t\t\t\t\t\t\t\t floor dosn't exist : " << r;
		}
	}
	void upgrade(int check)
	{
		char namecheck[10];
		int room, i = 1;
		try
		{
			if (check < 0 || check > 4)

			{
				throw (check);
			}
			else
			{
				cout << "\t\t\t\t\t\t\t\t\t Enter the room no : ";
				cin >> room;
				try
				{
					if (room < 0 || room > 10)

					{
						throw (room);
					}
					else
					{
						cout << "\t\t\t\t\t\t\t\t\tEnter the name to be updated :";

						cin >> namecheck;
						cf = Floor[check - 1];
						while (i < room)
						{
							cf = cf->next;
							i++;
						}
						i = 0;
						while (i < 3)
						{
							if (!strcmp(namecheck, cf->name[i]))

							{
								cout << "\n\t\t\t\t\t\t\t\t\tenter updated name : ";

								cin >> cf->name[i];
								break;
							}
							else
								i++;
						}
						if (i >= 3)
							cout << "\t\t\t\t\t\t\t\t\trecord not found ";
						else
						{
							cout << "\n\t\t\t\t\t\t\t\t\trecord updated\nprevious name : " << namecheck
								<< "\n\t\t\t\t\t\t\t\t\tupdated name : " << cf->name[i];
						}
					}
				}
				catch (int r)
				{
					cout << "\n\t\t\t\t\t\t\t\t\tinvalid room number : " << r;
				}
			}
		}

		catch (int r)
		{
			cout << "\n \t\t\t\t\t\t\t\t\tfloor dosn't exist : " << r;
		}
	}
};

int main()
{

	hostel rent;
	int key;
	char ch;
	int floorcheck;
	
	system("color 3c");

	rent.create();
	do
	{
		cout << "\n\n\n\t\t\t\t\t\t\t\t\t 1. Display the current status of rooms :";
		cout << "\n\t\t\t\t\t\t\t\t\t 2. Book a room for one Bed :";
		cout << "\n\t\t\t\t\t\t\t\t\t 3. Book a room for two Bed :";
		cout << "\n\t\t\t\t\t\t\t\t\t 4. Book a room for three Bed :";
		cout << "\n\t\t\t\t\t\t\t\t\t 5. cancle a Bed :";
		cout << "\n\t\t\t\t\t\t\t\t\t 6. upgrade rooms status :";
		cout<< endl;
		cout << "\n\t\t\t\t\t\t\t\t\t Enter your choice : ";
		cin >> key;
		cout << "\n\n\n\n";
		switch (key)
		{
		case 1:
		{
			rent.display();
			break;
		}
		case 2:
		{
			rent.book(1);
			break;
		}
		case 3:
		{
			rent.book(2);
			break;
		}
		case 4:
		{
			rent.book(3);
			break;
		}
		case 5:
		{
			cout << "Enter floor number : ";
			cin >> floorcheck;
			rent.cancle(floorcheck);
			break;
		}
		case 6:
		{
			cout << "\t\t\t\t\t\t\t\t\tEnter floor number : ";
			cin >> floorcheck;
			rent.upgrade(floorcheck);
			break;
		}

		default:
			cout << "\n\t\t\t\t\t\t\t\t\tInvalid choice ";
		}
		cout << "\n\t\t\t\t\t\t\t\t\tDo you want to continue(Y / N) ";
		cin >> ch;
	} while (ch == 'Y' || ch == 'y');
}
