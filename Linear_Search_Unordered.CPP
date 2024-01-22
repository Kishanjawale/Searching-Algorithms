
#include<iostream>
using namespace std;

const int NOT_FOUND=-1;
const int EMPTY_ARRAY=-2;

int LinearSearchUnsorted(int *iArray, int iSize,int iValue)
{
    register int iCnt=0;
    if(iSize==0)
    {
        return EMPTY_ARRAY;
    }
    for(iCnt=0;iCnt<iSize;iCnt++)
    {
        if(iArray[iCnt]==iValue)
        {
            return iCnt;
        }
    }
    return -1;
}


int  main()
{
    int iSize=0;
    cout<<"Enter the size of Array:"<<endl;
    cin>>iSize;
    int iPosition=0;

    int* iArray = new int[iSize]; // Dynamic memory allocation
    int iValue=0;

    cout<<"Enter the Array elements:"<<endl;
    for(register int iCnt=0;iCnt<iSize;iCnt++)
    {
        cin>>iArray[iCnt];
    }

    cout<<"Enter the Element you want to Search:"<<endl;
    cin>>iValue;

    iPosition = LinearSearchUnsorted(iArray,iSize,iValue);
    

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
