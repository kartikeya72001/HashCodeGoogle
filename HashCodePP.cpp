#include<iostream>
#include<algorithm>
using namespace std;
int ans=0;//Answer Variable
int arr1[10000];
int iter1=0;//iterate1able for arr1
int arr2[10000];
int iter2=0;
int arr3[10000];
int iter3=0;
int arr4[10000];
int iter4=0;
int arr5[10000];
int iter5=0;
int arr6[10000];
int iter6=0;
//Function1
int PointStartEnd(int *arr, int types, long long int ppl)//Array, Types People respectively
{
    int Sptr=0;//Start Pointer
    int Eptr=types-1;//End Pointer
    int sumnew=0;//New Sum to be checked
    while(Sptr<=Eptr)
    {
        sumnew+=arr[Sptr]+arr[Eptr];
        arr1[iter1++]=Eptr;
        arr1[iter1++]=Sptr;
        if(sumnew==ppl)//Checking for Equality Condition
        {
            sort(arr1,arr1+iter1);//Sorting the Array
            return sumnew;
        }
        if(sumnew>ppl)
        {
            sumnew=sumnew-arr[Sptr];
            arr[iter1-1]=arr[iter1];
            iter1--;
        }if(sumnew>ppl)
        {
            sumnew=sumnew-arr[Eptr];
            iter1--;
        }
        if(sumnew<ppl)
        {
            Sptr++;
            Eptr--;
        }
    }
    sort(arr1,arr1+iter1);//Final sort Out of the Loop
    return sumnew;
}
//Function2
int PointStartEnd2(int *arr, int types, long long int ppl)//Array, Types People respectively
{
    int Sptr=0;//Start Pointer
    int Eptr=types-1;//End Pointer
    int sumnew=0;//New Sum to be checked
    while(Sptr<=Eptr)
    {
        sumnew+=arr[Sptr]+arr[Eptr];
        arr2[iter2++]=Sptr;
        arr2[iter2++]=Eptr;
        if(sumnew==ppl)//Checking for Equality Condition
        {
            sort(arr2,arr2+iter2);//Sorting the Array
            return sumnew;
        }
        if(sumnew>ppl)
        {
            sumnew=sumnew-arr[Eptr];
            iter2--;
        }
        if(sumnew>ppl)
        {
            sumnew=sumnew-arr[Sptr];
            iter2--;
        }
        if(sumnew<ppl)
        {
            Sptr++;
            Eptr--;
        }
    }
    sort(arr2,arr2+iter2);//Final sort Out of the Loop
    return sumnew;
}
//Function 3
int PointIntCenter2(int *arr, int types, long long int sum)
{
    //Variables
    int middleLeft = types/2-1;
    int middleRight=types/2;
    long long int newsum=0;
    while(middleLeft>=0 && middleRight<types)
    {
        if(newsum == sum)//To check if got the correct sum
        {
            sort(arr4,arr4+iter3);
            return newsum;
        }
        newsum+=arr[middleLeft]+arr[middleRight];
        arr4[iter4++]=middleRight;
        arr4[iter4++]=middleLeft;
        if(newsum>sum)
        {
            newsum-=arr[middleLeft];
            iter4--;
        }
        if(newsum>sum){
            newsum-=arr[middleRight];
            iter4--;
        }
        middleRight++;
        middleLeft--;
    }
    sort(arr4,arr4+iter4);
    return newsum;

}
//Function 4
int PointIntCenter(int *arr, int types, long long int sum)
{
    //Variables
    int middleLeft = types/2-1;
    int middleRight=types/2;
    long long int newsum=0;
    while(middleLeft>=0 && middleRight<types)
    {
        if(newsum == sum)//To check if got the correct sum
        {
            sort(arr3,arr3+iter3);
            return newsum;
        }
        newsum+=arr[middleLeft]+arr[middleRight];
        arr3[iter3++]=middleLeft;
        arr3[iter3++]=middleRight;
        if(newsum>sum)
        {
            newsum-=arr[middleRight];
            iter3--;
        }
        if(newsum>sum){
            newsum-=arr[middleLeft];
            iter3--;
        }
        middleRight++;
        middleLeft--;
    }
    sort(arr3,arr3+iter3);
    return newsum;

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
    cout<<"Case 1"<<endl;
    answer=PointStartEnd(arr, types, ppl);
    cout<<answer<<endl;
    for(int i=0;i<iter1;i++)
    {
        cout<<arr1[i]<<" ";
    }
    cout<<"Case 2"<<endl;
    answer=PointStartEnd2(arr, types, ppl);
    cout<<answer<<endl;
    for(int i=0;i<iter2;i++)
    {
        cout<<arr2[i]<<" ";
    }
    return 0;
}
