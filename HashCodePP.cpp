#include<iostream>
#include<algorithm>
using namespace std;
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
int Compare(long long int O1, long long int O2, long long int O3, long long int O4, long long int O5, long long int O6)
{
    int best=0;
    best=best>O1?best:O1;
    best=best>O2?best:O2;
    best=best>O3?best:O3;
    best=best>O4?best:O4;
    best=best>O5?best:O5;
    best=best>O6?best:O6;
    if(best==O1)
        return 1;
    else if(best==O2)
        return 2;
    else if(best==O3)
        return 3;
    else if(best==O4)
        return 4;
    else if(best==O5)
        return 5;
    else if(best==O6)
        return 6;


}
int main()
{
    long long int O1=0,O2=0,O3=0,O4=0,O5=0,O6=0,ans;
    //Declaration of Variables
    long long int ppl=0;//Number of People
    int types=0,c,d;//Types of People
    int arr[100000];//Array Of Pizzas
    //Input data
    cin>>ppl;
    cin>>types;
    for(int i=0;i<types;i++)
    {
        cin>>arr[i];
    }
    O1=PointStartEnd(arr,types,ppl);
    O2=PointStartEnd2(arr,types,ppl);
    O3=PointIntCenter(arr,types,ppl);
    O4=PointIntCenter2(arr,types,ppl);
    ans=Compare(O1,O2,O3,O4,O5,O6);
    if(ans==1){
        cout<<"\n"<<iter1<<"\n";
        for(int i=0;i<iter1;i++){
            cout<<arr1[i]<<" ";
        }
    }
    else if(ans==2){
        cout<<"\n"<<iter2<<"\n";
        for(int i=0;i<iter2;i++){
            cout<<arr2[i]<<" ";
        }
    }
    else if(ans==3){
        cout<<"\n"<<iter3<<"\n";
        for(int i=0;i<iter3;i++){
            cout<<arr3[i]<<" ";
        }
    }
    else if(ans==4){
        cout<<"\n"<<iter4<<"\n";
        for(int i=0;i<iter4;i++){
            cout<<arr4[i]<<" ";
        }
    }
    else if(ans==5){
        cout<<"\n"<<iter5<<"\n";
        for(int i=0;i<iter5;i++){
            cout<<arr5[i]<<" ";
        }
    }
    else if(ans==6){
        cout<<"\n"<<iter6<<"\n";
        for(int i=0;i<iter6;i++){
            cout<<arr6[i]<<" ";
        }
    }
    return 0;
}
