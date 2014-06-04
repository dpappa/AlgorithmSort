#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

class AlgorithmLab
{
public:
	AlgorithmLab() { m_duplicates = false; }; // constructor
	~AlgorithmLab() {}; // de constructor
	void WriteToFile(std::vector<int> myVector);
	void Insertsort(std::vector<int> unsortedVector);
	std::vector<int> openFile(char* file);
	bool FindDuplicatesInVector(std::string line, std::vector<int> unsortedvector);
	std::vector<int> MergeHalfs(std::vector<int>left, std::vector<int> right);

	std::vector<int> Merge_Sort(std::vector<int> unsortedVector);
	std::vector<int> Quick_Sort(std::vector<int> unsortedVector);

	bool m_duplicates;

private:

}; 