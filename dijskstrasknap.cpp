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
int printSolution(int dist[], int V)
{
    
    int ret=0;
   // printf("Vertex \t\t Distance from Source\n");
    for (int i = 0; i < V; i++){
      //  printf("%d \t\t %d\n", i, dist[i]);
        ret+= dist[i];
    }
    return ret;
}
  
// Function that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
int dijkstra(int **graph, int src, int V)
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
    return printSolution(dist, V);
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
int max(double a, double b) { return (a > b)? a : b; }

// Returns the max value to put into truck
int knapSack(int W, int wt[], int val[], int n, int **graph)
{
    

    // Base Case
    if (n == 0 || W == 0){
        int ret = dijkstra(graph, n, W);
       // cout << "RETURN -"<< ret << endl;
        return -ret;
    }
    // If weight of the nth item is more
    // than Knapsack capacity W, then
    // this item cannot be included
    // in the optimal solution
    if (wt[n-1] > W){
        return knapSack(W, wt, val, n-1, graph);
    }
    // Return the maximum of two cases:
    // (1) nth item included
    // (2) not included
    else {
        int part1 =(val[n-1] - graph[0][n]) + knapSack(W-wt[n-1], wt, val, n-1, graph);
        int part2 =    knapSack(W, wt, val, n-1, graph);
        return max(part1,part2);
    }

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
      //  std::cout << it->str() ;
        numbers++;
    }
   
     //int graph= new int*[numbers+1];
    int **graph=new int*[numbers+1];
    
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
                            //std::cout << it->str() ;
            }
            numbers++;
        }
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

    int val_nap[hold+1];
    int wt_nap[hold+1];
    firstline=0;
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
        val_nap[firstline]= stoi(row[2]);
        wt_nap[firstline]= stoi(row[1]);
        firstline++;
		// create temp item from values to add to vector
		item temp(row[0],stoi(row[1]),stod(row[2]),row[3]);
		Items.push_back(temp);
	}

	file.close();

	Items = itemSorter(Items);

	int n = Items.size();
    
    int mn= sizeof(val_nap)/sizeof(val_nap[0]);
    cout << "Maximum profit is : "<< knapSack(W,wt_nap,val_nap, mn, graph);//


	return 0;
}

/*Resources for Dijkstra were also helpful and provided by Dijkstra’s shortest path algorithm | Greedy Algo-7. */
/* www.geeksforgeeks.org/0-1-knapsack-problem-dp-10 */

