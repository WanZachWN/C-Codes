#include<bits/stdc++.h>
using namespace std;

string printRandomString(int n) //random string generator function
{
	char alphabet[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g',
	'h', 'i', 'j', 'k', 'l', 'm', 'n',
	'o', 'p', 'q', 'r', 's', 't', 'u',
	'v', 'w', 'x', 'y', 'z' };

	string res = "";
	for (int i = 0; i < n; i++)
	res = res + alphabet[rand() % 26];

	return res;
}
int printRandomNumber(){ //random number generator function
	int num;
	num = 100 + (rand() % 900);
	return num;
}

class SensorData{ //sensorData class
	public:
	int i=0;
	virtual void generateData() = 0;
};
class SensorAData : public SensorData{ //SensorAData inherited from SensorData
public:
	int i=0;
	int arrA[100000];

	void generateData();
	void readData();
	void saveData();
	void loadData();
};
class SensorBData : public SensorData{ //SensorBData inherited from SensorData
public:
	int i=0;
	string arrB[100];

	void generateData();
	void readData();
	void saveData();
	void loadData();
};


void print_and_sort(SensorAData &obj){ //overloaded function to sort and print sensor data A
	sort(obj.arrA, (obj.arrA)+obj.i-1);
	for(int j=0;j<(obj.i-1);j++)
	cout<<obj.arrA[j]<<endl;
}
void print_and_sort(SensorBData &obj){ //overloaded function to sort and print sensor data A
	sort(obj.arrB, (obj.arrB)+obj.i-1);
	for(int j=0;j<(obj.i-1);j++)
	cout<<obj.arrB[j]<<endl;
}
void SensorAData::loadData(){ //load data to arrA from loader.txt
	try{
		ifstream f;
		f.open("loader.txt");
		if(f.peek() == EOF){
			f.close();
			throw string("loader.txt file is empty, no data saved.\n");
		}
		else{
			while(!f.eof()){
				f>>this->arrA[this->i];
				(this->i)++;
			}
			f.close();
		}
	}
	catch(string s){
		cout<<s;
	}
}
void SensorBData::loadData(){ //load data to arrB from loader.txt
	try{
		ifstream f;
		f.open("loader.txt");
		if(f.peek() == EOF){
			f.close();
			throw string("loader.txt file is empty, no data saved.\n");
			}
			else{
				while(!f.eof()){
				f>>this->arrB[this->i];
				(this->i)++;
		}
		f.close();
		}
	}
	catch(string s){
	cout<<s;
	}
}
void SensorAData::saveData(){ //save A's data to loader.txt
	try{
		fstream f;
		f.open("loader.txt");
		if(f.fail()){
			f.close();
			f.open("loader.txt", fstream::app);
			f.close();
			throw string("Save file loader.txt does not exist, generating new loader.txt file.\n");
		}
		else{
			f.close();
			f.open("loader.txt", fstream::app);
			int x=0;
			while(this->arrA[x] != EOF && x<100000){
				f<<this->arrA[x]<<endl;
				x++;
			}
			f.close();
		}
	}
	catch(string s){
		cout<<s;
	}
}
void SensorBData::saveData(){ //save B's data to loader.txt
try{
fstream f;
f.open("loader.txt");
if(f.fail()){
f.close();
f.open("loader.txt", fstream::app);
f.close();
throw string("Save file loader.txt does not exist, generating new loader.txt file.\n");
}else{
f.close();
f.open("loader.txt", fstream::app);
int x=0;
while((this->arrB[x] != "") && (x<100000)){
f<<this->arrB[x]<<endl;
x++;
}
f.close();
}
}
catch(string s){
cout<<s;
}
}


void SensorAData::readData(){ //read sensor A's data
	try{
		ifstream f;
		f.open("sensorA.txt");
		if(f.peek() == EOF){
			f.close();
			throw string("File sensorA.txt is empty, no new data from sensor A.\n");
		}else{
			while(!f.eof()){
				f>>this->arrA[this->i];
				(this->i)++;
			}
			f.close();
		}
	}
	catch(string s){
		cout<<s;
	}
}
void SensorBData::readData(){ //read sensor B's data
try{
ifstream f;
f.open("sensorB.txt");
if(f.peek() == EOF){
f.close();
throw string("File sensorB.txt is empty, no new data from sensor B.\n");
}else{
while(!f.eof()){
f>>this->arrB[this->i];
(this->i)++;
}
f.close();
}
}
catch(string s){
cout<<s;
}
}
void SensorAData::generateData(){ //generate sensor A's data
	try{
		fstream f;
		f.open("sensorA.txt");
		if(f.fail()){
			f.close();
			f.open("sensorA.txt", fstream::app);
			f.close();
			throw string("File does not exist, generating sensor A's data file sensorA.txt\n");
		}
		f.close();
		f.open("sensorA.txt", fstream::app);
		int line;
		int x=5;
		while(x--){
			line = printRandomNumber();
			f<<line<<endl;
		}
		f.close();
	}
	catch(string s){
		cout<<s;
	}
}
void SensorBData::generateData(){ //generate sensor B's data
	try{
		fstream f;
		f.open("sensorB.txt");
		if(f.fail()){
			f.close();
			f.open("sensorB.txt", fstream::app);
			f.close();
			throw string("File does not exist, generating sensor B's data file sensorB.txt\n");
		}
		f.close();
		f.open("sensorB.txt", fstream::app);
		string line;
		int x=7;
		while(x--){
			line = printRandomString(5);
			f<<line<<endl;
		}
		f.close();
	}
	catch(string str){
	cout<<str;
	}
}
int main(){
	srand(time(0)); //seed for random number generator
	SensorAData a; //create sensor A's instance
	a.generateData(); //generate A's data, give exception
	a.generateData(); //generated
	a.readData(); //read data
	print_and_sort(a); //sort and print
	a.saveData(); //save to loader.txt, generate exception
	SensorBData b;
	b.generateData(); ////generate B's data, give exception
	b.generateData(); //generated
	b.readData(); //read data
	print_and_sort(b); //sort and print
	b.saveData(); //save to loader.txt
	return 0;
}
