#include<iostream>
#include<string>
using namespace std;

class Data{
	protected:
		string data;
	public:
		Data (string d);
		void setData(string d);
		string getData();
};

class EncryptedData : Data{
	protected:
		string encryptedarray;
		string secretKey;
		bool encrypted;
	public:
		EncryptedData (string d, string key);
		void encrypt();
		void decrypt();
		string printData();
};
