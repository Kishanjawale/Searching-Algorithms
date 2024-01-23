
#include<iostream>
using namespace std;

const int NOT_FOUND=-1;
const int EMPTY_ARRAY=-2;
const int UNSORTED_ARRAY=-3;

int iterativeBinarySearch(int *iArray, int iSize,int iValue)
{
    //Check if Array is Empty   
    if(iSize==0)
    {
        return EMPTY_ARRAY;
    }
    
    //Logic to check that Array is Sorted or Not
    register int  iCnt=0;
    for(iCnt=0;iCnt<iSize-1;iCnt++)
    {
        if( iArray[iCnt + 1] < iArray[iCnt])
        {
            return UNSORTED_ARRAY;
        }
    }
    
    // Binary Search Logic
    int iMid=0;
    int iStart=0;
    int iEnd=iSize-1;
    while (iStart <= iEnd )
    {
        iMid=iStart+iEnd/2;
        if(iArray[iMid]==iValue)
        {
            return iMid;
        }
        else if(iArray[iMid]  < iValue   )
        {   
            iStart = iMid+1;
        }
        else if(iArray[iMid]  > iValue   )
        {
            iEnd=iMid-1;
        }
        else
        {
            return -1;        
        }
    }
}


int  main()
{
    int iSize=0;
    int iValue=0;
    int iPosition=0;
   
    cout<<"Enter the size of Array:"<<endl;
    cin>>iSize;
    

    int* iArray = new int[iSize]; // Dynamic memory allocation
    cout<<"Enter the Array elements:"<<endl;
    for(register int iCnt=0;iCnt<iSize;iCnt++)
    {
        cin>>iArray[iCnt];
    }

    cout<<"Enter the Element you want to Search:"<<endl;
    cin>>iValue;

    iPosition = iterativeBinarySearch(iArray,iSize,iValue);
    

    if(iPosition==NOT_FOUND)
    {
        cout<<"Error: Element Not found"<<endl;
    }
    else if(iPosition==EMPTY_ARRAY)
    {
        cout<<"Error: Array is empty."<<endl;
    }
    else if(iPosition==UNSORTED_ARRAY)
    {
        cout<<"Error:Given Array is not Sorted";

    }
    else
    {   
        cout<<"Element found at Position:"<<iPosition<<endl;
    }

    delete[] iArray; // Release allocated memory
    return 0;
}