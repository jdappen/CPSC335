/* Assignment 1: Alternating disks problem, lawnmower algorithm                                                                                                                              
 XX YY ( YOU NEED TO COMPLETE YOUR NAME )  
 Given 2n alternating disks (dark, light)  the program reads the number of single color disks 
 (light or dark), arranges the disks in the correct order and outputs the number of swaps 
 INPUT: a positive integer n and a list of 2n disks of alternating colors dark-light, starting with dark 
 OUTPUT: a list of 2n disks, the first n disks are light, the next n disks are dark, 
and an integer m representing the number of moves to move the dark ones after the light ones */
package cpsc335ass1part2;
import java.util.Scanner;

public class CPSC335Ass1part2 {

    public static void main(String[] args) {
       int n;
     int m = 1;
     int k;
     int i;
     int l= 1;
     int j = 0;
     int[] disks;
     
     //header prompt
     System.out.println("CPSC 3335-01-Programming Assignment #1");
     System.out.println("The alternating disk problem: lawnmower algorithm");
     System.out.println("Enter the number of single color disks(light or dark)");
     
     //input scanner
     Scanner input = new Scanner(System.in);
     
     //reads input and sets array size
     n = input.nextInt();
     disks = new int[2*n];
     
     for(i = 0; i < n; i++)
     {
         disks[2*i] = 1;
         disks[2*i+1] = 0;
     }
     
     System.out.println("Initial Configuration");
     
     print_disks(n, disks);
     
     for(k =0; k <n/2+1; k++)
     {

        for(  j = k; j < disks.length- 1; j++)
        {       
            if(disks[j] == 1)
            {
                int temp = disks[j+1];
                disks[j+1] = disks[j];
                disks[j] = temp;
                m++;
            }
         }
        
         for(j = disks.length -1; j> k; j--)
         {
             if(disks[j] == 0)
             {
                int temp = disks[j-1];
                disks[j-1] = disks[j];
                disks[j] = temp;
                m++;
             }
         }
        
        

     }
     
    //after shuffling
    System.out.println("After moving darker ones to the right");
    print_disks(n, disks);
    
    //pritn swap number
    System.out.println("Number of swaps is " + m);
    }
    
    public  static void print_disks(int n, int[] disks)
    {
        System.out.println("List of disks");
        for(int i = 0; i < disks.length; i++)
        {
            if(disks[i] == 0)
            {
                System.out.print("l");
            }
            else{
                System.out.print("d");
            }
        }
        System.out.println("");
    }
}
