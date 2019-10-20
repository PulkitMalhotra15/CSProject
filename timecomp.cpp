//---------- SOURCE CODE ----------

//---------- Header Section ----------
#include <iostream.h>
#include <time.h>
#include <math.h>
#include<fstream.h>
#include <stdlib.h>

// This section consists solely of declarations of classes, structs, functions and constants.
// Put all constants that need to be used throughout the program here.
// Put all class or struct structure related things here.
// Put all function prototypes here.
// Only put prototypes and not the actual function definition.

class sort
{
public:
	void insertsort(long _arr[ ], long n); //Insertion Sort declared
	void selsort(long _arr[ ], long n);    //Selection Sort declared
	void bubblesort(long _arr[ ], long n); //Bubble Sort declared 

};
void sort::insertsort(long _arr[ ], long n) //Insertion Sort defined
{
	const long a= n;
	long arr[100];
		for (long k = 0; k < n; k++)
		{
			arr[k]=_arr[k];
		}

	long i, j,temp;

	for(i=1; i<n; i++)
	{	temp=arr[i];
		j=i-1;
		while((temp<arr[j]) && (j>=0))
		{	arr[j+1]=arr[j];
			j=j-1;
		}
		arr[j+1]=temp;
	}
	cout<<"Elements sorted successfully by Insertion Sort\n";
}


void sort::selsort(long _arr[ ], long n) //Selection Sort defined
{
long arr[100];
		for (long k = 0; k < n; k++)
		{
			arr[k]=_arr[k];
		}

	long min_idx;

		for(long i = 0; i < n-1; i++)
		{   	min_idx = i;
				for(long j = i+1; j < n; j++)
					if(arr[j] < arr[min_idx])
            			min_idx = j;

				long temp = arr[min_idx];
		arr[min_idx] = arr[i];
		arr[i] = temp;
	}
	cout<<"Elements sorted successfully by Selection Sort \n";
	
}

void sort::bubblesort(long _arr[ ], long n) //Bubble Sort defined
{	long arr[100];
		for (long k = 0; k < n; k++)
		{
			arr[k]=_arr[k];
		}

		for(long i=0; i<(n-1); i++)
	{	for(long j=0; j<(n-i-1); j++)
		{	if(arr[j]>arr[j+1])
			{	long temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	cout<<"Elements sorted successfully by Bubble Sort\n";
}	
//---------- Final main Function ----------
int main()
{
	const long count= 100; //constant defined
	long a[count];
	clock_t time_req,time_req1,time_req2; //time variables defined
	sort obj; //object of class sort declared
	
		for (long i = 0; i < count; i++) //Taking random input in the array
		 {
			a[i]= random(count);
		 }

			time_req = clock(); //measuring current time of system
			obj.bubblesort(a, count); //Bubble sorting	
			time_req = clock() - time_req;//measuring time after sorting
			cout << " Using Bubble Sort, it took " << (double)time_req/CLOCKS_PER_SEC << " seconds" << endl; //getting the difference of the time to get time taken

    	
			time_req1 = clock();
			obj.selsort(a, count);//Selection Sort
			time_req1 = clock() - time_req1;
			cout << " Using Selection Sort, it took " << (double)time_req1/CLOCKS_PER_SEC << " seconds" << endl;

			 time_req2 = clock();
			obj.insertsort(a, count); //Insertion sort
			time_req2 = clock() - time_req2;
			cout << " Using Insertion Sort, it took " << (double)time_req2/CLOCKS_PER_SEC << " seconds" << endl;

				ofstream fout;

					fout.open("PARA1.TXT");//Data is stored in a text file
				  if(!fout.eof())
				  {
									fout<<time_req<<time_req1<<time_req2;
				  }
				 fout.close();
return 0;
}



