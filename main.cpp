#include <stdio.h>
#include<string.h>
//#include<fstream>
#include<conio.h>
//using namespace std;

struct Contact{
	char* name;
	char* number;
};

struct Contact *list[100000];
int i=0;

//fstream file("Contacts.txt",ios::binary|ios::in|ios::out|ios::app);
FILE *fp;

fp=fopen("Contacts.txt","a+b");
void save_To_File(){
	if (!file){
		 printf("file not opened!\n");
	}else{
		int j=0;
		while(j<i)
		file.write((char*)&list[j], sizeof(struct Contact));
		printf("contact added to file!\n");
		j++;
	}
}
void read_From_File(){

	if (!file){
		printf("file not opened!\n");
	}else{
		struct Contact *list2[i];
		int j=0;
		while(j<i)
		file.read((char*)&list2[j], sizeof(struct Contact));
		printf("contact readed from file!\n");
		j++;
	}
}

void add_New_Contact(char* name,char* number){
    struct Contact *list[i];
	list[i]->name=name;
	list[i]->number=number;
	i++;
}

void swap(struct Contact *xp, struct Contact *yp){
    struct Contact temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void bubbleSort(struct Contact* arr[], int n,int state1){
   	if(state1==0){
			int k, j;
			for (k = 0;k < n-1; k++) {
			// Last i elements are already in place
	       		for (j = 0; j < n-k-1; j++){
					if (strcmp(arr[j]->name,arr[j+1]->name)<0){
	        			swap(arr[j], arr[j+1]);
					}
	  			}
	  		}
	}
	else if (state1==1){
			int k, j;
			for (k = 0;k < n-1; k++) {
			// Last i elements are already in place
	       		for (j = 0; j < n-k-1; j++){
					if (strcmp(arr[j]->number, arr[j+1]->number)<0){
	        			swap(arr[j], arr[j+1]);
					}
	  			}
	  		}
	}
}
int binarySearch(struct Contact *arr[], int l, int r, char* x,int state1){
    while (l <= r)
    {
        int m = l + (r-l)/2;
        if(state1==0){
			// Check if x is present at mid
		    if (strcmp(arr[m]->name,x)==0)
		        return m;

		    // If x greater, ignore left half
		    if (strcmp(arr[m]->name,x)>0)
		          l = m + 1;

		        // If x is smaller, ignore right half
		    else
		        r = m - 1;

		}
		else if(state1==1){
			// Check if x is present at mid
	        if (strcmp(arr[m]->number,x)==0)
	            return m;
	        // If x greater, ignore left half
	        if (strcmp(arr[m]->number,x)>0)
	            l = m + 1;
	        // If x is smaller, ignore right half
	        else
	            r = m - 1;
	    }
		}
		// if we reach here, then element was
	    // not present
	    return -1;

}
void Process(){
	int state2;
	int state1;
	printf("Enter name or number(0 for name and 1 for number):");
	scanf("%d", &state1);
    char* name;
    char* number;
	if(state1==0|state1==1){
	printf("\nEnter:");
	if (state1==0){
		bubbleSort(list,i,state1);
		scanf("%s", &name);
		int index=binarySearch(list, 0 , i-1 , name,state1 );
		if(index==-1){
			printf("Not exists!\n");
			return;
		}
		printf("\n Delete or Cahnge?( 0 for delete 1 for change): \n");
		scanf("%d", &state2);
			if (state2==0){
				for(int j=index;j<=i;j++){
					list[j]=list[j+1];
				}
				i--;

			}
			else if (state2==1){
				int state3;
				printf("Enter 0 for changing name - 1 for changing number - 2 for changing both \n");
				scanf("%d", &state3);
				if(state3==0){
                    char* iname;
					printf("Enter new name:");
					scanf("%s", &iname);
					list[index]->name=iname;
				}
				else if(state3==1){
                    char* inumber;
					printf("Enter new number:");
					scanf("%s", &inumber);
					list[index]->number=inumber;
				}
				else if(state3==2){
                    char* iname;
                    char* inumber;
					printf("Enter new number:");
					scanf("%s", &inumber);
					printf("Enter new name:");
					scanf("%s", &iname);
					list[index]->number=inumber;
					list[index]->name=iname;
				}
				else{
					printf("Invalid input!\n");
				}

			}
			else{
				printf("Invalid input!\n");
			}
	}
	else if (state1==1){
		bubbleSort(list,i,state1);
		scanf("%s", &number);
		int index=binarySearch(list, 0 , i-1 , number,state1 );
		if(index==-1){
			printf("Not exists!\n");
			return;
		}
		printf("Delete or Cahnge?( 0 for delete 1 for change):\n");
		scanf("%d", &state2);
			if (state2==0){
				for(int j=index;j<=i;j++){
					list[j]=list[j+1];
				}
				i--;

			}
			else if (state2==1){
				int state3;
				printf("Enter 0 for changing name - 1 for changing number - 2 for changing both\n");
				scanf("%d", &state3);
				if(state3==0){
                    char* iname;
					printf("Enter new name:");
					scanf("%s", &iname);
					list[index]->name=iname;
				}
				else if(state3==1){
                    char* inumber;
					printf("Enter new number:");
					scanf("%s", &inumber);
					list[index]->number=inumber;
				}
				else if(state3==2){
					char* iname;
                    char* inumber;
					printf("Enter new number:");
					scanf("%s", &inumber);
					printf("Enter new name:");
					scanf("%s", &iname);
					list[index]->number=inumber;
					list[index]->name=iname;
				}
				else{
					printf("Invalid input!\n");
				}
			}
			else{
				printf("Invalid input!\n");
			}
	}
}
	else{
		printf("Invalid input!\n");
		return;
	}
}

int main(){
	add_New_Contact( "ali01","01");
	add_New_Contact( "ali02","02");
	add_New_Contact( "ali03","03");
	add_New_Contact( "ali04","04");
	add_New_Contact( "ali05","05");
	add_New_Contact( "ali06","06");
	add_New_Contact( "ali07","07");
	add_New_Contact( "ali08","08");
	add_New_Contact( "ali09","09");
	add_New_Contact( "ali10","10");
	add_New_Contact( "ali11","11");
	add_New_Contact( "ali12","12");
	add_New_Contact( "ali13","13");
	add_New_Contact( "ali14","14");
	add_New_Contact( "ali15","15");
	/*
	cout<<list[0]->name<<endl<<list[0]->number<<endl;
	cout<<list[1]->name<<endl<<list[1]->number<<endl;
	cout<<list[2]->name<<endl<<list[2]->number<<endl;
	cout<<list[3]->name<<endl<<list[3]->number<<endl;
	cout<<list[4]->name<<endl<<list[4]->number<<endl;
	cout<<list[5]->name<<endl<<list[5]->number<<endl;
	cout<<list[6]->name<<endl<<list[6]->number<<endl;
	cout<<list[7]->name<<endl<<list[7]->number<<endl;
	*/
	//Process();
	/*
	bubbleSort(list,i);
	cout<<list[0]->name<<endl<<list[0]->number<<endl;
	cout<<list[1]->name<<endl<<list[1]->number<<endl;
	cout<<list[2]->name<<endl<<list[2]->number<<endl;
	cout<<list[3]->name<<endl<<list[3]->number<<endl;
	cout<<list[4]->name<<endl<<list[4]->number<<endl;
	cout<<list[5]->name<<endl<<list[5]->number<<endl;
	cout<<list[6]->name<<endl<<list[6]->number<<endl;
	cout<<list[7]->name<<endl<<list[7]->number<<endl;
	cout<<list[8]->name<<endl<<list[8]->number<<endl;
	cout<<list[9]->name<<endl<<list[9]->number<<endl;
	cout<<list[10]->name<<endl<<list[10]->number<<endl;
	cout<<list[11]->name<<endl<<list[11]->number<<endl;
	cout<<list[12]->name<<endl<<list[12]->number<<endl;
	cout<<list[13]->name<<endl<<list[13]->number<<endl;
	cout<<list[14]->name<<endl<<list[14]->number<<endl;
//	cout<<list[15]->name<<endl<<list[15]->number<<endl;
*/


}
