#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <sstream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;
//===========================================================================================================
/*Base class sensor
  - That has a string array of size 120
  - A integer type size
  - A constructor that initialize the size to 0
  - function to return sensor[i] data because it is private
*/
class Sensor
{	
	private:
	string sensor[120];
	public:
	int size;
	Sensor()
	{
		size = 0;
	}
	void setSensor(int i, string data);
	string getSensor(int i);
};
//===========================================================================================================
/*Sub class sensorA inherits class Sensor as public
  - integer array of size 50
  - sensorA inherits the size from base class Sensor
  - constructor sensorA initialize it's size to 0 
  - A function getSize that returns the parent's size
*/
class SensorA : public Sensor
{
	public:
	int sensorA[50];
	SensorA()
	{
		size = 0;
	}
	int getsize()
	{
		return Sensor::size;
	}
	
};
//===========================================================================================================
/*Sub class sensorB inherits class Sensor as public
  - integer array of size 70
  - sensorB inherits the size from base class Sensor
  - constructor sensorB initialize it's size to 0 
  - A function getSize that returns the parent's size
*/
class SensorB : public Sensor
{	
	public:
	string sensorB[70];
	SensorB()
	{
		size = 0;
	}
	int getsize()
	{
		return Sensor::size;
	}
};
//===========================================================================================================
void Sensor::setSensor(int i, string data)
{
	sensor[i] = data;
}
string Sensor::getSensor(int i)
{
	return this->sensor[i];
}
//===========================================================================================================

//===========================================================================================================
/*Print and sort function for base class Sensor using function overloading
  - two for loops to sort
  - one is inside the first loop. This will compare all the data store in the sensor class
  - if the first data is less than the second then switch.
  - continue until the end of sensor's data stored
  - For loop to print every data element of Sensor stored in the array
*/
void print_and_sort(Sensor &sensorData)
{
	for(int i = 0; i < sensorData.size; i++)
	{
		for(int j = 0; j < sensorData.size; j++)
		{
			if(sensorData.getSensor(i) < sensorData.getSensor(j))
			{
				string temp = sensorData.getSensor(i);
				sensorData.setSensor(i, sensorData.getSensor(j));
				sensorData.setSensor(j, temp);
			}
		}
	}
	for(int p = 0; p < sensorData.size; p++)
	{
		cout << sensorData.getSensor(p) << " ";
	}
	cout << endl;
	
	return;
}
//===========================================================================================================
/*Print and sort function for base class SensorA using function overloading
  - two for loops to sort
  - one is inside the first loop. This will compare all the data store in the SensorA class
  - if the first data is less than the second then switch.
  - continue until the end of SensorA's data stored
  - For loop to print every data element of SensorA stored in the array
*/
void print_and_sort(SensorA &sensorDataA)
{
	int temp;
	for(int i = 0; i < sensorDataA.size; i++)
	{
		for(int j = 0; j < sensorDataA.size; j++)
		{
			if(sensorDataA.sensorA[i] < sensorDataA.sensorA[j])
			{
				temp = sensorDataA.sensorA[i];
				sensorDataA.sensorA[i] = sensorDataA.sensorA[j];
				sensorDataA.sensorA[j] = temp;
			}
		}
	}
	for(int p = 0; p < sensorDataA.size; p++)
	{
		cout << sensorDataA.sensorA[p] << " ";
	}
	cout << endl;
	
	return;
}
//===========================================================================================================
/*Print and sort function for base class SensorB using function overloading
  - two for loops to sort
  - one is inside the first loop. This will compare all the data store in the SensorB class
  - if the first data is less than the second then switch.
  - continue until the end of SensorB's data stored
  - For loop to print every data element of SensorB stored in the array
*/
void print_and_sort(SensorB &sensorDataB)
{
	for(int i = 0; i < sensorDataB.size; i++)
	{
		for(int j = 0; j < sensorDataB.size; j++)
		{
			if(sensorDataB.sensorB[i] < sensorDataB.sensorB[j])
			{
				string temp = sensorDataB.sensorB[i];
				sensorDataB.sensorB[i] = sensorDataB.sensorB[j];
				sensorDataB.sensorB[j] = temp;
			}
		}
	}
	for(int p = 0; p < sensorDataB.size; p++)
	{
		cout << sensorDataB.sensorB[p] << " ";
	}
	cout << endl;
	
	return;
}
//===========================================================================================================
/*Random generator function for SensorB that returns a type bool
  - Using a try block open SensorB.txt
  - Open the file if the file does not exist (it does not open)
   	close the file.
   	Open the file using ios::app to create a new file.
 	close the file again
   	Throw an exception
  - if it exist, close the file and append into the file
  - Generate data for SensorB and store it into SensorB.txt file
  - generate 5 characters and store into the file directly
  - go to the next line and repeat 7 times
  - close the file SensorB.txt
  - catch the throw as we have create the file but will still be able to continue
    however we will return false that we we're not able to generate new data
  - return true if there is no error
*/
bool RandGenB()
{
	try{
		ostringstream filenameB;
		filenameB << "SensorB.txt";
		fstream ofilesensorB;
		
		ofilesensorB.open(filenameB.str());
		if(!ofilesensorB.is_open())
		{
			ofilesensorB.close();
			ofilesensorB.open(filenameB.str(), ios::app);
			ofilesensorB.close();
			
			ostringstream err_msg;
			err_msg << "File does not exist, generating Sensor " << filenameB.str().at(6)
				<< " data file " << filenameB.str() << ends;
			throw runtime_error(err_msg.str());
		}
		ofilesensorB.close();
		ofilesensorB.open(filenameB.str(), ios:: out | ios::app);
		
		char rand_char;
		for(int i = 0; i < 7; i++)
		{
			for(int j = 0; j < 5; j++)
			{
				rand_char = 'a' + rand()%26;
				ofilesensorB << rand_char;
			}
			ofilesensorB << endl;
		}
		
		ofilesensorB.close();
		
	}
	catch(const runtime_error &err)
	{
		cerr << err.what() << endl;
		return false;
	}
	return true;
}
//===========================================================================================================
/*Random generator function for SensorA that returns a bool. 
  - Using a try block open SensorA.txt
  - Open the file if the file does not exist (it does not open)
   	close the file.
   	Open the file using ios::app to create a new file.
 	close the file again
   	Throw an exception
  - if it exist, close the file and append into the file
  - Generate data for SensorA and store it into SensorA.txt file
  - generate 5 characters and store into the file directly
  - go to the next line and repeat 7 times
  - close the file SensorA.txt
  - catch the throw as we have create the file but will still be able to continue but
    return a false
  - return true if there is no error
*/
bool RandGenA()
{
	try{
		ostringstream filenameA;
		filenameA << "SensorA.txt";
		fstream ofilesensorA;
		
		ofilesensorA.open(filenameA.str());
		if(!ofilesensorA.is_open())
		{
			ofilesensorA.close();
			ofilesensorA.open(filenameA.str(), ios::app);
			ofilesensorA.close();
			
			ostringstream err_msg;
			err_msg << "File does not exist, generating Sensor " << filenameA.str().at(6)
				<< " data file " << filenameA.str() << ends;
			throw runtime_error(err_msg.str());
		}
		ofilesensorA.close();
		ofilesensorA.open(filenameA.str(), ios:: out | ios::app);
		
		for(int i = 0; i < 5; i++)
		{
			ofilesensorA << (100 + rand() % 900) << endl;
		}
		
		ofilesensorA.close();
		
	}
	catch(const runtime_error &err)
	{
		cerr << err.what() << endl;
		return false;
	}
	return true;
}
//===========================================================================================================
/*Read file SensorA.txt function
  - open file SensorA.txt if the file is 
  - if we read the file first time and it is the end of the file
   	close the file and throw an error
  - if file is not empty, read the file using a while loop.
  - store it into a string variable and convert the string to an integer.
  - store the data into SensorA's integer array and store it into the Base class Sensor array
  - increment SensorA's and Sensor's size.
  - close the file
  - Open the file again with ios::out to flush out everything stored in SensorA.txt
  - close the file
  - catch block for the function throw. So we can still continue to run our program. 
  - return to main
*/
void ReadFileA(Sensor &sensorData, SensorA &sensordataA)
{
	try{
		ostringstream filenameA;
		filenameA << "SensorA.txt";
		fstream ffilesensorA;
		ffilesensorA.open(filenameA.str(), ios::in);
		
		if(ffilesensorA.eof())
		{
			ffilesensorA.close();
			ostringstream err_msg;
			err_msg << "File " << filenameA.str()
				<< " is empty, no new data from Sensor A" << ends;
			throw runtime_error(err_msg.str());
		}
		
		size_t size = 0;
		int value = 0;
		string content;
		while(true)
		{
			ffilesensorA >> content;
			if(ffilesensorA.eof())
			{
				break;
			}
			value = stoi(content, &size);
			
			sensordataA.sensorA[sensordataA.size] = value;
			sensorData.setSensor(sensorData.size, content);
			sensordataA.size++;
			sensorData.size++;
		}
		
		ffilesensorA.close();
		
		ffilesensorA.open(filenameA.str(), ios::out);
		ffilesensorA.close();
	}
	catch(const runtime_error &err)
	{
		cerr << err.what() << endl;
	}
	return;
}
//===========================================================================================================
/*Read file SensorB.txt function
  - open file SensorB.txt if the file is 
  - if we read the file first time and it is the end of the file
   	close the file and throw an error
  - if file is not empty, read the file using a while loop.
  - store it into a string
  - store the data into SensorB's string array and store it into the Base class Sensor array
  - increment SensorB's and Sensor's size.
  - close the file
  - Open the file again with ios::out to flush out everything stored in SensorB.txt
  - close the file
  - catch block for the function throw. So we can still continue to run our program.
  - return to main
*/
void ReadFileB(Sensor &sensorData, SensorB &sensordataB)
{
	try{
		ostringstream filenameB;
		filenameB << "SensorB.txt";
		fstream ffilesensorB;
		
		ffilesensorB.open(filenameB.str(), ios::in);
		if(ffilesensorB.eof())
		{
			ffilesensorB.close();
			ostringstream err_msg;
			err_msg << "File " << filenameB.str()
				<< " is empty, no new data from Sensor B" << ends;
			throw runtime_error(err_msg.str());
		}
		
		string content;
		while(true)
		{
			ffilesensorB >> content;
			if(ffilesensorB.eof())
			{
				break;
			}
			sensordataB.sensorB[sensordataB.size] = content;
			sensorData.setSensor(sensorData.size, content);
			sensordataB.size++;
			sensorData.size++;
		}
		ffilesensorB.close();
		
		ffilesensorB.open(filenameB.str(), ios::out);
		ffilesensorB.close();
	}
	catch(const runtime_error &err)
	{
		cerr << err.what() << endl;
	}
	return;
}
//===========================================================================================================
/*- Save sensors function
  - open the loader.txt file
  - if we fail to open therefore the file does not exist(same as if(!loadfile.is_open))
  - close the file
  - open the file again with ios::app to create a new file with the same name
  - close the file and throw an error
  - catch block to to display error but will be able to save data after creating our file
  - close file
  - open the loader.txt file (this time it exist) and we will append to it
  - for loop to save the data inside our Sensor string array
  - close the file and return to main
*/
void SaveSensor(Sensor &SensorData)
{
	ostringstream loader;
	loader << "loader.txt";
	
	fstream loadfile;
	
	try{
		loadfile.open(loader.str());
		if(loadfile.fail())
		{	
			loadfile.close();
			loadfile.open(loader.str(), ios::app);
			loadfile.close();
			
			ostringstream err_msg;
			err_msg << "Save file " << loader.str()
				<< " does not exist, generating new loader.txt" << ends;
			throw runtime_error(err_msg.str());
		}
	}
	catch(const runtime_error &err)
	{
		cerr << err.what() << endl;
	}
	loadfile.close();
	loadfile.open(loader.str());
	
	for(int i = 0; i < SensorData.size; i++)
	{
		loadfile << SensorData.getSensor(i) << endl;
	}
	loadfile.close();
	
	return; 
}
//===========================================================================================================
/*- Save sensors function
  - open the loader.txt file
  - if we fail to open therefore the file does not exist(same as if(!loadfile.is_open))
  - close the file
  - open the file again with ios::app to create a new file with the same name
  - close the file and throw an error
  - catch block to to display error but will be able to save data after creating our file
  - open the loader.txt file (this time it exist)
  - for loop to save the data inside our Sensor string array
  - close the file and return to main
*/
bool LoadData(Sensor &sensorData)
{
	ostringstream filename;
	filename << "loader.txt";
	ifstream loadfile;
	
	try{
		loadfile.open(filename.str(), ios::in);
		if(loadfile.fail())
		{
			loadfile.close();
			ostringstream err_msg;
			err_msg << filename.str() << " File does not Exist" << ends;
			throw runtime_error(err_msg.str());
		}
		string content;
		if(loadfile.peek() == EOF)
		{
			ostringstream err_msg;
			err_msg << " loader.txt File is empty, no data saved" << ends;
			throw runtime_error(err_msg.str());
		}
		while(true)
		{
			loadfile >> content;
			if(loadfile.eof())
			{
				break;
			}
			sensorData.setSensor(sensorData.size, content);
			sensorData.size++;
		}
	}
	catch(const runtime_error &err)
	{
		cerr << err.what() << endl;
		return false;
	}
	return true;
}
//===========================================================================================================
/*Copy from parent Sensor and store into SensorA
  - iterate all the way through Sensor's array
  - if Sensor's data is a digit
  	- this is done by checking the first element in the string sensor[i]
  	- enter if statement if it is true and convert string to integer
  	- increment SensorA's size.
  - exist if statements
  - repeat the loop until we iterate through all of Sensor's string array
  - exit function and return to main
*/
void CopyA(Sensor &sensor, SensorA &sensor_a)
{
	string content;
	for(int i = 0; i < sensor.size; i++)
	{
		content = sensor.getSensor(i);
		if(isdigit(content[0]))
		{
			sensor_a.sensorA[sensor_a.size] = stoi(content);
			sensor_a.size++;
		}
	}
	return;
}
//===========================================================================================================
/*Copy from parent Sensor and store into SensorB
  - iterate all the way through Sensor's array
  - if Sensor's data is a digit
  	- this is done by checking the first element in the string sensor[i]
  	- enter if statement if it is false and store into SensorB's string array
  	- increment SensorB's size.
  - exit if statement
  - repeat the loop until we iterate through all of Sensor's string array
  - exit function and return to main
*/
void CopyB(Sensor &sensor, SensorB &sensor_b)
{
	string content;
	for(int i = 0; i < sensor.size; i++)
	{
		content = sensor.getSensor(i);
		if(!isdigit(content[0]))
		{
			sensor_b.sensorB[sensor_b.size] = content;
			sensor_b.size++;
		}
	}
}
