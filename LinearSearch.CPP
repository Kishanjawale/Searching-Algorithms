#include<iostream>
using namespace std;
int LinearSearch(int *Arr,int size, int No )
{
    int iCnt=0;
    int Ret=0;
    if(size=0)
    {
        return -2;
    }
    for(iCnt=0;iCnt<size;iCnt++)
    {
        if(Arr[iCnt]==No)
        {
            return iCnt;
        }
    }
    return -1;
}
int main()
{
    int Size=0;
    int IRet=0;

    cout<<"Enter the Size of Array"<<endl;
    cin>>Size;
    
    int Arr[Size];

//Accepting Array From user
    cout<<"Enter The Array:"<<endl;
    
    for(int iCnt=0;iCnt<Size;iCnt++)
    {
        cin>>Arr[iCnt];
    }
   
    int Search;
    cout<<"Enter the element to search"<<endl;
    cin>>Search;

    IRet=LinearSearch(Arr,Size,Search);
    
    if(IRet==-1)
    {
        cout<<"element Not  Found"<<endl;
    }
    else if(IRet=-2)
    {
        cout<<"Array is Empty";
    }
    else
    {
        cout<<"Element Found at position:"<<IRet<<endl;
    }
    return 0;
}