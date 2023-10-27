#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"enter number of students ";
    cin>>n;
    int m;
    cout<<"enter number of subjects ";
    cin>>m;
    int arr[n][m];
    for(int i=0;i<n;i++)
    {
        int sum=0;
        for(int j=0;j<m;j++)
        {
            cout<<"enter marks of student "<<i+1<<" in subject "<<j+1<<" ";
            cin>>arr[i][j];
            sum+=arr[i][j];
        }
        cout<<"sum of student "<<i+1<<" is "<<sum<<endl;
    }
    for(int j=0;j<m;j++)
    {
        float sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=arr[j][i];
        }
        cout<<"average of subject "<<j+1<<" is "<<sum/n<<endl;
    }

}