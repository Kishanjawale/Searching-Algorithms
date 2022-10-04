#include<iostream>
using namespace std;

int BinarySearch(int Arr[],int size,int Value)
{
    //Elements should be in a sorted order to perform the BINARY SEARCH 
    //This Given For loop checks if elements are sorted or not
    int iCnt=0;
    for(iCnt=0;iCnt<size;iCnt++)
    {
        if(Arr[iCnt+1]<Arr[iCnt])
        {
            return -2;  //if elements are not sorted it will return exit code -2.
        }
    }

    //Logic Of BINARY SEARCH
    int beg=0;
    int end=size-1;
    
    while (beg<=end)
    {
       int mid=(beg+end)/2;
        
        if(Arr[mid]==Value)
        {
            return mid;
        }
        else if(Arr[mid] > Value)
        {
            end=mid-1;
        }   
        
        else if(Arr[mid] < Value)
        {
            beg=mid+1;            
        }  
        else
        {
            return -1;  //If element not found in array it will return exit code -1.
        }
    }    
}

int main()
{
    int size;
    int Arr[size];
    int iRet;
    int  iValue=0;

    cout<<"Enter the size of Array"<<endl;
    cin>>size;
    
    cout<<"Enter the Array elements:"<<endl;
    for(int iCnt=0;iCnt<size;iCnt++)
    {
        cin>>Arr[iCnt];
    }

    cout<<"Array elements are:"<<endl;
    for(int iCnt=0;iCnt<size;iCnt++)
    {
        cout<<Arr[iCnt]<<endl;
    }
   
    cout<<"Enter the element you want to search:"<<endl;
    cin>>iValue;

    iRet = BinarySearch(Arr,size,iValue);
    
    if(iRet==-1)
    {
        cout<<"Element Not Found";
    }
    else if(iRet==-2)
    {
        cout<<"ERROR : Elements Must be in a Sorted Order";
    }
    else
    {
        cout<<"Element Found At position:"<<iRet<<endl;
    }

    return 0;
}