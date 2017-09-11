

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include <chrono>
#include <cmath>

using namespace std;


struct point2D{
    float x;
    float y;
};

void print_cycle(int, point2D*, int*);
int farthest_point(int, point2D*);

int nearest(int, point2D*);

int main(int argc, char** argv) {

    point2D *P;
    int *M;
    bool *Visited;
    int i;
    int n;
    float dist;
    int A;
    int B;
    
    cout << endl << "CPSC 335-1 - Programming Assignment #3" << endl;
    cout << "Rectilinear traveling salesperson problem: INNI algorithm" << endl;
    cout << "Enter the number of vertices (>2)" << endl;
    
    cin >> n;
    
    if(n < 3)
    {
        return 0;
    }
    
    P = new point2D[n];
    
    cout << "Enter the points; make sure that they are distinct" << endl;
    
    for( i = 0; i < n; i++)
    {
        cout << "X = ";
        cin P[i].x;
        cout << "Y = ";
        cin >> P[i].y;
    }
    
    M = new int[n];
    
    for( i = 0; i < n; i++)
    {
        M[i] = i;
    }

    auto start = chrono::high_resolution_clock::now();
    
    Visited = new bool[n];
    
    for( i = 0; i < n; i++)
    {
        Visited[i] = false;
    }
    
    A = farthest_point(n,P);
    i = 0;
    M[i] = A;
    
    Visited[A] = true;
    
    for( i = 1; i < n; i++)
    {
        B = nearest(n,P,A,Visited);
        A =B;
        M[i] = A;
        Visited[A] = true;
    }
    
    dist = 0;
    
    for( i = 0; i < n-1; i++)
    {
        dist += abs(P[M[i]].x - P[M[i+1]].x) + abs(P[M[0]].y - P[M[n-1]].y);
        
    }
    
    dist += abs(P[M[0]].x - P[M[n-1]].x) + abs(P[M[0]].y - P[M[n-1]].y);
    
    auto end = chrono::high_resolution_clock::now();
    
    cout << "The Hamiltonian cycle of a relative minimum length " << endl;
    print_cycle(n, P, M);
    cout << "The relative minimum length is " << dist << endl;
    
    
    
    int microseconds = chrono::duration_cast<chrono::microseconds>(end - start).count();
    double seconds = microseconds / 1E6;
    cout << "elapsed time: " << seconds << " seconds" << endl;
    
    delete []P;
    delete []M;

    return 0;
}

int farthest_point(int n, point2D *P)
{
    float max_dist = 0;
    int i, j;
    int index;
    float dist;
  
    for(i=0; i < n-1; i++)
        for(j=0; j < n;j++) 
        {
            dist = abs(P[i].x - P[j].x) + abs(P[i].y - P[j].y);
            if (max_dist < dist)
            {
                
            
                max_dist = dist;
                index = i;
                
            }
            
        }
    return index;
}

int nearest(int n, point2D *P, int A, bool *Visited)
{
    float dist;
    
    for( int i = 0; i < n, i++)
    {
        
    }
}

void print_cycle( int n, point2D *P, int *seq)
{
    
}
