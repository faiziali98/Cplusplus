#include "database.h"

Data::Data(string d){
	data=d;
}

void Data:: setData(string d){
	data=d;
}

string Data::getData(){
	return data;
}

EncryptedData::EncryptedData(string d, string key):Data(d){
	secretKey=key;
}

void EncryptedData::encrypt(){
	int n=data.size();
	int k=secretKey.size();
	int loop=n;
	if (n>k)
		loop=n;
	else 
		loop=k;
	int keyl=0;
	for (int e=0; e<loop; e++)
	{
		char a=data[e];
		char b=secretKey[keyl];
		char d=a^b;
		encryptedarray=encryptedarray+d;
		keyl++;
		if (keyl>k-1)
			keyl=0;
	}
	encrypted=true;
}

void EncryptedData::decrypt(){
        int n=encryptedarray.size();
        int k=secretKey.size();
        int loop=n;
	string temp;
        if (n>k)
                loop=n;
        else
                loop=k;
        int keyl=0;
        for (int e=0; e<loop; e++){
                char d=(encryptedarray[e]^secretKey[keyl]);
		temp=temp+d;
                keyl++;
                if (keyl>k-1)
                        keyl=0;
        }
        encrypted=false;
	encryptedarray=temp;
}

string EncryptedData:: printData(){
	if (encrypted)
		{
		return encryptedarray;}
	else
		return data;
}




