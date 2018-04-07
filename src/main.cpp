#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char** argv){
	// Define weight and items vectors, as well as 2D array table.
	std::vector<int> weight = {0, 15, 25, 45, 30, 23, 37};
	std::vector<int> items = {0, 100, 360, 225, 67, 275, 168};
	int table[6][50];

	// Fill empty 2D array table with 0 values.
	 for(int i = 0; i < 6; i++){
                for(int w = 0; w < 50; w++){
                	table[i][w] = 0;
                }
        }
	
	// Loop through the item section of 2D array table (loop through the rows).
	for(int i = 1; i < 6; i++){
		// Loop through the weight section of 2D array table (Loop through the columns).
		for(int w = 1; w < 50; w++){
			// If the item has a weight LESS than the weight currently being looped through, set the 2D array table value at that point to the maximum value of either the previous item's maximum value OR the current item value plus the previous maximum value if it can fit in with the weight. 
			if(weight[i] < w){
				table[i][w] = std::max(table[i-1][w], items[i]+table[i-1][w-weight[i]]);
			}else{
			// Else, just set the item value to the previous maximum value, if it can fit.
				table[i][w] = table[i-1][w];		
			}
		}
	}
	
	// Prints out the 2D array.
	for(int i = 0; i < 6; i++){
		for(int w = 0; w < 50; w++){
			std::cout << table[i][w] << " ";
		}
		std::cout << std::endl;
	}
	
}
