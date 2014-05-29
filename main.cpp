// InsertAlgorithm.cpp : Defines the entry point for the console application.
//

#include "main.h"
using namespace std;

#define sourcefilepath "unsorted.txt"
#define destinationfilepath "sorted.txt"

int main(int argc, char* argv[]) {

	AlgorithmLab algorithmLab;

	for (int i = 1; i < argc - 1; i++){

		if (argv[i + 1] == string("-d"))
		{
			algorithmLab.m_duplicates = true;
		}

		std::vector<int> unsortedVector = algorithmLab.openFile(argv[argc - 1]);

		if (argv[i] == string("-i")) {

			algorithmLab.Insertsort(unsortedVector);
		}
		else if (argv[i] == string("-m")){
			algorithmLab.Merge_Sort(unsortedVector);
		}

		else
			cout << "Please enter a valid command" << '\n';
	}

	return 0;
}

void AlgorithmLab::WriteToFile(std::vector<int> myVector)
{
	ofstream myFile("sorted.txt");

	for (int j = 0; j < myVector.size(); j++)
	{
		myFile << myVector[j] << '\n';
	}

	myFile.close();
	return;
}

void AlgorithmLab::Insertsort(std::vector<int> unsortedVector)
{
	if (!unsortedVector.empty())
	{
		int item = 0; int steps = 0;
		for (int i = 0; i < unsortedVector.size(); i++)
		{
			item = unsortedVector[i];
			steps = i - 1;
			while (steps >= 0 && (unsortedVector[steps] > item))
			{
				unsortedVector[steps + 1] = unsortedVector[steps];
				steps--;
			}
			unsortedVector[steps + 1] = item;
		}
		WriteToFile(unsortedVector);
	}
}

std::vector<int> AlgorithmLab::openFile(char* file)
{
	std::vector<int> unsortedVector;
	ifstream myFile;
	myFile.open(file);
	string line;
	bool isThereDuplicates = false;
	if (myFile.is_open())
	{
		try
		{
			while (getline(myFile, line)){

				if (m_duplicates)
					isThereDuplicates = FindDuplicatesInVector(line, unsortedVector);

				if (!isThereDuplicates)
					unsortedVector.push_back(atoi(line.c_str()));

				isThereDuplicates = false;
			}
		}

		catch (...)
		{
			cout << "Error reading file. \n Make sure that it contains only integers." << endl;
			unsortedVector.clear();
			return unsortedVector;
		}
	}

	else
	{
		cout << "File does not exist" << endl;
		return unsortedVector;
	}

	myFile.close();
	return unsortedVector;
}

bool AlgorithmLab::FindDuplicatesInVector(std::string line, std::vector<int> unsortedvector)
{
	for (int i = 0; i < unsortedvector.size(); i++)
	{
		if (unsortedvector[i] == atoi(line.c_str()))
			return true;
	}

	return false;
}

std::vector<int> AlgorithmLab::MergeHalfs(std::vector<int>left, std::vector<int> right)
{
		std::vector<int> result;
		while (left.size() > 0 || right.size() > 0)

		{	
			if (left.size() > 0 && right.size() > 0)

			{					
				if (left.front() <= right.front())

				{								
					result.push_back(left.front());
					left.erase(left.begin());	
				}
				else
				{								
					result.push_back(right.front());
					right.erase(right.begin());	
				}
			}
				else if (left.size() > 0)			
			{									
				result.push_back(left.front());
				left.erase(left.begin());		
			}
				else if (right.size() > 0)			
			{									
				result.push_back(right.front());
				right.erase(right.begin());		
			}
		}
		WriteToFile(result);
		return result;
}

std::vector<int> AlgorithmLab::Merge_Sort(std::vector<int> unsortedVector)
{
	if (unsortedVector.size() <= 1)					

	{
		return unsortedVector;
	}										

	std::vector<int> left; std::vector<int> right;

	int middle = floor(unsortedVector.size() / 2);	

	for (int x = 0; x < middle; x++) {		
		left.push_back(unsortedVector[x]);
	}										

	for (int x = middle; x < unsortedVector.size(); x++) {
		right.push_back(unsortedVector[x]);
	}

	left = Merge_Sort(left);			
	right = Merge_Sort(right);
	return MergeHalfs(left, right);
}
