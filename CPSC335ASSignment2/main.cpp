/* 
 * File:   main.cpp
 * Author: bigmanlaptop
 *
 * Created on March 14, 2017, 3:38 PM
 */

#include <cstdlib>
#include <iostream>
#include <chrono>
#include <string>

using namespace std;


string algo(int n, int **a)
{
     int count = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(a[i][j] != 100 && a[i][j] != 0)
            {
                count++;
            }
        }
    }
    cout << count << endl;
    if(count == (2 * n))
    {
        return "Ring";
    }
    else if(count == ((2 * n)-2))
    {
        return "Star";
    }
    else if(count == (4 * n))
    {
        return "complete";
    }
    else
    {
        return "neither";
    }
}
/*
 * 
 */
int main(int argc, char** argv) {
     
    int numNodes;
    int **graph;
    string topo = "";
    cout << "Enter the number of nodes in the topology" << endl;
    cin >> numNodes;
    
    //create the two dimensional array
    graph = new int *[numNodes];
    for(int i = 0; i <numNodes; i++)
    {
        graph[i] = new int[numNodes];
    }
    cout << "Enter the weight matrix" << endl;
    
    // populate the two dimensional array
    for(int i = 0; i < numNodes; i++)
    {
        for(int j = 0; j < numNodes; j++)
        {
            cin >> graph[i][j];
        }
        
    }
    
    
    
    auto start = chrono::high_resolution_clock::now();
    
    topo = algo(numNodes, graph);
    
    auto end = chrono::high_resolution_clock::now();
    
    
    int microseconds = chrono::duration_cast<chrono::microseconds>(end-start).count();
    double seconds = microseconds/1E6;
    
    
    cout << "The topology is" << endl << topo << endl;
    cout << "elapsed time: " << seconds << " seconds" << endl;
    
    return 0;
}

