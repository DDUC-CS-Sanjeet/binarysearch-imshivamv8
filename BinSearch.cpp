#include<iostream>
#include<algorithm>
using namespace std;

bool binarySearchReacursive(int* array, int startIndex, int lastIndex, int element)
{
    int mid = 0;
	if(startIndex>lastIndex)
	    return false;
	else
	{
		mid=(startIndex+lastIndex)/2;
		if(array[mid]==element)
	        return true;
		else if(array[mid]>element)
		    binarySearchReacursive(array, startIndex, mid-1, element);
		else
		    binarySearchReacursive(array, mid+1, lastIndex, element);
    }
}

bool binarySearchIterative(int* array, int startIndex, int lastIndex, int element)
{
  int mid = 0;
  while(startIndex<=lastIndex)
  {
    mid = (startIndex+lastIndex)/2;
    if(array[mid] == element)
    {  
        return true;
    } 
    else if(array[mid] < element)
        startIndex = mid+1;
    else if(array[mid] > element)
        lastIndex = mid-1;
  }
   if(startIndex>lastIndex)
        return false;
}

int main()
{
  int size = 0, ele = 0;
  bool result_it = false, result_rec = false;
  try
  {
      cout<<"Enter the size of Array: ";
      cin>>size;
      if(size<1)
          throw "Invalid Size!!!";
  }
  catch(const char *str)
  {
    cout<<str;
  }
  int *arr = new int[size];
  cout<<"Enter the elements in the Array..."<<endl;
  for(int i=0; i<size; i++)
      cin>>arr[i];
  sort(arr, arr+size);
  cout<<"Enter the element to be searched: ";
  cin>>ele;
  result_it = binarySearchIterative(arr, 0, size-1, ele);
  result_rec = binarySearchReacursive(arr, 0, size-1, ele);
  if(result_it == true)
      cout<<ele<<" is found in the given Array through Iterative!!!"<<endl;
  else
      cout<<ele<<" is not found in the given Array through Iterative!!!"<<endl;
  if(result_rec)
      cout<<ele<<" is found in the given Array through Recursion!!!"<<endl;
  else
      cout<<ele<<" is not found in the given Array through Recursive!!!"<<endl;
  delete[] arr;
  return 0;
}
