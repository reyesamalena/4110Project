#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

class item {
	public:
	string name;
	int weight;
	int cost;
	string address;
	float value;
	float earn;

	item(string n,int w,int c,string a) {
		name = n;
		weight = w;
		cost = c;
		address = a;
		value = c/w;
		earn = c/10;
	}
};

void printItems(vector<item> I)
{
	cout << "Name\tWeight\tCost\tAddress\t\tValue\tEarn\n";
	for(int x=0;x<I.size();x++) {
		cout << I[x].name << "\t" << I[x].weight << "\t";
		cout << I[x].cost << "\t" << I[x].address << "\t";
		cout << I[x].value << "\t" << I[x].earn << "\n";
	}
}

int main()
{
	//store items
	vector<item>Items;

	string filename;
	//ask user for filename of item set
	cout << "Which file of item input to test?" << endl;
	getline(cin, filename);

	//read file for items
	ifstream file(filename.c_str());
	while(file)
	{
		string s;
		if(!getline(file,s)) break;

		//split row into values seperated by commas
		istringstream ss(s);
		vector<string> row;
		while(ss)
		{
			string value;
			if(!getline(ss, value, ',')) break;
			row.push_back(value);
		}

		//create temp item from values to add to vector
		item temp(row[0],stoi(row[1]),stoi(row[2]),row[3]);
		Items.push_back(temp);
	}

	file.close();
	printItems(Items);

	return 0;
}
