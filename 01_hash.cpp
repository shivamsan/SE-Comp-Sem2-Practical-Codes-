#include<iostream>
using namespace std;

class tele
{
    int prob;
    int arr[10] = {0};
    int col[10] = {0};
    string client[10]={"0"};

    public:

    void display(int n)
    {
         //display
        cout<<"client name "<<" telephone num "<<"collisons occured"<<endl;
		for (int i=0; i<n; i++)
        {
            cout << client[i] <<"\t\t";
			cout << arr[i] << "\t\t";
            cout << col[i]<<endl;
		}
    }
    void linear(int n)
    {
        int choice = 1;
        while (choice == 1)
        {
		int key;
        string name;

        cout<<"Enter name of client: "<<endl;
        cin>>name;
		cout << "Enter telephone no: " << " ";
		cin >> key;

		int d;
		d = key%10;
		int c = 0;

		for (int i=0; i<n; i++){
            
			if ((arr[d] > 0)&&(d<n) )
            {
				d++;
				c++;
			}
            else if(d>=n)
            {
                d=n-d;
                if (arr[d]>0)
                {
                    d++;
                }
            }

		}

        col[d] = c;
		arr[d] = key;
        client[d]=name;

        display(n);

        cout << endl;
		
        cout<<"do you want to enter another number? " << endl;
		cout << "Enter choice 0/1 ";
		cin >> choice;

	}
    }

    void quad(int n)
    {
        int choice = 1;
        while (choice == 1)
        {
		int key;
        string name;

        cout<<"Enter name of client: "<<endl;
        cin>>name;
		cout << "Enter telephone no: " << " ";
		cin >> key;

		int d;
		d = key%10;
		int c = 0;

		for (int i=0; i<n; i++){
            
			if ((arr[d] > 0)&&(d<n) )
            {
				d=(key+i*i)%10;
				c++;
			}
            else if(d>=n)
            {
                d=n-d;
                if (arr[d]>0)
                {
                    d=(key+i*i)%10;
                }
            }

		}

        col[d] = c;
		arr[d] = key;
        client[d]=name;

        display(n);

        cout << endl;
		
        cout<<"do you want to enter another number? " << endl;
		cout << "Enter choice 0/1 ";
		cin >> choice;

	}
    }

    void hash(int n)
    {
        cout<<"select btw linear probing and quad probing"<<endl;
        cout<<"1. Linear probing"<<endl;
        cout<<"2. Quad probing"<<endl;
        cout<<"enter choice 1/2: ";
        cin>>prob;
        if (prob == 1)
        {
            linear(n);
        }
        else if (prob == 2)
        {
            quad(n);
        }
        else
        {
            cout<<"invalid choice"<<endl;
        }
    }

    void search_key(int n)
    {
        int search;
        cout<<"enter key to search"<<endl;
        cin >> search;

        for(int i=0; i<n; i++)
        {
            if(arr[i] ==search)
            {
                cout<<"key found at "<<i<<" index"<<endl;
            }
        }
    }

};

int main()
{
    tele h;
    
	int n;
    cout<<"enter the capacity of the database: "<<endl;
    cin >> n;
    while(1)
    {
    cout<<"----------------telephone database------------------- "<<endl;
    cout<<"1. insert into the database"<<endl;
    cout<<"2. search from the database"<<endl;
    cout<<"3. exit"<<endl;
    cout <<"enter choice : ";

    int in;
    cin >> in;
    if (in==1)
    {
        h.hash(n);
    }
    else if(in ==2)
    {
        h.search_key(n);
    }
    else if (in ==3)
    {
        cout<<"exitinf................................"<<endl;
        break;
    }
    else
    {
        cout<<"invalid choice"<<endl;
    }
    }
}