#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <regex>
#include <limits.h>
#include <stdio.h>
  
// Number of vertices in the graph


using std::regex;
using std::string;
using std::sregex_token_iterator;

using namespace std;


// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
int minDistance(int dist[], bool sptSet[], int V)
{
    // Initialize min value
    int min = INT_MAX, min_index;
  
    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
  
    return min_index;
}
  
// A utility function to print the constructed distance array
void printSolution(int dist[], int V)
{
    printf("Vertex \t\t Distance from Source\n");
    for (int i = 0; i < V; i++){
        printf("%d \t\t %d\n", i, dist[i]);
    }
}
  
// Function that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
void dijkstra(int **graph, int src, int V)
{
    int dist[V]; // The output array.  dist[i] will hold the shortest
    // distance from src to i
  
    bool sptSet[V]; // sptSet[i] will be true if vertex i is included in shortest
    // path tree or shortest distance from src to i is finalized
  
    // Initialize all distances as INFINITE and stpSet[] as false
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;
  
    // Distance of source vertex from itself is always 0
    dist[src] = 0;
  
    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not
        // yet processed. u is always equal to src in the first iteration.
        int u = minDistance(dist, sptSet, V);
  
        // Mark the picked vertex as processed
        sptSet[u] = true;
  
        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < V; v++)
  
            // Update dist[v] only if is not in sptSet, there is an edge from
            // u to v, and total weight of path from src to  v through u is
            // smaller than current value of dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
  
    // print the constructed distance array
    printSolution(dist, V);
}

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
    
    
    
    smatch cps;
    regex comma(",");        //comma regex
    string mapfilename;
    string temp;
    
 
    // ask user for filename of item set
    cout << "Which file of item input to map txt?" << endl;
    getline(cin, mapfilename);
    int firstline=0;
    regex re("[\\s,]+");
    int numbers=0;
    // read file for items
    ifstream mapfile(mapfilename.c_str());
    getline(mapfile, temp);
    string s = temp;
    sregex_token_iterator it(s.begin(), s.end(), re, -1);
    sregex_token_iterator reg_end;
    for (; it != reg_end; ++it) {
        std::cout << it->str() ;
        numbers++;
    }
    cout << "elem----" << numbers<<  endl;
     //int graph= new int*[numbers+1];
    int **graph=new int*[numbers+1];
    //input array elements

    
    for(int i=0; i<numbers+1; i++){
        graph[i]= new int[numbers+1];
    }
    for(int i=0;i<numbers;i++)
    {
        for(int j=0;j<numbers+1;j++)
        {
            graph[i][j]=0;
        }
    }
    int hold=numbers;
    numbers=0;
    int rows=0;
    while(mapfile)
    {
        
        getline(mapfile, temp);
        string sms = temp;
        sregex_token_iterator it(sms.begin(), sms.end(), re, -1);
        sregex_token_iterator reg_end;
        for (; it != reg_end; ++it) {
            if(numbers==0){
                
            }else{
                string t= it->str() ;
                int tt=stoi(t);
                graph[rows][numbers-1]=tt;
                            std::cout << it->str() ;
            }
            numbers++;
        }
        cout << "elem" << numbers<<  endl;
                numbers=0;
        rows++;

    }

    mapfile.close();

    dijkstra(graph, 0, hold);
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

	//Items = eliminator(Items,W);	//eliminates that are not in the range
	Items = itemSorter(Items);

	int n = Items.size();
	cout << "Maximum profit is : "<< knapSack(W,Items,n) << endl;

	cout << "Items under Weight " << W << " :" << endl;
	printItems(Items);

	return 0;
}

