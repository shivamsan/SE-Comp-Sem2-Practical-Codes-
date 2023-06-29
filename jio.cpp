
#include <iostream>
using namespace std;

int main()
{

    int s;
    cout<<"Enter number of service providers : "<<endl;
    cin>>s;

    string o[s];
    cout<<"Enter the names of service provider : "<<endl;
    for(int i=0;i<s;i++)
        {
            cout << i+1 << " . office : ";
            cin>>o[i];

        }


    int n;
    cout<<"Enter number of cities : "<<endl;
    cin>>n;

    int a[n][n],b[n][n],d[n][n],e[n][n],f[n][n],z[n][n];
    a[n][n],b[n][n],d[n][n],e[n][n],f[n][n],z[n][n]={};


    string c[n];
    cout<<"Enter the names of cities : "<<endl;
    for(int i=0;i<n;i++)
    {
    cout << i+1 << " . City Name : ";
    cin >>c[i];
    }

    if(s>=1)
    {

    cout<<"for " + o[0]<<endl;
    cout<< "Enter time taken to travel from city to city "<< endl;
    for(int i=0;i<n;i++)
    {
    for(int j=0;j<n;j++)
    {
    cout << "Time taken to travel from  " << c[i] << " to " << c[j] << " : ";
    cin>>a[i][j];
    }
    }

    }

    if(s>=2)
    {
    cout<<"for " + o[1]<<endl;
    cout<< "Enter time taken to travel from city to city "<< endl;
    for(int i=0;i<n;i++)
    {
    for(int j=0;j<n;j++)
    {
    cout << "Time taken to travel from  " << c[i] << " to " << c[j] << " : ";
    cin>>b[i][j];
    }
    }
    }

    if(s>=3)
    {
    cout<<"for " + o[2]<<endl;
    cout<< "Enter time taken to travel from city to city "<< endl;
    for(int i=0;i<n;i++)
    {
    for(int j=0;j<n;j++)
    {
    cout << "Time taken to travel from  " << c[i] << " to " << c[j] << " : ";
    cin>>d[i][j];
    }
    }
    }

    if(s>=4)
    {
    cout<<"for " + o[3]<<endl;
    cout<< "Enter time taken to travel from city to city "<< endl;
    for(int i=0;i<n;i++)
    {
    for(int j=0;j<n;j++)
    {
    cout << "Time taken to travel from  " << c[i] << " to " << c[j] << " : ";
    cin>>e[i][j];
    }
    }
    }

    if(s>=5)
    {
    cout<<"for " + o[4]<<endl;
    cout<< "Enter time taken to travel from city to city "<< endl;
    for(int i=0;i<n;i++)
    {
    for(int j=0;j<n;j++)
    {
    cout << "Time taken to travel from  " << c[i] << " to " << c[j] << " : ";
    cin>>f[i][j];
    }
    }
    }
    
    if(s>=2)
    {
    for(int i=0;i<n;i++)
    {
    for(int j=0;j<n;j++)
    {
        if(a[i][j]<b[i][j])
        {
            z[i][j] = a[i][j];
        }
        else
        {
            z[i][j] = b[i][j];

        }
        
    }
    }
    }

    if(s>=3)
    {
    for(int i=0;i<n;i++)
    {
    for(int j=0;j<n;j++)
    {
        if(z[i][j]<d[i][j])
        {
            z[i][j] = z[i][j];
        }
        else
        {
            z[i][j] = d[i][j];

        }
        
    }
    }
    }

    if(s>=4)
    {
        
    for(int i=0;i<n;i++)
    {
    for(int j=0;j<n;j++)
    {
        if(z[i][j]<e[i][j])
        {
            z[i][j] = z[i][j];
        }
        else
        {
            z[i][j] = e[i][j];

        }
        
    }
    }
    }

    if(s>=5)
    {
    for(int i=0;i<n;i++)
    {
    for(int j=0;j<n;j++)
    {
        if(z[i][j]<f[i][j])
        {
            z[i][j] = z[i][j];
        }
        else
        {
            z[i][j] = f[i][j];
        }
    }
    }
    }

    cout<<"minimum spnaning graphs : "<<endl;

    for(int i=0;i<n;i++)
    {
    for(int j=0;j<n;j++)
    {
    cout<<z[i][j]<<"\t";
    }
    cout<<endl;
    }
}