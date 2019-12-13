#include <iostream>
#include <cstdio>
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
    int index;
    string name;
    int weight;
    double cost;
    string address;
    double value;
    double earn;

    item(int id, string n,int w,int c,string a) {
        index = id;
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




int** map_array(unsigned int size, string arr[] ){
     int** array2D = 0;

    for (int i = 0; i < 3; i++){
        array2D = new int*[size+1];
    }
    int dist[50];
    int tmp=0;
    for( int n =0; n< 50; n++){ //for array two
        if(n+1 ==1){
            tmp =2;
        }
        tmp = n+1;
        cout << tmp++ << endl;
        dist[n]=tmp;


    }
     random_shuffle(std::begin(dist), std::end(dist));
    int rand_dist = 0;

   
    cout<<endl;
    for (int h = 0; h < size+1; h++)
    {


          array2D[h] = new int[size+1];

          for (int w = 0; w < size; w++)
          {
                // fill in some initial values
                // (filling in zeros would be more logic, but this is just for the example)

                   array2D[h][w] = 0;
      
               
          }
    }
    int times=1;
    for (int h = 0; h < size+1; h++)
    {
 

          for (int w = 0; w < size+1; w++)
          {
                // fill in some initial values
                // (filling in zeros would be more logic, but this is just for the example)
              if(rand_dist==50){
                  rand_dist=0;
              }
              if(w>h){
                  
                  if(times==1){
                      
                      array2D[h][w] = 1;
                      
                      array2D[w][h]= 1;
                      rand_dist++;
                      times++;
                      
                  }else{
                      
                      array2D[h][w] = dist[rand_dist];
                      array2D[w][h]= dist[rand_dist];
                      rand_dist++;
                  }
                  

                 
                  
              }else if(w==h){
                   array2D[h][w] = 0;
              }
               
          }

    }

    return array2D;
}



int main(){
        // store items
        vector<item> Items;
            
    
        string fname;
    	string namearray[201];
   	int m=0;
   	cout << "Which file of map input to test?" << endl;
    	getline(cin, fname);
    
    	ifstream filen(fname.c_str());
    	while(filen)
    	{
        	string ps;
        	if(!getline(filen,ps)) break;
        
        	// split row into values seperated by commas
        	istringstream pss(ps);

        	while(pss)
        	{
            		string value;
            		if(!getline(pss, value, ',')) break;
            		namearray[m]= value;
            		m++;
        	}

    	}	

    	filen.close();

        string filename;
        // ask user for filename of item set
        cout << "Which file of item input to test?" << endl;
        getline(cin, filename);

        int W = 100;
        // ask user for maximum weight W
        cout << "What is the max weight, W, that the truck can carry?" << endl;
            cin >> W;
        int idtemp=0;
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
            item temp(idtemp, row[0],stoi(row[1]),stod(row[2]),row[3]);
            Items.push_back(temp);
        }

        file.close();

        
        Items = itemSorter(Items);
//	Items = eliminator(Items);
        int n = Items.size();
        cout << knapSack(W,Items,n) << endl;

    //    printItems(Items);

    
    
    
    int size = 201;
    
    int** my2DArray = map_array(size, namearray);
    
    // print contents of the array2D
    //cout<< "Map:"<< endl;

    for (int w = 0; w < size; w++)
    {
       cout<< namearray[w]<<",";
    }
    cout<<endl;

    for (int h = 0; h < size; h++)
    {       cout<< namearray[h]<<",";
    
          for (int w = 0; w < size; w++)
          {
              cout<<  my2DArray[h][w]<<",";
          }
        cout<<endl;
    }

        // important: clean up memory
        printf("\n");
        printf("Cleaning up memory...\n");
        for (  int h = 0; h < size; h++)
        {
          delete [] my2DArray[h];
        }
        delete [] my2DArray;
        my2DArray = 0;
        printf("Ready.\n");
    
    return 0;
    
}
