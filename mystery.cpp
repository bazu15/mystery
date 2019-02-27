#include <iostream>
#include <vector>
using namespace std;

void print(auto A)
{
   for (auto a : A) 
        cout <<a<<" ";

   cout<<endl;
}

void mystery1(auto& Data)
{
  cout<<endl<<"Mystery 1"<<endl<<"---------------------"<<endl;

  for ( int i = 0 ; i < Data.size( ) ; i++)
  {
    for ( int j = 0 ; j < i ; j++)
	if ( Data[ i ] < Data[ j ] )
	    swap( Data[ i ] , Data[ j ] );

    print(Data);
  }//end outer for (this brace is needed to include the print statement)

}

//... Other mysteries...
void mystery2(auto& Data) 
{
	int i, j, minIndex, tmp;
	cout<<endl<<"Mystery 2"<<endl<<"---------------------"<<endl;
	for (i = 0; i < Data.size() -1; i++) 
	{
		minIndex = i;
	//find smallest in unsorted part
	for (j = i + 1; j < Data.size(); j++)
	{
		if (Data[j] < Data[minIndex])
			minIndex = j;
	}
	if (minIndex != i) 
	{
		tmp = Data[i];
		Data[i] = Data[minIndex];
		Data[minIndex] = tmp;
	} //end if
	print(Data);
	} //end outer loop
} //end function
void mystery3(auto&Data)
{
	int nextIndex, moveitem, insertVal;
	cout<<endl<<"Mystery 3"<<endl<<"---------------------"<<endl;
	//loop through elements of vector
	for (nextIndex = 1; nextIndex < Data.size(); nextIndex ++)
 	{
		insertVal = Data[nextIndex]; //store valueof current element
		moveitem = nextIndex; //initialize location to place element
		
		//search for location to place currentelement
		while (moveitem >0 && Data[moveitem -1] > insertVal) 
		{
			//shift elements one slot to right
			Data[moveitem ] = Data[moveitem -1];moveitem--;
		
		} //end while
		Data[moveitem] = insertVal;
	
	print(Data);
	} //end for
}

int main()
{
    
  vector<int> Data = {36, 18, 22, 30, 29, 25, 12};

  vector<int> D1 = Data;
  vector<int> D2 = Data;
  vector<int> D3 = Data;

  mystery1(D1);
  mystery2(D2);
  mystery3(D3);

}
