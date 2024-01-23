#include<iostream>
using namespace std;

const int NOT_FOUND=-1;
const int EMPTY_ARRAY=-2;
const int UNSORTED_ARRAY=-3;

int CheckSortedOrNot(int *iArray,int iSize)
{
    register int iCnt=0;
    int iStart=0;
    int iEnd=iSize-1;
    
    //Logic to check that Array is Sorted or Not
    for(iCnt=0;iCnt<(iStart+iEnd)-1;iCnt++)
    {
         if( iArray[iCnt + 1] < iArray[iCnt])
         {
             return UNSORTED_ARRAY;
         }
    }

}

int RecursiveBinarySearch(int *iArray, int iStart ,int iEnd,int iValue)
{
    //Checking if The array is empty.
    if((iStart+iEnd)==0)
    {
        return EMPTY_ARRAY;
    }

    //Logic for Binary Search.
    int iMid= (iStart+iEnd)/2;
    if(iStart > iEnd)
    {
        return NOT_FOUND;
    }
    else if(iArray[iMid]==iValue)
    {
        return iMid;
    }
    else if(iArray[iMid] > iValue)
    {
        return RecursiveBinarySearch(iArray,iStart,iMid-1,iValue); //Recursive call if the ivalue gretaer than Array[Mid]
    }
    else if(iArray[iMid] < iValue)
    {
        return RecursiveBinarySearch(iArray,iMid+1,iEnd,iValue); //Recursive call if the Array[Mid] gretaer than iValue 
    }
    else
    {
        return NOT_FOUND;
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

    
    int iStart = 0;
    int iEnd =iSize-1;
    int checkSorted= CheckSortedOrNot(iArray, iSize);
    
    if(checkSorted==UNSORTED_ARRAY)
    {
        cout<<"Error:Given Array is not Sorted";
        return 0;
    }
 
    cout<<"Enter the Element you want to Search:"<<endl;
    cin>>iValue;


    iPosition = RecursiveBinarySearch(iArray,iStart,iEnd,iValue);
    if(iPosition==NOT_FOUND)
    {
        cout<<"Error: Element Not found"<<endl;
    }
    else if(iPosition==EMPTY_ARRAY)
    {
        cout<<"Error: Array is empty."<<endl;
    }
    else
    {   
        cout<<"Element found at Position:"<<iPosition<<endl;
    }
    
    delete[] iArray; // Release allocated memory
    
    return 0;
}