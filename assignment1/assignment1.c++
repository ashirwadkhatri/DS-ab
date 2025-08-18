/*
1) Developa Menudrivenprogramtodemonstrate the followingoperations of Arrays
——MENU——-
1.CREATE
2.DISPLAY
3.INSERT
4.DELETE
5.LINEAR SEARCH
6.EXIT
*/
#include<iostream>
using namespace std;
int main()
{
    int arr[100],n=0,choice;
    do 
    {
        cout <<"\n MENU \n"
                << "1. CREATE\n"
                << "2. DISPLAY\n"
                << "3. INSERT\n"
                << "4. DELETE\n"
                << "5. LINEAR SEARCH\n"
                << "6. EXIT\n"
                << "Enter your choice: ";
        cin >> choice;
        switch(choice)
        {
            case 1:{//create
            cout <<"enter the numbner of elements";
            cin >>n;
            cout <<"enter the elements\n";
            for(int i=0;i<n;i++)
            {
                cin >>arr[i];
            }
            cout <<"array is created ";
            break;  
        }
        case 2:{//display
            cout<< "The elements of the array are: ";}
            for(int i=0;i<n;i++)
            {
                cout << arr[i] <<"\t";
            }
            cout<<"\n";
            break;
            case 3:{//insert
                int pos,m;
                cout <<"enter the pos to enter value";
                cin >> pos;
                cout <<"enter the value to be inserted ";
                cin >>m;
                if(pos>n|| pos<0)
                {
                    cout <<"invalid";
                }
                else
                {
                    for(int i=n;i>=pos;i--)
                    {
                        arr[i]=arr[i-1];
                    }
                    arr[pos]=m;
                    n++;
                    cout <<"value inserted";
                }
                       }
            break;
                       case 4://delete
                       {
                        int pos;
                        cout<<"enter the position to delete";
                        cin>>pos;
                        if(pos<0 || pos>=n)
                        {
                            cout<<"invalid position";
                        }
                        else{
                            for(int i=pos;i<n-1;i++)
                            {
                                arr[i]=arr[i+1];         
                            }
                            n--;
                            cout<<"value is deleted";
                        }
                       }
                       case 5://linear search
                       {
                        int flag=0,a;
                        cout<<"enter the value to be searched";
                        cin>>a;
                        for(int i=0;i<n;i++)
                         {
                            if(arr[i]==a)
                         
                         {
                            cout << "value is found at pos " << i << "\n";
                            flag = 1;
                            break;
                         }
                        }
                        if(flag==0)
                        {
                            cout<<"not found";
                        }
                    }
                        break;
                        case 6://exit
                        cout<<"Exiting the program\n";
                        break;
                        default:
                        cout<<"Invalid choice, please try again.\n";
                        break;

    }
        }
     while(choice != 6);
    return 0;
}
