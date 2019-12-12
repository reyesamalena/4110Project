#include <iostream>
 #include <cstdio>

using namespace std;


int** map_array(unsigned int size ){
     int** array2D = 0;

    for (int i = 0; i < 3; i++){
        array2D = new int*[size];
    }
    int dist[50];
    for( int n =0; n< 50; n++){ //for array two
        dist[n]=n+1;

    }
     random_shuffle(std::begin(dist), std::end(dist));
    int rand_dist = 0;

    for (int h = 0; h < size; h++)
    {
          array2D[h] = new int[size];

          for (int w = 0; w < size; w++)
          {
                // fill in some initial values
                // (filling in zeros would be more logic, but this is just for the example)

                   array2D[h][w] = 0;
      
               
          }
    }
    
    for (int h = 0; h < size; h++)
    {


          for (int w = 0; w < size; w++)
          {
                // fill in some initial values
                // (filling in zeros would be more logic, but this is just for the example)
              if(w>h){
                  
                   array2D[h][w] = dist[rand_dist];
                  
                  array2D[w][h]= dist[rand_dist];
                  rand_dist++;
                 
                  
              }else if(w==h){
                   array2D[h][w] = 0;
              }
               
          }
    }

    return array2D;
}



int main(){
        int size = 5;
    
    int** my2DArray = map_array(size);
    
    // print contents of the array2D
    cout<< "Map:"<< endl;



    for (int h = 0; h < size; h++)
    {
    
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
