#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>

using namespace std;

// class to hold item properties
class item {
public:
	string name;
	int weight;
	double cost;
	string address;
	double value;
	double earn;

	item(string n,int w,int c,string a) {
		name = n;
		weight = w;
		cost = c;
		address = a;
		value = ((double)c)/((double)w);
		earn = ((double)c)/10;
	}
	
	// define operator to help sort items	
	bool operator> (const item &other) const {
		return value > other.value;
	}
};


// sort items by their value (cost/weight)
vector<item> itemSorter(vector<item> I) {
	vector<item> items_temp = I;
	sort(items_temp.begin(), items_temp.end(), greater <item>());
	return items_temp;
}

// eliminates items with weights > Weight max of truck
vector<item> eliminator(vector<item> I, int W) {
	vector<item> temp = I;
	vector<item> newItems;
	for(int i=0;i<temp.size();i++) {
		if(temp[i].weight <= W)
			newItems.push_back(temp[i]);
	}
	return newItems;
}

//prints all Items
void printItems(vector<item> I)
{
	cout << "Name\t\t\tWeight\tCost\tValue\tEarn\tAddress\n";
	for(int x=0;x<I.size();x++) {
		cout << I[x].name << "\t\t";
		cout << I[x].weight << "\t";
		cout << I[x].cost << "\t";
		cout << I[x].value << "\t";
		cout << I[x].earn << "\t";	
		cout << I[x].address << "\n";
	}
}

// utility function returns max of 2 ints
double max(double a, double b) { return (a > b)? a : b; }

// Returns the max value to put into truck
double knapSack(int W, vector<item> I, int n)
{
	int i, w;
	double K[n+1][W+1];

	//Build table K[][] in bottom up manner
	for (i=0;i<=n;i++) 
	{
		for (w=0;w<=W;w++)
		{
			if(i==0 || w==0)
				K[i][w] =0.0;
			else if(I[i-1].weight <= w)
				K[i][w] = (max(I[i-1].earn + (double)K[i-1][w - I[i-1].weight], K[i-1][w]));
			else
				K[i][w] = (K[i-1][w]);
		}
	}

	return (K[n][W]);
}



int main()
{
	// store items
	vector<item> Items;

	string filename;
	// ask user for filename of item set
	cout << "Which file of item input to test?" << endl;
	getline(cin, filename);

	int W = 100;	
	// ask user for maximum weight W
	cout << "What is the max weight, W, that the truck can carry?" << endl;
       	cin >> W;	


	// read file for items
	ifstream file(filename.c_str());
	while(file)
	{
		string s;
		if(!getline(file,s)) break;
		
		// split row into values seperated by commas
		istringstream ss(s);
		vector<string> row;
		row.clear();
		while(ss)
		{
			string value;
			if(!getline(ss, value, ',')) break;
			row.push_back(value);
		}
		// create temp item from values to add to vector
		item temp(row[0],stoi(row[1]),stod(row[2]),row[3]);
		Items.push_back(temp);
	}

	file.close();

	Items = eliminator(Items,W);	
	Items = itemSorter(Items);

	int n = Items.size();
	cout << "Maximum profit is : "<< knapSack(W,Items,n) << endl;

	cout << "Items under Weight " << W << " :" << endl;
	printItems(Items);

	return 0;
}
