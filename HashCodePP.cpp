#include<iostream>
#include<algorithm>
using namespace std;
int ans=0;//Answer Variable
int arr1[10000];
int iter1=0;//iter1able for arr1
int arr2[10000];
int arr3[10000];
int arr4[10000];
int PointStartEnd(int *arr, int types, long long int ppl)//Array, Types People respectively
{
    int Sptr=0;//Start Pointer
    int Eptr=types-1;//End Pointer
    int sumnew=0;//New Sum to be checked
    while(Sptr<=Eptr)
    {
        sumnew+=arr[Sptr]+arr[Eptr];
        if(sumnew==ppl)//Checking for Equality Condition
        {
            arr1[iter1++]=Eptr;
            arr1[iter1++]=Sptr;
            sort(arr1,arr1+iter1);//Sorting the Array
            return sumnew;
        }
        if(sumnew>ppl)
        {
            sumnew=sumnew-arr[Sptr];
            arr[iter1-1]=arr[iter1];
            iter1--;
        }
        if(sumnew<ppl)
        {
            arr1[iter1++]=Eptr;
            arr1[iter1++]=Sptr;
        }
        Sptr++;
        Eptr--;
    }
    sort(arr1,arr1+iter1);//Final sort Out of the Loop
    return sumnew;
}
int main()
{
    //Declaration of Variables
    long long int ppl=0;//Number of People
    int types=0;//Types of People
    int arr[100000];//Array Of Pizzas
    int answer=0;
    //Input data
    cin>>ppl;
    cin>>types;
    for(int i=0;i<types;i++)
    {
        cin>>arr[i];
    }
    //Functions Begin here
    answer=PointStartEnd(arr, types, ppl);
    cout<<answer<<endl;
    for(int i=0;i<iter1;i++)
    {
        cout<<arr1[i]<<" ";
    }
    return 0;
}
