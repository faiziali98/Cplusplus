#include "Date.cpp"
#include <iostream>
using namespace std;

int main(){
    Date arr[2];
    for (int n=0;n<2;n++)
    {
        int dd,mm,yy;
        if (n==0)
            cout<<"Enter the "<<n+1<<"st date. mm/dd/yy"<<endl;
        else if (n==1)
            cout<<"Enter the "<<n+1<<"nd date. mm/dd/yy"<<endl;
        cin>>mm>>dd>>yy;
        Date d1(mm,dd,yy);
        arr[n]=d1;
    }

    cout << "Testing operators" << endl;
	Date add = arr[0] + arr[1];//(Testing '+' operator.)
	 cout<< add ;//(Testing '//' operator.)
	Date substract = arr[0] - arr[1];//(Testing '-' operator.)
	cout << "Subtraction of dates: " << substract << endl;//(Testing '//' operator.)

	if (arr[1] == arr[0]) {//(Testing '==' operator.)
		cout << "Dates are equal" << endl;
	} else {
		cout << "Dates are not equal" << endl;
	}

	if (arr[1] < arr[0]) {//(Testing '<' operator.
        // Note: arr[1] is date 2 and arr[0] is date 1)
		cout << "Date 1 is lesser than Date 2" << endl;
	} else {
		cout << "Date 1 is not lesser than Date 2" << endl;
	}
}
