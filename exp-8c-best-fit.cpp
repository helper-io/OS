#include <iostream> 
#include <queue> 
#include <vector> 
using namespace std; 

// Process Class 
class process { 
public: 
	
	size_t size; 
	pid_t no; 
}; 

// Memory Class 
class memory { 
public: 
	size_t size; 

	pid_t no; 
	queue<process> space_occupied; 

	// Function to push process in a block 
	void push(const process p) 
	{ 
		if (p.size <= size) { 
			space_occupied.push(p); 
			size -= p.size; 
		} 
	} 

	process pop() 
	{ 
		process p; 

		// If space occupied is empty 
		if (!space_occupied.empty()) { 
			p = space_occupied.front(); 
			space_occupied.pop(); 
			size += p.size; 
			return p; 
		} 
	} 

	bool empty() 
	{ 
		return space_occupied.empty(); 
	} 
}; 


vector<memory> best_fit(vector<memory> memory_blocks, 
						queue<process> processess) 
{ 
	int i = 0, min, index = 0; 
	memory na; 
	na.no = -10; 

	// Loop till processe is not empty 
	while (!processess.empty()) { 
		min = 0; 

		// Traverse the memory_blocks 
		for (i = 0; i < memory_blocks.size(); i++) { 
			if (memory_blocks.at(i).size >= processess.front().size && (min == 0 || memory_blocks.at(i).size < min)) { 
				min = memory_blocks.at(i).size; 
				index = i; 
			} 
		} 

		if (min != 0) { 
			memory_blocks.at(index).push(processess.front()); 
		} 
		else { 
			na.size += processess.front().size; 
			na.push(processess.front()); 
		} 

		// Pop the processe 
		processess.pop(); 
	} 

	if (!na.space_occupied.empty()) { 
		memory_blocks.push_back(na); 
	} 

	// Return the memory_blocks 
	return memory_blocks; 
} 

void display(vector<memory> memory_blocks) 
{ 
	int i = 0, temp = 0; 
	process p; 
	cout << "+-------------+--------------+--------------+"
		<< endl; 
	cout << "| Process no. | Process size | Memory block |"
		<< endl; 
	cout << "+-------------+--------------+--------------+"
		<< endl; 

	// Traverse memory blocks size 
	for (i = 0; i < memory_blocks.size(); i++) { 

		// While memory block size is not empty 
		while (!memory_blocks.at(i).empty()) { 
			p = memory_blocks.at(i).pop(); 
			temp = to_string(p.no).length(); 
			cout << "|" << string(7 - temp / 2 - temp % 2, ' ') 
				<< p.no << string(6 - temp / 2, ' ') 
				<< "|"; 

			temp = to_string(p.size).length(); 
			cout << string(7 - temp / 2 - temp % 2, ' ') 
				<< p.size 
				<< string(7 - temp / 2, ' ') << "|"; 

			temp = to_string(memory_blocks.at(i).no).length(); 
			cout << string(7 - temp / 2 - temp % 2, ' '); 

			// If memory blocks is assigned 
			if (memory_blocks.at(i).no != -10) { 
				cout << memory_blocks.at(i).no; 
			} 

			// Else memory blocks is assigned 
			else { 
				cout << "N/A"; 
			} 
			cout << string(7 - temp / 2, ' ') 
				<< "|" << endl; 
		} 
	} 
	cout << "+-------------+--------------+--------------+"
		<< endl; 
} 

// Driver Code 
int main() 
{ 
	// Declare memory blocks 
	vector<memory> memory_blocks(5); 

	// Declare best fit blocks 
	vector<memory> best_fit_blocks; 

	// Declare queue of all processess 
	queue<process> processess; 
	process temp; 

	// Set sample data 
	memory_blocks[0].no = 1; 
	memory_blocks[0].size = 400; 

	memory_blocks[1].no = 2; 
	memory_blocks[1].size = 500; 

	memory_blocks[2].no = 3; 
	memory_blocks[2].size = 300; 

	memory_blocks[3].no = 4; 
	memory_blocks[3].size = 200; 

	memory_blocks[4].no = 5; 
	memory_blocks[4].size = 100; 

	temp.no = 1; 
	temp.size = 88; 

	// Push the processe to queue 
	processess.push(temp); 
	temp.no = 2; 
	temp.size = 192; 

	// Push the processe to queue 
	processess.push(temp); 
	temp.no = 3; 
	temp.size = 277; 

	// Push the processe to queue 
	processess.push(temp); 
	temp.no = 4; 
	temp.size = 365; 

	// Push the processe to queue 
	processess.push(temp); 
	temp.no = 5; 
	temp.size = 489; 

	// Push the processe to queue 
	processess.push(temp); 

	// Get the data 
	best_fit_blocks = best_fit(memory_blocks, 
							processess); 

	// Display the data 
	display(best_fit_blocks); 
	memory_blocks.clear(); 
	memory_blocks.shrink_to_fit(); 
	best_fit_blocks.clear(); 
	best_fit_blocks.shrink_to_fit(); 
	return 0; 
} 
