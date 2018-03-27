#include "database.cpp"

int main(){
	EncryptedData data("HelloBaby","Hello");
	data.encrypt();
	string e=data.printData();
	data.decrypt();
	string e1=data.printData();
	cout<<e1<<endl;
	for (int n=0; n<s;n++)
	cout<< e[n];
	cout<<endl;	
}
